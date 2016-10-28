//
//  GamePadXbox360.cpp
//  TestGame
//
//  Created by Jacob Sawyer on 10/26/16.
//  Copyright (c) 2016 Jacob Sawyer. All rights reserved.
//

#include "GamePadXbox360.h"
#include "GamePad.h"
#include <GLFW/glfw3.h>


GamePadXbox360::GamePadXbox360(int initgamePadNum) : GamePad(initgamePadNum)
{

}
GamePadXbox360::~GamePadXbox360()
{
    
}
bool GamePadXbox360::queryGamePad(int &keysPressed)
{
    const unsigned char *buttons = glfwGetJoystickButtons(gamePadNum, &BUTTONCOUNT);
    
    currentGamePadState = 0;
    
    if(buttons[0] == GLFW_PRESS)
        currentGamePadState = currentGamePadState | BUTTONS::BUTTON_UP;
    if(buttons[1] == GLFW_PRESS)
        currentGamePadState = currentGamePadState | BUTTONS::BUTTON_DOWN;
    if(buttons[2] == GLFW_PRESS)
        currentGamePadState = currentGamePadState | BUTTONS::BUTTON_LEFT;
    if(buttons[3] == GLFW_PRESS)
        currentGamePadState = currentGamePadState | BUTTONS::BUTTON_RIGHT;
    if(buttons[4] == GLFW_PRESS)
        currentGamePadState = currentGamePadState | BUTTONS::BUTTON_START;
    if(buttons[5] == GLFW_PRESS)
        currentGamePadState = currentGamePadState | BUTTONS::BUTTON_SELECT;
    /*
    if(buttons[6] == GLFW_PRESS)
        currentGamePadState = currentGamePadState | BUTTONS::BUTTON_UP;
    if(buttons[7] == GLFW_PRESS)
        currentGamePadState = currentGamePadState | BUTTONS::BUTTON_UP;
    */
    if(buttons[8] == GLFW_PRESS)
        currentGamePadState = currentGamePadState | BUTTONS::BUTTON_LB;
    if(buttons[9] == GLFW_PRESS)
        currentGamePadState = currentGamePadState | BUTTONS::BUTTON_RB;
    /*
    if(buttons[10] == GLFW_PRESS)
        currentGamePadState = currentGamePadState | BUTTONS::BUTTON_UP;
     */
    if(buttons[11] == GLFW_PRESS)
        currentGamePadState = currentGamePadState | BUTTONS::BUTTON_A;
    if(buttons[12] == GLFW_PRESS)
        currentGamePadState = currentGamePadState | BUTTONS::BUTTON_B;
    if(buttons[13] == GLFW_PRESS)
        currentGamePadState = currentGamePadState | BUTTONS::BUTTON_X;
    if(buttons[14] == GLFW_PRESS)
        currentGamePadState = currentGamePadState | BUTTONS::BUTTON_Y;
    
    
    
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
bool GamePadXbox360::initialize()
{
    return true;
}