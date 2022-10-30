/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
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
    QAction *action123;
    QWidget *centralwidget;
    QPushButton *simulation;
    QLineEdit *totalmoney;
    QLabel *label;
    QLineEdit *closetime;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *intertimescope;
    QLineEdit *durationscope;
    QLineEdit *moneyscope;
    QLabel *value;
    QLabel *label_6;
    QLineEdit *listnum;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(531, 555);
        action123 = new QAction(MainWindow);
        action123->setObjectName(QString::fromUtf8("action123"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        simulation = new QPushButton(centralwidget);
        simulation->setObjectName(QString::fromUtf8("simulation"));
        simulation->setGeometry(QRect(200, 460, 93, 28));
        totalmoney = new QLineEdit(centralwidget);
        totalmoney->setObjectName(QString::fromUtf8("totalmoney"));
        totalmoney->setGeometry(QRect(210, 80, 261, 31));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 90, 72, 15));
        closetime = new QLineEdit(centralwidget);
        closetime->setObjectName(QString::fromUtf8("closetime"));
        closetime->setGeometry(QRect(210, 130, 261, 31));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(50, 140, 72, 15));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(50, 190, 91, 20));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(50, 240, 131, 16));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(50, 290, 141, 16));
        label_5->setScaledContents(false);
        intertimescope = new QLineEdit(centralwidget);
        intertimescope->setObjectName(QString::fromUtf8("intertimescope"));
        intertimescope->setGeometry(QRect(210, 280, 261, 31));
        durationscope = new QLineEdit(centralwidget);
        durationscope->setObjectName(QString::fromUtf8("durationscope"));
        durationscope->setGeometry(QRect(210, 230, 261, 31));
        moneyscope = new QLineEdit(centralwidget);
        moneyscope->setObjectName(QString::fromUtf8("moneyscope"));
        moneyscope->setGeometry(QRect(210, 180, 261, 31));
        value = new QLabel(centralwidget);
        value->setObjectName(QString::fromUtf8("value"));
        value->setGeometry(QRect(160, 390, 171, 51));
        QFont font;
        font.setFamilies({QString::fromUtf8("Adobe Devanagari")});
        font.setPointSize(20);
        value->setFont(font);
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(50, 340, 141, 16));
        label_6->setScaledContents(false);
        listnum = new QLineEdit(centralwidget);
        listnum->setObjectName(QString::fromUtf8("listnum"));
        listnum->setGeometry(QRect(210, 330, 261, 31));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 531, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\351\223\266\350\241\214\344\270\232\345\212\241\346\250\241\346\213\237", nullptr));
        action123->setText(QCoreApplication::translate("MainWindow", "123", nullptr));
        simulation->setText(QCoreApplication::translate("MainWindow", "\346\250\241\346\213\237", nullptr));
        totalmoney->setText(QCoreApplication::translate("MainWindow", "10000", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\351\207\221\351\242\235\357\274\232", nullptr));
        closetime->setText(QCoreApplication::translate("MainWindow", "100", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\346\227\266\351\227\264\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\345\255\230\345\217\226\346\254\276\344\270\212\351\231\220\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\345\256\242\346\210\267\344\270\232\345\212\241\346\227\266\351\227\264\344\270\212\351\231\220\357\274\232", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\345\256\242\346\210\267\345\210\260\350\276\276\351\227\264\351\232\224\344\270\212\351\231\220\357\274\232", nullptr));
        intertimescope->setText(QCoreApplication::translate("MainWindow", "20", nullptr));
        durationscope->setText(QCoreApplication::translate("MainWindow", "15", nullptr));
        moneyscope->setText(QCoreApplication::translate("MainWindow", "5000", nullptr));
        value->setText(QString());
        label_6->setText(QCoreApplication::translate("MainWindow", "\351\230\237\345\210\227\344\270\252\346\225\260", nullptr));
        listnum->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
