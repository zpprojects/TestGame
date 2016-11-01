//
//  TextureManager.cpp
//  TestGame
//
//  Created by Jacob Sawyer on 10/25/16.
//  Copyright (c) 2016 Jacob Sawyer. All rights reserved.
//

#include "TextureManager.h"
#include <SOIL.h>
#include <GLFW/glfw3.h>

TextureManager* TextureManager::m_instance = NULL;

bool TextureManager::loadTexture(const char *pathToTexture, int &textureID)
{
    GLuint texture;
    /* load an image file directly as a new OpenGL texture */
    texture = SOIL_load_OGL_texture
    (
        pathToTexture,
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y
    );
        
    if(texture == 0)
        return false;
        
        
    // Typical Texture Generation Using Data From The Bitmap
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
        
    return true;                                        // Return Success
}