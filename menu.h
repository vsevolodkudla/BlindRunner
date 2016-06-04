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

    int _keyPress;

    unsigned char * _buf;

    ALCdevice * _device;
    ALCcontext * _context;

    char  _type[4];
    DWORD _size, _chunkSize;
    short _formatType, _channels;
    DWORD _sampleRate, _avgBytesPerSec;
    short _bytesPerSample, _bitsPerSample;
    DWORD _dataSize;

    ALuint * _source;
    ALuint * _buffer;
    ALuint _frequency;
    ALenum _format;

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
