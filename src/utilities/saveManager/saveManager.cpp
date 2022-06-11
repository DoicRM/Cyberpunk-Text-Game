#include "saveManager.hpp"

const std::string pro   = "Pro";
const std::string chap1 = "Chap_1";
const std::string chap2 = "Chap_2";
const std::string chap3 = "Chap_3";
const std::string epi   = "Epi";

int saveNr;

void SaveManager::createSave()
{
    Logger::startFuncLog(__FUNCTION__);
    std::ofstream newSave;
    std::string save = "save_";
    std::string file = ".dat";
    newSave.open(save + std::to_string(saveNr) + file, std::ios_base::trunc);
    saveNr++;
    newSave << "Player" << " :: " << "Unknown" << std::endl;
    newSave << "Gender" << " :: " << Sex::Undefined << std::endl;
    newSave << chap1 << " :: " << "1" << std::endl;
    newSave << Logger::getFormattedFullDate() << std::endl;
    newSave.close();
}

void SaveManager::loadSave()
{
    Logger::startFuncLog(__FUNCTION__);
    std::ifstream oldSave;
    oldSave.open("save.dat");

    if (!oldSave.is_open())
    {
        Logger::error("Unable to open file", __FUNCTION__);
        return Game::game[0].mainMenu();
    }

    std::string playerText, protoText, player, genderText, chapter;
    int gender;
    int stage;

    oldSave >> playerText >> protoText >> player >> genderText >> protoText >> gender >> chapter >> protoText >> stage;
    oldSave.close();

    Hero::heroes[0].setName(player);
    Hero::heroes[0].setSex(gender);
}

void SaveManager::updateSave(int saveNr, std::string player, int sex, std::string chapter, int stage)
{
    Logger::startFuncLog(__FUNCTION__);
    std::ofstream newSave;
    newSave.open("save" + std::to_string(saveNr) + ".dat", std::ios_base::app);
    newSave << "Player" << " :: " << "Unknown" << std::endl;
    newSave << chapter << " :: " << stage << std::endl;
    newSave.close();
}

void SaveManager::loadSaveInfo(std::string save)
{
    Logger::startFuncLog(__FUNCTION__);
    std::ifstream oldSave;
    oldSave.open(save);

    if (!oldSave.is_open())
    {
        Logger::error("Unable to open file", __FUNCTION__);
        return Game::game[0].mainMenu();
    }

    std::string playerText, protoText, player, genderText, chapter, date, hour;
    int gender;
    int stage;

    oldSave >> playerText >> protoText >> player >> genderText >> protoText >> gender >> chapter >> protoText >> stage >> date >> hour;
    oldSave.close();

    std::cout << "\t" << player << ", " << printSex(gender) << " | " << chapter << ": " << stage << " | " << date << " " << hour << std::endl;
}

void SaveManager::printSavesList()
{
    Logger::startFuncLog(__FUNCTION__);
    std::cout << std::endl;
    searchforSaves();
    std::cout << std::endl << std::endl;
}

void SaveManager::searchforSaves()
{
    Logger::startFuncLog(__FUNCTION__);
    _finddata_t f;
    intptr_t r;
    
    std::string currentPath = std::filesystem::current_path().string() + "\\";
    std::string searchingFilter = currentPath;
    searchingFilter += "save_*.dat";

    if ((r = _findfirst(searchingFilter.c_str(), &f)) > 0)
    {
        do
        {
            if (!(f.attrib & _A_SUBDIR)) {
                Logger::out((std::string)f.name + " found", __FUNCTION__);
                SaveManager::loadSaveInfo((std::string)f.name);
            }
        } while (!_findnext(r, &f));
    }
    else {
        Console::setConsoleColor(ConsoleColor::CC_Narration);
        std::cout << (std::string)jWriter["LoadGame"]["NoSavesFound"] << std::endl;
        Console::resetConsoleColor();
    }

    _findclose(r);
}

std::string SaveManager::printSex(int sex)
{
    std::string str;

    if (sex == Sex::Male)
    {
        return str = jWriter["Sex"]["Male"];
    }
    else if (sex == Sex::Female)
    {
        return str = jWriter["Sex"]["Female"];
    }

    return str = jWriter["Sex"]["Undefined"];
}
