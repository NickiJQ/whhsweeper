#ifndef DIALOG2_H
#define DIALOG2_H

#include <QDialog>

namespace Ui {
class Dialog2;
}

class Dialog2 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog2(QWidget *parent = 0);
    ~Dialog2();
    void label(int n);


signals:
    void same();
    void diffirent();
    void cl();

private:
    Ui::Dialog2 *ui;
    int m=0;

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
protected:
    void paintEvent(QPaintEvent *event);
};

#endif // DIALOG2_H
