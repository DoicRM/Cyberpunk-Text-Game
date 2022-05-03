#include "languageHandler.hpp"

nlohmann::json j;

void JSON::loadFile(int lang)
{
    std::string str;

    if (lang == PL) str = "pl";
    else str = "en";

    std::string path = std::filesystem::current_path().string() + "\\lang\\";
    std::ifstream reader(path + str + ".json");
    reader >> j;
    reader.close();
}