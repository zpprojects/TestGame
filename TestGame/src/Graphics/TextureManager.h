//
//  TextureManager.h
//  TestGame
//
//  Created by Jacob Sawyer on 10/25/16.
//  Copyright (c) 2016 Jacob Sawyer. All rights reserved.
//

#ifndef __TestGame__TextureManager__
#define __TestGame__TextureManager__

class TextureManager
{

private:
    static TextureManager* m_instance;
    
    TextureManager() {};
    ~TextureManager() {};
    
public:
    
    static TextureManager* instance()
    {
        if(!m_instance)
            m_instance = new TextureManager();
        return m_instance;
    }
    
    
    bool loadTexture(const char* pathToTexture, int &textureID);
     
    
};

#endif /* defined(__TestGame__TextureManager__) */
