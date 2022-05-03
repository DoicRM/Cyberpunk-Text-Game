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
    Fraction::initFractions();
    Npc::initNpcs();
    Location::initLocations();
    Quest::initQuests();
    Item::initItems();
    Weapon::initWeapons();
    Clothes::initClothes();
    initHeroEQ();
    initQuestsList();
}

void Game::run()
{
    Logger::out("Function starts", "Game::run");

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
    Console::resetConsoleColor();
    Menu langMenu;

    while (getLang() != EN && getLang() != PL)
    {
        Console::clearScreen();
        std::cout << std::endl;
        //--------------------------------
        langMenu.addOptions({ "EN", "PL" });
        langMenu.showOptions();
        //--------------------------------
        this->gameLang = langMenu.inputChoice();

        if (getLang() != EN && getLang() != PL) Logger::error("Entered invalid value of <b>gameLang</b>", "Game::selectLanguage");
        else if (getLang() == EN) Logger::out("Set English as game language", "Game::selectLanguage");
        else if (getLang() == PL) Logger::out("Set Polish as game language", "Game::selectLanguage");
    }

    JSON::loadFile(getLang());
    Console::clearScreen();
}

void Game::welcome()
{
    Logger::out("Function starts", "Game::welcome");
    Sleep(500); 
    Display::write(jWriter["Infos"].value("Welcome", ""), 40);
    Sleep(2000);
    Console::clearScreen();
}

std::array<std::string, 8> Game::logo = {
    "\t ****     **   *******     ******  ********** **     ** *******   ****     **     **     **      \n",
    "\t/**/**   /**  **/////**   **////**/////**/// /**    /**/**////** /**/**   /**    ****   /**      \n",
    "\t/**//**  /** **     //** **    //     /**    /**    /**/**   /** /**//**  /**   **//**  /**      \n",
    "\t/** //** /**/**      /**/**           /**    /**    /**/*******  /** //** /**  **  //** /**      \n",
    "\t/**  //**/**/**      /**/**           /**    /**    /**/**///**  /**  //**/** **********/**      \n",
    "\t/**   //****//**     ** //**    **    /**    /**    /**/**  //** /**   //****/**//////**/**      \n",
    "\t/**    //*** //*******   //******     /**    //******* /**   //**/**    //***/**     /**/********\n",
    "\t//      ///   ///////     //////      //      ///////  //     // //      /// //      // //////// "
};

void Game::writeLogo()
{
    Logger::out("Function starts", "Game::writeLogo");
    Console::setConsoleColor(CC_Lightblue);
    std::cout << std::endl;

    for (const auto& i : logo)
    {
        Display::write(i, 1);
    }

    Console::resetConsoleColor();
    std::cout << std::endl;
    Display::write(jWriter["Infos"].value("LogoSubtitle", ""), 2);
}

void Game::loadLogo()
{
    Logger::out("Function starts", "Game::loadLogo");
    Console::setConsoleColor(CC_Lightblue);
    std::cout << std::endl;

    for (const auto& i : logo)
    {
        std::cout << i;
    }

    std::cout << std::endl;
    Console::resetConsoleColor();
    std::cout << jWriter["Infos"].value("LogoSubtitle", "") << std::endl;
    mainMenu();
}

