#ifndef COMMANDPROCESSOR_H
#define COMMANDPROCESSOR_H

#include <QtCore>
#include "CommunicationHandler.h"

class CommandProcessor :  public QObject {

    Q_OBJECT

private:
    QSharedPointer<CommunicationHandler> communicationHandler;

public:
    CommandProcessor(QSharedPointer<CommunicationHandler> commHandler, QObject* _parent);

public slots:
    void commandMessageReceived(const QVariantMap command);

};

#endif
