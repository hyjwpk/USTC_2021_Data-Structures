#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "step.h"
#include "Bank.h"
#include "BankAdvanced.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_simulation_clicked()
{
    int totalmoney = ui->totalmoney->text().toInt();
    int closetime = ui->closetime->text().toInt();
    int moneyscope = ui->moneyscope->text().toInt();
    int durationscope = ui->durationscope->text().toInt();
    int intertimescope = ui->intertimescope->text().toInt();
    int listnum = ui->listnum->text().toInt();
    if(listnum == 1)
    {
        this->hide();
        Bank *bank = new Bank(totalmoney,closetime,moneyscope,durationscope,intertimescope);
        Step *step=new Step();
        step->setBank(bank);
        step->show();
        step->exec();
        this->show();
        while (bank->isEventListNotEmpty())
        {
            bank->handleEvent();
        }
        QString string = QString("平均用时：")+QString::number(bank->printResult());
        ui->value->setText(string);
        delete(bank);
    }
    else
    {
        BankAdvanced *bank = new BankAdvanced(totalmoney,closetime,moneyscope,durationscope,intertimescope,listnum);
        while (bank->isEventListNotEmpty())
        {
            bank->handleEvent();
        }
        QString string = QString("平均用时：")+QString::number(bank->printResult());
        ui->value->setText(string);
        delete(bank);
    }
}
