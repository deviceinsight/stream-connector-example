#ifndef DATAPOINTEMITTER_H
#define DATAPOINTEMITTER_H

#include <QtCore>

class DatapointEmitter :  public QObject {

    Q_OBJECT

private:
    QSharedPointer<QTextStream> stream;

public:
    explicit DatapointEmitter(QSharedPointer<QTextStream> _stream, QObject* _parent = 0);

public slots:
    void emitDatapointValue(const QString& key, const QVariant& value);

};

#endif
