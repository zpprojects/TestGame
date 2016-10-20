//
//  InputManager.cpp
//  TestGame
//
//  Created by Jacob Sawyer on 4/2/15.
//  Copyright (c) 2015 Jacob Sawyer. All rights reserved.
//

#include "InputManager.h"
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include "AudioManager.h"
#include "GameStateManager.h"

void InputManager::initialize()
{
    keysHeld = keysPressed = keysReleased = 0;
}
void InputManager::processKeyboardState()
{
    unsigned int currentKeyboardState = 0;
    
    if(glfwGetKey(window, GLFW_KEY_ESCAPE))
        currentKeyboardState = currentKeyboardState | KEYS::KEY_ESC;
    if(glfwGetKey(window, GLFW_KEY_UP))
        currentKeyboardState = currentKeyboardState | KEYS::KEY_UP;
    if(glfwGetKey(window, GLFW_KEY_DOWN))
        currentKeyboardState = currentKeyboardState | KEYS::KEY_DOWN;
    if(glfwGetKey(window, GLFW_KEY_LEFT))
        currentKeyboardState = currentKeyboardState | KEYS::KEY_LEFT;
    if(glfwGetKey(window, GLFW_KEY_RIGHT))
        currentKeyboardState = currentKeyboardState | KEYS::KEY_RIGHT;
    if(glfwGetKey(window, GLFW_KEY_W))
        currentKeyboardState = currentKeyboardState | KEYS::KEY_W;
    if(glfwGetKey(window, GLFW_KEY_S))
        currentKeyboardState = currentKeyboardState | KEYS::KEY_S;
    if(glfwGetKey(window, GLFW_KEY_A))
        currentKeyboardState = currentKeyboardState | KEYS::KEY_A;
    if(glfwGetKey(window, GLFW_KEY_D))
        currentKeyboardState = currentKeyboardState | KEYS::KEY_D;
    
    //if a key is not in the current state and it was in keys held it must of
    //been released
    keysReleased = keysHeld & ~currentKeyboardState;
    
    
    //if a key was held last state and is still pressed it is still held
    keysHeld = keysHeld & currentKeyboardState;
    
    //if a key was pressed last state and is pressed again this state it
    //it is now considered held
    keysHeld = keysHeld | (keysPressed & currentKeyboardState);
    
    
    //a key is considered pressed if it it was pressed this state but is
    //not considered to be held
    keysPressed = currentKeyboardState & ~keysHeld;
}
void InputManager::processKeys()
{
    if(KEYS::KEY_ESC & keysHeld)
    {
        GameStateManager::instance()->setState(GAMESTATE_CLOSING);
    }
    if(KEYS::KEY_D & keysPressed)
        AudioManager::instance()->playBuffer(0);
    if(KEYS::KEY_S & keysPressed)
        AudioManager::instance()->playBuffer(1);
    
}
char* InputManager::int2bin(int a, char *buffer, int buf_size)
{
    buffer += (buf_size - 1);
    for(int i= 31; i >= 0; i --) {
        *buffer-- = (a & 1) + '0';
        a>>=1;
    }
    return buffer;
}