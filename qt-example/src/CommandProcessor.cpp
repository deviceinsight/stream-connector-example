#include <QtCore>
#include "util/JsonUtil.h"
#include "CommandProcessor.h"

CommandProcessor::CommandProcessor(QSharedPointer<CommunicationHandler> commHandler, QObject* _parent)
    : communicationHandler(commHandler), QObject(_parent) {
}

void CommandProcessor::commandMessageReceived(const QVariantMap command) {

    QVariantMap commandResponse;
    commandResponse["id"] = command.value("command").toMap().value("id");

    if(qrand() % 2 == 0) {
        qDebug() << "command successfully executed";
        QVariantMap result;
        result["status"] = "successful";

        commandResponse["result"] = result;
    } else {
        qDebug() << "command unsuccessfully executed";
        commandResponse["errorCode"] = qrand();
        commandResponse["errorMessage"] = "Could not execute command.";
    }

    QVariantMap jsonMap;
    jsonMap["commandResponse"] = commandResponse;

    communicationHandler->sendMessage(jsonMap);
}

