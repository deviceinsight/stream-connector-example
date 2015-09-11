#ifndef GEOPOSITIONEMITTER_H
#define GEOPOSITIONEMITTER_H

#include <QtCore>
#include "CommunicationHandler.h"

class GeoPositionEmitter :  public QObject {

    Q_OBJECT

private:
    QSharedPointer<CommunicationHandler> communicationHandler;

public:
    explicit GeoPositionEmitter(QSharedPointer<CommunicationHandler> _communicationHandler, QObject* _parent = 0);

public slots:
    void emitGeoPosition(const float latitude, const float longitude);

};

#endif
