//
//  GameStateManager.cpp
//  TestGame
//
//  Created by Jacob Sawyer on 4/19/15.
//  Copyright (c) 2015 Jacob Sawyer. All rights reserved.
//

#include "GameStateManager.h"

GameStateManager* GameStateManager::m_instance = NULL;


bool GameStateManager::isGameRunning()
{
    return ( m_state != GAMESTATE_CLOSING );
}