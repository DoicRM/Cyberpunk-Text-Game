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
    while (gameLang != 1 && gameLang != 2)
    {
        Function::clearScreen();
        cout << endl;
        Function::write("  [1] EN", 25);
        cout << endl;
        Function::write("  [2] PL", 25);
        cout << endl;
        Function::write("  Select your language: ", 25);
        cin >> gameLang;
    }

    Function::clearScreen();
    welcome(); // Powitanie
}

void Game::welcome()
{
    cout << endl;
    Sleep(500); 

    if (getLang() == pl) Function::write("  RADOS£AW 'DOIC' MICHALAK PREZENTUJE GRÊ TEKSTOW¥ POD TYTU£EM", 40);
    else Function::write("  RADOS£AW 'DOIC' MICHALAK PRESENTS A TEXT GAME TITLED", 40);

    Sleep(2000);
    Function::clearScreen();
    writeLogo(); // Logo
}

void Game::writeLogo()
{
    Function::changeConsoleColor(yellow);
    cout << "" << endl;
    Function::write("   ======  ===    ===  =======   =======  =======   =======   ==     ==  ===    ==  ==     ==  ", 1);
    cout << endl;
    Function::write("  =======   ===  ===   ==   ===  ==       ==   ===  ==   ===  ==     ==  ====   ==  ==    ==   ", 1);
    cout << endl;
    Function::write("  ==         ======    ==   ==   ==       ==   ==   ==   ==   ==     ==  =====  ==  ==  ===    ", 1);
    cout << endl;
    Function::write("  ==          ====     ======    =======  ======    ======    ==     ==  =========  =====      ", 1);
    cout << endl;
    Function::write("  ==           ==      ==   ==   ==       =====     =====     ===   ===  == ======  ==  ===    ", 1);
    cout << endl;
    Function::write("  =======      ==      ==   ===  ==       ==  ==    ==         =======   ==   ====  ==   ==    ", 1);
    cout << endl;
    Function::write("    =====      ==      =======   =======  ==   ===  ==          =====    ==    ===  ==    ==   ", 1);
    cout << endl;
    cout << "" << endl;
    Function::changeConsoleColor();
    Function::write("                                                                      Demo Build", 2);
    cout << "" << endl;
    mainMenu(); // Menu g³ówne
}

void Game::logo()
{
    Function::changeConsoleColor(yellow);
    cout << "" << endl;
    cout << "   ======  ===    ===  =======   =======  =======   =======   ==     ==  ===    ==  ==     ==  " << endl;
    cout << "  =======   ===  ===   ==   ===  ==       ==   ===  ==   ===  ==     ==  ====   ==  ==    ==   " << endl;
    cout << "  ==         ======    ==   ==   ==       ==   ==   ==   ==   ==     ==  =====  ==  ==  ===    " << endl;
    cout << "  ==          ====     ======    =======  ======    ======    ==     ==  =========  =====      " << endl;
    cout << "  ==           ==      ==   ==   ==       =====     =====     ===   ===  == ======  ==  ===    " << endl;
    cout << "  =======      ==      ==   ===  ==       ==  ==    ==         =======   ==   ====  ==   ==    " << endl;
    cout << "   ======      ==      =======   =======  ==   ===  ==          =====    ==    ===  ==    ==   " << endl;
    cout << "" << endl;
    Function::changeConsoleColor();
    cout << "                                                                      Demo Build" << endl;
    cout << "" << endl;
    mainMenu(); // Menu g³ówne
}

void Game::mainMenu()
{
    Function::changeConsoleColor();
    cout << "" << endl;

    if (getLang() == pl)
    {
        Function::write("  [1] Nowa gra", 25);
        cout << endl;
        Function::write("  [2] Kontynuuj grê", 25);
        cout << endl;
        Function::write("  [3] O autorze", 25);
        cout << endl;
        Function::write("  [4] WyjdŸ z gry", 25);
        cout << endl;
        Function::write("  > ", 25);
    }
    else
    {
        Function::write("  [1] New game", 25);
        cout << endl;
        Function::write("  [2] Continue game", 25);
        cout << endl;
        Function::write("  [3] About author", 25);
        cout << endl;
        Function::write("  [4] Quit game", 25);
        cout << endl;
        Function::write("  > ", 25);
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
    } while (choice != 1 && choice != 2 && choice != 3 && choice != 4);
}

void Game::newGame()
{
    Event::initAll();
    Function::clearScreen();

    //ptrCurrentLocation = DarkAlley;

    Event::prologue();
    Event::storyIntroduction();
    Event::scene001();
}

void Game::continueGame()
{
    Sleep(500);
    Function::clearScreen();
    cout << endl;
    Function::changeConsoleColor(lightblue);

    if (getLang() == pl) Function::write("  Nic tu nie ma. Ta funkcja jest obecnie niedostêpna.", 25);
    else Function::write("  There's nothing here. This feature is currently unavailable.", 25);

    Sleep(1000);
    Function::waitForUserInput();
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
    Function::write("                                         AUTHOR");
    cout << endl;
    cout << "" << endl;
    Function::changeConsoleColor();

    if (getLang() == pl) Function::write("  Rados³aw 'Doic' Michalak jest m³odym programist¹ i studentem AHE w £odzi. To naprawdê fajny goœæ, mówiê ci!", 25);
    else Function::write("  Rados³aw 'Doic' Michalak is a young programmer and a student at AHE in £ódŸ. He's a really cool guy, I tell you!", 25);
   
    Sleep(1000);
    Function::waitForUserInput();
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
            Function::write("  Jesteœ pewien, ¿e chcesz wyjœæ z gry?", 25);
            cout << endl;
            Function::write("  [1] Tak", 25);
            cout << endl;
            Function::write("  [2] Nie", 25);
            cout << endl;
            Function::write("  > ", 25);
        }
        else
        {
            Sleep(500);
            Function::clearScreen();
            cout << endl;
            Function::write("  Are you sure you want to end the game?", 25);
            cout << endl;
            Function::write("  [1] Yes", 25);
            cout << endl;
            Function::write("  [2] No", 25);
            cout << endl;
            Function::write("  > ", 25);
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
