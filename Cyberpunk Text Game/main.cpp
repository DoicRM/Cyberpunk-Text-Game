#include "game.h"

using namespace std;

int main()
{   
    //cout << "\t\t\t\t\t\t\t\t\t\t\t\t  i" << endl;

    SetConsoleTitleA("Cyberpunk Text Game");
    setlocale(LC_ALL, "polish"); // Zainicjowanie polskich znaków

    Game game;

    while (game.getPlaying())
    {
        //game.selectLanguage(); // Wybór języka gry
        game.welcome();
    }

    Function::waitForUserInput();

    return 0;
}