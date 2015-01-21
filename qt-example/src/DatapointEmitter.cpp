#include <QtCore>
#include "JsonUtil.h"
#include "DatapointEmitter.h"


DatapointEmitter::DatapointEmitter(QSharedPointer<QTextStream> _stream, QObject* _parent)
	: QObject(_parent), stream(_stream) {
}

void DatapointEmitter::emitDatapointValue(const QString& key, const QVariant& value) {
	QVariantMap valueMap;

	valueMap["value"] = value;
	valueMap["key"] = key;

	QVariantMap jsonMap;
	jsonMap["datapointValue"] = valueMap;

	QString json = JsonUtil::stringify(jsonMap);

	*stream << json << "\n";
	stream->flush();
}

