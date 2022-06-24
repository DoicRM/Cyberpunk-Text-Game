#include "game.hpp"
#include "../utilities/saveManager/saveManager.hpp"

std::map <int, Game> Game::game;

Game::Game()
{
    this->menu = 0;
    this->choice = 0;
    this->gameLang = 0;
    this->playing = true;
    this->currentLocation = nullptr;
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
    initHeroIventory();
    initHeroJournal();
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

    while (getLang() != GameLanguage::EN && getLang() != GameLanguage::PL)
    {
        Console::clearScreen();
        std::cout << std::endl;
        //--------------------------------
        langMenu.addOptions({ "EN", "PL" });
        langMenu.showOptions();
        //--------------------------------
        this->gameLang = langMenu.inputChoice();

        if (getLang() != GameLanguage::EN && getLang() != GameLanguage::PL)
        {
            Logger::error("Entered invalid value of <b>gameLang</b>", __FUNCTION__);
        }
    }

    if (getLang() == GameLanguage::EN) {
        Logger::out("Set English as game language", __FUNCTION__);
    }
    else if (getLang() == GameLanguage::PL)
    {
        Logger::out("Set Polish as game language", __FUNCTION__);
    }

    LanguageHandler::loadDataFromFile(getLang());
    Console::clearScreen();
}

void Game::welcome()
{
    Logger::startFuncLog(__FUNCTION__);
    Console::wait(500); 
    Display::write(jWriter["main"]["welcome"], 40);
    Console::wait(2000);
    Console::clearScreen();
}

std::array<std::string, 8> Game::logo = {
    "\t ****     **   *******     ******  ********** **     ** *******   ****     **     **     **\n",
    "\t/**/**   /**  **/////**   **////**/////**/// /**    /**/**////** /**/**   /**    ****   /**\n",
    "\t/**//**  /** **     //** **    //     /**    /**    /**/**   /** /**//**  /**   **//**  /**\n",
    "\t/** //** /**/**      /**/**           /**    /**    /**/*******  /** //** /**  **  //** /**\n",
    "\t/**  //**/**/**      /**/**           /**    /**    /**/**///**  /**  //**/** **********/**\n",
    "\t/**   //****//**     ** //**    **    /**    /**    /**/**  //** /**   //****/**//////**/**\n",
    "\t/**    //*** //*******   //******     /**    //******* /**   //**/**    //***/**     /**/********\n",
    "\t//      ///   ///////     //////      //      ///////  //     // //      /// //      // ////////\n"
};

void Game::writeLogo()
{
    Logger::startFuncLog(__FUNCTION__);
    Console::setConsoleColor(ConsoleColor::CC_Lightblue);
    std::cout << std::endl;

    for (const auto& i : logo)
    {
        Display::write(i, 1);
    }

    Console::resetConsoleColor();
    std::cout << std::endl;
}

void Game::loadLogo()
{
    Logger::startFuncLog(__FUNCTION__);
    Console::setConsoleColor(ConsoleColor::CC_Lightblue);
    std::cout << std::endl;

    for (const auto& i : logo)
    {
        std::cout << i;
    }

    std::cout << std::endl;
    Console::resetConsoleColor();
    mainMenu();
}

void Game::mainMenu()
{
    Logger::startFuncLog(__FUNCTION__);
    Console::resetConsoleColor();
    std::cout << std::endl;
    Menu mainMenu;
    //--------------------------------
    mainMenu.addOptions({ jWriter["mainMenu"][0], jWriter["mainMenu"][1], jWriter["mainMenu"][2], jWriter["mainMenu"][3], jWriter["mainMenu"][4] });
    mainMenu.showOptions();
    //--------------------------------

    do
    {
        menu = mainMenu.inputChoice();

        switch (menu) {
        case 1: newGame(); break;
        case 2: laodGame(); break;
        case 3: changeLanguage(); break;
        case 4: credits(); break;
        case 5: endGame(); break;
        }
    } while (menu > 5 || menu <= 0);
}

void Game::newGame()
{
    Logger::startFuncLog(__FUNCTION__);
    SaveManager::createSave();
    initAll();
    Console::clearScreen();
    setCurrentLocation(&Location::locations["DarkAlley"]);
}

void Game::laodGame()
{
    Logger::startFuncLog(__FUNCTION__);
    Console::clearScreen();
    SaveManager::printSavesList();
    Console::resetConsoleColor();
    Console::wait(1000);
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
        Display::write(jWriter["main"]["selectYouLanguage"], 25);
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

    if (getLang() == GameLanguage::EN)
    {
        Logger::out("Set English as game language", __FUNCTION__);
    }
    else if (getLang() == GameLanguage::PL)
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
        Display::write(jWriter["quitGame"]["prompt"], 25);
        //--------------------------------
        quitMenu.addOptions({ jWriter["quitGame"]["yes"], jWriter["quitGame"]["no"] });
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
    Console::wait(500);
    Console::clearScreen();
    Console::setConsoleColor(ConsoleColor::CC_Lightblue);
    Display::write(jWriter["credits"]["author"]);
    Console::resetConsoleColor();
    Display::write("\n\tRadosław 'Doic' Michalak\n\n");
    Console::setConsoleColor(ConsoleColor::CC_Lightblue);
    Display::write(jWriter["credits"]["testers"]);
    Console::resetConsoleColor();
    Display::write("\n\t    Paweł Michalak\n\n");
    Console::setConsoleColor(ConsoleColor::CC_Lightblue);
    Display::write(jWriter["credits"]["thanks"]);
    Console::resetConsoleColor();
    Display::write("\n\t   Dominik Szpilski\n\t     Daniel Obłąk\n\n");
    Console::wait(1000);
    pause();
    Console::clearScreen();
    loadLogo();
    mainMenu();
}

void Game::setCurrentLocation(Location* location)
{
    this->currentLocation = location;
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

void Game::initHeroIventory()
{
    Logger::startFuncLog(__FUNCTION__);
    std::ofstream eq;
    eq.open("eq.txt");

    if (!eq.is_open())
    {
        return Logger::error("Unable to open file", __FUNCTION__);
    }
    
    eq << (std::string)jWriter["inventory"]["noItems"] << std::endl;
    eq.close();
}

void Game::initHeroJournal()
{
    Logger::startFuncLog(__FUNCTION__);
    std::ofstream quests;
    quests.open("journal.txt");

    if (!quests.is_open())
    {
        return Logger::error("Unable to open file", __FUNCTION__);
    }
    
    quests << (std::string)jWriter["journal"]["noQuests"] << std::endl;
    quests.close();
}

void Game::pause()
{
    std::cout << (std::string)jWriter["main"]["pressAnyKey"];
    Console::waitForUserInput();
}