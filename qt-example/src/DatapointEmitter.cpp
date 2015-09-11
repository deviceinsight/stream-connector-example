#include <QtCore>
#include "DatapointEmitter.h"

DatapointEmitter::DatapointEmitter(QSharedPointer<CommunicationHandler> _communicationHandler, QObject* _parent)
    : QObject(_parent), communicationHandler(_communicationHandler) {
}

void DatapointEmitter::emitDatapointValue(const QString& key, const QVariant& value) {
    QVariantMap valueMap;

    valueMap["value"] = value;
    valueMap["key"] = key;

    QVariantMap jsonMap;
    jsonMap["datapointValue"] = valueMap;

    communicationHandler->sendMessage(jsonMap);
}

