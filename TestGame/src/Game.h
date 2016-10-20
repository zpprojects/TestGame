//
//  Game.h
//  TestGame
//
//  Created by Jacob Sawyer on 4/19/15.
//  Copyright (c) 2015 Jacob Sawyer. All rights reserved.
//

#ifndef __TestGame__Game__
#define __TestGame__Game__

#include <stdio.h>

class GameWindow;
class InputManager;
class AudioManager;
class GameStateManager;


class Game
{
    
public:
    
    static Game* instance()
    {
        if(!m_instance)
            m_instance = new Game();
        return m_instance;
    };
    
    bool initialize();
    bool isGameRunning();
    void update();
    void render();
    void destory();
    
private:
    
    GameWindow* gWindow;
    InputManager* gInputManager;
    AudioManager* gAudioManager;
    GameStateManager* gGameStateManager;
    
    static Game* m_instance;
    Game();
    ~Game(){};
};

#endif /* defined(__TestGame__Game__) */
