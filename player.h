#ifndef PLAYER_H
#define PLAYER_H

#include <OpenAL/al.h>
#include <OpenAL/alc.h>


class Player
{
    int _speed;
    int _stay;
    ALfloat ListenerPos[3];
    ALfloat ListenerVel[3];
    ALfloat ListenerOri[6];

    int _sta;
    int _turn;
    int _step;
    float _timeSta;


    ALCdevice *device;
    ALCcontext *context;

    ALuint source;
    ALuint buffer;
    ALuint frequency;
    ALenum format=0;

public:
    Player(float x = 0, float y = 0, float z = 0);
    void SetSpeed(int speed);
    void Update(float time);
    void Up();
    void Down();
    void Left();
    void Right();

};

#endif // PLAYER_H
