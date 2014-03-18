#ifndef TESTWIDGET_H
#define TESTWIDGET_H

#include <QWidget>
#include "mosquittopp.h"
#include "mymqtt.h"

namespace Ui {
class testWidget;
}

class testWidget : public QWidget
{
    Q_OBJECT

public:
    explicit testWidget(QWidget *parent = 0);
    ~testWidget();

private slots:
    void on_pushButton_clicked();

private:
    Ui::testWidget *ui;
   myMqtt *myMqttClient;
};

#endif // TESTWIDGET_H
