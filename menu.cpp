#include "menu.h"

Menu::Menu()
{
    _device = alcOpenDevice(NULL);
    _context = alcCreateContext(_device, NULL);
    alcMakeContextCurrent(_context);


}

void Menu::BeginGame()
{
    Music("Music/MainBackground.wav", 3, _music);
    _gameStage = 2;
    Say("Voice/Hello.wav", 0);
    while(isPlaying());
    Say("Voice/NewGame.wav", 0);
    while(isPlaying());
    Say("Voice/Rules.wav", 0);

}

void Menu::NewGame()
{
    alSourceStop(_music);
    _time.start();
    runner.StartGame();
}

void Menu::EndGame()
{
    runner.StopGame();
}

bool Menu::Music(char *filename, float dist, ALuint &_source)
{
    char  _type[4];
    DWORD _size, _chunkSize;
    short _formatType, _channels;
    DWORD _sampleRate, _avgBytesPerSec;
    short _bytesPerSample, _bitsPerSample;
    DWORD _dataSize;

    ALuint _buffer;
    ALuint _frequency;
    ALenum _format = 0;

    FILE * _file=fopen(filename,"rb");
    if(!_file)
        return false;
    fread(_type,sizeof(char),4,_file);
    if(_type[0]!='R' || _type[1]!='I' || _type[2]!='F' || _type[3]!='F')
    return false;

    fread(&_size, sizeof(DWORD),1,_file);
    fread(_type, sizeof(char),4,_file);
    if (_type[0]!='W' || _type[1]!='A' || _type[2]!='V' || _type[3]!='E')
    return false;

    fread(_type,sizeof(char),4,_file);
    if (_type[0]!='f' || _type[1]!='m' || _type[2]!='t' || _type[3]!=' ')
    return false;

    fread(&_chunkSize,sizeof(DWORD),1,_file);
    fread(&_formatType,sizeof(short),1,_file);
    fread(&_channels,sizeof(short),1,_file);
    fread(&_sampleRate,sizeof(DWORD),1,_file);
    fread(&_avgBytesPerSec,sizeof(DWORD),1,_file);
    fread(&_bytesPerSample,sizeof(short),1,_file);
    fread(&_bitsPerSample,sizeof(short),1,_file);

    fread(_type,sizeof(char),4,_file);
    if (_type[0]!='d' || _type[1]!='a' || _type[2]!='t' || _type[3]!='a')
    return false;

    fread(&_dataSize,sizeof(DWORD),1,_file);

    _buf = new unsigned char[_dataSize];

    fread(_buf,sizeof(BYTE),_dataSize,_file);

    _frequency = _sampleRate;

    alGenBuffers(1, &_buffer);
    alGenSources(1, &_source);

    if(alGetError() != AL_NO_ERROR)
        return false;

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
    if(!_format)
        return false;

    alBufferData(_buffer, _format, _buf, _dataSize, _frequency);
    if(alGetError() != AL_NO_ERROR)
        return false;

    ALfloat SourcePos[] = { 0, dist, 1 };
    ALfloat SourceVel[] = { 0.0, 0.0, 0.0 };
    ALfloat ListenerPos[] = { 0.0, 0.0, 0.0 };
    ALfloat ListenerVel[] = { 0.0, 0.0, 0.0 };
    ALfloat ListenerOri[] = { 0.0, 0.0, -1.0,  0.0, 1.0, 0.0 };

    alListenerfv(AL_POSITION,    ListenerPos);
    alListenerfv(AL_VELOCITY,    ListenerVel);
    alListenerfv(AL_ORIENTATION, ListenerOri);

    alSourcei (_source, AL_BUFFER,   _buffer);
    alSourcef (_source, AL_PITCH,    1.0f     );
    alSourcef (_source, AL_GAIN,     1.0f     );
    alSourcefv(_source, AL_POSITION, SourcePos);
    alSourcefv(_source, AL_VELOCITY, SourceVel);
    alSourcei (_source, AL_LOOPING,  AL_TRUE );

    alSourcePlay(_source);
}

