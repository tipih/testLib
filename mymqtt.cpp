#include "mymqtt.h"
#include "mosquittopp.h"
#include <QDebug>
#include <QElapsedTimer>

myMqtt::myMqtt(const char *id ):QObject(0),
                                mosquittopp(id)
{
mHost="localhost";
mPort=1883;

//Create a timer for a messageloop
//This could also be done by a thread, but why
messageLoop = new QTimer(this);
messageLoop->setInterval(10);
myMqtt::QObject::connect(messageLoop,SIGNAL(timeout()),this,SLOT(messageLoopHandler()));


}


void myMqtt::connectBroaker(QString host, int port)
{
mHost=host;
mPort=port;


int rc=myMqtt::mosquittopp::connect(host.toStdString().c_str(),port,5);
if (rc) errorHandler(rc);
 else
messageLoop->start();
    //loop_(0,1);
}


void myMqtt::publishBroaker(QString tropic, QString message){
    QByteArray text = message.toLocal8Bit();
    char *data = text.data();


    //QElapsedTimer timer;
    //qint64 nanoSec;
    //timer.start();
    myMqtt::publish(NULL,tropic.toStdString().c_str(),text.size(),data,NULL,true);
    //nanoSec = timer.nsecsElapsed();

    //qDebug()<<nanoSec;
    //loop_write(1);


}


//********************************************************
//Helper functions
void myMqtt::errorHandler(int errorId){
   QString mError;
    switch(errorId){
                        case MOSQ_ERR_INVAL:
                           mError="Error: Invalid input. Does your topic contain '+' or '#'?";
                            break;
                        case MOSQ_ERR_NOMEM:
                            mError="Error: Out of memory when trying to publish message.";
                            break;
                        case MOSQ_ERR_NO_CONN:
                            mError="Error: Client not connected when trying to publish.";
                            break;
                        case MOSQ_ERR_PROTOCOL:
                            mError="Error: Protocol error when communicating with broker.";
                            break;
                        case MOSQ_ERR_PAYLOAD_SIZE:
                           mError= "Error: Message payload is too large.";
                            break;
                        case MOSQ_ERR_ERRNO:
                            mError="Error: Message System call failed.";
                            break;
                        case MOSQ_ERR_CONN_LOST:
                            mError="Error: Connection lost to broaker.";
                            break;


                    }
    qDebug()<<"Error "<<mError;
    emit broakerError(errorId);
}

void myMqtt::messageLoopHandler(){
    loop(0,1);
}

//********************************************************
//Implementation of callbacks
//We do not do to much here, just emitting signals
//Then it is up to the user to react on it


void myMqtt::on_connect(int rc){
    qDebug()<<"Got connected "<<rc;
    emit broakerConnected();
}

void myMqtt::on_disconnect(int rc){
    errorHandler(rc);
    emit broakerDisconnected();
    //TODO
    //Should try to reconnect, use a timer for that

}

void myMqtt::on_message(const mosquitto_message *message){

   QByteArray mData = QByteArray::fromRawData(static_cast<char*>(message->payload),message->payloadlen);
  //Keep a clean class, do not do to much here

  // qDebug()<<"Got a message "<<message->topic<<" Payload="<<mData;
   emit broakerMessage(message->topic,mData);
}

void myMqtt::on_publish(int mid){
  Q_UNUSED(mid);
    // qDebug()<<"Published a message "<<mid;
}

void myMqtt::on_error(){
    qDebug()<<"Error happend ter";
    emit broakerError(666);
}

void myMqtt::on_subscribe(uint16_t mid, int qos_count, const uint8_t *granted_qos){
    Q_UNUSED(mid);
    Q_UNUSED(qos_count);
    Q_UNUSED(granted_qos);
 qDebug()<<"Did subscribe";
}

void myMqtt::on_unsubscribe(int mid){
    qDebug()<<"Did unsubscribe "<<mid;
}
