//
//  GUIButton.h
//  TestGame
//
//  Created by Jacob Sawyer on 10/31/16.
//  Copyright (c) 2016 Jacob Sawyer. All rights reserved.
//

#ifndef __TestGame__GUIButton__
#define __TestGame__GUIButton__

#include <stdio.h>
#include "GUIComponent.h"
#include <GLFW/GLFW3.h>

class GUIButton : public GUIComponent
{

    
public:
    
    GUIButton(int initx, int inity);
    ~GUIButton(){};
    
    void changeSelectionStatus(bool status);
    void activateButton();
    void update(float dt);
    bool loadTexture(const char* filePath);
    void draw();
    
    
private:
    
    GLuint VBO, VAO;
    GLfloat vertices[12];
    int textureID;
    bool isSelected;
    
};

#endif /* defined(__TestGame__GUIButton__) */
