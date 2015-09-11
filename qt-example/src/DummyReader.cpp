#include <QtCore>
#include "DummyReader.h"

DummyReader::DummyReader(QSharedPointer<Configuration> config, QObject* parent)
    : configuration(config), QObject(parent), counter(0) {
    t = new QTimer(this);
    this->connect(t, SIGNAL(timeout()), this, SLOT(timerFired()));

}

void DummyReader::configurationReceived() {
    int interval = configuration->getInterval();

    if(interval > 0) {
        qDebug() << "Timer started with interval" << interval << "s.";
        t->start(interval * 1000);
    } else {
        qDebug() << "Timer interval invalid. <" << interval << "sec>";
    }
}

void DummyReader::timerFired() {
    counter++;

    if(counter % 3 == 1) {
        emit eventReceived(QString("dummy event %1").arg(counter), 0, false, false, "this is an event", QDateTime::currentDateTimeUtc());
    } else if(counter % 3 == 2) {
        emit valueReceived("dummydatapoint", QString("%1").arg(counter));
    } else {
        emit geoPositionReceived((((float)qrand() / (float)RAND_MAX) * 180) - 90, (((float)qrand() / (float)RAND_MAX) * 360) - 180);
    }
}
