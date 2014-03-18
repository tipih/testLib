#include "testwidget.h"
#include "ui_testwidget.h"
#include <QDebug>
#include <QElapsedTimer>






testWidget::testWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::testWidget)
{
    ui->setupUi(this);
    isConnected=false;
    messageId=0;


    mosqpp::lib_init();
    mosqpp::lib_version(&major,&minor,&revision);

    qDebug()<<major<<" "<<minor<<" "<<revision;
    QString myId="testtest";

    //Created the message broaker class, pass on a uniq ID
    myMqttClient = new myMqtt(myId.toStdString().c_str());

    connect(myMqttClient,SIGNAL(broakerConnected()),this,SLOT(on_broaker_connection()));
    connect(myMqttClient,SIGNAL(broakerDisconnected()),this,SLOT(on_broaker_disconnect()));
    connect(myMqttClient,SIGNAL(broakerError(int)),this,SLOT(on_broaker_error(int)));
    connect(myMqttClient,SIGNAL(broakerMessage(QString,QByteArray)),this,SLOT(on_broaker_message(QString,QByteArray)));


    mTimer = new QTimer(this);
    connect(mTimer,SIGNAL(timeout()),this,SLOT(on_mTimeOut()));


}

testWidget::~testWidget()
{
    delete ui;
    mosqpp::lib_cleanup();
}

void testWidget::on_pushButton_clicked()
{
//Button slot
//We make the connection from here
    myMqttClient->connectBroaker();

    //Create a test timer for trying out the message sending.
    mTimer->setInterval(10);
    mTimer->start();


}


void testWidget::on_pushButton_2_clicked()
{
    //only try to subscribe if we have a valid connection

   int didISubscribe=999;
   if (isConnected)
      {
       myMqttClient->subscribe(&didISubscribe,"test");
       qDebug()<<"test "<<didISubscribe;
   }

}


//***********************************************************************
//Helper function from here
int testWidget::getNewMessageId(){
    messageId++;
    return messageId;
}




//***********************************************************************
//Slots from the point of
void testWidget::on_broaker_connection(){
    isConnected=true;
}

void testWidget::on_broaker_disconnect(){
    isConnected=false;
}

void testWidget::on_broaker_error(int errorNumber){

    qDebug()<<"Error happened "<<errorNumber;
}

void testWidget::on_broaker_message(QString tropic, QByteArray data){
    qDebug()<<"Broaker message: "<<data;
}


void testWidget::on_pushButton_3_clicked()
{
 QString mData= "my data";

  if (isConnected)
    myMqttClient->publishBroaker("test","my messageData");
}

void testWidget::on_mTimeOut(){
if(isConnected)
     myMqttClient->publishBroaker("test","message Number  "+QString::number(getNewMessageId()));
else
    qDebug()<<"Not sending";
}
