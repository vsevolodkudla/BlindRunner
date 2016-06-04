#include "menu.h"

Menu::Menu():
    _format(0)
{
    _device = alcOpenDevice(NULL);
    _context = alcCreateContext(_device, NULL);
    alcMakeContextCurrent(_context);

    /*
    if(_bitsPerSample == 8)
    {
        if(_channels == 1)
            _format = AL_FORMAT_MONO8;
        else if(_channels == 2)
            _format = AL_FORMAT_STEREO8;
    }
    else if(_bitsPerSample == 16)
    {
        if(_channels == 1)
            _format = AL_FORMAT_MONO16;
        else if(_channels == 2)
            _format = AL_FORMAT_STEREO16;
    }
    alBufferData(_buffer, _format, _buf, _dataSize, _frequency);*/
}

void Menu::BeginGame()
{
    runner.StartGame();
    _time.start();
}

void Menu::NewGame()
{
    runner.StartGame();
}

void Menu::EndGame()
{
    runner.StopGame();
}

void Menu::setKey(int key)
{
    if(key == Qt::Key_Space)
    {
        runner.PauseGame();
    }
    else
       runner.SetKey(key);
}

void Menu::SetThread(QThread &cThread)
{
    connect(&cThread, SIGNAL(started()), this, SLOT(Update()));
}

void Menu::Update()
{
    while(true)
    {
        runner.Update((float)_time.restart()/1000);
        Sleep(100);
    }
}
