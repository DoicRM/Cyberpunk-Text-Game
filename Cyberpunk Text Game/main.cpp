#include "game.h"

int main()
{   
    //cout << "\t\t\t\t\t\t\t\t\t\t\t\t  i" << endl;
    Logger::setup();
    Function::nameGame("Cyberpunk Text Game v.1.0");
    Function::initSpecialChars("polish");

    Game game;
    Logger::out("Game start", "Game::Game");

    while (game.getPlaying())
    {
        game.selectLanguage();
        game.welcome();
        game.writeLogo();
        game.mainMenu();
        game.end();
    }

    Function::waitForUserInput();

    return 0;
}