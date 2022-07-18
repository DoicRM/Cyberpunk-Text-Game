#define _WIN32_WINNT 0x0500
#include "Game/Game.hpp"

int main()
{
    Console::initConsole();
    Logger::setup(false); // for debugging
    GameSettings config;
    if (config.loadConfigFile())
    {
        Game Nocturnal;
        Game::game[0] = Nocturnal;
        Game::game[0].run();
    }
    Logger::cleanup();
    Game::game.clear(); // memory free
}