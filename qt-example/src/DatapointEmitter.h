#ifndef DATAPOINTEMITTER_H
#define DATAPOINTEMITTER_H

#include <QtCore>
#include "CommunicationHandler.h"

class DatapointEmitter :  public QObject {

    Q_OBJECT

private:
    QSharedPointer<CommunicationHandler> communicationHandler;

public:
    explicit DatapointEmitter(QSharedPointer<CommunicationHandler> _communicationHandler, QObject* _parent = 0);

public slots:
    void emitDatapointValue(const QString& key, const QVariant& value);

};

#endif
