#include "game.h"

Game::Game()
{
    Logger::out("Function start", "Game::Game");
    this->menu = 0;
    this->choice = 0;
    this->gameLang = 0;
    this->playing = true;
    this->ptrCurrentLocation = nullptr;
}

Game::~Game()
{   
    Logger::out("Function start", "Game::~Game");
}

void Game::run()
{
    Logger::out("Function start", "Game::run");
    Function::nameGame("Nocturnal - v.1.0");
    Function::initSpecialChars("polish");

    while (this->getPlaying())
    {
        selectLanguage();
        welcome();
        writeLogo();
        mainMenu();
        end();
    }
}

void Game::init()
{
    Logger::out("Function start", "Game::init");
    Fraction::initFractions();
    Hero::initHero();
    Npc::initNpcs();
    Location::initLocations();
    Item::initItems();
    Weapon::initWeapons();
    Clothes::initClothes();
    Quest::initQuests();
    Function::initHeroEQ();
    Function::initQuestsList();
}

void Game::selectLanguage()
{
    Logger::out("Function start", "Game::selectLanguage");
    Function::changeConsoleColor();

    while (this->gameLang != en && this->gameLang != pl)
    {
        Function::clearScreen();
        std::cout << std::endl;
        Function::write("\tSelect your language: ", 25);
        std::cout << std::endl;
        Function::clearChoices();
        Function::addChoice("EN");
        Function::addChoice("PL");
        Function::showChoices();
        std::cin >> this->gameLang;

        if (this->gameLang != en && this->gameLang != pl) Logger::error("Invalid value of 'gameLang'", "Game::selectLanguage");
        else if (getLang() == en) Logger::out("Game language is English", "Game::selectLanguage");
        else if (getLang() == pl) Logger::out("Game language is Polish", "Game::selectLanguage");
    }

    Function::clearChoices();
    Function::clearScreen();
}

void Game::welcome()
{
    Logger::out("Function start", "Game::welcome");
    std::cout << std::endl;
    Sleep(500); 

    if (this->getLang() == pl) Function::write("\tRADOS£AW 'DOIC' MICHALAK PREZENTUJE GRÊ TEKSTOW¥ POD TYTU£EM", 40);
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

    if (this->getLang() == pl)
    {
        Function::clearChoices();
        Function::addChoice("Nowa gra");
        Function::addChoice("Kontynuuj grê");
        Function::addChoice("Zmieñ jêzyk");
        Function::addChoice("Napisy");
        Function::addChoice("WyjdŸ z gry");
        Function::showChoices();
    }
    else
    {
        Function::clearChoices();
        Function::addChoice("New game");
        Function::addChoice("Continue game");
        Function::addChoice("Change language");
        Function::addChoice("Credits");
        Function::addChoice("Quit game");
        Function::showChoices();
    }

    do
    {
        std::cin >> this->menu;

        switch (this->menu) {
        case 1:
            Function::clearChoices();
            newGame();
            break;
        case 2:
            Function::clearChoices();
            continueGame();
            break;
        case 3:
            Function::clearChoices();
            changeLanguage();
            break;
        case 4:
            Function::clearChoices();
            credits();
            break;
        case 5:
            Function::clearChoices();
            endGame();
            break;
        }
    } while (this->menu > 5 || this->menu <= 0);
}

void Game::newGame()
{
    Logger::out("Function start", "Game::newGame");
    //Game* ptrGame = this;
    init();
    Function::clearScreen();
    setCurrentLocation(&Location::locations["DarkAlley"]);
    Event::darkAlley();
}

void Game::continueGame()
{
    Logger::out("Function start", "Game::continueGame");
    Sleep(500);
    Function::clearScreen();
    std::cout << std::endl;
    Function::changeConsoleColor(lightblue);

    if (this->getLang() == pl) Function::write("\tNic tu nie ma. Ta funkcja jest obecnie niedostêpna.\n\n", 25);
    else Function::write("\tThere's nothing here. This feature is currently unavailable.\n\n", 25);

    Function::changeConsoleColor();
    Sleep(1000);
    Function::pauseGame();
    Function::clearScreen();
    logo();
    mainMenu();
}

