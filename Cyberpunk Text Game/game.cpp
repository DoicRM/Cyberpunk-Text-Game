#include "game.h"

Game::Game()
{
    menu = 0;
    choice = 0;
    gameLang = 0;
    playing = true;
    ptrCurrentLocation = nullptr;
}

Game::~Game()
{   
}

void Game::selectLanguage()
{
    Logger::out("Function start", "Game::selectLanguage");
    while (gameLang != 1 && gameLang != 2)
    {
        Function::clearScreen();
        std::cout << std::endl;
        Function::write("\t[1] EN", 25);
        std::cout << std::endl;
        Function::write("\t[2] PL", 25);
        std::cout << std::endl;
        Function::write("\tSelect your language: ", 25);
        std::cin >> gameLang;
    }

    if (getLang() == en) Logger::out("Game language is English", "Game::selectLanguage");
    else Logger::out("Game language is Polish", "Game::selectLanguage");

    Function::clearScreen();
}

void Game::welcome()
{
    Logger::out("Function start", "Game::welcome");
    std::cout << std::endl;
    Sleep(500); 

    if (getLang() == pl) Function::write("\tRADOS£AW 'DOIC' MICHALAK PREZENTUJE GRÊ TEKSTOW¥ POD TYTU£EM", 40);
    else Function::write("\tRADOS£AW 'DOIC' MICHALAK PRESENTS A TEXT GAME TITLED", 40);

    Sleep(2000);
    Function::clearScreen();
}

void Game::writeLogo()
{
    Logger::out("Function start", "Game::writeLogo");
    Function::changeConsoleColor(yellow);
    std::cout << "" << std::endl;
    Function::write("\t ======  ===    ===  =======   =======  =======   =======   ==     ==  ===    ==  ==    ==", 1);
    std::cout << std::endl;
    Function::write("\t=======   ===  ===   ==   ===  ==       ==   ===  ==   ===  ==     ==  ====   ==  ==   == ", 1);
    std::cout << std::endl;
    Function::write("\t==         ======    ==   ==   ==       ==   ==   ==   ==   ==     ==  =====  ==  ==  ==  ", 1);
    std::cout << std::endl;
    Function::write("\t==          ====     ======    =======  ======    ======    ==     ==  =========  =====   ", 1);
    std::cout << std::endl;
    Function::write("\t==           ==      ==   ==   ==       =====     =====     ===   ===  == ======  ==  ==  ", 1);
    std::cout << std::endl;
    Function::write("\t=======      ==      ==   ===  ==       ==  ==    ==         =======   ==   ====  ==   == ", 1);
    std::cout << std::endl;
    Function::write("\t ======      ==      =======   =======  ==   ===  ==          =====    ==    ===  ==    ==", 1);
    std::cout << std::endl;
    std::cout << "" << std::endl;
    Function::changeConsoleColor();
    Function::write("\t\t\t\t\t\t\t\t\tDemo Build", 2);
    std::cout << std::endl;
    std::cout << "" << std::endl;
}

void Game::logo()
{
    Logger::out("Function start", "Game::logo");
    Function::changeConsoleColor(yellow);
    std::cout << "" << std::endl;
    std::cout << "\t ======  ===    ===  =======   =======  =======   =======   ==     ==  ===    ==  ==    ==" << std::endl;
    std::cout << "\t=======   ===  ===   ==   ===  ==       ==   ===  ==   ===  ==     ==  ====   ==  ==   == " << std::endl;
    std::cout << "\t==         ======    ==   ==   ==       ==   ==   ==   ==   ==     ==  =====  ==  ==  ==  " << std::endl;
    std::cout << "\t==          ====     ======    =======  ======    ======    ==     ==  =========  =====   " << std::endl;
    std::cout << "\t==           ==      ==   ==   ==       =====     =====     ===   ===  == ======  ==  ==  " << std::endl;
    std::cout << "\t=======      ==      ==   ===  ==       ==  ==    ==         =======   ==   ====  ==   == " << std::endl;
    std::cout << "\t ======      ==      =======   =======  ==   ===  ==          =====    ==    ===  ==    ==" << std::endl;
    std::cout << "" << std::endl;
    Function::changeConsoleColor();
    std::cout << "\t\t\t\t\t\t\t\t\tDemo Build" << std::endl;
    std::cout << "" << std::endl;
    mainMenu();
}

