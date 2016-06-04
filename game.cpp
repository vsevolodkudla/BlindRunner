#include "game.h"

Game::Game():step(5), _isGameStart(false)
{

}

long Game::dist(ALfloat *mas1, ALfloat *mas2)
{
    long tmp = sqrt(
                pow(mas1[0] - mas2[0], 2) +
                pow(mas1[1] - mas2[1], 2) +
                pow(mas1[2] - mas2[2], 2) );
    qDebug() << "dist " << tmp << endl;
    return tmp;
}

bool Game::StartGame()
{
    _lisner.SetSpeed(1);
    _lisner._ListenerPos[0] = 0;
    _lisner._ListenerPos[1] = 0;
    _lisner._ListenerPos[2] = 0;

    for(int i = 0; i < 10; i++)
    {
        SountObject * tmp = new SountObject;
        tmp->LoadMusic("Zombi.wav");
        tmp->SetSpeed(0);
        tmp->SetPos(-1000,-1000,-1000);
        tmp->Play();
        _zombi.push_back(tmp);
        Sleep(100);
    }
    _isGameStart = true;
    return true;
}

bool Game::PauseGame()
{

    return true;
}

bool Game::StopGame()
{
    foreach (SountObject * tmp, _zombi)
    {
        tmp->Stop();
    }
    return true;
}

void Game::Update(float time)
{
    if(_isGameStart)
    {
        _lisner.Update(time);
        foreach (SountObject * tmp, _zombi)
        {
            tmp->Update(time);
            int dis;
            if (dis = dist(_lisner._ListenerPos,tmp->_SourcePos) > 20)
            {
                tmp->SetPos(_lisner._ListenerPos[0] + step * (5 - rand()%10), 0, _lisner._ListenerPos[0] + rand()%20);
            }
            qDebug() << "Dist: " << dis << endl;
        }
    }
}

void Game::SetKey(int key)
{
    if(key == Qt::Key_Left)
    {
          _lisner.Left();
    }else
        if(key == Qt::Key_Right)
        {
            _lisner.Right();
        }
}
