#include "dialog2.h"
#include "ui_dialog2.h"
#include<QPainter>
Dialog2::Dialog2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog2)
{
    ui->setupUi(this);
}

Dialog2::~Dialog2()
{
    delete ui;
}



void Dialog2::on_pushButton_clicked()
{
    emit same();
    this->close();
}

void Dialog2::on_pushButton_2_clicked()
{
    emit diffirent();
    this->close();
}

void Dialog2::on_pushButton_3_clicked()
{
    emit cl();
    this->close();
}
void Dialog2::label(int n){
    m=n;
    update();
}

void Dialog2::paintEvent(QPaintEvent *event)
{
    QImage ddd;
    if(m==1){
    ddd.load(":/pic/source/pic2.jpg");
    }
    if(m==0){
        ddd.load(":/pic/source/kdkd.jpg");
    }
    QPainter painter(this);
    painter.drawImage(QPoint(30,30),ddd);
    painter.end();
}


