#include "game.h"

int main()
{   
    Logger::setup(false);
    Game::init();
    Game::game[0].run();
    Logger::cleanup();
    Game::game.clear();
    return 0;
}