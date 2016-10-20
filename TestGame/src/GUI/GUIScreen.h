//
//  GUIScreen.h
//  TestGame
//
//  Created by Jacob Sawyer on 4/4/15.
//  Copyright (c) 2015 Jacob Sawyer. All rights reserved.
//

#ifndef __TestGame__GUIScreen__
#define __TestGame__GUIScreen__

#include <GLFW/glfw3.h>

class GUIScreen
{

public:
    
    GUIScreen(){};
    ~GUIScreen(){};
    
    void loadData();
    void update(float dt);
    void draw();
    
private:
    
    GLuint myVBO;
    GLuint myIndices;
    

};

#endif /* defined(__TestGame__GUIScreen__) */
