//
//  GamePadXbox360.h
//  TestGame
//
//  Created by Jacob Sawyer on 10/26/16.
//  Copyright (c) 2016 Jacob Sawyer. All rights reserved.
//

#ifndef __TestGame__GamePadXbox360__
#define __TestGame__GamePadXbox360__

#include <stdio.h>
#include "GamePad.h"

class GamePadXbox360 : public GamePad
{
public:
    GamePadXbox360(int initgamePadNum);
    ~GamePadXbox360();
    
    bool queryGamePad(int &keysPressed);
private:
    int BUTTONCOUNT=15;
    bool initialize();
};

#endif /* defined(__TestGame__GamePadXbox360__) */
