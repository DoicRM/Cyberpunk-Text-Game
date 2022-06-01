#include "languageHandler.hpp"

nlohmann::json jWriter;
std::string JSON_VALUE_ERROR = "[VALUE ERROR]";

void JSON::loadDataFromFile(int lang)
{
    Logger::startFuncLog(__FUNCTION__);
    std::string str;

    if (lang == PL) str = "pl";
    else str = "en";

    std::string path = std::filesystem::current_path().string() + "\\localisation\\";
    std::ifstream jReader(path + str + ".json");

    try
    {
        jWriter = nlohmann::json::parse(jReader);
    }
    catch (nlohmann::json::parse_error& ex)
    {
        Logger::error("Parse error at byte " + ex.byte, __FUNCTION__);
    }

    jReader.close();
}