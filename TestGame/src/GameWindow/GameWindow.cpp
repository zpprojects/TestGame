//
//  GameWindow.cpp
//  TestGame
//
//  Created by Jacob Sawyer on 4/2/15.
//  Copyright (c) 2015 Jacob Sawyer. All rights reserved.
//

#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include "GameWindow.h"
#include "GUIScreen.h"

bool GameWindow::initWindow(const char *title, int height, int width)
{
    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
        exit(EXIT_FAILURE);
    window = glfwCreateWindow(height, width, title, NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);
    //glMatrixMode(GL_PROJECTION);
    //glLoadIdentity();
    //float aspectRatio = 600.0f / 800.0f;
    //glFrustum(0.5f, -0.5f, -0.5f * aspectRatio, 0.5f * aspectRatio, 1.0f, 50.0f);
    //glMatrixMode(GL_MODELVIEW);
    
    
    //testing the screen functions
    testScreen = new GUIScreen();
    testScreen->loadData();
    
    return true;
};
bool GameWindow::update()
{
    float ratio;
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    ratio = width / (float) height;
    glViewport(0, 0, width, height);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRotatef((float) glfwGetTime() * 50.f, 0.f, 0.f, 1.f);
    glBegin(GL_TRIANGLES);
    glColor3f(1.f, 0.f, 0.f);
    glVertex3f(-0.6f, -0.4f, 0.f);
    glColor3f(0.f, 1.f, 0.f);
    glVertex3f(0.6f, -0.4f, 0.f);
    glColor3f(0.f, 0.f, 1.f);
    glVertex3f(0.f, 0.6f, 0.f);
    glEnd();
    
    testScreen->update(0);
    testScreen->draw();
    
    glfwSwapBuffers(window);
    glfwPollEvents();
    
    return true;
}