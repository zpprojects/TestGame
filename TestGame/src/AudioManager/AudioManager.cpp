//
//  AudioManager.cpp
//  TestGame
//
//  Created by Jacob Sawyer on 4/5/15.
//  Copyright (c) 2015 Jacob Sawyer. All rights reserved.
//

#include "AudioManager.h"
#include <AL/alut.h>
#define FILENAME "gunshot.wav"

AudioManager* AudioManager::m_instance = NULL;


bool AudioManager::initalize()
{
    if(alutInit(NULL, 0) != AL_TRUE)
        return false;
    num_of_sounds = 0;
    
    list_audio_devices(alcGetString(NULL, ALC_DEVICE_SPECIFIER));
    
    return true;
}
bool AudioManager::loadFileIntoBuffer(const char *filepath)
{

    bufferArray[num_of_sounds] = alutCreateBufferFromFile(filepath);
    
    if(bufferArray[num_of_sounds] == AL_NONE)
    {
        printf("error loading file\n");
        int error = alGetError();
        if (error)
            printf("%s\n", alutGetErrorString(error));
        return false;
    }
    
    num_of_sounds++;
    return true;
}
bool AudioManager::playBuffer(ALuint buffer)
{
    
    ALuint source;
    alGenSources(1, &source);
    alSourcei(source, AL_BUFFER, bufferArray[buffer]);

    alSourcePlay(source);
    
    return true;
}
void AudioManager::list_audio_devices(const ALCchar *devices)
{
    const ALCchar *device = devices, *next = devices + 1;
    size_t len = 0;
    
    fprintf(stdout, "Devices list:\n");
    fprintf(stdout, "----------\n");
    while (device && *device != '\0' && next && *next != '\0') {
        fprintf(stdout, "%s\n", device);
        len = strlen(device);
        device += (len + 1);
        next += (len + 2);
    }
    fprintf(stdout, "----------\n");
}
bool AudioManager::destroy()
{
    return true;
}