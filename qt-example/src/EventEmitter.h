#ifndef EVENTEMITTER_H
#define EVENTMITTER_H

#include <QtCore>
#include "CommunicationHandler.h"

class EventEmitter :  public QObject {

    Q_OBJECT

private:
    QSharedPointer<CommunicationHandler> communicationHandler;

public:
    explicit EventEmitter(QSharedPointer<CommunicationHandler> _communicationHandler, QObject* _parent = 0);

public slots:
    void emitEvent(const QString& eventKey, const int priority, QVariant come, QVariant acknowledged, const QString& text, QDateTime timestamp);

};

#endif
