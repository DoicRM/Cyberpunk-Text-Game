#include "SaveManager.hpp"

int saveNr = 0;

void SaveManager::createSave()
{
    Logger::startFuncLog(__FUNCTION__);
    CreateDirectory("data\\saves", NULL);
    std::ofstream newSave;
    std::string savesPath = std::filesystem::current_path().string() + "\\data\\saves\\";
    std::string saveStr = "save_";
    std::string file = ".dat";
    newSave.open(savesPath + saveStr + std::to_string(saveNr) + file, std::ios_base::trunc);
    saveNr++;
    newSave << Logger::getFormattedFullDate() << std::endl;
    newSave << "Player" << " :: " << (std::string)json["loadGame"]["unknown"] << std::endl;
    newSave << "Sex" << " :: " << Sex::Undefined << std::endl;
    newSave << 0 << " :: " << 1 << std::endl;
    newSave.close();
}

void SaveManager::loadSave(int nr)
{
    Logger::startFuncLog(__FUNCTION__);
    Save save;
    std::ifstream oldSave;
    std::string savesPath = std::filesystem::current_path().string() + "\\data\\saves\\";
    oldSave.open(savesPath + "save_" + std::to_string(nr) + ".dat");

    if (!oldSave.is_open())
    {
        Logger::error("Unable to open 'save_" + std::to_string(nr) + ".dat' file", __FUNCTION__);
        return Game::game[0].loadLogo();
    }

    std::string playerText, protoText, genderText;

    oldSave >> save.date >> save.hour >> playerText >> protoText >> save.player >> genderText >> protoText >> save.gender >> save.chapter >> protoText >> save.stage;
    oldSave.close();

    Hero::heroes["Hero"].setName(save.player);
    Hero::heroes["Hero"].setSex(save.gender);
}

void SaveManager::updateSave(int saveNr, std::string player, int sex, int chapter, int stage)
{
    Logger::startFuncLog(__FUNCTION__);
    std::string savesPath = std::filesystem::current_path().string() + "\\data\\saves\\";
    std::ofstream loadedSave;
    loadedSave.open(savesPath + "save_" + std::to_string(saveNr) + ".dat", std::ios_base::trunc);
    loadedSave << Logger::getFormattedFullDate() << std::endl;
    loadedSave << "Player" << " :: " << player << std::endl;
    loadedSave << "Sex" << " :: " << sex << std::endl;
    loadedSave << chapter << " :: " << stage << std::endl;
    loadedSave.close();
}

void SaveManager::loadSaveInfo(std::string saveToLoad)
{
    Logger::startFuncLog(__FUNCTION__);
    Save save;
    std::string savesPath = std::filesystem::current_path().string() + "\\data\\saves\\";
    std::ifstream oldSave;
    oldSave.open(savesPath + saveToLoad);

    if (!oldSave.is_open())
    {
        return Logger::error("Unable to open '" + saveToLoad + "' file", __FUNCTION__);
    }

    std::string playerText, protoText, genderText;

    oldSave >> save.date >> save.hour >> playerText >> protoText >> save.player >> genderText >> protoText >> save.gender >> save.chapter >> protoText >> save.stage;
    oldSave.close();

    std::cout << "\t" << save.player << ", " << printSex(save.gender) << " | " << getChapterString(save.chapter) << " : " << save.stage << " | " << save.date << " " << save.hour << std::endl;
}

void SaveManager::printSavesList()
{
    Logger::startFuncLog(__FUNCTION__);
    SaveManager::searchForSaves();
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
        std::cout << (std::string)json["loadGame"]["noSavesFound"] << std::endl;
        Console::resetConsoleColor();
    }

    _findclose(r);
}

std::string SaveManager::printSex(int sex)
{
    if (sex == Sex::Male)
    {
        return json["sex"]["male"];
    }
    else if (sex == Sex::Female)
    {
        return json["sex"]["female"];
    }
    return json["sex"]["undefined"];
}

std::string SaveManager::getChapterString(int chapter)
{
    if (chapter == 0 || chapter < 0)
    {
        return json["story"]["prologue"];
    }
    else if (chapter == 1 || chapter == 2)
    {
        std::string str;
        str += json["story"]["chapter"];
        str += std::to_string(chapter);
        return str;
    }
    return json["story"]["epilogue"];
}
