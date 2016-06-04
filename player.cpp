#include "player.h"

Player::Player(float x, float y, float z) :
    format(0),
    _turn(0),
    _stay(0)
{
    _ListenerPos[0] = x;
    _ListenerPos[1] = y;
    _ListenerPos[2] = z;

    _ListenerOri[0] = 0;
    _ListenerOri[1] = 0;
    _ListenerOri[2] = -1;
    _ListenerOri[3] = 0;
    _ListenerOri[4] = 1;
    _ListenerOri[5] = 0;

    _ListenerVel[0] = 0;
    _ListenerVel[1] = 0;
    _ListenerVel[2] = 0;
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
    _ListenerPos[2] += time * _speed;
    _ListenerPos[0] += _turn * _stay;
    _turn = 0;

    qDebug() << "Player: " << _ListenerPos[0] << " " << _ListenerPos[1] << " " << _ListenerPos[2] << endl;

    alListenerfv(AL_POSITION,    _ListenerPos);
}
void Player::SetSpeed(int speed)
{
    _speed = speed;
}
