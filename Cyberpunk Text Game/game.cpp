#include "game.hpp"

std::map <int, Game> Game::game;

Game::Game()
{
    //Logger::out("Function starts", "Game::Game");
    this->menu = 0;
    this->choice = 0;
    this->gameLang = 0;
    this->playing = true;
    this->ptrCurrentLocation = nullptr;
}

Game::~Game()
{   
    //Logger::out("Function starts", "Game::~Game");
}

void Game::init()
{
    Logger::out("Function starts", "Game::init");
    Game Nocturnal;
    game[0] = Nocturnal;
}

void Game::initAll()
{
    Hero::initHero();

    if (game[0].getLang() == en)
    {
        Fraction::initFractions_EN();
        Npc::initNpcs_EN();
        Location::initLocations_EN();
        Item::initItems_EN();
        Weapon::initWeapons_EN();
        Clothes::initClothes_EN();
        Quest::initQuests_EN();
    }
    else {
        Fraction::initFractions_PL();
        Npc::initNpcs_PL();
        Location::initLocations_PL();
        Item::initItems_PL();
        Weapon::initWeapons_PL();
        Clothes::initClothes_PL();
        Quest::initQuests_PL();
    }

    initHeroEQ();
    initQuestsList();
}

void Game::run()
{
    Logger::out("Function starts", "Game::run");
    Console::nameGame("Nocturnal - Demo Build");
    Console::initSpecialChars("polish");

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
    Logger::out("Function starts", "Game::selectLanguage");
    Console::changeConsoleColor();

    while (getLang() != en && getLang() != pl)
    {
        Console::clearScreen();
        Output::write("\n\tSelect your language:\n", 25);
        Decision::clearChoices();
        Decision::addChoice("EN");
        Decision::addChoice("PL");
        Decision::showChoices();
        gameLang = Input::getChoice();

        if (getLang() != en && getLang() != pl) Logger::error("Entered invalid value of <b>gameLang</b>", "Game::selectLanguage");
        else if (getLang() == en) Logger::out("Set English as game language", "Game::selectLanguage");
        else if (getLang() == pl) Logger::out("Set Polish as game language", "Game::selectLanguage");
    }

    Decision::clearChoices();
    Console::clearScreen();
}

void Game::welcome()
{
    Logger::out("Function starts", "Game::welcome");
    Sleep(500); 

    if (getLang() == pl) Output::write("\n\tRADOS£AW 'DOIC' MICHALAK PREZENTUJE GRÊ TEKSTOW¥ POD TYTU£EM", 40);
    else Output::write("\n\tRADOS£AW 'DOIC' MICHALAK PRESENTS A TEXT GAME TITLED", 40);

    Sleep(2000);
    Console::clearScreen();
}

void Game::writeLogo()
{
    Logger::out("Function starts", "Game::writeLogo");
    Console::changeConsoleColor(lightblue);
    Output::write("\n\t ****     **   *******     ******  ********** **     ** *******   ****     **     **     **      ", 1);
    Output::write("\n\t/**/**   /**  **/////**   **////**/////**/// /**    /**/**////** /**/**   /**    ****   /**      ", 1);
    Output::write("\n\t/**//**  /** **     //** **    //     /**    /**    /**/**   /** /**//**  /**   **//**  /**      ", 1);
    Output::write("\n\t/** //** /**/**      /**/**           /**    /**    /**/*******  /** //** /**  **  //** /**      ", 1);
    Output::write("\n\t/**  //**/**/**      /**/**           /**    /**    /**/**///**  /**  //**/** **********/**      ", 1);
    Output::write("\n\t/**   //****//**     ** //**    **    /**    /**    /**/**  //** /**   //****/**//////**/**      ", 1);
    Output::write("\n\t/**    //*** //*******   //******     /**    //******* /**   //**/**    //***/**     /**/********", 1);
    Output::write("\n\t//      ///   ///////     //////      //      ///////  //     // //      /// //      // //////// ", 1);
    Console::changeConsoleColor();

    if (getLang() == en) Output::write("\n\n\t\t\t\t\t     A Cyberpunk Text Game\n\n", 2);
    else Output::write("\n\n\t\t\t\t\t     Cyberpunkowa gra tekstowa\n\n", 2);
}

void Game::logo()
{
    Logger::out("Function starts", "Game::logo");
    Console::changeConsoleColor(lightblue);
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
    Console::changeConsoleColor();

    if (getLang() == en) std::cout << "\n\t\t\t\t\t     A Cyberpunk Text Game\n\n" << std::endl;
    else std::cout << "\n\t\t\t\t\t     Cyberpunkowa gra tekstowa\n\n" << std::endl;

    mainMenu();
}

void Game::mainMenu()
{
    Logger::out("Function starts", "Game::mainMenu");
    Console::changeConsoleColor();
    std::cout << std::endl;

    if (getLang() == pl)
    {
        Decision::clearChoices();
        Decision::addChoice("Nowa gra");
        Decision::addChoice("Kontynuuj grê");
        Decision::addChoice("Zmieñ jêzyk");
        Decision::addChoice("Napisy");
        Decision::addChoice("WyjdŸ z gry");
        Decision::showChoices();
    }
    else
    {
        Decision::clearChoices();
        Decision::addChoice("New game");
        Decision::addChoice("Continue game");
        Decision::addChoice("Change language");
        Decision::addChoice("Credits");
        Decision::addChoice("Quit game");
        Decision::showChoices();
    }

    do
    {
        menu = Input::getChoice();

        switch (menu) {
        case 1:
            Decision::clearChoices();
            newGame();
            break;
        case 2:
            Decision::clearChoices();
            continueGame();
            break;
        case 3:
            Decision::clearChoices();
            changeLanguage();
            break;
        case 4:
            Decision::clearChoices();
            credits();
            break;
        case 5:
            Decision::clearChoices();
            endGame();
            break;
        }
    } while (menu > 5 || menu <= 0);
}

