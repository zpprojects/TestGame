//
//  GUIManager.h
//  TestGame
//
//  Created by Jacob Sawyer on 4/4/15.
//  Copyright (c) 2015 Jacob Sawyer. All rights reserved.
//

#ifndef __TestGame__GUIManager__
#define __TestGame__GUIManager__

#include <GLFW/glfw3.h>
#include <vector>

class GUIScreen;

class GUIManager
{
private:
    
    static GUIManager* m_instance;
    GUIManager() {};
    ~GUIManager() {};
    std::vector<GUIScreen*> screenVector;
    
public:
    
    static GUIManager* instance()
    {
        if(!m_instance)
            m_instance = new GUIManager();
        return m_instance;
    }
    
    void drawCurrentScreen();
    
};

#endif /* defined(__TestGame__GUIManager__) */
