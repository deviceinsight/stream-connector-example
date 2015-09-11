#include "Configuration.h"

Configuration::Configuration() {
    /* Setting default values */
    interval = 5;
}

int Configuration::getInterval() const {
    return interval;
}


void Configuration::updateConfiguration(QVariantMap map)  {
    if(map.contains("interval") && map["interval"].canConvert<int>()) {
        interval = map["interval"].toInt();
    }

    emit configurationReceived();
}