void Game::newGame()
{
    Logger::out("Function starts", "Game::newGame");
    initAll();
    Console::clearScreen();
    setCurrentLocation(&Location::locations["DarkAlley"]);
}

void Game::continueGame()
{
    Logger::out("Function starts", "Game::continueGame");
    Sleep(500);
    Console::clearScreen();
    Console::changeConsoleColor(lightblue);

    if (getLang() == pl) Output::write("\n\tNic tu nie ma. Ta funkcja jest obecnie niedostêpna.\n\n", 25);
    else Output::write("\n\tThere's nothing here. This feature is currently unavailable.\n\n", 25);

    Console::changeConsoleColor();
    Sleep(1000);
    pause();
    Console::clearScreen();
    logo();
    mainMenu();
}

void Game::changeLanguage()
{
    Logger::out("Function starts", "Game::changeLanguage");

    int change = 0;

    while (change != en && change != pl)
    {
        Console::clearScreen();

        if (getLang() == en) Output::write("\n\tSelect your language:\n", 25);
        else if (getLang() == pl) Output::write("\n\tWybierz swój jêzyk:\n", 25);

        Decision::clearChoices();
        Decision::addChoice("EN");
        Decision::addChoice("PL");
        Decision::showChoices();
        change = Input::getChoice();

        if (change != en && change != pl) Logger::error("Entered invalid value of <b>gameLang</b>", "Game::changeLanguage");
    }

    this->gameLang = change;

    if (getLang() == en) Logger::out("Set English as game language", "Game::changeLanguage");
    else if (getLang() == pl) Logger::out("Set Polish as game language", "Game::changeLanguage");

    Decision::clearChoices();
    Console::clearScreen();
    logo();
    mainMenu();
}

void Game::endGame()
{
    Logger::out("Function starts", "Game::endGame");

    do
    {
        if (getLang() == pl)
        {
            Sleep(500);
            Console::clearScreen();
            Output::write("\n\tJesteœ pewien, ¿e chcesz wyjœæ z gry?\n", 25);

            Decision::clearChoices();
            Decision::addChoice("Tak");
            Decision::addChoice("Nie");
            Decision::showChoices();
        }
        else
        {
            Sleep(500);
            Console::clearScreen();
            Output::write("\n\tAre you sure you want to end the game?\n", 25);

            Decision::clearChoices();
            Decision::addChoice("Yes");
            Decision::addChoice("No");
            Decision::showChoices();
        }

        choice = Input::getChoice();

        switch (choice) {
        case 1:
            Decision::clearChoices();
            end();
            break;
        case 2:
            Decision::clearChoices();
            Console::clearScreen();
            Sleep(500); 
            logo();
            mainMenu();
            break;
        }
    } while (choice != 1 && choice != 2);
}

void Game::credits()
{
    Logger::out("Function starts", "Game::credits");
    Sleep(500);
    Console::clearScreen();

    if (getLang() == pl)
    {
        Console::changeConsoleColor(lightblue);
        Output::write("\n\t\tAUTOR\n");
        Console::changeConsoleColor();
        Output::write("\tRados³aw 'Doic' Michalak\n\n");
        Console::changeConsoleColor(lightblue);
        Output::write("\t       TESTERZY\n");
        Console::changeConsoleColor();
        Output::write("\t    Pawe³ Michalak\n\n");
        Console::changeConsoleColor(lightblue);
        Output::write("\t     PODZIÊKOWANIA\n");
        Console::changeConsoleColor();
        Output::write("\t   Dominik Szpilski\n\t     Daniel Ob³¹k\n\n");
    }
    else
    {
        Console::changeConsoleColor(lightblue);
        Output::write("\n\t\tAUTHOR\n");
        Console::changeConsoleColor();
        Output::write("\tRados³aw 'Doic' Michalak\n\n");
        Console::changeConsoleColor(lightblue);
        Output::write("\t\tTESTERS\n");
        Console::changeConsoleColor();
        Output::write("\t   Pawe³ Michalak\n\n");
        Console::changeConsoleColor(lightblue);
        Output::write("\t\tTHANKS\n");
        Console::changeConsoleColor();
        Output::write("\t   Dominik Szpilski\n\t     Daniel Ob³¹k\n\n");
    }

    Sleep(1000);
    pause();
    Console::clearScreen();
    logo();
    mainMenu();
}

void Game::test()
{
    Logger::out("Function starts", "Game::test");
}

void Game::setCurrentLocation(Location* location)
{
    this->ptrCurrentLocation = location;
    Logger::out("Set <b>" + getCurrentLocation()->getName() + "</b> as current location", "Game::setCurrentLocation");
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
    Logger::out("Function starts", "Function::initHeroEQ");
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
    Logger::out("Function starts", "Function::initQuestsList");
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

    Console::waitForUserInput();
}

