#include <QtCore>
#include "DummyReader.h"

DummyReader::DummyReader(const QString& _dpKey, int interval, QObject* parent)
    : QObject(parent), dpKey(_dpKey), counter(0) {

    if(interval < 1) {
        interval = 10;
    }

    QTimer* t = new QTimer(this);
    this->connect(t, SIGNAL(timeout()), this, SLOT(timerFired()));
    t->start(interval * 1000); //this is in milliseconds
}

void DummyReader::timerFired() {

    counter++;


    if(counter % 3 == 1) {
        emit eventReceived("dummy event", 0, false, false, "this is an event", QDateTime::currentDateTime());
    } else if(counter % 3 == 2) {
        emit valueReceived(dpKey, QString("%1").arg(counter));
    } else {
        emit geoPositionReceived((((float)qrand() / (float)RAND_MAX) * 180) - 90, (((float)qrand() / (float)RAND_MAX) * 360) - 180);
    }
}
