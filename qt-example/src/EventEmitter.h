#ifndef EVENTEMITTER_H
#define EVENTMITTER_H

#include <QtCore>

class EventEmitter :  public QObject {

Q_OBJECT

private:
	QSharedPointer<QTextStream> stream;

public:
	explicit EventEmitter(QSharedPointer<QTextStream> _stream, QObject* _parent=0);

public slots:
	void emitEvent(const QString& eventKey, const int priority,QVariant come, QVariant acknowledged, const QString& text, QDateTime timestamp); 

};

#endif
