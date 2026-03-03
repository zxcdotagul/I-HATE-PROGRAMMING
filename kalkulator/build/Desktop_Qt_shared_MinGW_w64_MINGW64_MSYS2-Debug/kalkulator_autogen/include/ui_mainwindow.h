/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton_1;
    QPushButton *pushButton_4;
    QPushButton *pushButton_7;
    QPushButton *pushButton_2;
    QPushButton *pushButton_5;
    QPushButton *pushButton_8;
    QPushButton *pushButton_3;
    QPushButton *pushButton_6;
    QPushButton *pushButton_9;
    QPushButton *pushButton_plus;
    QPushButton *pushButton_minus;
    QPushButton *pushButton_multiply;
    QPushButton *pushButton_delit;
    QLabel *label_operand;
    QLineEdit *lineEdit;
    QPushButton *pushButton_tochka;
    QPushButton *pushButton_0;
    QPushButton *pushButton_sp;
    QLabel *label_sign;
    QPushButton *pushButton_ravno;
    QPushButton *pushButton_remove;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1307, 625);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        pushButton_1 = new QPushButton(centralwidget);
        pushButton_1->setObjectName("pushButton_1");
        pushButton_1->setGeometry(QRect(200, 200, 90, 29));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(200, 250, 90, 29));
        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(200, 300, 90, 29));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(300, 200, 90, 29));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(300, 250, 90, 29));
        pushButton_8 = new QPushButton(centralwidget);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(300, 300, 90, 29));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(410, 200, 90, 29));
        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(410, 250, 91, 29));
        pushButton_9 = new QPushButton(centralwidget);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setGeometry(QRect(410, 300, 90, 29));
        pushButton_plus = new QPushButton(centralwidget);
        pushButton_plus->setObjectName("pushButton_plus");
        pushButton_plus->setGeometry(QRect(550, 150, 90, 29));
        pushButton_minus = new QPushButton(centralwidget);
        pushButton_minus->setObjectName("pushButton_minus");
        pushButton_minus->setGeometry(QRect(550, 200, 90, 29));
        pushButton_multiply = new QPushButton(centralwidget);
        pushButton_multiply->setObjectName("pushButton_multiply");
        pushButton_multiply->setGeometry(QRect(550, 250, 90, 29));
        pushButton_delit = new QPushButton(centralwidget);
        pushButton_delit->setObjectName("pushButton_delit");
        pushButton_delit->setGeometry(QRect(550, 300, 90, 29));
        label_operand = new QLabel(centralwidget);
        label_operand->setObjectName("label_operand");
        label_operand->setGeometry(QRect(540, 40, 171, 41));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(200, 150, 321, 31));
        pushButton_tochka = new QPushButton(centralwidget);
        pushButton_tochka->setObjectName("pushButton_tochka");
        pushButton_tochka->setGeometry(QRect(200, 340, 90, 29));
        pushButton_0 = new QPushButton(centralwidget);
        pushButton_0->setObjectName("pushButton_0");
        pushButton_0->setGeometry(QRect(300, 340, 90, 29));
        pushButton_sp = new QPushButton(centralwidget);
        pushButton_sp->setObjectName("pushButton_sp");
        pushButton_sp->setGeometry(QRect(410, 340, 90, 29));
        label_sign = new QLabel(centralwidget);
        label_sign->setObjectName("label_sign");
        label_sign->setGeometry(QRect(540, 90, 63, 20));
        pushButton_ravno = new QPushButton(centralwidget);
        pushButton_ravno->setObjectName("pushButton_ravno");
        pushButton_ravno->setGeometry(QRect(550, 350, 90, 29));
        pushButton_remove = new QPushButton(centralwidget);
        pushButton_remove->setObjectName("pushButton_remove");
        pushButton_remove->setGeometry(QRect(310, 400, 90, 29));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1307, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton_1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        pushButton_plus->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        pushButton_minus->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        pushButton_multiply->setText(QCoreApplication::translate("MainWindow", "*", nullptr));
        pushButton_delit->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
        label_operand->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        pushButton_tochka->setText(QCoreApplication::translate("MainWindow", ".", nullptr));
        pushButton_0->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        pushButton_sp->setText(QCoreApplication::translate("MainWindow", "<-", nullptr));
        label_sign->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        pushButton_ravno->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        pushButton_remove->setText(QCoreApplication::translate("MainWindow", "CE", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
