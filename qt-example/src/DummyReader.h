#ifndef DUMMYREADER_H_
#define DUMMYREADER_H_

#include <QtCore>
#include "Configuration.h"

class DummyReader :  public QObject {

    Q_OBJECT

private:
    QTimer* t;
    QSharedPointer<Configuration> configuration;
    int counter;

public:
    explicit DummyReader(QSharedPointer<Configuration> config, QObject* parent = 0);

public slots:
    void configurationReceived();
    void timerFired();

signals:
    void valueReceived(const QString& k, const QVariant& v);
    void eventReceived(const QString& eventKey, const int priority, QVariant come, QVariant acknowledged, const QString& text, QDateTime timestamp);
    void geoPositionReceived(const float latitude, const float longitude);
};

#endif
