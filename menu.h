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

    int _gameStage;

    int _keyPress;

    unsigned char * _buf;

    ALCdevice * _device;
    ALCcontext * _context;

    ALuint _music;
    ALuint _source;

public:

    Menu();
    void BeginGame();
    void NewGame();
    void EndGame();

    bool Say(char *, float dist);
    bool Music(char *filename, float dist, ALuint &_source);
    bool isPlaying();

    void SetThread(QThread &cThread);
public slots:
    void Update();
    void SetKey(int);

};

#endif // MENU_H
