#ifndef SOUNTOBJECT_H
#define SOUNTOBJECT_H

#include <cstdlib>
#include <iostream>
#include <windows.h>

#include <OpenAL/al.h>
#include <OpenAL/alc.h>

#include <QDebug>

class SountObject
{
    char  _type[4];
    DWORD _size, _chunkSize;
    short _formatType, _channels;
    DWORD _sampleRate, _avgBytesPerSec;
    short _bytesPerSample, _bitsPerSample;
    DWORD _dataSize;
    unsigned char* _buf;

    int _speed;
    FILE * _file;

    ALuint _source;
    ALuint _buffer;
    ALuint _frequency;
    ALenum _format;

public:
    SountObject();
    ~SountObject();
    void Play();
    void Stop();
    void SetPos(ALfloat x, ALfloat y, ALfloat z);
    void SetVer(ALfloat x, ALfloat y, ALfloat z);
    bool LoadMusic(char *filename);
    void SetSpeed(int speed);
    void Update(float time);

    ALfloat _SourcePos[3];
    ALfloat _SourceVel[3];
};

#endif // SOUNTOBJECT_H
