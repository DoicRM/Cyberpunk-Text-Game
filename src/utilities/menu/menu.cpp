#include "./menu.hpp"

Menu::Menu()
{
    this->optionNr = 1;
    this->choice = 0;
    std::map <int, std::pair<std::string, std::function<void()>>> options;
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
    std::cout << "\n\t> " + options[choice].first << std::endl;
}

void Menu::clearOptions()
{
    this->options.clear();
    this->optionNr = 1;
}

void Menu::addOptions(std::vector<std::pair<std::string, std::function<void()>>> options)
{
    clearOptions();

    for (const auto& option : options)
    {
        this->options[optionNr] = std::make_pair(option.first, option.second);
        this->optionNr += 1;
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
        actionOption(option.first, option.second.first);
    }
}
 
void Menu::inputChoice()
{
    Logger::startFuncLog(__FUNCTION__);
    this->choice = Input::getChoice();

    if (this->choice <= options.size() && this->choice > 0)
    {
        return callFunction();
    }

    Logger::invalidHeroChoiceError(__FUNCTION__);
}

int Menu::getInputChoice()
{
    Logger::startFuncLog(__FUNCTION__);
    this->choice = Input::getChoice();

    return this->choice;
}

void Menu::callFunction()
{
    std::function<void()> func = options[this->choice].second;
    Console::clearScreen();
    showHeroChoice();
    func();
}