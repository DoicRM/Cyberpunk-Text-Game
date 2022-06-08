#define _WIN32_WINNT 0x0500
#include "./game/game.hpp"

int main()
{   
    UINT defaultInputEncoding = GetConsoleCP();
    UINT defaultOutputEncoding = GetConsoleOutputCP();
    Console::initConsole("Nocturnal [Demo Build]", 65001 /* UTF-8 */);
    Logger::setup(false);
    Game::init();
    Game::game[0].run();
    Logger::cleanup();
    Game::game.clear();
    Console::resetConsoleEncoding(defaultInputEncoding, defaultOutputEncoding);
    return EXIT_SUCCESS;
}