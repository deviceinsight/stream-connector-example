#include <QtCore>
#include "JsonUtil.h"
#include "ConfigReader.h"


static const int MAX_LINE_LEN = 8192;


ConfigReader::ConfigReader(QSharedPointer<QTextStream> _stream, QObject* _parent)
    : QThread(_parent), stream(_stream) {
}


void ConfigReader::run() {
    while(!stream->atEnd()) {
        QString str = stream->readLine(MAX_LINE_LEN);

        if(stream->status() != QTextStream::Ok) {
            break;
        }

    }

    QCoreApplication::exit(0);
}

QVariantMap ConfigReader::readConfig() {
    if(!stream->atEnd()) {
        QString str = stream->readLine(MAX_LINE_LEN);

        if(stream->status() != QTextStream::Ok) {
            QCoreApplication::exit(0);
            return QVariantMap();
        } else {
            QVariantMap cfgMap = JsonUtil::parse(str).toMap();
            return cfgMap;
        }
    } else {
        QCoreApplication::exit(0);
        return QVariantMap();
    }
}

