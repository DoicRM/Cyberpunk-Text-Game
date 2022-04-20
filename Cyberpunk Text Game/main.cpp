#include "./game/game.hpp"

int main()
{   
    srand((unsigned)time(NULL));
    Logger::setup(false);
    Game::init();
    Game::game[0].run();
    Logger::cleanup();
    Game::game.clear();
    exit(0);
}