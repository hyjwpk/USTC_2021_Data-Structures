#include "step.h"
#include "ui_step.h"

Step::Step(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Step)
{
    ui->setupUi(this);
}

Step::~Step()
{
    delete ui;
}

void Step::setBank(Bank *bank)
{
    this->bank=bank;
    QNode *node = bank->eventList.getFront();
    for(int i=0;node;i++)
    {
        ui->eventList->setItem(i,0,new QTableWidgetItem(QString::number(node->data[0])));
        ui->eventList->setItem(i,1,new QTableWidgetItem(QString::number(node->data[1])));
        node=node->next;
    }
}

void Step::on_nextStep_clicked()
{
    if((bank->isEventListNotEmpty()))
    {
        bank->handleEvent();
        ui->totalMoney->setText(QString::number(bank->totalMoney));
        ui->eventList->clearContents();
        ui->withdrawMoneyList->clearContents();
        ui->customerList1->clearContents();
        QNode *node;
        node = bank->eventList.getFront();
        for(int i=0;node&&i<13;i++)
        {
            ui->eventList->setItem(i,0,new QTableWidgetItem(QString::number(node->data[0])));
            ui->eventList->setItem(i,1,new QTableWidgetItem(QString::number(node->data[1])));
            node=node->next;
        }
        node = bank->withdrawMoneyList.getFront();
        for(int i=0;node&&i<13;i++)
        {
            ui->withdrawMoneyList->setItem(i,0,new QTableWidgetItem(QString::number(node->data[0])));
            ui->withdrawMoneyList->setItem(i,1,new QTableWidgetItem(QString::number(node->data[1])));
            ui->withdrawMoneyList->setItem(i,2,new QTableWidgetItem(QString::number(node->data[2])));
            node=node->next;
        }
        node = bank->customerList1.getFront();
        for(int i=0;node&&i<13;i++)
        {
            ui->customerList1->setItem(i,0,new QTableWidgetItem(QString::number(node->data[0])));
            ui->customerList1->setItem(i,1,new QTableWidgetItem(QString::number(node->data[1])));
            ui->customerList1->setItem(i,2,new QTableWidgetItem(QString::number(node->data[2])));
            node=node->next;
        }
    }
    else
        accept();
}
