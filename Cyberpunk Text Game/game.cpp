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
    Logger::out("Function starts", "Game::selectLanguage");
    Function::changeConsoleColor();

    while (getLang() != en && getLang() != pl)
    {
        Function::clearScreen();
        Function::write("\n\tSelect your language:\n", 25);
        Function::clearChoices();
        Function::addChoice("EN");
        Function::addChoice("PL");
        Function::showChoices();
        gameLang = Function::getChoice();

        if (getLang() != en && getLang() != pl) Logger::error("Entered invalid value of <b>gameLang</b>", "Game::selectLanguage");
        else if (getLang() == en) Logger::out("Set English as game language", "Game::selectLanguage");
        else if (getLang() == pl) Logger::out("Set Polish as game language", "Game::selectLanguage");
    }

    Function::clearChoices();
    Function::clearScreen();
}

void Game::welcome()
{
    Logger::out("Function starts", "Game::welcome");
    Sleep(500); 

    if (getLang() == pl) Function::write("\n\tRADOS�AW 'DOIC' MICHALAK PREZENTUJE GR� TEKSTOW� POD TYTU�EM", 40);
    else Function::write("\n\tRADOS�AW 'DOIC' MICHALAK PRESENTS A TEXT GAME TITLED", 40);

    Sleep(2000);
    Function::clearScreen();
}

void Game::writeLogo()
{
    Logger::out("Function starts", "Game::writeLogo");
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

    if (getLang() == en) Function::write("\n\n\t\t\t\t\t     A Cyberpunk Text Game\n\n", 2);
    else Function::write("\n\n\t\t\t\t\t     Cyberpunkowa gra tekstowa\n\n", 2);
}

void Game::logo()
{
    Logger::out("Function starts", "Game::logo");
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

    if (getLang() == en) std::cout << "\n\t\t\t\t\t     A Cyberpunk Text Game\n\n" << std::endl;
    else std::cout << "\n\t\t\t\t\t     Cyberpunkowa gra tekstowa\n\n" << std::endl;

    mainMenu();
}

void Game::mainMenu()
{
    Logger::out("Function starts", "Game::mainMenu");
    Function::changeConsoleColor();
    std::cout << std::endl;

    if (getLang() == pl)
    {
        Function::clearChoices();
        Function::addChoice("Nowa gra");
        Function::addChoice("Kontynuuj gr�");
        Function::addChoice("Zmie� j�zyk");
        Function::addChoice("Napisy");
        Function::addChoice("Wyjd� z gry");
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
        menu = Function::getChoice();

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
    Logger::out("Function starts", "Game::newGame");
    initAll();
    Function::clearScreen();
    setCurrentLocation(&Location::locations["DarkAlley"]);
}

void Game::continueGame()
{
    Logger::out("Function starts", "Game::continueGame");
    Sleep(500);
    Function::clearScreen();
    Function::changeConsoleColor(lightblue);

    if (getLang() == pl) Function::write("\n\tNic tu nie ma. Ta funkcja jest obecnie niedost�pna.\n\n", 25);
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
    Logger::out("Function starts", "Game::changeLanguage");

    int change = 0;

    while (change != en && change != pl)
    {
        Function::clearScreen();

        if (getLang() == en) Function::write("\n\tSelect your language:\n", 25);
        else if (getLang() == pl) Function::write("\n\tWybierz sw�j j�zyk:\n", 25);

        Function::clearChoices();
        Function::addChoice("EN");
        Function::addChoice("PL");
        Function::showChoices();
        change = Function::getChoice();

        if (change != en && change != pl) Logger::error("Entered invalid value of <b>gameLang</b>", "Game::changeLanguage");
    }

    this->gameLang = change;

    if (getLang() == en) Logger::out("Set English as game language", "Game::changeLanguage");
    else if (getLang() == pl) Logger::out("Set Polish as game language", "Game::changeLanguage");

    Function::clearChoices();
    Function::clearScreen();
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
            Function::clearScreen();
            Function::write("\n\tJeste� pewien, �e chcesz wyj�� z gry?\n", 25);

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

        choice = Function::getChoice();

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
    Logger::out("Function starts", "Game::credits");
    Sleep(500);
    Function::clearScreen();

    if (getLang() == pl)
    {
        Function::changeConsoleColor(lightblue);
        Function::write("\n\t\tAUTOR\n");
        Function::changeConsoleColor();
        Function::write("\tRados�aw 'Doic' Michalak\n\n");
        Function::changeConsoleColor(lightblue);
        Function::write("\t       TESTERZY\n");
        Function::changeConsoleColor();
        Function::write("\t    Pawe� Michalak\n\n");
        Function::changeConsoleColor(lightblue);
        Function::write("\t     PODZI�KOWANIA\n");
        Function::changeConsoleColor();
        Function::write("\t   Dominik Szpilski\n\t     Daniel Ob��k\n\n");
    }
    else
    {
        Function::changeConsoleColor(lightblue);
        Function::write("\n\t\tAUTHOR\n");
        Function::changeConsoleColor();
        Function::write("\tRados�aw 'Doic' Michalak\n\n");
        Function::changeConsoleColor(lightblue);
        Function::write("\t\tTESTERS\n");
        Function::changeConsoleColor();
        Function::write("\t   Pawe� Michalak\n\n");
        Function::changeConsoleColor(lightblue);
        Function::write("\t\tTHANKS\n");
        Function::changeConsoleColor();
        Function::write("\t   Dominik Szpilski\n\t     Daniel Ob��k\n\n");
    }

    Sleep(1000);
    pause();
    Function::clearScreen();
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

// Inicjowanie listy zada�
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
    else if (Game::game[0].getLang() == pl) std::cout << "\tWci�nij DOWOLNY PRZYCISK, aby kontynuowa�...";

    Function::waitForUserInput();
}

