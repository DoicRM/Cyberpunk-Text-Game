#include "./game/game.hpp"

int main()
{   
    srand((unsigned)time(NULL));
    Logger::setup(false);
    SetConsoleCP(65001); // set console encoding to UTF-8
    Game::init();
    Game::game[0].run();
    Logger::cleanup();
    Game::game.clear();
    SetConsoleCP(852); // set default console encoding
    exit(0);
}