//
//  TextureManager.h
//  TestGame
//
//  Created by Jacob Sawyer on 10/25/16.
//  Copyright (c) 2016 Jacob Sawyer. All rights reserved.
//

#ifndef __TestGame__TextureManager__
#define __TestGame__TextureManager__

#include <stdio.h>
#include <SOIL.h>
#include <GLFW/glfw3.h>

int LoadGLTextures()                                    // Load Bitmaps And Convert To Textures
{
    GLuint texture[50];
    /* load an image file directly as a new OpenGL texture */
    texture[0] = SOIL_load_OGL_texture
    (
     "Data/NeHe.bmp",
     SOIL_LOAD_AUTO,
     SOIL_CREATE_NEW_ID,
     SOIL_FLAG_INVERT_Y
     );
    
    if(texture[0] == 0)
        return false;
    
    
    // Typical Texture Generation Using Data From The Bitmap
    glBindTexture(GL_TEXTURE_2D, texture[0]);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    
    return true;                                        // Return Success
}

#endif /* defined(__TestGame__TextureManager__) */
