#include "game.h"

Game::Game()
{
    menu = 0;
    choice = 0;
    gameLang = en;
    playing = true;
    ptrCurrentLocation = nullptr;
}

Game::~Game()
{   
}

void Game::selectLanguage()
{
    while (gameLang != 1 && gameLang != 2)
    {
        Function::clearScreen();
        cout << endl;
        Function::write("\t[1] EN", 25);
        cout << endl;
        Function::write("\t[2] PL", 25);
        cout << endl;
        Function::write("\tSelect your language: ", 25);
        cin >> gameLang;
    }

    Function::clearScreen();
    welcome();
}

void Game::welcome()
{
    cout << endl;
    Sleep(500); 

    if (getLang() == pl) Function::write("\tRADOS£AW 'DOIC' MICHALAK PREZENTUJE GRÊ TEKSTOW¥ POD TYTU£EM", 40);
    else Function::write("\tRADOS£AW 'DOIC' MICHALAK PRESENTS A TEXT GAME TITLED", 40);

    Sleep(2000);
    Function::clearScreen();
    writeLogo();
}

void Game::writeLogo()
{
    Function::changeConsoleColor(yellow);
    cout << "" << endl;
    Function::write("\t ======  ===    ===  =======   =======  =======   =======   ==     ==  ===    ==  ==    ==", 1);
    cout << endl;
    Function::write("\t=======   ===  ===   ==   ===  ==       ==   ===  ==   ===  ==     ==  ====   ==  ==   == ", 1);
    cout << endl;
    Function::write("\t==         ======    ==   ==   ==       ==   ==   ==   ==   ==     ==  =====  ==  ==  ==  ", 1);
    cout << endl;
    Function::write("\t==          ====     ======    =======  ======    ======    ==     ==  =========  =====   ", 1);
    cout << endl;
    Function::write("\t==           ==      ==   ==   ==       =====     =====     ===   ===  == ======  ==  ==  ", 1);
    cout << endl;
    Function::write("\t=======      ==      ==   ===  ==       ==  ==    ==         =======   ==   ====  ==   == ", 1);
    cout << endl;
    Function::write("\t ======      ==      =======   =======  ==   ===  ==          =====    ==    ===  ==    ==", 1);
    cout << endl;
    cout << "" << endl;
    Function::changeConsoleColor();
    Function::write("\t\t\t\t\t\t\t\t\tDemo Build", 2);
    cout << endl;
    cout << "" << endl;
    mainMenu();
}

void Game::logo()
{
    Function::changeConsoleColor(yellow);
    cout << "" << endl;
    cout << "\t ======  ===    ===  =======   =======  =======   =======   ==     ==  ===    ==  ==    ==" << endl;
    cout << "\t=======   ===  ===   ==   ===  ==       ==   ===  ==   ===  ==     ==  ====   ==  ==   == " << endl;
    cout << "\t==         ======    ==   ==   ==       ==   ==   ==   ==   ==     ==  =====  ==  ==  ==  " << endl;
    cout << "\t==          ====     ======    =======  ======    ======    ==     ==  =========  =====   " << endl;
    cout << "\t==           ==      ==   ==   ==       =====     =====     ===   ===  == ======  ==  ==  " << endl;
    cout << "\t=======      ==      ==   ===  ==       ==  ==    ==         =======   ==   ====  ==   == " << endl;
    cout << "\t ======      ==      =======   =======  ==   ===  ==          =====    ==    ===  ==    ==" << endl;
    cout << "" << endl;
    Function::changeConsoleColor();
    cout << "\t\t\t\t\t\t\t\t\tDemo Build" << endl;
    cout << "" << endl;
    mainMenu();
}

void Game::mainMenu()
{
    Function::changeConsoleColor();
    cout << "" << endl;

    if (getLang() == pl)
    {
        Function::write("\t[1] Nowa gra", 25);
        cout << endl;
        Function::write("\t[2] Kontynuuj grê", 25);
        cout << endl;
        Function::write("\t[3] O autorze", 25);
        cout << endl;
        Function::write("\t[4] WyjdŸ z gry", 25);
        cout << endl;
        Function::write("\t> ", 25);
    }
    else
    {
        Function::write("\t[1] New game", 25);
        cout << endl;
        Function::write("\t[2] Continue game", 25);
        cout << endl;
        Function::write("\t[3] About author", 25);
        cout << endl;
        Function::write("\t[4] Quit game", 25);
        cout << endl;
        Function::write("\t> ", 25);
    }

    do
    {
        cin >> menu;
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
    Event::initAll();
    Function::clearScreen();
    //setCurrentLocation(DarkAlley);
    Event::darkAlley();
}

void Game::continueGame()
{
    Sleep(500);
    Function::clearScreen();
    cout << endl;
    Function::changeConsoleColor(lightblue);

    if (getLang() == pl) Function::write("\tNic tu nie ma. Ta funkcja jest obecnie niedostêpna.", 25);
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
    Sleep(500);
    Function::clearScreen();
    cout << endl;
    Function::changeConsoleColor(lightblue);
    Function::write("\t\t\t\t\tAUTHOR");
    cout << endl;
    cout << "" << endl;
    Function::changeConsoleColor();

    if (getLang() == pl) Function::write("\tRados³aw 'Doic' Michalak to m³ody pasjonat sztuki programowania i student AHE w £odzi.", 25);
    else Function::write("\tRados³aw 'Doic' Michalak is a young enthusiast of the art of programming and a student of\n\tAHE in £ódŸ.\n\n", 25);
   
    Sleep(1000);
    Function::pauseGame();
    Function::clearScreen();
    logo();
    mainMenu();
}

void Game::endGame()
{
    do
    {
        if (getLang() == pl)
        {
            Sleep(500);
            Function::clearScreen();
            cout << endl;
            Function::write("\tJesteœ pewien, ¿e chcesz wyjœæ z gry?", 25);
            cout << endl;
            Function::write("\t[1] Tak", 25);
            cout << endl;
            Function::write("\t[2] Nie", 25);
            cout << endl;
            Function::write("\t> ", 25);
        }
        else
        {
            Sleep(500);
            Function::clearScreen();
            cout << endl;
            Function::write("\tAre you sure you want to end the game?", 25);
            cout << endl;
            Function::write("\t[1] Yes", 25);
            cout << endl;
            Function::write("\t[2] No", 25);
            cout << endl;
            Function::write("\t> ", 25);
        }

        cin >> choice;

        switch (choice) {
        case 1:
            playing = false;
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
    Function::write("\t\tAUTHOR\n\tRados³aw 'Doic' Michalak\n\n\t\tTESTERS\n\tPawe³ Michalak\n\n\t\tTHANKS\n\tDominik Szpilski\n\tDaniel Ob³¹k");
}

void Game::setCurrentLocation(Location* location)
{
    ptrCurrentLocation = location;
}

Location* Game::getCurrentLocation()
{
    return ptrCurrentLocation;
}

void Game::test()
{
}