void Game::changeLanguage()
{
    Logger::out("Function start", "Game::changeLanguage");

    int change = 0;

    while (change != en && change != pl)
    {
        Function::clearScreen();
        std::cout << std::endl;

        if (this->getLang() == en) Function::write("\tSelect your language: ", 25);
        else if (this->getLang() == pl) Function::write("\tWybierz swój jêzyk: ", 25);

        std::cout << std::endl;
        Function::clearChoices();
        Function::addChoice("EN");
        Function::addChoice("PL");
        Function::showChoices();
        std::cin >> change;

        if (change != en && change != pl) Logger::error("Invalid value of 'gameLang'", "Game::changeLanguage");
    }

    this->gameLang = change;

    if (this->getLang() == en) Logger::out("Game language is English", "Game::changeLanguage");
    else if (this->getLang() == pl) Logger::out("Game language is Polish", "Game::changeLanguage");

    Function::clearChoices();
    Function::clearScreen();
    logo();
    mainMenu();
}

void Game::endGame()
{
    Logger::out("Function start", "Game::endGame");

    do
    {
        if (this->getLang() == pl)
        {
            Sleep(500);
            Function::clearScreen();
            std::cout << std::endl;
            Function::write("\tJesteœ pewien, ¿e chcesz wyjœæ z gry?", 25);
            std::cout << std::endl;
            Function::clearChoices();
            Function::addChoice("Tak");
            Function::addChoice("Nie");
            Function::showChoices();
        }
        else
        {
            Sleep(500);
            Function::clearScreen();
            std::cout << std::endl;
            Function::write("\tAre you sure you want to end the game?", 25);
            std::cout << std::endl;
            Function::clearChoices();
            Function::addChoice("Yes");
            Function::addChoice("No");
            Function::showChoices();
        }

        std::cin >> this->choice;

        switch (this->choice) {
        case 1:
            Function::clearChoices();
            end();
            break;
        case 2:
            Function::clearChoices();
            Function::clearScreen();
            Sleep(500); 
            logo();
            mainMenu();
            break;
        }
    } while (this->choice != 1 && this->choice != 2);
}

void Game::credits()
{
    Logger::out("Function start", "Game::credits");
    Sleep(500);
    Function::clearScreen();
    std::cout << std::endl;

    if (this->getLang() == pl)
    {
        Function::changeConsoleColor(lightblue);
        Function::write("\t\tAUTOR\n");
        Function::changeConsoleColor();
        Function::write("\tRados³aw 'Doic' Michalak\n\n");
        Function::changeConsoleColor(lightblue);
        Function::write("\t       TESTERZY\n");
        Function::changeConsoleColor();
        Function::write("\t    Pawe³ Michalak\n\n");
        Function::changeConsoleColor(lightblue);
        Function::write("\t     PODZIÊKOWANIA\n");
        Function::changeConsoleColor();
        Function::write("\t   Dominik Szpilski\n\t     Daniel Ob³¹k\n\n");
    }
    else
    {
        Function::changeConsoleColor(lightblue);
        Function::write("\t\tAUTHOR\n");
        Function::changeConsoleColor();
        Function::write("\tRados³aw 'Doic' Michalak\n\n");
        Function::changeConsoleColor(lightblue);
        Function::write("\t\tTESTERS\n");
        Function::changeConsoleColor();
        Function::write("\t   Pawe³ Michalak\n\n");
        Function::changeConsoleColor(lightblue);
        Function::write("\t\tTHANKS\n");
        Function::changeConsoleColor();
        Function::write("\t   Dominik Szpilski\n\t     Daniel Ob³¹k\n\n");
    }

    Sleep(1000);
    Function::pauseGame();
    Function::clearScreen();
    logo();
    mainMenu();
}

void Game::test()
{
    Logger::out("Function start", "Game::test");
}