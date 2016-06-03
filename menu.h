#ifndef MENU_H
#define MENU_H

#include "game.h"
#include <QThread>
#include <QObject>
#include <QTime>

class Menu : public QObject
{
    Q_OBJECT
    Game runner;
    QTime _time;
    unsigned char * _buf;
public:
    Menu();
    void BeginGame();
    void NewGame();
    void EndGame();

    void SetThread(QThread &cThread);
public slots:
    void Update();
    void setKey(int key);
};

#endif // MENU_H
