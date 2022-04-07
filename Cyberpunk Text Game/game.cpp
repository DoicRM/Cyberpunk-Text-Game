#include "game.h"

std::map <int, Game> Game::game;

Game::Game()
{
    //Logger::out("Function start", "Game::Game");
    this->menu = 0;
    this->choice = 0;
    this->gameLang = 0;
    this->playing = true;
    this->ptrCurrentLocation = nullptr;
}

Game::~Game()
{   
    //Logger::out("Function start", "Game::~Game");
}

void Game::init()
{
    Logger::out("Function start", "Game::init");
    Game Nocturnal;
    game[0] = Nocturnal;
}

void Game::initAll()
{
    Fraction::initFractions();
    Hero::initHero();
    Npc::initNpcs();
    Location::initLocations();
    Item::initItems();
    Weapon::initWeapons();
    Clothes::initClothes();
    Quest::initQuests();
    initHeroEQ();
    initQuestsList();
}

void Game::run()
{
    Logger::out("Function start", "Game::run");
    Function::nameGame("Nocturnal - Demo Build");
    Function::initSpecialChars("polish");

    while (getPlaying())
    {
        selectLanguage();
        welcome();
        writeLogo();
        mainMenu();
        end();
    }
}

void Game::selectLanguage()
{
    Logger::out("Function start", "Game::selectLanguage");
    Function::changeConsoleColor();

    while (getLang() != en && getLang() != pl)
    {
        Function::clearScreen();
        Function::write("\n\tSelect your language:\n", 25);
        Function::clearChoices();
        Function::addChoice("EN");
        Function::addChoice("PL");
        Function::showChoices();
        std::cin >> gameLang;

        if (getLang() != en && getLang() != pl) Logger::error("Invalid value of 'gameLang'", "Game::selectLanguage");
        else if (getLang() == en) Logger::out("Game language is English", "Game::selectLanguage");
        else if (getLang() == pl) Logger::out("Game language is Polish", "Game::selectLanguage");
    }

    Function::clearChoices();
    Function::clearScreen();
}

void Game::welcome()
{
    Logger::out("Function start", "Game::welcome");
    Sleep(500); 

    if (getLang() == pl) Function::write("\n\tRADOS£AW 'DOIC' MICHALAK PREZENTUJE GRÊ TEKSTOW¥ POD TYTU£EM", 40);
    else Function::write("\n\tRADOS£AW 'DOIC' MICHALAK PRESENTS A TEXT GAME TITLED", 40);

    Sleep(2000);
    Function::clearScreen();
}

void Game::writeLogo()
{
    Logger::out("Function start", "Game::writeLogo");
    Function::changeConsoleColor(lightblue);
    Function::write("\n\t ****     **   *******     ******  ********** **     ** *******   ****     **     **     **      ", 1);
    Function::write("\n\t/**/**   /**  **/////**   **////**/////**/// /**    /**/**////** /**/**   /**    ****   /**      ", 1);
    Function::write("\n\t/**//**  /** **     //** **    //     /**    /**    /**/**   /** /**//**  /**   **//**  /**      ", 1);
    Function::write("\n\t/** //** /**/**      /**/**           /**    /**    /**/*******  /** //** /**  **  //** /**      ", 1);
    Function::write("\n\t/**  //**/**/**      /**/**           /**    /**    /**/**///**  /**  //**/** **********/**      ", 1);
    Function::write("\n\t/**   //****//**     ** //**    **    /**    /**    /**/**  //** /**   //****/**//////**/**      ", 1);
    Function::write("\n\t/**    //*** //*******   //******     /**    //******* /**   //**/**    //***/**     /**/********", 1);
    Function::write("\n\t//      ///   ///////     //////      //      ///////  //     // //      /// //      // //////// ", 1);
    Function::changeConsoleColor();
    Function::write("\n\n\t\t\t\t\t     A Cyberpunk Text Game\n\n", 2);
}

void Game::logo()
{
    Logger::out("Function start", "Game::logo");
    Function::changeConsoleColor(lightblue);
    std::cout << std::endl;
    std::cout << "\t ****     **   *******     ******  ********** **     ** *******   ****     **     **     **      " << std::endl;
    std::cout << "\t/**/**   /**  **/////**   **////**/////**/// /**    /**/**////** /**/**   /**    ****   /**      " << std::endl;
    std::cout << "\t/**//**  /** **     //** **    //     /**    /**    /**/**   /** /**//**  /**   **//**  /**      " << std::endl;
    std::cout << "\t/** //** /**/**      /**/**           /**    /**    /**/*******  /** //** /**  **  //** /**      " << std::endl;
    std::cout << "\t/**  //**/**/**      /**/**           /**    /**    /**/**///**  /**  //**/** **********/**      " << std::endl;
    std::cout << "\t/**   //****//**     ** //**    **    /**    /**    /**/**  //** /**   //****/**//////**/**      " << std::endl;
    std::cout << "\t/**    //*** //*******   //******     /**    //******* /**   //**/**    //***/**     /**/********" << std::endl;
    std::cout << "\t//      ///   ///////     //////      //      ///////  //     // //      /// //      // //////// " << std::endl;
    std::cout << std::endl;
    Function::changeConsoleColor();
    std::cout << "\n\t\t\t\t\t     A Cyberpunk Text Game\n\n" << std::endl;
    mainMenu();
}

