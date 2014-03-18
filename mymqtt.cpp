#include "mymqtt.h"
#include "mosquittopp.h"
#include <QDebug>

myMqtt::myMqtt(const char *id ):QObject(0),
   mosquittopp(id)
{

myMqtt::mosquittopp::connect("localhost",1883,20);
loop_start();

}

void myMqtt::on_connect(int rc){
    qDebug()<<"Got connected";
}
