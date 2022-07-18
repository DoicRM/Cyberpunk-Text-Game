#include "GameSettings.hpp"

int GameSettings::lang = 0; // by default

GameSettings::GameSettings()
{
}

GameSettings::~GameSettings()
{
}

void GameSettings::createConfigFile()
{
    Logger::startFuncLog(__FUNCTION__);

    nlohmann::json j;
    std::ofstream configFile;
    configFile.open("config.json");

    GameSettings::lang = GameSettings::selectLanguage();

    TCHAR username[UNLEN + 1];
    DWORD size = UNLEN + 1;

    if (GetUserName((TCHAR*)username, &size))
    {
        j["user"] = username;
    }

    j["language"] = GameSettings::lang;
    configFile << std::setw(4) << j << std::endl;
    configFile.close();
}

bool GameSettings::loadConfigFile()
{
    Logger::startFuncLog(__FUNCTION__);

    nlohmann::json j;
    std::ifstream configFile;
    configFile.open("config.json");

    if (!configFile.is_open())
    {
        this->createConfigFile();
    }
    else {
        try
        {
            j = nlohmann::json::parse(configFile);
        }
        catch (nlohmann::json::exception& e)
        {
            Logger::error(e.what(), __FUNCTION__);
            AllocConsole();
            MessageBox(FindWindowA("ConsoleWindowClass", NULL), e.what(), "Parse JSON data from file", MB_ICONERROR);
            return false;
        }

        GameSettings::lang = j["language"];
        configFile.close();
    }

    GameSettings::loadDataFromFile(GameSettings::lang);

    return true;
}

int GameSettings::selectLanguage()
{
    Logger::startFuncLog(__FUNCTION__);
    int choice = 0;

    while (true)
    {
        Console::resetConsoleColor();
        Console::clearScreen();
        Display::write("\n\t[1] EN", 25);
        Display::write("\n\t[2] PL", 25);
        Display::write("\n\t> ", 25);
        std::cin >> choice;

        if (choice == GameLanguage::EN
            || choice == GameLanguage::PL)
        {
            break;
        }
        else {
            Logger::invalidHeroChoiceError(__FUNCTION__);
            continue;
        }
    }

    return choice;
}

void GameSettings::loadDataFromFile(int lang)
{
    Logger::startFuncLog(__FUNCTION__);

    std::string fileName = getFileName(lang);
    std::string path = std::filesystem::current_path().string() + "\\data\\localisation\\";
    std::ifstream jReader(path + fileName + ".json");

    try
    {
        json = nlohmann::json::parse(jReader);
    }
    catch (nlohmann::json::exception& e)
    {
        Logger::error(e.what(), __FUNCTION__);
        AllocConsole();
        /* Make sure the validated language files are in the data/localisation folder. */
        MessageBox(FindWindowA("ConsoleWindowClass", NULL), e.what(), "Parse JSON data from file", MB_ICONERROR);
    }

    jReader.close();
}

std::string GameSettings::getFileName(int lang)
{
    Logger::startFuncLog(__FUNCTION__);

    if (lang == GameLanguage::EN)
    {
        Logger::out("Set English as game language", __FUNCTION__);
        return "en";
    }

    Logger::out("Set Polish as game language", __FUNCTION__);
    return "pl";
}
