//
//  GamePad.h
//  TestGame
//
//  Created by Jacob Sawyer on 10/26/16.
//  Copyright (c) 2016 Jacob Sawyer. All rights reserved.
//

#ifndef __TestGame__GamePad__
#define __TestGame__GamePad__

#include <stdio.h>

class GamePad
{

    
public:
    enum BUTTONS : unsigned int
    {
        BUTTON_UP      =   1,
        BUTTON_DOWN    =   1 << 1,
        BUTTON_LEFT    =   1 << 2,
        BUTTON_RIGHT   =   1 << 3,
        BUTTON_A       =   1 << 4,
        BUTTON_B       =   1 << 5,
        BUTTON_X       =   1 << 6,
        BUTTON_Y       =   1 << 7,
        BUTTON_LB      =   1 << 8,
        BUTTON_RB      =   1 << 9,
        BUTTON_SELECT  =   1 << 10,
        BUTTON_START  =   1 << 11
    };
    GamePad(int initgamePadNum);
    ~GamePad();
    
    virtual bool queryGamePad(int &BUTTONsPressed) = 0;
    void getButtonStatus(int &mbuttonsReleased, int &mbuttonsHeld, int &mbuttonsPressed)
    {
        mbuttonsReleased = buttonsReleased;
        mbuttonsHeld = buttonsHeld;
        mbuttonsPressed = buttonsPressed;
    };
    
protected:
    virtual bool initialize() = 0;
    int gamePadNum;
    int currentGamePadState, buttonsReleased, buttonsHeld, buttonsPressed;
};

#endif /* defined(__TestGame__GamePad__) */
