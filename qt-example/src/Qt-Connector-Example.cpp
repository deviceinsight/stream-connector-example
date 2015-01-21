#include <QtCore>

#include <QDebug>
#include <QtCore/QList>

#include "EventEmitter.h"
#include "DatapointEmitter.h"
#include "ConfigReader.h"
#include "DummyReader.h"

int main (int argc, char* argv[]) {

	//QT main loop
	QCoreApplication a(argc,argv);

	int interval = 20; //interval in seconds
/*
	if (a.arguments().size() > 1) {
		if (a.arguments().at(1) == "-h") {
			qDebug() << "Usage: connector <interval>"; //\n\tUse DUMMY as directory for demo data";
			::exit(0);
		}
		else {
			interval = a.arguments().at(1).toInt();
		}
		
	}
*/
	//safe pointers to stdin and stdout
	QSharedPointer<QTextStream> streamStdoutPtr = QSharedPointer<QTextStream>(new QTextStream(stdout));
	QSharedPointer<QTextStream> streamStdinPtr = QSharedPointer<QTextStream>(new QTextStream(stdin));

	//read and parse the config from stdin
	ConfigReader *cfgr = new ConfigReader(streamStdinPtr, &a);
	QVariantMap cfgMap = cfgr->readConfig();

	// apply config
	if (cfgMap.contains("interval")) {
		interval = cfgMap["interval"].toInt();
	}

	cfgr->start();
	EventEmitter *eve = new EventEmitter(streamStdoutPtr, &a);
	DatapointEmitter *dpe = new DatapointEmitter(streamStdoutPtr, &a);
        
	DummyReader *dummy = new DummyReader("example key", interval, &a);
	dummy->connect(dummy,SIGNAL(valueReceived(QString,QVariant)),dpe,SLOT(emitDatapointValue(QString,QVariant)));
	dummy->connect(dummy,SIGNAL(eventReceived(QString,int,QVariant,QVariant,QString,QDateTime)),eve,SLOT(emitEvent(QString,int,QVariant,QVariant,QString,QDateTime)));

	a.exec();

}


