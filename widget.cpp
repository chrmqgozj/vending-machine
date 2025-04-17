#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <QString>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->pbCoke->setEnabled(false);
    ui->pbTea->setEnabled(false);
    ui->pbCoffee->setEnabled(false);
    ui->pbReset->setEnabled(false);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int diff)
{
    money += diff;
    ui->lcdNumber->display(money);

    if (money >= 200)
    {
        ui->pbCoke->setEnabled(true);
        ui->pbTea->setEnabled(true);
        ui->pbCoffee->setEnabled(true);
        ui->pbReset->setEnabled(true);
    }
    else if (money >= 150)
    {
        ui->pbCoke->setEnabled(false);
        ui->pbTea->setEnabled(true);
        ui->pbCoffee->setEnabled(true);
        ui->pbReset->setEnabled(true);
    }
    else if (money >= 100)
    {
        ui->pbCoke->setEnabled(false);
        ui->pbTea->setEnabled(false);
        ui->pbCoffee->setEnabled(true);
        ui->pbReset->setEnabled(true);
    }
    else if (money > 0)
    {
        ui->pbCoke->setEnabled(false);
        ui->pbTea->setEnabled(false);
        ui->pbCoffee->setEnabled(false);
        ui->pbReset->setEnabled(true);
    }
    else if (money == 0)
    {
        ui->pbCoke->setEnabled(false);
        ui->pbTea->setEnabled(false);
        ui->pbCoffee->setEnabled(false);
        ui->pbReset->setEnabled(false);
    }
}

void Widget::on_pb10_clicked()
{
    changeMoney(10);
}

void Widget::on_pb50_clicked()
{
    changeMoney(50);
}

void Widget::on_pb100_clicked()
{
    changeMoney(100);
}

void Widget::on_pb500_clicked()
{
    changeMoney(500);
}


void Widget::on_pbCoffee_clicked()
{
    changeMoney(-100);
}


void Widget::on_pbTea_clicked()
{
    changeMoney(-150);
}


void Widget::on_pbCoke_clicked()
{
    changeMoney(-200);
}


void Widget::on_pbReset_clicked()
{
    int num500 = money / 500;
    money = money % 500;
    int num100 = money / 100;
    money = money % 100;
    int num50 = money / 50;
    money = money % 50;
    int num10 = money / 10;
    money = money % 10;
    changeMoney(0);

    QString msg = QString("500: %1\n 100: %2\n50: %3\n10: %4\n").arg(num500).arg(num100).arg(num50).arg(num10);

    QMessageBox mb;
    mb.information(this, "Reset", msg);
}

