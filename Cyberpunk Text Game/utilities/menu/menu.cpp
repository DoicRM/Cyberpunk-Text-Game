#include "./menu.hpp"

std::map <std::string, Menu> menus;

Menu::Menu()
{
    //Logger::out("Function starts", "Menu::Menu");
    this->optionNr = 0;
    this->choice = 0;
    std::map <int, std::string> options;
}

Menu::~Menu()
{
    //Logger::out("Function starts", "Menu::~Menu");
}

void Menu::actionOption(int nr, std::string text)
{
    Display::write("\t[" + std::to_string(nr) + "] " + text + "\n", 25);
}

void Menu::showHeroAction(std::string text)
{
    Console::resetConsoleColor();
    std::cout << "\n\t> " + text + "\n";
}

void Menu::showHeroChoice()
{
    Console::resetConsoleColor();
    std::cout << "\n\t> " + options[choice-1] + "\n";
}

void Menu::clearOptions()
{
    this->options.clear();
    this->optionNr = 0;
}

void Menu::addOption(std::string description)
{
    this->options[optionNr] = description;
    this->optionNr += 1;
}

void Menu::addOptions(std::array<std::string, 10> options)
{
    clearOptions();

    for (auto& i : options)
    {
        if (!i.empty())
        {
            this->options[optionNr] = i;
            this->optionNr += 1;
        }
    }
}

void Menu::showOptions()
{
    Console::resetConsoleColor();

    for (int j = 0; j < options.size(); j++)
    {
        actionOption(j + 1, options[j]);
    }
}

int Menu::inputChoice()
{
    Display::write("\t> ", 25);
    std::cin >> this->choice;
    std::cin.clear();
    std::cin.ignore();
    Logger::out("Entered <b>" + std::to_string(this->choice) + "</b>", "Menu::getChoice");
    return this->choice;
}