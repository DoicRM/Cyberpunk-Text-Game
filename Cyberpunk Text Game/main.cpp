#include "game.h"

int main()
{   
    //cout << "\t\t\t\t\t\t\t\t\t\t\t\t  i" << endl;
    Logger::setup(false);
    Game game;
    game.run();
    Logger::cleanup();
    return 0;
}