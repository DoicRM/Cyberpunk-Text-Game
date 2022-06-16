#include "languageHandler.hpp"

nlohmann::json jWriter;
std::string JSON_VALUE_ERROR = "[VALUE ERROR]";

void LanguageHandler::loadDataFromFile(int lang)
{
    Logger::startFuncLog(__FUNCTION__);

    std::string str = getLang(lang);
    std::string path = std::filesystem::current_path().string() + "\\data\\localisation\\";
    std::ifstream jReader(path + str + ".json");

    if (!jReader.is_open())
    {
        Logger::error("Unable to open '" + str + ".json' file", __FUNCTION__);
        std::runtime_error("Unable to open '" + str + ".json' file");
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

std::string LanguageHandler::getLang(int lang)
{
    if (lang == EN)
    {
        return "en";
    }

    return "pl";
}