
#include "GeoPositionEmitter.h"

GeoPositionEmitter::GeoPositionEmitter(QSharedPointer<CommunicationHandler> _communicationHandler, QObject* _parent)
    : QObject(_parent), communicationHandler(_communicationHandler) {
}

void GeoPositionEmitter::emitGeoPosition(const float latitude, const float longitude) {
    QVariantMap valueMap;

    valueMap["latitude"] = QString::number(latitude);
    valueMap["longitude"] = QString::number(longitude);
    valueMap["tsIso8601"] = QDateTime::currentDateTimeUtc().toString(Qt::ISODate);

    QVariantMap jsonMap;
    jsonMap["geoPosition"] = valueMap;

    communicationHandler->sendMessage(jsonMap);
}