#include <QtCore>
#include "DummyReader.h"

DummyReader::DummyReader(const QString& _dpKey, int interval, QObject* parent) 
	: QObject(parent), dpKey(_dpKey), counter(0) {

	if ( interval < 1 ) {
		interval = 10;
	}
		
	QTimer* t = new QTimer(this);
	this->connect(t, SIGNAL(timeout()), this, SLOT(timerFired()));
	t->start(interval * 1000); //this is in milliseconds
}

void DummyReader::timerFired() {
    	
	QString val = QString("%1").arg(++counter);
	emit valueReceived(dpKey, val);

	if (counter % 10 == 0) {
		emit eventReceived ("dummy event",0,false, false, "this is an event", QDateTime::currentDateTime()); 		
	}
	
}


