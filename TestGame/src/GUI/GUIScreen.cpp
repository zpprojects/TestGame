//
//  GUIScreen.cpp
//  TestGame
//
//  Created by Jacob Sawyer on 4/4/15.
//  Copyright (c) 2015 Jacob Sawyer. All rights reserved.
//

#include "GUIScreen.h"
#include <GLFW/glfw3.h>
#include "GUIComponent.h"



void GUIScreen::loadData()
{

}
void GUIScreen::addComponenet(GUIComponent *guiComponent)
{
    componentsVector.push_back(guiComponent);
}
void GUIScreen::update(float dt)
{
    for (int i=0; i<componentsVector.size(); i++) {
        componentsVector.at(i)->update(dt);
    }
}
void GUIScreen::draw()
{
    for (int i=0; i<componentsVector.size(); i++) {
        componentsVector.at(i)->draw();
    }
}