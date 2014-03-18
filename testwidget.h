#ifndef TESTWIDGET_H
#define TESTWIDGET_H

#include <QWidget>
#include "mosquittopp.h"
#include "mymqtt.h"
#include <QTimer>

namespace Ui {
class testWidget;
}

class testWidget : public QWidget
{
    Q_OBJECT

public:
     myMqtt *myMqttClient;
    explicit testWidget(QWidget *parent = 0);
    ~testWidget();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

    //Broaker slots
    void on_broaker_connection();
    void on_broaker_disconnect();
    void on_broaker_error(int errorNumber);
    void on_broaker_message(QString tropic,QByteArray data);

    void on_pushButton_3_clicked();
    void on_mTimeOut();

private:
    Ui::testWidget *ui;
    QTimer *mTimer;

    int getNewMessageId();
    bool isConnected;
    int major;
    int minor;
    int revision;
    int messageId;
};

#endif // TESTWIDGET_H
