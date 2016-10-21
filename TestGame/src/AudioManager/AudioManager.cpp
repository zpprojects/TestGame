//
//  AudioManager.cpp
//  TestGame
//
//  Created by Jacob Sawyer on 4/5/15.
//  Copyright (c) 2015 Jacob Sawyer. All rights reserved.
//

#include "AudioManager.h"
#include <AL/alut.h>

AudioManager* AudioManager::m_instance = NULL;


bool AudioManager::initalize()
{
    if(alutInit(NULL, 0) != AL_TRUE)
        return false;
    
    //counter for the total # of sounds loaded
    num_of_sounds = 0;
    
    list_audio_devices(alcGetString(NULL, ALC_DEVICE_SPECIFIER));
    
    //Generate all the sources that we will be using for sound effects
    for(sourceCounter=0;sourceCounter<NUM_SOURCES;sourceCounter++)
    {
        alGenSources(1, &source[sourceCounter]);
    }
    //set the sourceCounter back to 0 so it is ready for later
    sourceCounter=0;
    return true;
}
bool AudioManager::loadFileIntoBuffer(const char *filepath)
{

    bufferArray[num_of_sounds] = alutCreateBufferFromFile(filepath);
    
    if(bufferArray[num_of_sounds] == AL_NONE)
    {
        printf("error loading file:");
        printf(filepath);
        
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
    
    //cycle through counters
    if(sourceCounter<NUM_SOURCES-1)
        sourceCounter++;
    else
        sourceCounter=0;
    
    alSourcei(source[sourceCounter], AL_BUFFER, bufferArray[buffer]);

    alSourcePlay(source[sourceCounter]);
    
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