void Game::mainMenu()
{
    Logger::out("Function starts", "Game::mainMenu");
    Console::resetConsoleColor();
    std::cout << std::endl;
    Menu mainMenu;
    //--------------------------------
    mainMenu.addOptions({ jWriter["MainMenu"].value("1", ""), jWriter["MainMenu"].value("2", ""), jWriter["MainMenu"].value("3", ""), jWriter["MainMenu"].value("4", ""), jWriter["MainMenu"].value("5", "") });
    mainMenu.showOptions();
    //--------------------------------

    do
    {
        menu = mainMenu.inputChoice();

        switch (menu) {
        case 1: newGame(); break;
        case 2: continueGame(); break;
        case 3: changeLanguage(); break;
        case 4: credits(); break;
        case 5: endGame(); break;
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
    Console::clearScreen();
    Console::setConsoleColor(CC_Lightblue);
    Display::write(jWriter["Infos"].value("ContinueGame", ""), 25);
    Console::resetConsoleColor();
    Sleep(1000);
    pause();
    Console::clearScreen();
    loadLogo();
    mainMenu();
}

void Game::changeLanguage()
{
    Logger::out("Function starts", "Game::changeLanguage");
    int change = 0;
    Menu langMenu;

    while (change != EN && change != PL)
    {
        Console::clearScreen();
        Display::write(jWriter["Infos"].value("SelectYourLanguage", ""), 25);
        //--------------------------------
        langMenu.addOptions({ "EN", "PL" });
        langMenu.showOptions();
        //--------------------------------
        change = langMenu.inputChoice();

        if (change != EN && change != PL)
            Logger::error("Entered invalid value of <b>gameLang</b>", "Game::changeLanguage");
    }

    this->gameLang = change;
    JSON::loadFile(getLang());

    if (getLang() == EN)
        Logger::out("Set English as game language", "Game::changeLanguage");
    else if (getLang() == PL)
        Logger::out("Set Polish as game language", "Game::changeLanguage");

    Console::clearScreen();
    loadLogo();
    mainMenu();
}

void Game::endGame()
{
    Logger::out("Function starts", "Game::endGame");
    Menu quitMenu;

    do
    {
        Console::clearScreen();
        Display::write(jWriter["QuitGame"].value("ConfirmQuitGame", ""), 25);
        //--------------------------------
        quitMenu.addOptions({ jWriter["QuitGame"].value("Yes", ""), jWriter["QuitGame"].value("No", "") });
        quitMenu.showOptions();
        //--------------------------------
        choice = quitMenu.inputChoice();

        switch (choice) {
        case 1:
            end();
            break;
        case 2:
            Console::clearScreen(); 
            loadLogo();
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
    Console::setConsoleColor(CC_Lightblue);
    Display::write(jWriter["Credits"].value("Author", ""));
    Console::resetConsoleColor();
    Display::write("\n\tRadosław 'Doic' Michalak\n\n");
    Console::setConsoleColor(CC_Lightblue);
    Display::write(jWriter["Credits"].value("Testers", ""));
    Console::resetConsoleColor();
    Display::write("\n\t    Paweł Michalak\n\n");
    Console::setConsoleColor(CC_Lightblue);
    Display::write(jWriter["Credits"].value("Thanks", ""));
    Console::resetConsoleColor();
    Display::write("\n\t   Dominik Szpilski\n\t     Daniel Obłąk\n\n");
    Sleep(1000);
    pause();
    Console::clearScreen();
    loadLogo();
    mainMenu();
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
    else if (getCurrentLocation() == &Location::locations["SleepersHideout"]) Event::sleepersHideout();
}

void Game::initHeroEQ()
{
    Logger::out("Function starts", "Function::initHeroEQ");
    std::ofstream eq;
    eq.open("eq.txt");

    if (eq.good())
    {
        Logger::out("Access to txt file", "Function::initHeroEQ");
        eq << jWriter["InventoryInfos"].value("NoItemsInInv", "") << std::endl;
        eq.close();
    }
    else Logger::error("No file access", "Function::initHeroEQ");
}

void Game::initQuestsList()
{
    Logger::out("Function starts", "Function::initQuestsList");
    std::ofstream q;
    q.open("journal.txt");

    if (q.good())
    {
        Logger::out("Access to txt file", "Function::initQuestsList");
        q << jWriter["JournalInfos"].value("NoQuestsInJournal", "") << std::endl;
        q.close();
    }
    else Logger::error("No file access", "Function::initQuestsList");
}

void Game::pause()
{
    std::cout << jWriter["Infos"].value("PressAnyKey", "");
    Console::waitForUserInput();
}