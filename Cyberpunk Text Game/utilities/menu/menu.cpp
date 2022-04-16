#include "./menu.hpp"

std::map <std::string, Menu> menus;

Menu::Menu()
{
    Logger::out("Function starts", "Menu::Menu");
    this->optionNr = 0;
    this->choice = 0;
    std::map <int, std::string> options;
}

Menu::~Menu()
{
    Logger::out("Function starts", "Menu::~Menu");
}

void Menu::actionOption(int nr, std::string text)
{
    Output::write("\t[" + std::to_string(nr) + "] " + text + "\n", 25);
}

void Menu::showHeroAction(std::string text)
{
    Console::resetConsoleColor();
    std::cout << "\n\t> " + text + "\n";
}

void Menu::showHeroChoice()
{
    Console::resetConsoleColor();
    std::cout << "\n\t" + options[choice] + "\n";
}

void Menu::clearOptions()
{
    //Logger::out("Value of choice before reset: " + std::to_string(optionNr), "Menu::clearOptions");
    this->options.clear();
    this->optionNr = 0;
    //Logger::out("Value of choice after reset: " + std::to_string(optionNr), "Menu::clearOptions");
}

void Menu::addOption(std::string description)
{
    this->options[optionNr] = description;
    this->optionNr += 1;
}

void Menu::addOptions(std::array<std::string, 10> options)
{
    for (int i = 0; i < options.size(); i++)
    {
        if (!options[i].empty())
        {
            this->options[optionNr] = options[i];
            this->optionNr += 1;
        }
    }
}

void Menu::showOptions()
{
    std::map<int, std::string>::size_type optionsSize;
    optionsSize = options.size();
    Console::resetConsoleColor();

    for (int j = 0; j < options.size(); j++)
    {
        actionOption(j + 1, options[j]);
    }
}

int Menu::inputChoice()
{
    Output::write("\t> ", 25);
    std::cin >> this->choice;
    std::cin.clear();
    std::cin.ignore();
    Logger::out("Entered <b>" + std::to_string(this->choice) + "</b>", "Menu::getChoice");
    return this->choice;
}