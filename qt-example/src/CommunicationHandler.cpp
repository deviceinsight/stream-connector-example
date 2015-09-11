
#include "CommunicationHandler.h"


CommunicationHandler::CommunicationHandler(QObject* _parent):
    configurationReceived(false),
    QThread(_parent) {

    /* safe pointers to stdin and stdout */
    output = QSharedPointer<QTextStream>(new QTextStream(stdout));
    input = QSharedPointer<QTextStream>(new QTextStream(stdin));
}


void CommunicationHandler::run() {
    while(!input->atEnd()) {
        QString line = input->readLine(MAX_LINE_LEN);

        QVariantMap map = JsonUtil::parse(line).toMap();

        if(!map.empty()) {
            if(!configurationReceived) {
                /* First received line is always the configuration */
                qDebug() << "Configuration message received:" << line;
                configurationReceived = true;
                emit configurationMessageReceived(map);
            } else {
                /* All other lines are suspected to be commands */
                qDebug() << "command message received:" << line;
                emit commandMessageReceived(map);
            }
        }

        if(input->status() != QTextStream::Ok) {
            qDebug() << "Status of input stream not ok. Status was:" << input->status();
            QCoreApplication::exit(1);
        }
    }

    qDebug() << "Input-stream ended unexpected.";
    QCoreApplication::exit(1);
}

void CommunicationHandler::transmitMessage(QString message) {
    message.append("\n");
    *output << message;
    output->flush();
}

void CommunicationHandler::sendMessage(QVariantMap map) {
    QString transmitString = JsonUtil::stringify(map);
    transmitMessage(transmitString);
}