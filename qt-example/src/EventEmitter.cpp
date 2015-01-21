#include <QtCore>
#include "JsonUtil.h"
#include "EventEmitter.h"


EventEmitter::EventEmitter(QSharedPointer<QTextStream> _stream, QObject* _parent)
	: QObject(_parent), stream(_stream) {
}

void EventEmitter::emitEvent(const QString& eventKey, const int priority, QVariant come, QVariant acknowledged, const QString& text,  QDateTime timestamp) {
	
	QVariantMap valueMap;

	valueMap["eventKey"] = eventKey;
	valueMap["priority"] = priority;
	valueMap["come"] = come;
	valueMap["acknowledged"] = acknowledged;
	valueMap["text"] = text;
	valueMap["timestamp"] = timestamp.toString(Qt::ISODate);

	QVariantMap jsonMap;
	jsonMap["event"] = valueMap;

	QString json = JsonUtil::stringify(jsonMap);

	*stream << json << "\n";
	stream->flush();
}

