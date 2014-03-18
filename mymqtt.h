#ifndef MYMQTT_H
#define MYMQTT_H

#include <QObject>
#include "mosquittopp.h"

class myMqtt : public QObject, mosqpp::mosquittopp
{
Q_OBJECT
public:
    explicit myMqtt(const char *id=0);
    void on_connect(int rc);
//    void on_message(const struct mosquitto_message *message);
//    void on_subscribe(uint16_t mid, int qos_count, const uint8_t *granted_qos);
signals:

public slots:

};

#endif // MYMQTT_H
