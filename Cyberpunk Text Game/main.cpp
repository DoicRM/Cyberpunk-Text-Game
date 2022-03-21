#include "game.h"

int main()
{   
    Logger::setup(false);
    Game game;
    game.run();
    Logger::cleanup();
    return 0;
}