//
//  GUIComponent.h
//  TestGame
//
//  Created by Jacob Sawyer on 4/4/15.
//  Copyright (c) 2015 Jacob Sawyer. All rights reserved.
//

#ifndef __TestGame__GUIComponent__
#define __TestGame__GUIComponent__

#include <stdio.h>

class GUIComponent
{

public:
    
    GUIComponent(int initx, int inity);
    ~GUIComponent() {};
    virtual void update(float dt) = 0;
    virtual void draw(){};

private:
    int posx, posy;
    
};

#endif /* defined(__TestGame__GUIComponent__) */
