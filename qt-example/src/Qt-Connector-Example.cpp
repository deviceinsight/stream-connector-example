#include <QtCore>
#include <QDebug>
#include <QtCore/QList>

#include "Configuration.h"
#include "CommunicationHandler.h"
#include "EventEmitter.h"
#include "DatapointEmitter.h"
#include "GeoPositionEmitter.h"
#include "DummyReader.h"
#include "CommandProcessor.h"

int main(int argc, char* argv[]) {

    /* initialisation of random number generator */
    qsrand((uint)QTime::currentTime().msec());

    /* Qt main application */
    QCoreApplication app(argc, argv);

    /* Create Configuration-Object */
    Configuration *configurationPtr = new Configuration();
    QSharedPointer<Configuration> configuration(configurationPtr);

    /* Setup CommunicationHandler */
    CommunicationHandler *commHdlPtr = new CommunicationHandler(&app);
    QSharedPointer<CommunicationHandler> commHandler(commHdlPtr);

    /* Setup CommandProcessor */
    CommandProcessor *commandProcessor = new CommandProcessor(commHandler, &app);

    /* Output generation */
    EventEmitter *eve = new EventEmitter(commHandler, &app);
    DatapointEmitter *dpe = new DatapointEmitter(commHandler, &app);
    GeoPositionEmitter *gpe = new GeoPositionEmitter(commHandler, &app);
    DummyReader *dummy = new DummyReader(configuration, &app);

    /* Setting up signals and slots */
    app.connect(commHandler.data(), SIGNAL(configurationMessageReceived(QVariantMap)), configuration.data(), SLOT(updateConfiguration(QVariantMap)));
    app.connect(commHandler.data(), SIGNAL(commandMessageReceived(QVariantMap)), commandProcessor, SLOT(commandMessageReceived(QVariantMap)));

    app.connect(configuration.data(), SIGNAL(configurationReceived()), dummy, SLOT(configurationReceived()));

    dummy->connect(dummy, SIGNAL(valueReceived(QString, QVariant)), dpe, SLOT(emitDatapointValue(QString, QVariant)));
    dummy->connect(dummy, SIGNAL(eventReceived(QString, int, QVariant, QVariant, QString, QDateTime)), eve, SLOT(emitEvent(QString, int, QVariant, QVariant, QString, QDateTime)));
    dummy->connect(dummy, SIGNAL(geoPositionReceived(float, float)), gpe, SLOT(emitGeoPosition(float, float)));


    /* Start communication handler */
    commHandler->start();

    /* Enter main loop...*/
    app.exec();
}


