#ifndef GAME_H
#define GAME_H

#include <list>
#include "player.h"
#include "sountobject.h"

using namespace std;
class Game
{
    Player _lisner;
    list<SountObject *> _zombi;
    int step;
public:
    Game();
    bool StartGame();
    bool PauseGame();
    bool StopGame();
    void Update(float time);
    void SetKey(int key);

};

#endif // GAME_H
