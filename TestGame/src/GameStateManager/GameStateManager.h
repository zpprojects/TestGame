//
//  GameStateManager.h
//  TestGame
//
//  Created by Jacob Sawyer on 4/19/15.
//  Copyright (c) 2015 Jacob Sawyer. All rights reserved.
//

#ifndef __TestGame__GameStateManager__
#define __TestGame__GameStateManager__

#include <stdio.h>

enum GameState {
    GAMESTATE_INITIALIZING,
    GAMESTATE_INTRO,
    GAMESTATE_MAINMENU,
    GAMESTATE_CHARACTERSELECT,
    GAMESTATE_LEVELSELECT,
    GAMESTATE_RUNNING,
    GAMESTATE_PAUSED,
    GAMESTATE_GAMESTATS,
    GAMESTATE_CLOSING,
    GAMESTATE_DONE
};

class GameStateManager
{
public:
    static GameStateManager* instance()
    {
        if(!m_instance)
            m_instance = new GameStateManager();
        return m_instance;
    };
    
    bool isGameRunning();
    void setState(int state) {m_state = state;};
    
private:
    
    int m_state;
    
    GameStateManager(){};
    ~GameStateManager(){};
    static GameStateManager* m_instance;
    
};

#endif /* defined(__TestGame__GameStateManager__) */
