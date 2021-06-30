#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "balon.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer();
    timer->setInterval(750);
    int *v_ptr = &vurulan;
    int *k_ptr = &kacan;
    int *s_ptr = &sure;
    QLabel *lb1 = ui->label_4;
    QLabel *lb2 = ui->label_3;
    QLabel *lb3 = ui->label_5;
    connect(timer, &QTimer::timeout, [this, lb2, k_ptr, lb1, v_ptr](){
        new balon(this, lb2, k_ptr, lb1, v_ptr);
        timer->start();
    });
    timer2 = new QTimer();
    timer2->setInterval(1000);
    connect(timer2, &QTimer::timeout, [this, lb3, s_ptr](){
        ++*(s_ptr);
        lb3->setNum(*(s_ptr));
        timer2->start();
    });
    timer->start();
    timer2->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

