//
//  GenericOneAxisGamePad.cpp
//  TestGame
//
//  Created by Jacob Sawyer on 10/29/16.
//  Copyright (c) 2016 Jacob Sawyer. All rights reserved.
//

#include "GenericOneAxisGamePad.h"
#include <Glfw/glfw3.h>

GenericOneAxisGamePad::GenericOneAxisGamePad(int initgamePadNum) : GamePad(initgamePadNum)
{
    currentGamePadState, buttonsPressed, buttonsReleased, buttonsHeld = 0;
    gamePadNum = initgamePadNum;
}
GenericOneAxisGamePad::~GenericOneAxisGamePad()
{
    
}
bool GenericOneAxisGamePad::initialize()
{
    return true;
}
bool GenericOneAxisGamePad::queryGamePad(int &BUTTONsPressed)
{
    int buttonCount;
    const unsigned char *buttons = glfwGetJoystickButtons(gamePadNum, &buttonCount);
    
    currentGamePadState = 0;
    
    if(buttons[0] == GLFW_PRESS)
        currentGamePadState = currentGamePadState | BUTTONS::BUTTON_B;
    if(buttons[1] == GLFW_PRESS)
        currentGamePadState = currentGamePadState | BUTTONS::BUTTON_A;
    if(buttons[8] == GLFW_PRESS)
        currentGamePadState = currentGamePadState | BUTTONS::BUTTON_SELECT;
    if(buttons[9] == GLFW_PRESS)
        currentGamePadState = currentGamePadState | BUTTONS::BUTTON_START;
    
    int axesCount;
    const float *axes = glfwGetJoystickAxes( GLFW_JOYSTICK_1, &axesCount );
    
    if (axes[0] == -1)
        currentGamePadState = currentGamePadState | BUTTONS::BUTTON_LEFT;
    if (axes[0] == 1)
        currentGamePadState = currentGamePadState | BUTTONS::BUTTON_RIGHT;
    if (axes[1] == -1)
        currentGamePadState = currentGamePadState | BUTTONS::BUTTON_UP;
    if (axes[1] == 1)
        currentGamePadState = currentGamePadState | BUTTONS::BUTTON_DOWN;
    //if a button is not in the current state and it was in buttons held it must of
    //been released
    buttonsReleased = buttonsHeld & ~currentGamePadState;
    
    
    //if a button was held last state and is still pressed it is still held
    buttonsHeld = buttonsHeld & currentGamePadState;
    
    //if a button was pressed last state and is pressed again this state it
    //it is now considered held
    buttonsHeld = buttonsHeld | (buttonsPressed & currentGamePadState);
    
    //a key is considered pressed if it it was pressed this state but is
    //not considered to be held
    buttonsPressed = currentGamePadState & ~buttonsHeld;
    
    return true;
}