void Game::mainMenu()
{
    Logger::out("Function start", "Game::mainMenu");
    Function::changeConsoleColor();
    std::cout << "" << std::endl;

    if (getLang() == pl)
    {
        Function::write("\t[1] Nowa gra", 25);
        std::cout << std::endl;
        Function::write("\t[2] Kontynuuj grê", 25);
        std::cout << std::endl;
        Function::write("\t[3] O autorze", 25);
        std::cout << std::endl;
        Function::write("\t[4] WyjdŸ z gry", 25);
        std::cout << std::endl;
        Function::write("\t> ", 25);
    }
    else
    {
        Function::write("\t[1] New game", 25);
        std::cout << std::endl;
        Function::write("\t[2] Continue game", 25);
        std::cout << std::endl;
        Function::write("\t[3] About author", 25);
        std::cout << std::endl;
        Function::write("\t[4] Quit game", 25);
        std::cout << std::endl;
        Function::write("\t> ", 25);
    }

    do
    {
        std::cin >> menu;
        switch (menu) {
        case 1:
            newGame();
            break;
        case 2:
            continueGame();
            break;
        case 3:
            aboutAuthor();
            break;
        case 4:
            endGame();
            break;
        }
    } while (menu > 4 || menu <= 0);
}

void Game::newGame()
{
    Logger::out("Function start", "Game::newGame");
    Event::initAll();
    Function::clearScreen();
    //setCurrentLocation(DarkAlley);
    Event::darkAlley();
}

void Game::continueGame()
{
    Logger::out("Function start", "Game::continueGame");
    Sleep(500);
    Function::clearScreen();
    std::cout << std::endl;
    Function::changeConsoleColor(lightblue);

    if (getLang() == pl) Function::write("\tNic tu nie ma. Ta funkcja jest obecnie niedostêpna.\n\n", 25);
    else Function::write("\tThere's nothing here. This feature is currently unavailable.\n\n", 25);

    Function::changeConsoleColor();
    Sleep(1000);
    Function::pauseGame();
    Function::clearScreen();
    logo();
    mainMenu();
}

void Game::aboutAuthor()
{
    Logger::out("Function start", "Game::aboutAuthor");
    Sleep(500);
    Function::clearScreen();
    std::cout << std::endl;
    Function::changeConsoleColor(lightblue);
    Function::write("\t\t\t\t\tAUTHOR");
    std::cout << std::endl;
    std::cout << "" << std::endl;
    Function::changeConsoleColor();

    if (getLang() == pl) Function::write("\tRados³aw 'Doic' Michalak to m³ody pasjonat sztuki programowania i student AHE w £odzi.\n\n", 25);
    else Function::write("\tRados³aw 'Doic' Michalak is a young enthusiast of the art of programming and a student of\n\tAHE in £ódŸ.\n\n", 25);
   
    Sleep(1000);
    Function::pauseGame();
    Function::clearScreen();
    logo();
    mainMenu();
}

void Game::endGame()
{
    Logger::out("Function start", "Game::endGame");

    do
    {
        if (getLang() == pl)
        {
            Sleep(500);
            Function::clearScreen();
            std::cout << std::endl;
            Function::write("\tJesteœ pewien, ¿e chcesz wyjœæ z gry?", 25);
            std::cout << std::endl;
            Function::write("\t[1] Tak", 25);
            std::cout << std::endl;
            Function::write("\t[2] Nie", 25);
            std::cout << std::endl;
            Function::write("\t> ", 25);
        }
        else
        {
            Sleep(500);
            Function::clearScreen();
            std::cout << std::endl;
            Function::write("\tAre you sure you want to end the game?", 25);
            std::cout << std::endl;
            Function::write("\t[1] Yes", 25);
            std::cout << std::endl;
            Function::write("\t[2] No", 25);
            std::cout << std::endl;
            Function::write("\t> ", 25);
        }

        std::cin >> choice;

        switch (choice) {
        case 1:
            end();
            break;
        case 2:
            Function::clearScreen();
            Sleep(500); 
            logo();
            mainMenu();
            break;
        }
    } while (choice != 1 && choice != 2);
}

void Game::credits()
{
    Logger::out("Function start", "Game::credits");
    Function::write("\t\tAUTHOR\n\tRados³aw 'Doic' Michalak\n\n\t\tTESTERS\n\tPawe³ Michalak\n\n\t\tTHANKS\n\tDominik Szpilski\n\tDaniel Ob³¹k");
}

void Game::test()
{
    Logger::out("Function start", "Game::test");
}