#include <cstdio>

#include <GLFW/glfw3.h>
#include "SOIL.h"

// function declarations
void drawscene();
void idlefunc();
void updatedisplay();

// global data
GLuint texture; // our example texture

int main(int argc, char **argv) {
    if (!glfwInit()) {
        fprintf(stderr, "Failed to initialize GLFW\n");
        return 1;
    }
    
    if (!glfwCreateWindow(640, 480, 0, 0, 0, 0, 16, 0, GLFW_WINDOW)) {
        fprintf(stderr, "Failed to open GLFW window\n");
        return 1;
    }
    
    // enable vsync (if available)
    glfwSwapInterval(1);
    
    // load textures
    texture = SOIL_load_OGL_texture(
                                    "tex.png",
                                    SOIL_LOAD_AUTO,
                                    SOIL_CREATE_NEW_ID,
                                    SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_MIPMAPS | SOIL_FLAG_DDS_LOAD_DIRECT
                                    );
    
    // check for an error during the texture loading
    if (!texture) {
        printf("SOIL loading error: '%s'\n", SOIL_last_result());
    }
    
    while (glfwGetWindowParam(GLFW_OPENED)) {
        idlefunc();
    }
    
    // if we get here something went wrong
    return 0;
}

// this function gets called every frame
void idlefunc() {
    updatedisplay();
    drawscene();
}

// set up te display
void updatedisplay() {
    int screen_width, screen_height;
    glfwGetWindowSize(&screen_width, &screen_height);
    
    if (screen_height <= 0) screen_height = 1;
    if (screen_width <= 0) screen_width = 1;
    
    glViewport(0, 0, screen_width, screen_height);
    
    glClearColor(0.02f, 0.02f, 0.02f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    
    glEnable(GL_TEXTURE_2D);
    glDisable(GL_DEPTH_TEST);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, screen_width, screen_height, 0.0, 0.0, 1.0);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    // displacement trick for exact pixelization
    glTranslatef(0.375f, 0.375f, 0.0f);
}

// draw the scene in this function
void drawscene() {
    glBindTexture(GL_TEXTURE_2D, texture);
    glPushMatrix();
    glTranslatef(10.0f, 10.0f, 0);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex2f(0.0f, 0.0f);
    glTexCoord2f(0.0f, 128.0f);
    glVertex2f(0.0f, 128.0f);
    glTexCoord2f(128.0f, 128.0f);
    glVertex2f(128.0f, 128.0f);
    glTexCoord2f(128.0f, 0.0f);
    glVertex2f(128.0f, 0.0f);
    glEnd();
    glPopMatrix();
    
    glfwSwapBuffers();
}