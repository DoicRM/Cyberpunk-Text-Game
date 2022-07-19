#include "Game.hpp"
#include "../Utilities/SaveManager/SaveManager.hpp"

std::map <int, Game> Game::game;

Game::Game()
{
    this->menu = 0;
    this->choice = 0;
    this->playing = true;
    this->currentLocation = nullptr;
}

Game::~Game()
{
}

void Game::initAll()
{
    Hero::initHero();
    Fraction::initFractions();
    Npc::initNpcs();
    initLocations();
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
        welcome();
        writeLogo();
        mainMenu();
        end();
    }
}

void Game::welcome()
{
    Logger::startFuncLog(__FUNCTION__);
    Console::clearScreen();
    Console::wait(500);
    Display::write(json["main"]["welcome"], 40);
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
    Console::clearScreen();
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

    Menu mainMenu({
        std::make_pair(json["mainMenu"][0], std::bind(&Game::newGame, this)),
        std::make_pair(json["mainMenu"][1], std::bind(&Game::loadGame, this)),
        std::make_pair(json["mainMenu"][2], std::bind(&Game::changeLanguage, this)),
        std::make_pair(json["mainMenu"][3], std::bind(&Game::credits, this)),
        std::make_pair(json["mainMenu"][4], std::bind(&Game::endGame, this))
    });
}

void Game::newGame()
{
    Logger::startFuncLog(__FUNCTION__);
    SaveManager::createSave();
    Game::initAll();
    Console::clearScreen();
    Game::setCurrentLocation(&Location::locations["DarkAlley"]);
}

void Game::loadGame()
{
    Logger::startFuncLog(__FUNCTION__);
    Console::clearScreen();
    Console::setConsoleColor(CC_Red);
    std::cout << (std::string)json["main"]["notAvailable"] << std::endl;
    Console::resetConsoleColor();
    SaveManager::printSavesList();
    Console::wait(1000);
    Console::setConsoleColor(ConsoleColor::CC_Narration);
    std::cout << (std::string)json["main"]["backToMenu"];
    Console::waitForUserInput();
    Console::resetConsoleColor();
    Console::clearScreen();
    Game::loadLogo();
    Game::mainMenu();
}

void Game::changeLanguage()
{
    Logger::startFuncLog(__FUNCTION__);
    GameSettings::createConfigFile();
    GameSettings::loadDataFromFile(GameSettings::lang);
    Game::loadLogo();
}

void Game::endGame()
{
    Logger::startFuncLog(__FUNCTION__);

    Console::clearScreen();
    Display::write(json["quitGame"]["prompt"], 25);

    Menu quitMenu({
        std::make_pair(json["quitGame"]["yes"], std::bind(&Game::end, this)),
        std::make_pair(json["quitGame"]["no"], std::bind(&Game::loadLogo, this))
    });
}

void Game::credits()
{
    Logger::startFuncLog(__FUNCTION__);
    Console::clearScreen();
    Console::setConsoleColor(ConsoleColor::CC_Lightblue);
    Display::write(json["credits"]["author"]);
    Console::resetConsoleColor();
    Display::write("\n\tRadosław 'Doic' Michalak\n\n");
    Console::setConsoleColor(ConsoleColor::CC_Lightblue);
    Display::write(json["credits"]["testers"]);
    Console::resetConsoleColor();
    Display::write("\n\t    Paweł Michalak\n\n");
    Console::setConsoleColor(ConsoleColor::CC_Lightblue);
    Display::write(json["credits"]["thanks"]);
    Console::resetConsoleColor();
    Display::write("\n\t   Dominik Szpilski\n\t     Daniel Obłąk\n\n");
    Console::wait(1000);
    Console::setConsoleColor(ConsoleColor::CC_Narration);
    std::cout << (std::string)json["main"]["backToMenu"];
    Console::waitForUserInput();
    Console::resetConsoleColor();
    Console::clearScreen();
    Game::loadLogo();
    Game::mainMenu();
}

void Game::setCurrentLocation(Location* location)
{
    this->currentLocation = location;
    Logger::out("Set <b>" + getCurrentLocation()->getName() + "</b> as current location", __FUNCTION__);
    Game::getCurrentLocation()->getEvents()();
}

void Game::initHeroIventory()
{
    Logger::startFuncLog(__FUNCTION__);
    std::ofstream eq;
    eq.open("inventory.txt");

    if (!eq.is_open())
    {
        return Logger::error("Unable to open file", __FUNCTION__);
    }

    eq << (std::string)json["inventory"]["noItems"] << std::endl;
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

    quests << (std::string)json["journal"]["noQuests"] << std::endl;
    quests.close();
}

void Game::pause()
{
    std::cout << (std::string)json["main"]["pressAnyKey"];
    Console::waitForUserInput();
}

void Game::initLocations()
{
    Logger::startFuncLog(__FUNCTION__);

    Location DarkAlley(json["locations"]["darkAlley"]["name"], Fraction::fractions["Beggars"], Event::darkAlley);
    Location Street(json["locations"]["street"]["name"], Fraction::fractions["Police"], Event::street);
    Location Nightclub(json["locations"]["nightclub"]["name"], Fraction::fractions["Hammers"], Event::nightclub);
    Location GunShop(json["locations"]["gunShop"]["name"], Fraction::fractions["None"], Event::gunShop);
    Location SleepersHideout(json["locations"]["sleepersHideout"]["name"], Fraction::fractions["Sleepers"], Event::sleepersHideout);

    Location::locations["DarkAlley"] = DarkAlley;
    Location::locations["Street"] = Street;
    Location::locations["Nightclub"] = Nightclub;
    Location::locations["GunShop"] = GunShop;
    Location::locations["SleepersHideout"] = SleepersHideout;
}
