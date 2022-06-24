#include "./menu.hpp"

Menu::Menu()
{
    this->optionNr = 0;
    this->choice = 0;
    std::map <int, std::string> options;
}

Menu::~Menu()
{
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

void Menu::addOptions(std::vector<std::string> options)
{
    clearOptions();

    for (const auto& option : options)
    {
        if (!option.empty())
        {
            this->options[optionNr] = option;
            this->optionNr += 1;
        }
    }
}

void Menu::showOptions()
{
    if (options.empty())
    {
        return;
    }

    Console::resetConsoleColor();

    for (const auto& option : options)
    {
        actionOption(option.first + 1, option.second);
    }
}

int Menu::inputChoice()
{
    this->choice = Input::getChoice();
    return this->choice;
}