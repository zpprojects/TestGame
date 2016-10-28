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
#include <vector>
#include "GamePad.h"

#define MAXGAMEPADS




class InputManager
{
public:
    enum KEYS : unsigned int
    {
    KEY_UP      =   1,
    KEY_DOWN    =   1 << 1,
    KEY_LEFT    =   1 << 2,
    KEY_RIGHT   =   1 << 3,
    KEY_W       =   1 << 4,
    KEY_S       =   1 << 5,
    KEY_A       =   1 << 6,
    KEY_D       =   1 << 7,
    KEY_Q       =   1 << 8,
    KEY_E       =   1 << 9,
    KEY_ESC     =   1 << 10,
    KEY_ENTER   =   1 << 11
    };
    GLFWwindow* window;
    InputManager(GLFWwindow* initWindow)
    {
        window = initWindow;
        initialize();
    };
    ~InputManager(){};
    void processKeyboardState();
    void processGamePadState();
    void processKeys();
    void processGamePadButtons();
    bool checkForGamePads();
    bool createGamePads();
    
    int numOfGamePads;
private:
    unsigned int keysPressed,keysHeld,keysReleased;
    void initialize();
    char* int2bin(int a, char *buffer, int buf_size);
    std::vector<GamePad*> gamepadVector;
    
};

#endif /* defined(__TestGame__InputManager__) */
