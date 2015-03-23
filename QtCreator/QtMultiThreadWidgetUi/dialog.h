#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <mythread.h>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private:
    Ui::Dialog *ui;
    MyThread *mThread;

public slots:
    void changeLabel(int num);
    void onNumberChanged(int);
    void onChangeLabel(int num);
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_run_clicked();
};

#endif // DIALOG_H
