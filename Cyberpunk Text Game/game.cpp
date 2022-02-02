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
        Function::write("\t[1] EN", 25);
        cout << endl;
        Function::write("\t[2] PL", 25);
        cout << endl;
        Function::write("\tSelect your language: ", 25);
        cin >> gameLang;
    }

    Function::clearScreen();
    welcome(); // Powitanie
}

void Game::welcome()
{
    cout << endl;
    Sleep(500); 

    if (getLang() == pl) Function::write("\tRADOS�AW 'DOIC' MICHALAK PREZENTUJE GR� TEKSTOW� POD TYTU�EM", 40);
    else Function::write("\tRADOS�AW 'DOIC' MICHALAK PRESENTS A TEXT GAME TITLED", 40);

    Sleep(2000);
    Function::clearScreen();
    writeLogo(); // Logo
}

void Game::writeLogo()
{
    Function::changeConsoleColor(yellow);
    cout << "" << endl;
    Function::write("\t ======  ===    ===  =======   =======  =======   =======   ==     ==  ===    ==  ==    ==  ", 1);
    cout << endl;
    Function::write("\t=======   ===  ===   ==   ===  ==       ==   ===  ==   ===  ==     ==  ====   ==  ==   ==   ", 1);
    cout << endl;
    Function::write("\t==         ======    ==   ==   ==       ==   ==   ==   ==   ==     ==  =====  ==  ==  ==    ", 1);
    cout << endl;
    Function::write("\t==          ====     ======    =======  ======    ======    ==     ==  =========  =====     ", 1);
    cout << endl;
    Function::write("\t==           ==      ==   ==   ==       =====     =====     ===   ===  == ======  ==  ==    ", 1);
    cout << endl;
    Function::write("\t=======      ==      ==   ===  ==       ==  ==    ==         =======   ==   ====  ==   ==   ", 1);
    cout << endl;
    Function::write("\t ======      ==      =======   =======  ==   ===  ==          =====    ==    ===  ==    ==  ", 1);
    cout << endl;
    cout << "" << endl;
    Function::changeConsoleColor();
    Function::write("\t\t\t\t\t\t\t\t\tDemo Build", 2);
    cout << endl;
    cout << "" << endl;
    mainMenu(); // Menu g��wne
}

void Game::logo()
{
    Function::changeConsoleColor(yellow);
    cout << "" << endl;
    cout << "\t ======  ===    ===  =======   =======  =======   =======   ==     ==  ===    ==  ==    ==  " << endl;
    cout << "\t=======   ===  ===   ==   ===  ==       ==   ===  ==   ===  ==     ==  ====   ==  ==   ==   " << endl;
    cout << "\t==         ======    ==   ==   ==       ==   ==   ==   ==   ==     ==  =====  ==  ==  ==    " << endl;
    cout << "\t==          ====     ======    =======  ======    ======    ==     ==  =========  =====     " << endl;
    cout << "\t==           ==      ==   ==   ==       =====     =====     ===   ===  == ======  ==  ==    " << endl;
    cout << "\t=======      ==      ==   ===  ==       ==  ==    ==         =======   ==   ====  ==   ==   " << endl;
    cout << "\t ======      ==      =======   =======  ==   ===  ==          =====    ==    ===  ==    ==  " << endl;
    cout << "" << endl;
    Function::changeConsoleColor();
    cout << "\t\t\t\t\t\t\t\t\tDemo Build" << endl;
    cout << "" << endl;
    mainMenu(); // Menu g��wne
}

void Game::mainMenu()
{
    Function::changeConsoleColor();
    cout << "" << endl;

    if (getLang() == pl)
    {
        Function::write("\t[1] Nowa gra", 25);
        cout << endl;
        Function::write("\t[2] Kontynuuj gr�", 25);
        cout << endl;
        Function::write("\t[3] O autorze", 25);
        cout << endl;
        Function::write("\t[4] Wyjd� z gry", 25);
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
    } while (choice != 1 && choice != 2 && choice != 3 && choice != 4);
}

void Game::newGame()
{
    Event::initAll();
    Function::clearScreen();

    //ptrCurrentLocation = DarkAlley;

    Event::DarkAlley();
}

void Game::continueGame()
{
    Sleep(500);
    Function::clearScreen();
    cout << endl;
    Function::changeConsoleColor(lightblue);

    if (getLang() == pl) Function::write("\tNic tu nie ma. Ta funkcja jest obecnie niedost�pna.", 25);
    else Function::write("\tThere's nothing here. This feature is currently unavailable.", 25);

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
    Function::write("\t\t\t\t\tAUTHOR");
    cout << endl;
    cout << "" << endl;
    Function::changeConsoleColor();

    if (getLang() == pl) Function::write("\tRados�aw 'Doic' Michalak jest m�odym programist� i studentem AHE w �odzi.\n\tTo naprawd� fajny go��, m�wi� ci!", 25);
    else Function::write("\tRados�aw 'Doic' Michalak is a young programmer and a student at AHE in ��d�.\n\tHe's a really cool guy, I tell you!", 25);
   
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
            Function::write("\tJeste� pewien, �e chcesz wyj�� z gry?", 25);
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
    Function::write("\t\tAUTHOR\n\tRados�aw 'Doic' Michalak\n\n\t\tTESTERS\n\tPawe� Michalak\n\n\t\tTHANKS\n\tDominik Szpilski\n\tDaniel Ob��k");
}