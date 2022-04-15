

std::map <int, std::string> Menu::choices;
int choiceNr = 0;

Menu::Menu()
{
    this->choiceNr = 0;
}

Menu::~Menu()
{

}

void Menu::actionOption(int nr, std::string text)
{
    std::string str = "\t[" + std::to_string(nr) + "] " + text;
    Output::write(str, 25);
    std::cout << std::endl;
}

void Menu::showHeroAction(std::string text)
{
    std::cout << std::endl;
    Console::resetConsoleColor();
    std::string str = "\t> " + text;
    std::cout << str << std::endl;
}

void Menu::clearChoices()
{
    //Logger::out("Value of choice before reset: " + std::to_string(choiceNr), "Function::clearChoices");
    Menu::choices.clear();
    choiceNr = 0;
    //Logger::out("Value of choice after reset: " + std::to_string(choiceNr), "Function::clearChoices");
}

void Menu::addChoice(std::string description)
{
    choices[choiceNr] = description;
    choiceNr += 1;
}

void Menu::showChoices()
{
    std::map<int, std::string>::size_type choicesSize;
    choicesSize = choices.size();
    Console::resetConsoleColor();

    for (int j = 0; j < choices.size(); j++)
    {
        Menu::actionOption(j + 1, choices[j]);
    }
}