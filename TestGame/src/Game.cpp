//
//  Game.cpp
//  TestGame
//
//  Created by Jacob Sawyer on 4/19/15.
//  Copyright (c) 2015 Jacob Sawyer. All rights reserved.
//

#include "Game.h"
#include "GameWindow.h"
#include "AudioManager.h"
#include "InputManager.h"
#include "GameStateManager.h"
#include "GUI/GUIManager.h"
#include "GUI/GUIScreen.h"
#include "GUI/GUIComponents/GUIButton.h"

Game* Game::m_instance = NULL;

Game::Game()
{
    
}
bool Game::initialize()
{
    gGameStateManager = GameStateManager::instance();
    gGameStateManager->setState(GAMESTATE_INITIALIZING);
    
    gWindow = new GameWindow("Testing a new game", 640, 480);
    gInputManager = new InputManager(gWindow->getGLWindow());
    if (gInputManager->checkForGamePads())
        gInputManager->createGamePads();
    gAudioManager = AudioManager::instance();
    gAudioManager->loadFileIntoBuffer("./Resources/Audio/SoundEffects/gunshot.wav");
    gGUIManager = GUIManager::instance();
    GUIButton* button = new GUIButton(10,10);
    button->loadTexture("./Resources/Textures/Test/newgame.png");
    GUIScreen* mainScreen = new GUIScreen();
    mainScreen->addComponenet(button);
    
    
    return true;
}
void Game::update()
{
    gWindow->update();
    gInputManager->processKeyboardState();
    gInputManager->processGamePadState();
    gInputManager->processKeys();
    gInputManager->processGamePadButtons();
}

bool Game::isGameRunning()
{
    return gGameStateManager->isGameRunning();
}
void Game::destory()
{
    gWindow->destroyWindow();
    gAudioManager->destroy();
    
}