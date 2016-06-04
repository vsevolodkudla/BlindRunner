#ifndef GAME_H
#define GAME_H

#include <Qt>
#include <list>
#include "player.h"
#include "sountobject.h"
#include <math.h>
#include <QDebug>

using namespace std;
class Game
{
    Player _lisner;
    list<SountObject *> _zombi;
    int step;
    bool _isGameStart;

    ALuint *_source;
    ALuint *_buffer;

    long dist(ALfloat *mas1, ALfloat *mas2);
public:
    Game();

    bool StartGame();
    bool PauseGame();
    bool StopGame();

    void Update(float time);
    void SetKey(int key);

};

#endif // GAME_H
