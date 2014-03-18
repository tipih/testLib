#include "testwidget.h"
#include "ui_testwidget.h"
#include <QDebug>





testWidget::testWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::testWidget)
{
    ui->setupUi(this);

    int test1,test2,test3;

}

testWidget::~testWidget()
{
    delete ui;
}

void testWidget::on_pushButton_clicked()
{

int major;
int minor;
int revision;
mosqpp::lib_init();
mosqpp::lib_version(&major,&minor,&revision);

qDebug()<<major<<" "<<minor<<" "<<revision;
QString myId="testtest";
myMqttClient = new myMqtt(myId.toStdString().c_str());




}





