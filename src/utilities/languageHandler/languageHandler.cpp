#include "languageHandler.hpp"

nlohmann::json jWriter;

void LanguageHandler::loadDataFromFile(int lang)
{
    Logger::startFuncLog(__FUNCTION__);

    std::string fileName = getFileName(lang);
    std::string path = std::filesystem::current_path().string() + "\\data\\localisation\\";
    std::ifstream jReader(path + fileName + ".json");

    try
    {
        jWriter = nlohmann::json::parse(jReader);
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

std::string LanguageHandler::getFileName(int lang)
{
    if (lang == GameLanguage::EN)
    {
        Logger::out("Set English as game language", __FUNCTION__);
        return "en";
    }

    Logger::out("Set Polish as game language", __FUNCTION__);
    return "pl";
}