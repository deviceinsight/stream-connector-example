#include <QtCore>
#include "EventEmitter.h"
#include "CommunicationHandler.h"

EventEmitter::EventEmitter(QSharedPointer<CommunicationHandler> _communicationHandler, QObject* _parent)
    : QObject(_parent), communicationHandler(_communicationHandler) {
}

void EventEmitter::emitEvent(const QString& eventKey, const int priority, QVariant come, QVariant acknowledged, const QString& text,  QDateTime tsIso8601) {

    QVariantMap valueMap;

    valueMap["eventKey"] = eventKey;
    valueMap["priority"] = priority;
    valueMap["come"] = come;
    valueMap["acknowledged"] = acknowledged;
    valueMap["text"] = text;
    valueMap["tsIso8601"] = tsIso8601.toString(Qt::ISODate);

    QVariantMap jsonMap;
    jsonMap["event"] = valueMap;

    communicationHandler->sendMessage(jsonMap);
}

