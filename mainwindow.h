#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "menu.h"
#include <QKeyEvent>
#include <QThread>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    Menu _menu;
    QThread _thread;

    void keyPressEvent(QKeyEvent *event);

signals:
    void setKey(int);
};

#endif // MAINWINDOW_H
