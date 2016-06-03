#include "sountobject.h"

SountObject::SountObject()
{

}

void SountObject::Play()
{
    alGenBuffers(1, &_buffer);
    alGenSources(1, &_source);
    if(alGetError() != AL_NO_ERROR)
        return;

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
        return;

    alBufferData(_buffer, _format, _buf, _dataSize, _frequency);
    if(alGetError() != AL_NO_ERROR)
        return;

    alSourcei (_source, AL_BUFFER,   _buffer);
    alSourcef (_source, AL_PITCH,    1.0f     );
    alSourcef (_source, AL_GAIN,     1.0f     );
    alSourcefv(_source, AL_POSITION, _SourcePos);
    alSourcefv(_source, AL_VELOCITY, _SourceVel);
    alSourcei (_source, AL_LOOPING,  AL_FALSE );

    alSourcePlay(_source);
}

void SountObject::SetPos(ALfloat x, ALfloat y, ALfloat z)
{
    _SourcePos[0] = x;
    _SourcePos[1] = y;
    _SourcePos[2] = z;
}

void SountObject::SetVer(ALfloat x, ALfloat y, ALfloat z)
{
    _SourceVel[0] = x;
    _SourceVel[1] = y;
    _SourceVel[2] = z;
}

bool SountObject::LoadMusic(char *filename)
{
    _file=fopen(filename,"rb");
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

    fread(_buf,sizeof(BYTE),_dataSize,_file);
    _frequency=_sampleRate;
}

void SountObject::SetSpeed(int speed)
{
    _speed = speed;
}

void SountObject::Update(float time)
{
    _SourcePos[2] += time *_speed;

}
