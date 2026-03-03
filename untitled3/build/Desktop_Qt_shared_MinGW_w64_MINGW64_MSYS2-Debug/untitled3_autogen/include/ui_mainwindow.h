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
    QPushButton *ButtonAbout;
    QPushButton *ButtonTo2;
    QPushButton *ButtonTo10;
    QLabel *label;
    QLineEdit *Edit_10cc;
    QLineEdit *Edit_2cc;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *Edit_16cc;
    QLineEdit *Edit_8cc;
    QPushButton *ButtonTo8;
    QPushButton *ButtonFrom8;
    QPushButton *ButtonTo16;
    QPushButton *ButtonFrom16;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1406, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        ButtonAbout = new QPushButton(centralwidget);
        ButtonAbout->setObjectName("ButtonAbout");
        ButtonAbout->setGeometry(QRect(950, 20, 90, 29));
        ButtonTo2 = new QPushButton(centralwidget);
        ButtonTo2->setObjectName("ButtonTo2");
        ButtonTo2->setGeometry(QRect(500, 90, 141, 29));
        ButtonTo10 = new QPushButton(centralwidget);
        ButtonTo10->setObjectName("ButtonTo10");
        ButtonTo10->setGeometry(QRect(500, 120, 141, 29));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(280, 90, 91, 20));
        Edit_10cc = new QLineEdit(centralwidget);
        Edit_10cc->setObjectName("Edit_10cc");
        Edit_10cc->setGeometry(QRect(380, 90, 113, 28));
        Edit_2cc = new QLineEdit(centralwidget);
        Edit_2cc->setObjectName("Edit_2cc");
        Edit_2cc->setGeometry(QRect(380, 120, 113, 28));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(280, 120, 81, 20));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(280, 190, 81, 31));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(280, 160, 81, 20));
        Edit_16cc = new QLineEdit(centralwidget);
        Edit_16cc->setObjectName("Edit_16cc");
        Edit_16cc->setGeometry(QRect(380, 200, 113, 28));
        Edit_8cc = new QLineEdit(centralwidget);
        Edit_8cc->setObjectName("Edit_8cc");
        Edit_8cc->setGeometry(QRect(380, 160, 113, 28));
        ButtonTo8 = new QPushButton(centralwidget);
        ButtonTo8->setObjectName("ButtonTo8");
        ButtonTo8->setGeometry(QRect(680, 200, 161, 29));
        ButtonFrom8 = new QPushButton(centralwidget);
        ButtonFrom8->setObjectName("ButtonFrom8");
        ButtonFrom8->setGeometry(QRect(500, 160, 171, 29));
        ButtonTo16 = new QPushButton(centralwidget);
        ButtonTo16->setObjectName("ButtonTo16");
        ButtonTo16->setGeometry(QRect(680, 160, 151, 29));
        ButtonFrom16 = new QPushButton(centralwidget);
        ButtonFrom16->setObjectName("ButtonFrom16");
        ButtonFrom16->setGeometry(QRect(500, 200, 161, 29));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1406, 25));
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
        ButtonAbout->setText(QCoreApplication::translate("MainWindow", "\320\236 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\265", nullptr));
        ButtonTo2->setText(QCoreApplication::translate("MainWindow", "\320\277\320\265\321\200\320\265\320\262\320\265\321\201\321\202\320\270 \320\262 2\321\201\321\201", nullptr));
        ButtonTo10->setText(QCoreApplication::translate("MainWindow", "\320\277\320\265\321\200\320\265\320\262\320\265\321\201\321\202\320\270 \320\262 10\321\201\321\201", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\321\207\320\270\321\201\320\273\320\276 \320\262 10 \321\201\321\201", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\321\207\320\270\321\201\320\273\320\276 \320\262 2 \321\201\321\201", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\321\207\320\270\321\201\320\273\320\276 \320\26216 \321\201\321\201", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\321\207\320\270\321\201\320\273\320\276 \320\262 8\321\201\321\201", nullptr));
        ButtonTo8->setText(QCoreApplication::translate("MainWindow", "\320\277\320\265\321\200\320\265\320\262\320\265\321\201\321\202\320\270 \320\270\320\267 10 \321\201\321\201 \320\262 8 \321\201\321\201", nullptr));
        ButtonFrom8->setText(QCoreApplication::translate("MainWindow", " \320\277\320\265\321\200\320\265\320\262\320\265\321\201\321\202\320\270 \320\270\320\267 8\321\201\321\201 \320\262 10\321\201\321\201", nullptr));
        ButtonTo16->setText(QCoreApplication::translate("MainWindow", "\320\277\320\265\321\200\320\265\320\262\320\265\321\201\321\202\320\270 \320\270\320\267 10 \320\262 16", nullptr));
        ButtonFrom16->setText(QCoreApplication::translate("MainWindow", "\320\277\320\265\321\200\320\265\320\262\320\265\321\201\321\202\320\270 \320\270\320\267 16 \320\262 10", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
