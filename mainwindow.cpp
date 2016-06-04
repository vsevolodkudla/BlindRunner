#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(this, SIGNAL(setKey(int)), &_menu, SLOT(SetKey(int)));
    _menu.BeginGame();
    _menu.SetThread(_thread);
    _menu.moveToThread(&_thread);

    _thread.start();


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    _menu.SetKey(event->key());
}
