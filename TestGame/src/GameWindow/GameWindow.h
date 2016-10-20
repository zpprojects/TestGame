//
//  GameWindow.h
//  TestGame
//
//  Created by Jacob Sawyer on 4/2/15.
//  Copyright (c) 2015 Jacob Sawyer. All rights reserved.
//

#ifndef __TestGame__GameWindow__
#define __TestGame__GameWindow__

#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>

class GUIScreen;

class GameWindow
{
    
public:
    GLFWwindow* window;
    
    GameWindow(const char* title, int height, int width){
        initWindow(title, height, width);
    }
    ~GameWindow(){};
    bool destroyWindow(){
        glfwDestroyWindow(window);
        glfwTerminate();
        exit(EXIT_SUCCESS);
    };
    bool WindowShouldClose(){
        return glfwWindowShouldClose(window);
    };
    GLFWwindow* getGLWindow() { return window;};
    bool update();
private:
    bool initWindow(const char* title, int height, int width);
    static void error_callback(int error, const char* description){
        fputs(description, stderr);
    }
    GUIScreen* testScreen;
};

#endif /* defined(__TestGame__GameWindow__) */
