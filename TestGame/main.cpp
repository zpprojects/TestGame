#include "game.h"

int main(void)
{
    Game* game = Game::instance();
    game->initialize();
    
    while (game->isGameRunning())
    {
        game->update();
    }
    game->destory();
}
