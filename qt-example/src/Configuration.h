#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <QtCore>

class Configuration : public QObject  {

    Q_OBJECT

private:
    int interval;
    QSharedPointer<Configuration> configuration;

public:
    Configuration();
    int getInterval() const;

public slots:
    void updateConfiguration(QVariantMap map);

signals:
    void configurationReceived();

};

#endif
