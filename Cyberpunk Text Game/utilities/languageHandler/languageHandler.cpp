#include "languageHandler.hpp"

nlohmann::json jWriter;

void JSON::loadFile(int lang)
{
    std::string str;

    if (lang == PL) str = "pl";
    else str = "en";

    std::string path = std::filesystem::current_path().string() + "\\localisation\\";
    std::ifstream jReader(path + str + ".json");
    jReader >> jWriter;
    jReader.close();
}