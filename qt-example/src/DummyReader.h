#ifndef DUMMYREADER_H_
#define DUMMYREADER_H_

#include <QtCore>

class DummyReader :  public QObject {

    Q_OBJECT

private:
    const QString dpKey;

    int counter;

public:
    explicit DummyReader(const QString& _dpKey, int interval, QObject* parent = 0);

public slots:
    void timerFired();

signals:
    void valueReceived(const QString& k, const QVariant& v);
    void eventReceived(const QString& eventKey, const int priority, QVariant come, QVariant acknowledged, const QString& text, QDateTime timestamp);
    void geoPositionReceived(const float latitude, const float longitude);
};

#endif
