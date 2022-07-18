#include "./Menu.hpp"

Menu::Menu()
{
    clearOptions();
}

Menu::Menu(std::vector<std::pair<std::string, std::function<void()>>> options)
{
    clearOptions();
    addOptions(options);
    showOptions();
    inputChoice();
}

Menu::~Menu()
{
}

void Menu::actionOption(int nr, std::string text)
{
    Display::write("\t[" + std::to_string(nr) + "] " + text + "\n", 25);
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
    this->choice = 0;
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

    while (true)
    {
        this->choice = Input::getChoice();

        if (this->choice <= options.size() && this->choice > 0)
        {
            callFunction();
            break;
            return;
        }

        Logger::invalidHeroChoiceError(__FUNCTION__);
        continue;
    }
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