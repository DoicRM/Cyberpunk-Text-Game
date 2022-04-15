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

    if (game[0].getLang() == EN)
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
    Console::resetConsoleColor();

    Menu langMenu;

    while (getLang() != EN && getLang() != PL)
    {
        Console::clearScreen();
        Output::write("\n\tSelect your language:\n", 25);
        langMenu.clearOptions();
        langMenu.addOption("EN");
        langMenu.addOption("PL");
        langMenu.showOptions();
        gameLang = langMenu.getChoice();

        if (getLang() != EN && getLang() != PL) Logger::error("Entered invalid value of <b>gameLang</b>", "Game::selectLanguage");
        else if (getLang() == EN) Logger::out("Set English as game language", "Game::selectLanguage");
        else if (getLang() == PL) Logger::out("Set Polish as game language", "Game::selectLanguage");
    }

    langMenu.clearOptions();
    Console::clearScreen();
}

void Game::welcome()
{
    Logger::out("Function starts", "Game::welcome");
    Sleep(500); 

    if (getLang() == PL) Output::write("\n\tRADOS£AW 'DOIC' MICHALAK PREZENTUJE GRÊ TEKSTOW¥ POD TYTU£EM", 40);
    else Output::write("\n\tRADOS£AW 'DOIC' MICHALAK PRESENTS A TEXT GAME TITLED", 40);

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

    for (int i = 0; i < logo.size(); i++)
    {
        Output::write(logo[i], 1);
    }

    Console::resetConsoleColor();

    if (getLang() == EN) Output::write("\n\n\t\t\t\t\t     A Cyberpunk Text Game\n\n", 2);
    else Output::write("\n\n\t\t\t\t\t     Cyberpunkowa gra tekstowa\n\n", 2);
}

void Game::loadLogo()
{
    Logger::out("Function starts", "Game::loadLogo");
    Console::setConsoleColor(CC_Lightblue);
    std::cout << std::endl;

    for (int i = 0; i < logo.size(); i++)
    {
        std::cout << logo[i];
    }

    std::cout << std::endl;
    Console::resetConsoleColor();

    if (getLang() == EN) std::cout << "\n\t\t\t\t\t     A Cyberpunk Text Game\n\n" << std::endl;
    else std::cout << "\n\t\t\t\t\t     Cyberpunkowa gra tekstowa\n\n" << std::endl;

    mainMenu();
}

