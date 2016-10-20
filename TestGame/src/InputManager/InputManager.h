//
//  InputManager.h
//  TestGame
//
//  Created by Jacob Sawyer on 4/2/15.
//  Copyright (c) 2015 Jacob Sawyer. All rights reserved.
//

#ifndef __TestGame__InputManager__
#define __TestGame__InputManager__

#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>




class InputManager
{
public:
    enum KEYS : unsigned int
    {
    NONE        =   0,
    KEY_UP      =   1 << 0,
    KEY_DOWN    =   1 << 1,
    KEY_LEFT    =   1 << 2,
    KEY_RIGHT   =   1 << 3,
    KEY_W       =   1 << 4,
    KEY_S       =   1 << 5,
    KEY_A       =   1 << 6,
    KEY_D       =   1 << 7,
    KEY_ESC     =   1 << 16
    };
    GLFWwindow* window;
    InputManager(GLFWwindow* initWindow)
    {
        window = initWindow;
        initialize();
    };
    ~InputManager(){};
    void processKeyboardState();
    void processKeys();
private:
    unsigned int keysPressed,keysHeld,keysReleased;
    void initialize();
    char* int2bin(int a, char *buffer, int buf_size);
};

#endif /* defined(__TestGame__InputManager__) */
