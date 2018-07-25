#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPainter>
#include"dialog.h"
#include<QtGlobal>
#include<QTime>
#include<QTimer>
#include<QMouseEvent>
#include<QLabel>
#include"dialog2.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    Dialog *w=new Dialog(this);
    connect(w,SIGNAL(checknandu1(int)),this,SLOT(getnandu1()));
     connect(w,SIGNAL(checknandu2(int)),this,SLOT(getnandu2()));
      connect(w,SIGNAL(checknandu3(int)),this,SLOT(getnandu3()));
      if(w->exec()==QDialog::Accepted){
           w->close();
          QCursor cursor;
          cursor.setShape(Qt::OpenHandCursor);
          setCursor(cursor);
          setMouseTracking(true);
          qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
          ui->setupUi(this);
          leinumber=0;
      }
      else{
          this->close();
      }
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::digleft(int x, int y)
{
    if(nandu==1){
        if(map[x*10+y].recent==0){
            if(map[x*10+y].lei==0){
                map[x*10+y].recent=1;
                if(map[x*10+y].number==0){
                    if(x-1>=0){
                        digleft(x-1,y);
                        if(y-1>=0){
                            digleft(x-1,y-1);
                        }
                        if(y+1<=9){
                            digleft(x-1,y+1);
                        }
                    }
                    if(x+1<=9){
                        digleft(x+1,y);
                        if(y-1>=0){
                            digleft(x+1,y-1);
                        }
                        if(y+1<=9){
                            digleft(x+1,y+1);
                        }
                    }
                    if(y-1>=0){digleft(x,y-1);}
                    if(y+1<=9){digleft(x,y+1);}
                }
            }
            if(map[x*10+y].lei==1)
            {
                map[x*10+y].recent=2;
                check=3;
            }
        }
    }
    if(nandu==2){
        if(map[x*20+y].recent==0){
            if(map[x*20+y].lei==0){
                map[x*20+y].recent=1;
                if(map[x*20+y].number==0){
                    if(x-1>=0){
                        digleft(x-1,y);
                        if(y-1>=0){
                            digleft(x-1,y-1);
                        }
                        if(y+1<=19){
                            digleft(x-1,y+1);
                        }
                    }
                    if(x+1<=19){
                        digleft(x+1,y);
                        if(y-1>=0){
                            digleft(x+1,y-1);
                        }
                        if(y+1<=19){
                            digleft(x+1,y+1);
                        }
                    }
                    if(y-1>=0){digleft(x,y-1);}
                    if(y+1<=19){digleft(x,y+1);}
                }
            }
            if(map[x*20+y].lei==1)
            {
                map[x*20+y].recent=2;
                check=3;
            }
        }
    }
    if(nandu==3){
        if(map[x*15+y].recent==0){
            if(map[x*15+y].lei==0){
                map[x*15+y].recent=1;
                if(map[x*15+y].number==0){
                    if(x-1>=0){
                        digleft(x-1,y);
                        if(y-1>=0){
                            digleft(x-1,y-1);
                        }
                        if(y+1<=14){
                            digleft(x-1,y+1);
                        }
                    }
                    if(x+1<=14){
                        digleft(x+1,y);
                        if(y-1>=0){
                            digleft(x+1,y-1);
                        }
                        if(y+1<=14){
                            digleft(x+1,y+1);
                        }
                    }
                    if(y-1>=0){digleft(x,y-1);}
                    if(y+1<=14){digleft(x,y+1);}
                }
            }
            if(map[x*15+y].lei==1)
            {
                map[x*15+y].recent=2;
                check=3;
            }
        }
    }
    checkwin();
}

void MainWindow::digright(int x, int y)
{
    if(nandu==1){
        if(map[x*10+y].recent==0){
            map[x*10+y].recent=3;
        }
        else if(map[x*10+y].recent==3){
            map[x*10+y].recent=0;
        }
    }
    if(nandu==2){
        if(map[x*20+y].recent==0){
            map[x*20+y].recent=3;
        }
        else if(map[x*20+y].recent==3){
            map[x*20+y].recent=0;
        }
    }
    if(nandu==3){
        if(map[x*15+y].recent==0){
            map[x*15+y].recent=3;
        }
        else if(map[x*15+y].recent==3){
            map[x*15+y].recent=0;
        }
    }
}

void MainWindow::checkwin()
{
    if(check!=3){
    if(nandu==1){
        for(int i=0;i<100;i++){
            if((map[i].lei==0)&&(map[i].recent==0)){
                break;
            }
            if(i==99){
                check=1;
            }
        }
    }
    if(nandu==2){
        for(int i=0;i<400;i++){
            if((map[i].lei==0)&&(map[i].recent==0)){
                break;
            }
            if(i==399){
                check=1;
            }
        }
    }
    if(nandu==3){
        for(int i=0;i<225;i++){
            if((map[i].lei==0)&&(map[i].recent==0)){
                break;
            }
            if(i==225){
                check=1;
            }
        }
    }
    }

}