bool Menu::Say(char *filename, float dist)
{
    char  _type[4];
    DWORD _size, _chunkSize;
    short _formatType, _channels;
    DWORD _sampleRate, _avgBytesPerSec;
    short _bytesPerSample, _bitsPerSample;
    DWORD _dataSize;

    ALuint _buffer;
    ALuint _frequency;
    ALenum _format;

    FILE * _file=fopen(filename,"rb");
    if(!_file)
        return false;
    fread(_type,sizeof(char),4,_file);
    if(_type[0]!='R' || _type[1]!='I' || _type[2]!='F' || _type[3]!='F')
    return false;

    fread(&_size, sizeof(DWORD),1,_file);
    fread(_type, sizeof(char),4,_file);
    if (_type[0]!='W' || _type[1]!='A' || _type[2]!='V' || _type[3]!='E')
    return false;

    fread(_type,sizeof(char),4,_file);
    if (_type[0]!='f' || _type[1]!='m' || _type[2]!='t' || _type[3]!=' ')
    return false;

    fread(&_chunkSize,sizeof(DWORD),1,_file);
    fread(&_formatType,sizeof(short),1,_file);
    fread(&_channels,sizeof(short),1,_file);
    fread(&_sampleRate,sizeof(DWORD),1,_file);
    fread(&_avgBytesPerSec,sizeof(DWORD),1,_file);
    fread(&_bytesPerSample,sizeof(short),1,_file);
    fread(&_bitsPerSample,sizeof(short),1,_file);

    fread(_type,sizeof(char),4,_file);
    if (_type[0]!='d' || _type[1]!='a' || _type[2]!='t' || _type[3]!='a')
    return false;

    fread(&_dataSize,sizeof(DWORD),1,_file);

    _buf = new unsigned char[_dataSize];

    fread(_buf,sizeof(BYTE),_dataSize,_file);

    _frequency = _sampleRate;

    alGenBuffers(1, &_buffer);
    alGenSources(1, &_source);

    if(alGetError() != AL_NO_ERROR)
        return false;

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
    if(!_format)
        return false;

    alBufferData(_buffer, _format, _buf, _dataSize, _frequency);
    if(alGetError() != AL_NO_ERROR)
        return false;

    ALfloat SourcePos[] = { 0, dist, 1 };
    ALfloat SourceVel[] = { 0.0, 0.0, 0.0 };
    ALfloat ListenerPos[] = { 0.0, 0.0, 0.0 };
    ALfloat ListenerVel[] = { 0.0, 0.0, 0.0 };
    ALfloat ListenerOri[] = { 0.0, 0.0, -1.0,  0.0, 1.0, 0.0 };

    alListenerfv(AL_POSITION,    ListenerPos);
    alListenerfv(AL_VELOCITY,    ListenerVel);
    alListenerfv(AL_ORIENTATION, ListenerOri);

    alSourcei (_source, AL_BUFFER,   _buffer);
    alSourcef (_source, AL_PITCH,    1.0f     );
    alSourcef (_source, AL_GAIN,     1.0f     );
    alSourcefv(_source, AL_POSITION, SourcePos);
    alSourcefv(_source, AL_VELOCITY, SourceVel);
    alSourcei (_source, AL_LOOPING,  AL_FALSE );

    alSourcePlay(_source);
}

void Menu::SetKey(int key)
{
    qDebug() << key << " " << _gameStage << endl;
    if(_gameStage == 2 && key == Qt::Key_Right && !isPlaying())
    {
        _gameStage = 3;
        Say("Voice/Ok.wav", 0);
        while(isPlaying());
        NewGame();
    }
    if(_gameStage == 2 && key == Qt::Key_Left && !isPlaying())
    {
        _gameStage = 4;
        Say("Voice/Quit.wav", 0);
    }
    if(_gameStage == 4 && key == Qt::Key_Right && !isPlaying())
    {
        Say("Voice/ByeBye.wav", 0);
        while(isPlaying());
        exit(0);
    }
    if(_gameStage == 4 && key == Qt::Key_Left && !isPlaying())
    {
        _gameStage = 2;
        Say("Voice/NewGame.wav", 0);
    }
    if(_gameStage == 5 && key == Qt::Key_Right && !isPlaying())
    {
        alSourceStop(_music);
        runner.ResumeGame();
        _gameStage = 3;
    }
    if(_gameStage == 5 && key == Qt::Key_Left && !isPlaying())
    {
        _gameStage = 4;
        Say("Voice/Quit.wav", 0);
    }
    if(_gameStage == 3)
    if(key == Qt::Key_Space)
    {
        runner.PauseGame();
        Music("Music/MainBackground.wav", 3, _music);
        Say("Voice/Pause.wav", 0);
        while(isPlaying());
        Say("Voice/Continue.wav", 0);
        _gameStage = 5;
    }
    else
       runner.SetKey(key);
}

void Menu::SetThread(QThread &cThread)
{
    connect(&cThread, SIGNAL(started()), this, SLOT(Update()));
}

bool Menu::isPlaying()
{
    ALenum state;

    alGetSourcei(_source, AL_SOURCE_STATE, &state);

    return (state == AL_PLAYING);
}

void Menu::Update()
{
    while(true)
    {
        if(!runner.gameover)
        {
            if(_gameStage == 3)
            {
                runner.Update((float)_time.restart()/1000);
                Sleep(100);
            }
        }else
        {
            runner.StopGame();
            runner.gameover = false;
            Music("Music/Zombies eating.wav", 1, _music);
            Say("Voice/GameOver.wav", 0);
            while (isPlaying());
            Say("Voice/NewGame.wav", 0);
            _gameStage = 2;
        }

    }
}
