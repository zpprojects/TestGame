//
//  GUIButton.cpp
//  TestGame
//
//  Created by Jacob Sawyer on 10/31/16.
//  Copyright (c) 2016 Jacob Sawyer. All rights reserved.
//

#include "GUIButton.h"
#include "GUIComponent.h"
#include "../../Graphics/TextureManager.h"
#include "GLFW/GLFW3.h"



GUIButton::GUIButton(int initx, int inity) : GUIComponent(initx, inity)
{
    textureID = 0;
}
void GUIButton::update(float dt)
{

    
}
void GUIButton::draw()
{
    
}
bool GUIButton::loadTexture(const char *filePath)
{
    TextureManager* tm = TextureManager::instance();
    tm->loadTexture(filePath, textureID);
    return true;
}