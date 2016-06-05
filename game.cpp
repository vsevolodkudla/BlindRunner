#include "game.h"

Game::Game():
    step(5),
    _isGameStart(false),
    gameover(false)
{

}

long Game::dist(ALfloat *mas1, ALfloat *mas2)
{
    return sqrt(
                pow(mas1[0] - mas2[0], 2) +
                pow(mas1[1] - mas2[1], 2) +
                pow(mas1[2] - mas2[2], 2) );
}

bool Game::StartGame()
{
    gameover = false;
    qDebug() << "New Game" << endl;
    _lisner.SetSpeed(1);
    _lisner._ListenerPos[0] = 0;
    _lisner._ListenerPos[1] = 0;
    _lisner._ListenerPos[2] = 0;

    for(int i = 0; i < 10; i++)
    {
        SountObject * tmp = new SountObject;
        tmp->LoadMusic(QString("Sounds/Zombie (" + QString::number(1+ rand()%7) + ").wav").toLatin1().data());
        tmp->SetSpeed(0);
        tmp->SetPos(2*(rand()%3) - 2, 0, 5*(i+1));
        tmp->Play();
        _zombi.push_back(tmp);
        Sleep(100);
    }
    _isGameStart = true;
    return true;
}
ALfloat* Game::getPlayerPos()
{
    return _lisner._ListenerPos;
}

bool Game::PauseGame()
{
    foreach (SountObject * tmp, _zombi)
    {
        tmp->Stop();
    }
    return true;
}
bool Game::ResumeGame()
{
    foreach (SountObject * tmp, _zombi)
    {
        tmp->Play();
    }
    return true;
}

bool Game::StopGame()
{
    foreach (SountObject * tmp, _zombi)
    {
        tmp->Stop();
        delete tmp;
    }
    _zombi.clear();
    return true;
}

void Game::Update(float time)
{
    int dis;
    if(_isGameStart)
    {
        _lisner.Update(time);


        foreach (SountObject * tmp, _zombi)
        {
            tmp->Update(time);

            if(_lisner._ListenerPos[2] - tmp->_SourcePos[2] > 20)
            {
                SountObject * tmp = new SountObject;
                tmp->LoadMusic(QString("Sounds/Zombie (" + QString::number(1+ rand()%7) + ").wav").toLatin1().data());
                tmp->SetSpeed(0);
                tmp->SetPos(2*(rand()%3) - 2, 0, _lisner._ListenerPos[2] + 30);
                tmp->Play();
                _zombi.push_back(tmp);
                _zombi.pop_front();
            }
            if ((dis = dist(_lisner._ListenerPos,tmp->_SourcePos)) < 1)
            {
                qDebug() << "Game Ower: " << dis << endl;
                _isGameStart = false;
                gameover = true;
            }
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
