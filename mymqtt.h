#ifndef MYMQTT_H
#define MYMQTT_H

#include <QObject>
#include "mosquittopp.h"
#include "stdint.h"
#include <QTimer>




class myMqtt : public QObject, public mosqpp::mosquittopp
{
Q_OBJECT
public:
    explicit myMqtt(const char *id=0);
    // implementing all callbacks from mosquitto library
    void on_connect(int rc);
    void on_message(const struct mosquitto_message *message);
    void on_subscribe(uint16_t mid, int qos_count, const uint8_t *granted_qos);
    void on_disconnect(int rc);
    void on_publish(int mid);
    void on_unsubscribe(int mid);
    void on_error();

    void connectBroaker(QString host="localhost",int port=1883);
    void publishBroaker(QString tropic,QString message);


private:
    QString mHost;
    int mPort;
    QTimer *messageLoop;

    void errorHandler(int errorId);

signals:
    void broakerConnected();
    void broakerDisconnected();
    void broakerError(int errorCode);
    void broakerMessage(QString tropic, QByteArray message);

public slots:

private slots:
    void messageLoopHandler();

};

#endif // MYMQTT_H
