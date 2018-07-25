#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QToolButton>
namespace Ui {
class MainWindow;
}
struct tangle{
    int lei=0;
    int number=0;
    int recent=0;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void digleft(int x,int y);
    void digright(int x,int y);
    void checkwin();

private:
    Ui::MainWindow *ui;
    int nandu;
    QList<tangle> map;
    int leinumber;
    int gameset=0;
    int check=0;



private slots:
    void getnandu1();
    void getnandu2();
    void getnandu3();
    void gengxin();
    void getsame();
    void getcl();

protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
};

#endif // MAINWINDOW_H
