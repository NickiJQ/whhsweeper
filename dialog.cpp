#include "dialog.h"
#include "ui_dialog.h"
#include<QPainter>
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_radioButton_toggled(bool checked)
{
    emit checknandu1(1);
}

void Dialog::on_radioButton_2_toggled(bool checked)
{
    emit checknandu2(2);
}

void Dialog::on_radioButton_3_toggled(bool checked)
{
    emit checknandu3(3);
}

void Dialog::on_pushButton_clicked()
{
    accept();
}

void Dialog::on_pushButton_2_clicked()
{
    close();
}

void Dialog::paintEvent(QPaintEvent *event)
{
    QImage sss;
    sss.load(":/pic/source/未标题-1.jpg");
    QPainter painter(this);
    painter.drawImage(QPoint(0,0),sss);
    painter.end();
}
