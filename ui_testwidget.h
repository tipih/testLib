/********************************************************************************
** Form generated from reading UI file 'testwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTWIDGET_H
#define UI_TESTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_testWidget
{
public:
    QPushButton *pushButton;

    void setupUi(QWidget *testWidget)
    {
        if (testWidget->objectName().isEmpty())
            testWidget->setObjectName(QStringLiteral("testWidget"));
        testWidget->resize(400, 300);
        pushButton = new QPushButton(testWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(20, 210, 361, 81));

        retranslateUi(testWidget);

        QMetaObject::connectSlotsByName(testWidget);
    } // setupUi

    void retranslateUi(QWidget *testWidget)
    {
        testWidget->setWindowTitle(QApplication::translate("testWidget", "testWidget", 0));
        pushButton->setText(QApplication::translate("testWidget", "PushButton", 0));
    } // retranslateUi

};

namespace Ui {
    class testWidget: public Ui_testWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTWIDGET_H
