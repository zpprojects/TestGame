//
//  GUIMenuItem.h
//  TestGame
//
//  Created by Jacob Sawyer on 6/22/15.
//  Copyright (c) 2015 Jacob Sawyer. All rights reserved.
//

#ifndef __TestGame__GUIMenuItem__
#define __TestGame__GUIMenuItem__

#include <stdio.h>
#include "GUIComponent.h"

class GUIMenuItem : GUIComponent
{
public:
    
    GUIMenuItem(){};
    ~GUIMenuItem(){};
    void update(float dt);
    void draw();
    
private:
    
    float posx, posy;
    
};

#endif /* defined(__TestGame__GUIMenuItem__) */
