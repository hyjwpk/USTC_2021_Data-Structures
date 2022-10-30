/********************************************************************************
** Form generated from reading UI file 'step.ui'
**
** Created by: Qt User Interface Compiler version 6.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STEP_H
#define UI_STEP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_Step
{
public:
    QLabel *label_2;
    QLabel *label_4;
    QPushButton *nextStep;
    QLabel *label_1;
    QLabel *label_3;
    QLabel *totalMoney;
    QTableWidget *eventList;
    QTableWidget *withdrawMoneyList;
    QTableWidget *customerList1;

    void setupUi(QDialog *Step)
    {
        if (Step->objectName().isEmpty())
            Step->setObjectName(QString::fromUtf8("Step"));
        Step->resize(1249, 634);
        Step->setMaximumSize(QSize(1296, 634));
        label_2 = new QLabel(Step);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(530, 30, 72, 15));
        label_2->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(Step);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(470, 540, 72, 15));
        nextStep = new QPushButton(Step);
        nextStep->setObjectName(QString::fromUtf8("nextStep"));
        nextStep->setGeometry(QRect(530, 580, 93, 28));
        label_1 = new QLabel(Step);
        label_1->setObjectName(QString::fromUtf8("label_1"));
        label_1->setGeometry(QRect(160, 30, 72, 15));
        label_1->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(Step);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(960, 30, 72, 15));
        label_3->setAlignment(Qt::AlignCenter);
        totalMoney = new QLabel(Step);
        totalMoney->setObjectName(QString::fromUtf8("totalMoney"));
        totalMoney->setGeometry(QRect(550, 540, 72, 15));
        eventList = new QTableWidget(Step);
        if (eventList->columnCount() < 2)
            eventList->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        eventList->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        eventList->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        if (eventList->rowCount() < 13)
            eventList->setRowCount(13);
        eventList->setObjectName(QString::fromUtf8("eventList"));
        eventList->setGeometry(QRect(90, 60, 241, 451));
        eventList->setEditTriggers(QAbstractItemView::NoEditTriggers);
        eventList->setRowCount(13);
        eventList->setColumnCount(2);
        withdrawMoneyList = new QTableWidget(Step);
        if (withdrawMoneyList->columnCount() < 3)
            withdrawMoneyList->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        withdrawMoneyList->setHorizontalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        withdrawMoneyList->setHorizontalHeaderItem(1, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        withdrawMoneyList->setHorizontalHeaderItem(2, __qtablewidgetitem4);
        if (withdrawMoneyList->rowCount() < 13)
            withdrawMoneyList->setRowCount(13);
        withdrawMoneyList->setObjectName(QString::fromUtf8("withdrawMoneyList"));
        withdrawMoneyList->setGeometry(QRect(410, 60, 341, 451));
        withdrawMoneyList->setEditTriggers(QAbstractItemView::NoEditTriggers);
        withdrawMoneyList->setRowCount(13);
        withdrawMoneyList->setColumnCount(3);
        customerList1 = new QTableWidget(Step);
        if (customerList1->columnCount() < 3)
            customerList1->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        customerList1->setHorizontalHeaderItem(0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        customerList1->setHorizontalHeaderItem(1, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        customerList1->setHorizontalHeaderItem(2, __qtablewidgetitem7);
        if (customerList1->rowCount() < 13)
            customerList1->setRowCount(13);
        customerList1->setObjectName(QString::fromUtf8("customerList1"));
        customerList1->setGeometry(QRect(830, 60, 341, 451));
        customerList1->setEditTriggers(QAbstractItemView::NoEditTriggers);
        customerList1->setRowCount(13);
        customerList1->setColumnCount(3);

        retranslateUi(Step);

        QMetaObject::connectSlotsByName(Step);
    } // setupUi

    void retranslateUi(QDialog *Step)
    {
        Step->setWindowTitle(QCoreApplication::translate("Step", "Dialog", nullptr));
        label_2->setText(QCoreApplication::translate("Step", "\345\217\226\351\222\261\351\230\237\345\210\227", nullptr));
        label_4->setText(QCoreApplication::translate("Step", "\345\275\223\345\211\215\351\207\221\351\242\235\357\274\232", nullptr));
        nextStep->setText(QCoreApplication::translate("Step", "\344\270\213\344\270\200\346\255\245", nullptr));
        label_1->setText(QCoreApplication::translate("Step", "\344\272\213\344\273\266\350\241\250", nullptr));
        label_3->setText(QCoreApplication::translate("Step", "\351\241\276\345\256\242\351\230\237\345\210\227", nullptr));
        totalMoney->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = eventList->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("Step", "\346\227\266\351\227\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = eventList->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("Step", "\344\272\213\344\273\266", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = withdrawMoneyList->horizontalHeaderItem(0);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("Step", "\345\210\260\350\276\276\346\227\266\351\227\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = withdrawMoneyList->horizontalHeaderItem(1);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("Step", "\345\255\230\345\217\226\351\207\221\351\242\235", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = withdrawMoneyList->horizontalHeaderItem(2);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("Step", "\345\244\204\347\220\206\346\227\266\351\227\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = customerList1->horizontalHeaderItem(0);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("Step", "\345\210\260\350\276\276\346\227\266\351\227\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = customerList1->horizontalHeaderItem(1);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("Step", "\345\255\230\345\217\226\351\207\221\351\242\235", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = customerList1->horizontalHeaderItem(2);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("Step", "\345\244\204\347\220\206\346\227\266\351\227\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Step: public Ui_Step {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STEP_H
