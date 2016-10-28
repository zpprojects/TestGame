//
//  ShaderManager.h
//  TestGame
//
//  Created by Jacob Sawyer on 10/23/16.
//  Copyright (c) 2016 Jacob Sawyer. All rights reserved.
//

#ifndef __TestGame__ShaderManager__
#define __TestGame__ShaderManager__

#include <stdio.h>
#include <vector>
#include <GLFW/glfw3.h>


class ShaderManager
{
    
public:
    
    static ShaderManager* instance()
    {
        if(!m_instance)
            m_instance = new ShaderManager();
        return m_instance;
    }
    bool initialize();
    enum SHADERLIST{
        BASIC=0
    };
    static const bool loadShaderFromFile(const char *filepath);

private:

    static ShaderManager* m_instance;
    ShaderManager();
    ~ShaderManager();
    std::vector<GLuint> shaderVector;

};


#endif /* defined(__TestGame__ShaderManager__) */
