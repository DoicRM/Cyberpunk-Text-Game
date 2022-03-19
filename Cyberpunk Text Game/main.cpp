#include "game.h"

int main()
{   
    //cout << "\t\t\t\t\t\t\t\t\t\t\t\t  i" << endl;
    Logger::Setup();
    Function::nameGame("Cyberpunk Text Game");
    Function::initSpecialChars("polish");

    Game game;
    Logger::Out("Game was create", "Game::Game");

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