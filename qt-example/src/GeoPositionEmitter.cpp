
#include "JsonUtil.h"
#include "GeoPositionEmitter.h"

GeoPositionEmitter::GeoPositionEmitter(QSharedPointer<QTextStream> _stream, QObject* _parent)
    : QObject(_parent), stream(_stream) {
}

void GeoPositionEmitter::emitGeoPosition(const float latitude, const float longitude) {
    QVariantMap valueMap;

    valueMap["latitude"] = QString::number(latitude);
    valueMap["longitude"] = QString::number(longitude);
    valueMap["tsIso8601"] = QDateTime::currentDateTimeUtc().toString(Qt::ISODate);

    QVariantMap jsonMap;
    jsonMap["geoPosition"] = valueMap;

    QString json = JsonUtil::stringify(jsonMap);

    *stream << json << "\n";
    stream->flush();
}