#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _menu.BeginGame();
    _menu.SetThread(_thread);
    _menu.moveToThread(&_thread);

    _thread.start();

    connect(this, SIGNAL(setKey(int)), &_menu, SLOT(setKey(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    emit setKey(event->key());
}