void Game::mainMenu()
{
    Logger::out("Function start", "Game::mainMenu");
    Function::changeConsoleColor();
    std::cout << std::endl;

    if (getLang() == pl)
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
        std::cin >> menu;

        switch (menu) {
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
    } while (menu > 5 || menu <= 0);
}

void Game::newGame()
{
    Logger::out("Function start", "Game::newGame");
    initAll();
    Function::clearScreen();
    setCurrentLocation(&Location::locations["DarkAlley"]);
}

void Game::continueGame()
{
    Logger::out("Function start", "Game::continueGame");
    Sleep(500);
    Function::clearScreen();
    Function::changeConsoleColor(lightblue);

    if (getLang() == pl) Function::write("\n\tNic tu nie ma. Ta funkcja jest obecnie niedostêpna.\n\n", 25);
    else Function::write("\n\tThere's nothing here. This feature is currently unavailable.\n\n", 25);

    Function::changeConsoleColor();
    Sleep(1000);
    pause();
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

        if (getLang() == en) Function::write("\n\tSelect your language:\n", 25);
        else if (getLang() == pl) Function::write("\n\tWybierz swój jêzyk:\n", 25);

        Function::clearChoices();
        Function::addChoice("EN");
        Function::addChoice("PL");
        Function::showChoices();
        std::cin >> change;

        if (change != en && change != pl) Logger::error("Invalid value of 'gameLang'", "Game::changeLanguage");
    }

    this->gameLang = change;

    if (getLang() == en) Logger::out("Game language is English", "Game::changeLanguage");
    else if (getLang() == pl) Logger::out("Game language is Polish", "Game::changeLanguage");

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
        if (getLang() == pl)
        {
            Sleep(500);
            Function::clearScreen();
            Function::write("\n\tJesteœ pewien, ¿e chcesz wyjœæ z gry?\n", 25);

            Function::clearChoices();
            Function::addChoice("Tak");
            Function::addChoice("Nie");
            Function::showChoices();
        }
        else
        {
            Sleep(500);
            Function::clearScreen();
            Function::write("\n\tAre you sure you want to end the game?\n", 25);

            Function::clearChoices();
            Function::addChoice("Yes");
            Function::addChoice("No");
            Function::showChoices();
        }

        std::cin >> choice;

        switch (choice) {
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
    } while (choice != 1 && choice != 2);
}

void Game::credits()
{
    Logger::out("Function start", "Game::credits");
    Sleep(500);
    Function::clearScreen();

    if (getLang() == pl)
    {
        Function::changeConsoleColor(lightblue);
        Function::write("\n\t\tAUTOR\n");
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
        Function::write("\n\t\tAUTHOR\n");
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
    pause();
    Function::clearScreen();
    logo();
    mainMenu();
}

void Game::test()
{
    Logger::out("Function start", "Game::test");
}

void Game::setCurrentLocation(Location* location)
{
    this->ptrCurrentLocation = location;
    Logger::out("Actual location is " + getCurrentLocation()->getName(), "Game::setCurrentLocation");
    startEventsByLocation();
}

void Game::startEventsByLocation()
{
    if (getCurrentLocation() == &Location::locations["DarkAlley"]) Event::darkAlley();
    else if (getCurrentLocation() == &Location::locations["Street"]) Event::street();
    else if (getCurrentLocation() == &Location::locations["Nightclub"]) Event::nightclub();
    else if (getCurrentLocation() == &Location::locations["GunShop"]) Event::gunShop();
}

// Inicjowanie ekwipunku gracza
void Game::initHeroEQ()
{
    Logger::out("Function start", "Function::initHeroEQ");
    std::fstream eq;
    eq.open("eq.txt", std::ios::out);

    if (eq.good())
    {
        Logger::out("Access to txt file", "Function::initHeroEQ");

        if (Game::game[0].getLang() == en) eq << "                                    ITEMS                                  " << std::endl;
        else if (Game::game[0].getLang() == pl) eq << "                               PRZEDMIOTY                                  " << std::endl;

        eq << "..........................................................................." << std::endl;
        eq.close();
    }
    else Logger::error("No file access", "Function::initHeroEQ");
}

// Inicjowanie listy zadañ
void Game::initQuestsList()
{
    Logger::out("Function start", "Function::initQuestsList");
    std::fstream q;
    q.open("quests.txt", std::ios::out);

    if (q.good())
    {
        Logger::out("Access to txt file", "Function::initQuestsList");

        if (Game::game[0].getLang() == en) q << "                                    QUESTS                                 " << std::endl;
        else if (Game::game[0].getLang() == pl) q << "                                   ZADANIA                                 " << std::endl;

        q << "..........................................................................." << std::endl;
        q.close();
    }
    else Logger::error("No file access", "Function::initQuestsList");
}

void Game::pause()
{
    if (Game::game[0].getLang() == en) std::cout << "\tPress ANY KEY to continue...";
    else if (Game::game[0].getLang() == pl) std::cout << "\tWciœnij DOWOLNY PRZYCISK, aby kontynuowaæ...";

    Function::waitForUserInput();
}

