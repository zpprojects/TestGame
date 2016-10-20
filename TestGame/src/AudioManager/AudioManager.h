//
//  AudioManager.h
//  TestGame
//
//  Created by Jacob Sawyer on 4/5/15.
//  Copyright (c) 2015 Jacob Sawyer. All rights reserved.
//

#ifndef __TestGame__AudioManager__
#define __TestGame__AudioManager__

#include <stdio.h>
#include <vector>
#include <AL/alut.h>

#define NUM_BUFFERS 64
#define NUM_SRC 3
#define BUFFER_SIZE 4096

class AudioManager
{
    
public:
    
    static AudioManager* instance()
    {
        if(!m_instance)
            m_instance = new AudioManager();
        return m_instance;
    };
    
    std::vector<ALuint> sourceVector;
    std::vector<ALuint> soundBufferVector;
    
    ALuint bufferArray[NUM_BUFFERS];
    
    
    bool loadFileIntoBuffer(const char* filepath);
    bool playBuffer(ALuint buffer);
    static void list_audio_devices(const ALCchar *devices);
    bool destroy();
    
private:
    
    static AudioManager* m_instance;
    
    ALCdevice *device;
    ALCcontext *context;
    
    ALuint buffer[NUM_BUFFERS];
    ALuint source[NUM_SRC];
    ALuint num_of_sounds;
    
    ALsizei size, freq;
    ALenum format;
    ALvoid *data;
    
    AudioManager(){ initalize();}
    ~AudioManager(){}
    
    bool initalize();
    
};

#endif /* defined(__TestGame__AudioManager__) */
