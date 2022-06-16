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
    CreateDirectory("data\\saves", NULL);
    std::ofstream newSave;
    std::string savesPath = std::filesystem::current_path().string() + "\\data\\saves\\";
    std::string save = "save_";
    std::string file = ".dat";
    newSave.open(savesPath + save + std::to_string(saveNr) + file, std::ios_base::trunc);
    saveNr++;
    newSave << Logger::getFormattedFullDate() << std::endl;
    newSave << "Player" << " :: " << "Unknown" << std::endl;
    newSave << "Gender" << " :: " << Sex::Undefined << std::endl;
    newSave << chap1 << " :: " << "1" << std::endl;
    newSave.close();
}

void SaveManager::loadSave(int nr)
{
    Logger::startFuncLog(__FUNCTION__);
    std::ifstream oldSave;
    std::string savesPath = std::filesystem::current_path().string() + "\\data\\saves\\";
    oldSave.open(savesPath + "save_" + std::to_string(nr) + ".dat");

    if (!oldSave.is_open())
    {
        Logger::error("Unable to open 'save_" + std::to_string(nr) + ".txt' file", __FUNCTION__);
        return Game::game[0].loadLogo();
    }

    std::string date, hour, playerText, protoText, player, genderText, chapter;
    int gender;
    int stage;

    oldSave >> date >> hour >> playerText >> protoText >> player >> genderText >> protoText >> gender >> chapter >> protoText >> stage;
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
    std::string savesPath = std::filesystem::current_path().string() + "\\data\\saves\\";
    std::ifstream oldSave;
    oldSave.open(savesPath + save);

    if (!oldSave.is_open())
    {
        return Logger::error("Unable to open '" + save + "' file", __FUNCTION__);
    }

    std::string date, hour, playerText, protoText, player, genderText, chapter;
    int gender;
    int stage;

    oldSave >> date >> hour >> playerText >> protoText >> player >> genderText >> protoText >> gender >> chapter >> protoText >> stage;
    oldSave.close();

    std::cout << "\t" << player << ", " << printSex(gender) << " | " << chapter << ": " << stage << " | " << date << " " << hour << std::endl;
}

void SaveManager::printSavesList()
{
    Logger::startFuncLog(__FUNCTION__);
    std::cout << std::endl;
    searchForSaves();
    std::cout << std::endl << std::endl;
}

void SaveManager::searchForSaves()
{
    Logger::startFuncLog(__FUNCTION__);
    _finddata_t f;
    intptr_t r;
    
    std::string savesPath = std::filesystem::current_path().string() + "\\data\\saves\\";
    std::string searchingFilter = savesPath;
    searchingFilter += "save_*.dat";

    if ((r = _findfirst(searchingFilter.c_str(), &f)) > 0)
    {
        do
        {
            if (!(f.attrib & _A_SUBDIR))
            {
                Logger::out((std::string)f.name + " found", __FUNCTION__);
                SaveManager::loadSaveInfo((std::string)f.name);
            }
        } while (!_findnext(r, &f));
    }
    else
    {
        Console::setConsoleColor(ConsoleColor::CC_Narration);
        std::cout << (std::string)jWriter["LoadGame"]["NoSavesFound"] << std::endl;
        Console::resetConsoleColor();
    }

    _findclose(r);
}

std::string SaveManager::printSex(int sex)
{
    if (sex == Sex::Male)
    {
        return jWriter["Sex"]["Male"];
    }
    else if (sex == Sex::Female)
    {
        return jWriter["Sex"]["Female"];
    }

    return jWriter["Sex"]["Undefined"];
}
