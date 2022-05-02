#include "./game/game.hpp"

int main()
{   
    int defaultEncoding = GetConsoleOutputCP();
    SetConsoleOutputCP(65001); // set console encoding to UTF-8
    srand((unsigned)time(NULL));
    Logger::setup(false);
    Game::init();
    Game::game[0].run();
    Logger::cleanup();
    Game::game.clear();
    SetConsoleOutputCP(defaultEncoding); // set default console encoding
    exit(0);
}