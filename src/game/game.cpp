#include "game.hpp"

std::map <int, Game> Game::game;

Game::Game()
{
    this->menu = 0;
    this->choice = 0;
    this->gameLang = 0;
    this->playing = true;
    this->ptrCurrentLocation = nullptr;
}

Game::~Game()
{   
}

void Game::init()
{
    Logger::startFuncLog(__FUNCTION__);
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
    Logger::startFuncLog(__FUNCTION__);

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
    Logger::startFuncLog(__FUNCTION__);
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

        if (getLang() != EN && getLang() != PL)
        {
            Logger::error("Entered invalid value of <b>gameLang</b>", __FUNCTION__);
        }

        if (getLang() == EN) {
            Logger::out("Set English as game language", __FUNCTION__);
        }
        else if (getLang() == PL)
        {
            Logger::out("Set Polish as game language", __FUNCTION__);
        }
    }

    LanguageHandler::loadDataFromFile(getLang());
    Console::clearScreen();
}

void Game::welcome()
{
    Logger::startFuncLog(__FUNCTION__);
    Sleep(500); 
    Display::write(jWriter.at("Infos").value("Welcome", JSON_VALUE_ERROR), 40);
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
    Logger::startFuncLog(__FUNCTION__);
    Console::setConsoleColor(CC_Lightblue);
    std::cout << std::endl;

    for (const auto& i : logo)
    {
        Display::write(i, 1);
    }

    Console::resetConsoleColor();
    std::cout << std::endl;
    Display::write(jWriter.at("Infos").value("LogoSubtitle", JSON_VALUE_ERROR), 2);
}

void Game::loadLogo()
{
    Logger::startFuncLog(__FUNCTION__);
    Console::setConsoleColor(CC_Lightblue);
    std::cout << std::endl;

    for (const auto& i : logo)
    {
        std::cout << i;
    }

    std::cout << std::endl;
    Console::resetConsoleColor();
    std::cout << jWriter.at("Infos").value("LogoSubtitle", JSON_VALUE_ERROR) << std::endl;
    mainMenu();
}

void Game::mainMenu()
{
    Logger::startFuncLog(__FUNCTION__);
    Console::resetConsoleColor();
    std::cout << std::endl;
    Menu mainMenu;
    //--------------------------------
    mainMenu.addOptions({ jWriter.at("MainMenu").at(0), jWriter.at("MainMenu").at(1), jWriter.at("MainMenu").at(2), jWriter.at("MainMenu").at(3), jWriter.at("MainMenu").at(4) });
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
    Logger::startFuncLog(__FUNCTION__);
    initAll();
    Console::clearScreen();
    setCurrentLocation(&Location::locations["DarkAlley"]);
}

void Game::continueGame()
{
    Logger::startFuncLog(__FUNCTION__);
    Console::clearScreen();
    Console::setConsoleColor(CC_Lightblue);
    Display::write(jWriter.at("Infos").value("ContinueGame", JSON_VALUE_ERROR), 25);
    Console::resetConsoleColor();
    Sleep(1000);
    pause();
    Console::clearScreen();
    loadLogo();
    mainMenu();
}

void Game::changeLanguage()
{
    Logger::startFuncLog(__FUNCTION__);
    int change = 0;
    Menu langMenu;

    while (change != EN && change != PL)
    {
        Console::clearScreen();
        Display::write(jWriter.at("Infos").value("SelectYourLanguage", ""), 25);
        //--------------------------------
        langMenu.addOptions({ "EN", "PL" });
        langMenu.showOptions();
        //--------------------------------
        change = langMenu.inputChoice();

        if (change != EN && change != PL)
        {
            Logger::error("Entered invalid value of <b>gameLang</b>", __FUNCTION__);
        }
    }

    this->gameLang = change;
    LanguageHandler::loadDataFromFile(getLang());

    if (getLang() == EN)
    {
        Logger::out("Set English as game language", __FUNCTION__);
    }

    if (getLang() == PL)
    {
        Logger::out("Set Polish as game language", __FUNCTION__);
    }

    Console::clearScreen();
    loadLogo();
    mainMenu();
}

void Game::endGame()
{
    Logger::startFuncLog(__FUNCTION__);
    Menu quitMenu;

    do
    {
        Console::clearScreen();
        Display::write(jWriter.at("QuitGame").value("Prompt", JSON_VALUE_ERROR), 25);
        //--------------------------------
        quitMenu.addOptions({ jWriter.at("QuitGame").at("Yes"), jWriter.at("QuitGame").at("No") });
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
    Logger::startFuncLog(__FUNCTION__);
    Sleep(500);
    Console::clearScreen();
    Console::setConsoleColor(CC_Lightblue);
    Display::write(jWriter.at("Credits").value("Author", JSON_VALUE_ERROR));
    Console::resetConsoleColor();
    Display::write("\n\tRadosław 'Doic' Michalak\n\n");
    Console::setConsoleColor(CC_Lightblue);
    Display::write(jWriter.at("Credits").value("Testers", JSON_VALUE_ERROR));
    Console::resetConsoleColor();
    Display::write("\n\t    Paweł Michalak\n\n");
    Console::setConsoleColor(CC_Lightblue);
    Display::write(jWriter.at("Credits").value("Thanks", JSON_VALUE_ERROR));
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
    Logger::out("Set <b>" + getCurrentLocation()->getName() + "</b> as current location", __FUNCTION__);
    startEventsByLocation();
}

void Game::startEventsByLocation()
{
    if (getCurrentLocation() == &Location::locations["DarkAlley"]) { Event::darkAlley(); }
    else if (getCurrentLocation() == &Location::locations["Street"]) { Event::street(); }
    else if (getCurrentLocation() == &Location::locations["Nightclub"]) { Event::nightclub(); }
    else if (getCurrentLocation() == &Location::locations["GunShop"]) { Event::gunShop(); }
    else if (getCurrentLocation() == &Location::locations["SleepersHideout"]) { Event::sleepersHideout(); }
}

void Game::initHeroEQ()
{
    Logger::startFuncLog(__FUNCTION__);
    std::ofstream eq;
    eq.open("eq.txt");

    if (!eq.good())
    {
        return Logger::error("No file access", __FUNCTION__);
    }
    
    Logger::out("Access to txt file", __FUNCTION__);
    eq << jWriter.at("InventoryInfos").value("NoItemsInInv", JSON_VALUE_ERROR) << std::endl;
    eq.close();
}

void Game::initQuestsList()
{
    Logger::startFuncLog(__FUNCTION__);
    std::ofstream q;
    q.open("journal.txt");

    if (!q.good())
    {
        return Logger::error("No file access", __FUNCTION__);
    }
    
    Logger::out("Access to txt file", __FUNCTION__);
    q << jWriter.at("JournalInfos").value("NoQuestsInJournal", JSON_VALUE_ERROR) << std::endl;
    q.close();
}

void Game::pause()
{
    std::cout << jWriter.at("Infos").value("PressAnyKey", JSON_VALUE_ERROR);
    Console::waitForUserInput();
}