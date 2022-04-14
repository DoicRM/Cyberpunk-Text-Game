#include "utilities.hpp"

std::map <int, std::string> Decision::choices;
int choiceNr = 0;

// CONSOLE
void Console::changeConsoleColor(int color)
{
    HANDLE hOut;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hOut, color);
}

void Console::waitForUserInput()
{
#pragma warning(suppress : 6031)
    _getch();
}

void Console::clearScreen()
{
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
    system("cls");
#else
    system("clear");
#endif
}

// OUTPUT
void Output::write(const std::string& text, int speed)
{
    using namespace std::chrono_literals;

    for (auto letter : text)
    {
        std::cout << letter;
        std::cout.flush();
        std::this_thread::sleep_for(std::chrono::milliseconds(speed));
    }
}

void Output::writeNarration(std::string text, int speed)
{
    Console::changeConsoleColor(narration);
    Output::write(text, speed);
    Console::changeConsoleColor();
}

void Output::writeDialogue(std::string text, int speed)
{
    Console::changeConsoleColor(dialogue);
    Output::write(text, speed);
    Console::changeConsoleColor();
}

// INPUT
int Input::getChoice()
{
    int choice;
    Output::write("\t> ", 25);
    std::cin >> choice;
    std::cin.clear();
    std::cin.ignore();
    Logger::out("Entered <b>" + std::to_string(choice) + "</b>", "Function::getChoice");
    return choice;
}

std::string Input::getString()
{
    std::string text;
    Output::write("\t> ", 25);
    std::cin >> text;
    std::cin.clear();
    std::cin.ignore();
    Logger::out("Entered <b>" + text + "</b>", "Function::getString");
    return text;
}

// DECISION
void Decision::actionOption(int nr, std::string text)
{
    std::string str = "\t[" + std::to_string(nr) + "] " + text;
    Output::write(str, 25);
    std::cout << std::endl;
}

void Decision::showHeroAction(std::string text)
{
    std::cout << std::endl;
    Console::changeConsoleColor();
    std::string str = "\t> " + text;
    std::cout << str << std::endl;
}

void Decision::clearChoices()
{
    //Logger::out("Value of choice before reset: " + std::to_string(choiceNr), "Function::clearChoices");
    Decision::choices.clear();
    choiceNr = 0;
    //Logger::out("Value of choice after reset: " + std::to_string(choiceNr), "Function::clearChoices");
}

void Decision::addChoice(std::string description)
{
    choices[choiceNr] = description;
    choiceNr += 1;
}

void Decision::showChoices()
{
    std::map<int, std::string>::size_type choicesSize;
    choicesSize = choices.size();
    Console::changeConsoleColor();

    for (int j = 0; j < choices.size(); j++)
    {
        Decision::actionOption(j+1, choices[j]);
    }
}