void Game::mainMenu()
{
    Logger::out("Function starts", "Game::mainMenu");
    Console::resetConsoleColor();
    std::cout << std::endl;

    Menu mainMenu;

    if (getLang() == PL)
    {
        mainMenu.clearOptions();
        mainMenu.addOption("Nowa gra");
        mainMenu.addOption("Kontynuuj grê");
        mainMenu.addOption("Zmieñ jêzyk");
        mainMenu.addOption("Napisy");
        mainMenu.addOption("WyjdŸ z gry");
        mainMenu.showOptions();
    }
    else
    {
        mainMenu.clearOptions();
        mainMenu.addOption("New game");
        mainMenu.addOption("Continue game");
        mainMenu.addOption("Change language");
        mainMenu.addOption("Credits");
        mainMenu.addOption("Quit game");
        mainMenu.showOptions();
    }

    do
    {
        menu = mainMenu.getChoice();

        switch (menu) {
        case 1:
            mainMenu.clearOptions();
            newGame();
            break;
        case 2:
            mainMenu.clearOptions();
            continueGame();
            break;
        case 3:
            mainMenu.clearOptions();
            changeLanguage();
            break;
        case 4:
            mainMenu.clearOptions();
            credits();
            break;
        case 5:
            mainMenu.clearOptions();
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
    Console::setConsoleColor(CC_Lightblue);

    if (getLang() == PL) Output::write("\n\tNic tu nie ma. Ta funkcja jest obecnie niedostêpna.\n\n", 25);
    else Output::write("\n\tThere's nothing here. This feature is currently unavailable.\n\n", 25);

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

        if (getLang() == EN) Output::write("\n\tSelect your language:\n", 25);
        else if (getLang() == PL) Output::write("\n\tWybierz swój jêzyk:\n", 25);

        langMenu.clearOptions();
        langMenu.addOption("EN");
        langMenu.addOption("PL");
        langMenu.showOptions();
        change = langMenu.getChoice();

        if (change != EN && change != PL) Logger::error("Entered invalid value of <b>gameLang</b>", "Game::changeLanguage");
    }

    this->gameLang = change;

    if (getLang() == EN) Logger::out("Set English as game language", "Game::changeLanguage");
    else if (getLang() == PL) Logger::out("Set Polish as game language", "Game::changeLanguage");

    langMenu.clearOptions();
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
        if (getLang() == PL)
        {
            Sleep(500);
            Console::clearScreen();
            Output::write("\n\tJesteœ pewien, ¿e chcesz wyjœæ z gry?\n", 25);

            quitMenu.clearOptions();
            quitMenu.addOption("Tak");
            quitMenu.addOption("Nie");
            quitMenu.showOptions();
        }
        else
        {
            Sleep(500);
            Console::clearScreen();
            Output::write("\n\tAre you sure you want to end the game?\n", 25);

            quitMenu.clearOptions();
            quitMenu.addOption("Yes");
            quitMenu.addOption("No");
            quitMenu.showOptions();
        }

        choice = Input::getChoice();

        switch (choice) {
        case 1:
            quitMenu.clearOptions();
            end();
            break;
        case 2:
            quitMenu.clearOptions();
            Console::clearScreen();
            Sleep(500); 
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

    if (getLang() == PL)
    {
        Console::setConsoleColor(CC_Lightblue);
        Output::write("\n\t\tAUTOR\n");
        Console::resetConsoleColor();
        Output::write("\tRados³aw 'Doic' Michalak\n\n");
        Console::setConsoleColor(CC_Lightblue);
        Output::write("\t       TESTERZY\n");
        Console::resetConsoleColor();
        Output::write("\t    Pawe³ Michalak\n\n");
        Console::setConsoleColor(CC_Lightblue);
        Output::write("\t     PODZIÊKOWANIA\n");
        Console::resetConsoleColor();
        Output::write("\t   Dominik Szpilski\n\t     Daniel Ob³¹k\n\n");
    }
    else
    {
        Console::setConsoleColor(CC_Lightblue);
        Output::write("\n\t\tAUTHOR\n");
        Console::resetConsoleColor();
        Output::write("\tRados³aw 'Doic' Michalak\n\n");
        Console::setConsoleColor(CC_Lightblue);
        Output::write("\t\tTESTERS\n");
        Console::resetConsoleColor();
        Output::write("\t   Pawe³ Michalak\n\n");
        Console::setConsoleColor(CC_Lightblue);
        Output::write("\t\tTHANKS\n");
        Console::resetConsoleColor();
        Output::write("\t   Dominik Szpilski\n\t     Daniel Ob³¹k\n\n");
    }

    Sleep(1000);
    pause();
    Console::clearScreen();
    loadLogo();
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

        if (Game::game[0].getLang() == EN) eq << "                                    ITEMS                                  " << std::endl;
        else if (Game::game[0].getLang() == PL) eq << "                               PRZEDMIOTY                                  " << std::endl;

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

        if (Game::game[0].getLang() == EN) q << "                                    QUESTS                                 " << std::endl;
        else if (Game::game[0].getLang() == PL) q << "                                   ZADANIA                                 " << std::endl;

        q << "..........................................................................." << std::endl;
        q.close();
    }
    else Logger::error("No file access", "Function::initQuestsList");
}

void Game::pause()
{
    if (Game::game[0].getLang() == EN) std::cout << "\tPress ANY KEY to continue...";
    else if (Game::game[0].getLang() == PL) std::cout << "\tWciœnij DOWOLNY PRZYCISK, aby kontynuowaæ...";

    Console::waitForUserInput();
}

