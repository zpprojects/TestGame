//
//  GenericOneAxisGamePad.h
//  TestGame
//
//  Created by Jacob Sawyer on 10/29/16.
//  Copyright (c) 2016 Jacob Sawyer. All rights reserved.
//

#ifndef __TestGame__GenericOneAxisGamePad__
#define __TestGame__GenericOneAxisGamePad__

#include <stdio.h>
#include "GamePad.h"

class GenericOneAxisGamePad : public GamePad
{
public:
    GenericOneAxisGamePad(int initgamePadNum);
    ~GenericOneAxisGamePad();
    
    bool queryGamePad(int &keysPressed);
private:
    bool initialize();
};

#endif /* defined(__TestGame__GenericOneAxisGamePad__) */
