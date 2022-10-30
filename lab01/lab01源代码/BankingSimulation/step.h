#ifndef STEP_H
#define STEP_H

#include <QDialog>
#include "Bank.h"

namespace Ui {
class Step;
}

class Step : public QDialog
{
    Q_OBJECT

public:
    explicit Step(QWidget *parent = nullptr);
    void setBank(Bank *bank);
    ~Step();

private slots:
    void on_nextStep_clicked();

private:
    Ui::Step *ui;
    Bank *bank;
};

#endif // STEP_H
