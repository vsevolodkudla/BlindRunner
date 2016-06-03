#ifndef SOUNTOBJECT_H
#define SOUNTOBJECT_H

#include <cstdlib>
#include <iostream>
#include <windows.h>

#include <OpenAL/al.h>
#include <OpenAL/alc.h>

class SountObject
{
    char  _type[4];
    DWORD _size, _chunkSize;
    short _formatType, _channels;
    DWORD _sampleRate, _avgBytesPerSec;
    short _bytesPerSample, _bitsPerSample;
    DWORD _dataSize;
    unsigned char* _buf;

    ALfloat _SourcePos[3];
    ALfloat _SourceVel[3];

    int _speed;
    FILE * _file;

    ALCdevice *_device;
    ALCcontext *_context;

    ALuint _source;
    ALuint _buffer;
    ALuint _frequency;
    ALenum _format=0;

public:
    SountObject();
    void Play();
    void Stop();
    void SetPos(ALfloat x, ALfloat y, ALfloat z);
    void SetVer(ALfloat x, ALfloat y, ALfloat z);
    bool LoadMusic(char *filename);
    void SetSpeed(int speed);
    void Update(float time);
};

#endif // SOUNTOBJECT_H
