//
//  GUIScreen.cpp
//  TestGame
//
//  Created by Jacob Sawyer on 4/4/15.
//  Copyright (c) 2015 Jacob Sawyer. All rights reserved.
//

#include "GUIScreen.h"
#include <GLFW/glfw3.h>



void GUIScreen::loadData()
{
    GLfloat vertexData[] = {0, 2, 0,  -2, -2, 0,   2, -2, 0};
    GLubyte indexData[] = {0, 1, 2};
    
    glGenBuffers(1, &myVBO);
    glGenBuffers(1, &myIndices);
    
    glBindBuffer(GL_ARRAY_BUFFER, myVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, myIndices);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indexData), indexData, GL_STATIC_DRAW);
}
void GUIScreen::draw()
{
    glLoadIdentity();
    glTranslatef(0, 0, -10);
    
    glColor3f(1, 0, 0);
    
    glBindBuffer(GL_ARRAY_BUFFER, myVBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, myIndices);
    
    glEnableVertexAttribArray(0);                                               //ENABLE VERTEX POSITION
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, 0);      // VERTEX POSITION POINTER
    
    glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, 0);
}
void GUIScreen::update(float dt)
{
    
}