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
#include "GamePad.h"
#include "GamePadXbox360.h"


static const char *XBOX_CONTROLLER_NAME = "Wireless 360 Controller";

void InputManager::initialize()
{
    keysHeld = keysPressed = keysReleased = 0;
    
    numOfGamePads = 0;
    int present = glfwJoystickPresent(GLFW_JOYSTICK_1 );
    
    
}
bool InputManager::checkForGamePads()
{
    for(int i=0;i<16;i++)
    {
        if (glfwJoystickPresent(i)) {
            numOfGamePads++;
        }
        else break;
    }
    if (numOfGamePads == 0) {
        return false;
    }
    
    return true;
}
bool InputManager::createGamePads()
{
    //go through each gamepad and see what type it is
    for (int i=0; i<numOfGamePads; i++) {
        const char *name = glfwGetJoystickName( GLFW_JOYSTICK_1 );

        if ( strcmp(name, XBOX_CONTROLLER_NAME) == 0)
        {
            gamepadVector.push_back(new GamePadXbox360(i));
            printf("xbox controller created.\n");
        }
    }
    
    return true;
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
void InputManager::processGamePadState()
{
    int buttonsPressed;
    for(int i=0;i<numOfGamePads;i++)
    {
        gamepadVector.at(i)->queryGamePad(buttonsPressed);
        /*
        printf( "\n\n\n\n\n\n\n\n\n\n" );
        int buttonCount;
        const unsigned char *buttons = glfwGetJoystickButtons( GLFW_JOYSTICK_1, &buttonCount );
        for (int i=0;i<buttonCount;i++)
        {
            printf("%i" , buttons[i]);
        }*/
    }
    
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
void InputManager::processGamePadButtons()
{
    int buttonsPressed, buttonsReleased, buttonsHeld = 0;
    
    gamepadVector.at(0)->getButtonStatus(buttonsReleased, buttonsHeld, buttonsPressed);
    
    if(KEYS::KEY_ESC & buttonsHeld)
    {
        GameStateManager::instance()->setState(GAMESTATE_CLOSING);
    }
    if(KEYS::KEY_D & buttonsPressed)
        AudioManager::instance()->playBuffer(0);
    if(KEYS::KEY_S & buttonsPressed)
        AudioManager::instance()->playBuffer(1);
    
    
    printf( "\n\n\n\n\n\n\n\n\n\n" );
    
    char tempBuffer[33];
    tempBuffer[32] = '\0';
    int2bin(buttonsPressed, tempBuffer, 32);
    printf(tempBuffer); printf( "\n" );
    
    tempBuffer[32] = '\0';
    int2bin(buttonsHeld, tempBuffer, 32);
    printf(tempBuffer); printf( "\n" );
    
    tempBuffer[32] = '\0';
    int2bin(buttonsReleased, tempBuffer, 32);
    printf(tempBuffer); printf( "\n" );
    
    
    
    
    
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