void MainWindow::getnandu1()
{
    nandu=1;
}

void MainWindow::getnandu2()
{
    nandu=3;
}

void MainWindow::getnandu3()
{
    nandu=2;
}

void MainWindow::gengxin()
{
    Dialog *w=new Dialog(this);
    connect(w,SIGNAL(checknandu1(int)),this,SLOT(getnandu1()));
     connect(w,SIGNAL(checknandu2(int)),this,SLOT(getnandu2()));
      connect(w,SIGNAL(checknandu3(int)),this,SLOT(getnandu3()));
      if(w->exec()==QDialog::Accepted){
           w->close();
      }

}

void MainWindow::getsame()
{
    nandu=nandu;
}

void MainWindow::getcl()
{
    this->close();
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    if(gameset==0){
    if(nandu==1){
        this->setWindowTitle("扫扫whh  难度：简单");
        tangle a[100];
        for(int i=0;i<15;i++){
            int test=qrand()%100;
            if(a[test].lei==1){
                i--;
            }
            else{
                a[test].lei=1;
                a[test].number=10;
                leinumber++;
            }
        }
        for(int i=0;i<100;i++){
            if(a[i].number!=10){
                if((i%10!=0)&&(a[i-1].lei==1)){
                        a[i].number++;
            }
                if((i>=10)&&(a[i-10].lei==1)){
                    a[i].number++;
                }
                if(((i+1)%10!=0)&&(a[i+1].lei==1)){
                    a[i].number++;
                }
                if((i<=89)&&(a[i+10].lei==1)){
                    a[i].number++;
                }
                if((i%10!=0)&&(i>=10)&&(a[i-11].lei==1)){
                    a[i].number++;
                }
                if((i%10!=0)&&(i<=89)&&(a[i+9].lei==1)){
                    a[i].number++;
                }
                if(((i+1)%10!=0)&&(i>=10)&&(a[i-9].lei==1)){
                    a[i].number++;
                }
                if(((i+1)%10!=0)&&(i<=89)&&(a[i+11].lei==1)){
                    a[i].number++;
                }
            }
        }
        for(int i=0;i<100;i++){
            map<<a[i];
        }
        this->setGeometry(700,300,500,500);

    }
    if(nandu==2){
        this->setWindowTitle("扫扫whh  难度：困难");
        tangle a[400];
        for(int i=0;i<60;i++){
            int test=qrand()%400;
            if(a[test].lei==1){
                i--;
            }
            else{
                a[test].lei=1;
                a[test].number=10;
            }
        }
        for(int i=0;i<400;i++){
            if(a[i].number!=10){
                if((i%20!=0)&&(a[i-1].lei==1)){
                        a[i].number++;
            }
                if((i>=20)&&(a[i-20].lei==1)){
                    a[i].number++;
                }
                if(((i+1)%10!=20)&&(a[i+1].lei==1)){
                    a[i].number++;
                }
                if((i<=379)&&(a[i+20].lei==1)){
                    a[i].number++;
                }
                if((i%20!=0)&&(i>=20)&&(a[i-21].lei==1)){
                    a[i].number++;
                }
                if((i%20!=0)&&(i<=379)&&(a[i+19].lei==1)){
                    a[i].number++;
                }
                if(((i+1)%20!=0)&&(i>=20)&&(a[i-19].lei==1)){
                    a[i].number++;
                }
                if(((i+1)%20!=0)&&(i<=379)&&(a[i+21].lei==1)){
                    a[i].number++;
                }
            }
        }
        for(int i=0;i<400;i++){
            map<<a[i];
        }
         this->setGeometry(500,50,1000,1000);

    }
    if(nandu==3){
        this->setWindowTitle("扫扫whh   难度：中等");
        tangle a[225];
        for(int i=0;i<30;i++){
            int test=qrand()%225;
            if(a[test].lei==1){
                i--;
            }
            else{
                a[test].lei=1;
                a[test].number=10;
            }
        }
        for(int i=0;i<225;i++){
            if(a[i].number!=10){
                if((i%15!=0)&&(a[i-1].lei==1)){
                        a[i].number++;
            }
                if((i>=15)&&(a[i-15].lei==1)){
                    a[i].number++;
                }
                if(((i+1)%15!=0)&&(a[i+1].lei==1)){
                    a[i].number++;
                }
                if((i<=209)&&(a[i+15].lei==1)){
                    a[i].number++;
                }
                if((i%15!=0)&&(i>=15)&&(a[i-16].lei==1)){
                    a[i].number++;
                }
                if((i%15!=0)&&(i<=209)&&(a[i+14].lei==1)){
                    a[i].number++;
                }
                if(((i+1)%15!=0)&&(i>=15)&&(a[i-14].lei==1)){
                    a[i].number++;
                }
                if(((i+1)%15!=0)&&(i<=209)&&(a[i+16].lei==1)){
                    a[i].number++;
                }
            }
        }
        for(int i=0;i<225;i++){
            map<<a[i];
        }
         this->setGeometry(600,200,750,750);

    }
    gameset=1;
    }
    QPainter painter;
    QImage image;
    image.load(":/pic/source/1.png");
    QImage flag;
    flag.load(":/pic/source/flag.png");
    QImage lei;
    lei.load(":/pic/source/lei3.jpg");
    QImage num[10];
    num[0].load(":/pic/source/empty.png");
    num[1].load(":/pic/source/(1).png");
    num[2].load(":/pic/source/(2).png");
    num[3].load(":/pic/source/(3).png");
    num[4].load(":/pic/source/(4).png");
    num[5].load(":/pic/source/(5).png");
    num[6].load(":/pic/source/(6).png");
    num[7].load(":/pic/source/(7).png");
    num[8].load(":/pic/source/(8).png");
    num[9].load(":/pic/source/(9).png");
    QPen pen(Qt::black,3,Qt::SolidLine,Qt::SquareCap);
    painter.begin(this);
    painter.setPen(pen);
    if(nandu==1){
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                if(map[i*10+j].recent==0){
                painter.drawImage(QPoint(i*50,j*50),image);
                }
                if((map[i*10+j].recent)==1){
                    painter.drawImage(QPoint(i*50,j*50),num[map[i*10+j].number]);
                }
                if((map[i*10+j].recent==2)){
                    painter.drawImage(QPoint(i*50,j*50),lei);
                }
                if((map[i*10+j].recent==3)){
                    painter.drawImage(QPoint(i*50,j*50),flag);
                }
            }
        }

        for(int i=0;i<=10;i++){
            painter.drawLine(QPoint(i*50,0),QPoint(i*50,500));
        }
        for(int i=0;i<=10;i++){
            painter.drawLine(QPoint(0,i*50),QPoint(500,i*50));
        }

    }
    if(nandu==2){
        for(int i=0;i<20;i++){
            for(int j=0;j<20;j++){
                if(map[i*20+j].recent==0){
                painter.drawImage(QPoint(i*50,j*50),image);
                }
                if((map[i*20+j].recent)==1){
                    painter.drawImage(QPoint(i*50,j*50),num[map[i*20+j].number]);
                }
                if((map[i*20+j].recent==2)){
                    painter.drawImage(QPoint(i*50,j*50),lei);
                }
                if((map[i*20+j].recent==3)){
                    painter.drawImage(QPoint(i*50,j*50),flag);
                }
            }
        }

        for(int i=0;i<=20;i++){
            painter.drawLine(QPoint(i*50,0),QPoint(i*50,1000));
        }
        for(int i=0;i<=20;i++){
            painter.drawLine(QPoint(0,i*50),QPoint(1000,i*50));
        }

    }
    if(nandu==3){
        for(int i=0;i<15;i++){
            for(int j=0;j<15;j++){
                if(map[i*15+j].recent==0){
                painter.drawImage(QPoint(i*50,j*50),image);
                }
                if((map[i*15+j].recent)==1){
                    painter.drawImage(QPoint(i*50,j*50),num[map[i*15+j].number]);
                }
                if((map[i*15+j].recent==2)){
                    painter.drawImage(QPoint(i*50,j*50),lei);
                }
                if((map[i*15+j].recent==3)){
                    painter.drawImage(QPoint(i*50,j*50),flag);
                }
            }
        }

        for(int i=0;i<=15;i++){
            painter.drawLine(QPoint(i*50,0),QPoint(i*50,750));
        }
        for(int i=0;i<=15;i++){
            painter.drawLine(QPoint(0,i*50),QPoint(750,i*50));
        }

    }
    painter.end();
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{

    QPoint aaa=event->pos();
    int m,n;
    m=aaa.rx()/50;
    n=aaa.ry()/50;
    if(event->button()==Qt::LeftButton){
        digleft(m,n);
    }
    if(event->button()==Qt::RightButton){
        digright(m,n);
    }
    if(check==3){
       Dialog2 *t=new Dialog2(this);
       connect(t,SIGNAL(same()),this,SLOT(getsame()));
       connect(t,SIGNAL(diffirent()),this,SLOT(gengxin()));
       connect(t,SIGNAL(cl()),this,SLOT(close()));
       t->setWindowTitle("you die");
       t->label(1);
       t->exec();
       gameset=0;
       map.clear();
       check=0;
       leinumber=0;
    }
    if(check==1){
        Dialog2 *t=new Dialog2(this);
        connect(t,SIGNAL(same()),this,SLOT(getsame()));
        connect(t,SIGNAL(diffirent()),this,SLOT(gengxin()));
        connect(t,SIGNAL(cl()),this,SLOT(close()));
        t->setWindowTitle("you win");
        t->label(0);
        t->exec();
        gameset=0;
        map.clear();
        check=0;
        leinumber=0;
    }
    update();
}


