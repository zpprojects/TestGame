//
//  GamePad.cpp
//  TestGame
//
//  Created by Jacob Sawyer on 10/26/16.
//  Copyright (c) 2016 Jacob Sawyer. All rights reserved.
//

#include "GamePad.h"
#include <GLFW/glfw3.h>

GamePad::GamePad(int initgamePadNum)
{
    currentGamePadState, buttonsPressed, buttonsReleased, buttonsHeld = 0;
    gamePadNum = initgamePadNum;
}
GamePad::~GamePad()
{
    
}
bool GamePad::initialize()
{
    return true;
}
bool GamePad::queryGamePad(int &BUTTONsPressed)
{
    
    return true;
}