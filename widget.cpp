#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);


    ui->pbCoffe->setEnabled(false);
    ui->pbTea->setEnabled(false);
    ui->pbMilk->setEnabled(false);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int diff){
    money += diff;
    ui->lcdNumber->display(money);


    ui->pbCoffe->setEnabled(money >= 100);
    ui->pbTea->setEnabled(money >= 150);
    ui->pbMilk->setEnabled(money >= 200);
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

void Widget::on_pbCoffe_clicked()
{
    changeMoney(-100);
}

void Widget::on_pbTea_clicked()
{
    changeMoney(-150);
}

void Widget::on_pbMilk_clicked()
{
    changeMoney(-200);
}

void Widget::on_pbReset_clicked()
{
    QMessageBox mb;

    int num500 = money / 500;
    int remainingAfter500 = money % 500;
    int num100 = remainingAfter500 / 100;
    int remainingAfter100 = remainingAfter500 % 100;
    int num50 = remainingAfter100 / 50;
    int remainingAfter50 = remainingAfter100 % 50;   /
    int num10 = remainingAfter50 / 10;


    QString message = QString("500원: %1 개\n100원: %2 개\n50원: %3 개\n10원: %4 개")
                          .arg(num500).arg(num100).arg(num50).arg(num10);



    mb.information(this, "Reset", message);
    changeMoney(-money);
}

