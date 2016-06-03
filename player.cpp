#include "player.h"

Player::Player(float x, float y, float z)
{
    ListenerPos[0] = x;
    ListenerPos[1] = y;
    ListenerPos[2] = z;
}

void Player::Up()
{
    _sta = 1;
}

void Player::Down()
{
    _sta = -1;
}
void Player::Left()
{
    _turn = -1;
}

void Player::Right()
{
    _turn = 1;
}

void Player::Update(float time)
{
    ListenerPos[2] += time * _speed;
    ListenerPos[0] += _turn * _stay;
    _turn = 0;

    alListenerfv(AL_POSITION,    ListenerPos);
    alListenerfv(AL_VELOCITY,    ListenerVel);
    alListenerfv(AL_ORIENTATION, ListenerOri);

}
