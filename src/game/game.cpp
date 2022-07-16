#include "game.hpp"
#include "../utilities/saveManager/saveManager.hpp"

std::map <int, Game> Game::game;

Game::Game()
{
    Weather weather;

    this->menu = 0;
    this->choice = 0;
    this->gameLang = 0;
    this->playing = true;
    this->currentLocation = nullptr;
    this->weather = weather;
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
        selectLanguage();
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

    while(true)
    {
        Console::clearScreen();
        std::cout << std::endl;
        
        langMenu.addOptions({
            std::make_pair("EN", std::bind(&Game::welcome, this)),
            std::make_pair("PL", std::bind(&Game::welcome, this))
        });
        langMenu.showOptions();
        
        this->gameLang = langMenu.getInputChoice();
        Console::clearScreen();

        if (langMenu.getChoice() <= langMenu.getOptionsSize() && langMenu.getChoice() > 0)
        {
            LanguageHandler::loadDataFromFile(getLang());
            langMenu.callFunction();
            break;
        }
        else {
            Logger::invalidHeroChoiceError(__FUNCTION__);
            continue;
        }
    }
}

void Game::welcome()
{
    Logger::startFuncLog(__FUNCTION__);
    Console::clearScreen();
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
        std::make_pair(jWriter["mainMenu"][0], std::bind(&Game::newGame, this)),
        std::make_pair(jWriter["mainMenu"][1], std::bind(&Game::loadGame, this)),
        std::make_pair(jWriter["mainMenu"][2], std::bind(&Game::changeLanguage, this)),
        std::make_pair(jWriter["mainMenu"][3], std::bind(&Game::credits, this)),
        std::make_pair(jWriter["mainMenu"][4], std::bind(&Game::endGame, this))
    });
}

void Game::newGame()
{
    Logger::startFuncLog(__FUNCTION__);
    SaveManager::createSave();
    initAll();
    Console::clearScreen();
    setCurrentLocation(&Location::locations["DarkAlley"]);
}

void Game::loadGame()
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
    Menu langMenu;

    while (true)
    {
        Console::clearScreen();
        Display::write(jWriter["main"]["selectYouLanguage"], 25);

        langMenu.addOptions({
            std::make_pair("EN", std::bind(&Game::loadLogo, this)),
            std::make_pair("PL", std::bind(&Game::loadLogo, this))
        });
        langMenu.showOptions();

        this->gameLang = langMenu.getInputChoice();
        Console::clearScreen();

        if (langMenu.getChoice() <= langMenu.getOptionsSize() && langMenu.getChoice() > 0)
        {
            LanguageHandler::loadDataFromFile(getLang());
            langMenu.callFunction();
            break;
        }
        else {
            Logger::invalidHeroChoiceError(__FUNCTION__);
            continue;
        }
    }
}

void Game::endGame()
{
    Logger::startFuncLog(__FUNCTION__);

    Console::clearScreen();
    Display::write(jWriter["quitGame"]["prompt"], 25);

    Menu quitMenu({
        std::make_pair(jWriter["quitGame"]["yes"], std::bind(&Game::end, this)),
        std::make_pair(jWriter["quitGame"]["no"], std::bind(&Game::loadLogo, this))
    });
}

void Game::credits()
{
    Logger::startFuncLog(__FUNCTION__);
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
    getCurrentLocation()->getEvents()();
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

void Game::initLocations()
{
    Logger::startFuncLog(__FUNCTION__);

    Location DarkAlley(jWriter["locations"]["darkAlley"]["name"], Fraction::fractions["Beggars"], Event::darkAlley);
    Location Street(jWriter["locations"]["street"]["name"], Fraction::fractions["Police"], Event::street);
    Location Nightclub(jWriter["locations"]["nightclub"]["name"], Fraction::fractions["Hammers"], Event::nightclub);
    Location GunShop(jWriter["locations"]["gunShop"]["name"], Fraction::fractions["None"], Event::gunShop);
    Location SleepersHideout(jWriter["locations"]["sleepersHideout"]["name"], Fraction::fractions["Sleepers"], Event::sleepersHideout);

    Location::locations["DarkAlley"] = DarkAlley;
    Location::locations["Street"] = Street;
    Location::locations["Nightclub"] = Nightclub;
    Location::locations["GunShop"] = GunShop;
    Location::locations["SleepersHideout"] = SleepersHideout;
}