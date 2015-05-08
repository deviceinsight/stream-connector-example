#ifndef GEOPOSITIONEMITTER_H
#define GEOPOSITIONEMITTER_H

#include <QtCore>

class GeoPositionEmitter :  public QObject {

    Q_OBJECT

private:
    QSharedPointer<QTextStream> stream;

public:
    explicit GeoPositionEmitter(QSharedPointer<QTextStream> _stream, QObject* _parent = 0);

public slots:
    void emitGeoPosition(const float latitude, const float longitude);

};

#endif
