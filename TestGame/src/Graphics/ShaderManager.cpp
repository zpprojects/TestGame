//
//  ShaderManager.cpp
//  TestGame
//
//  Created by Jacob Sawyer on 10/23/16.
//  Copyright (c) 2016 Jacob Sawyer. All rights reserved.
//

#include "ShaderManager.h"
#include "Shaders.h"
#include <iostream>
#include <string>
#include <fstream>

ShaderManager* ShaderManager::m_instance = NULL;

ShaderManager::ShaderManager()
{
    initialize();
}
bool ShaderManager::initialize()
{
    GLuint fragment_shader, vertex_shader, program;
    
    vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex_shader, 1, &basic_vertex_shader_text, NULL);
    glCompileShader(vertex_shader);
    
    fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment_shader, 1, &basic_fragment_shader_text, NULL);
    glCompileShader(fragment_shader);
    
    program = glCreateProgram();
    glAttachShader(program, vertex_shader);
    glAttachShader(program, fragment_shader);
    glLinkProgram(program);
    
    shaderVector.push_back(program);
    
    glDeleteShader(fragment_shader);
    glDeleteShader(vertex_shader);
    
    
    return true;
}
const bool ShaderManager::loadShaderFromFile(const char *filepath)
{
    
    
    return true;
}