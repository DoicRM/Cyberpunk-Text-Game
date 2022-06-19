#include "languageHandler.hpp"

nlohmann::json jWriter;

void LanguageHandler::loadDataFromFile(int lang)
{
    Logger::startFuncLog(__FUNCTION__);

    std::string fileName = getFileName(lang);
    std::string path = std::filesystem::current_path().string() + "\\data\\localisation\\";
    std::ifstream jReader(path + fileName + ".json");

    if (!jReader.is_open())
    {
        Logger::error("Unable to open '" + fileName + ".json' file", __FUNCTION__);
        std::runtime_error("Unable to open '" + fileName + ".json' file");
        return;
    }

    try
    {
        jWriter = nlohmann::json::parse(jReader);
    }
    catch (nlohmann::json::exception& e)
    {
        Logger::error(e.what(), __FUNCTION__);
        std::runtime_error(e.what());
    }

    jReader.close();
}

std::string LanguageHandler::getFileName(int lang)
{
    if (lang == EN)
    {
        return "en";
    }

    return "pl";
}