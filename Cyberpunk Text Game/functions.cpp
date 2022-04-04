#include "functions.h"

std::map <int, std::string> Function::choices;
int choiceNr = 0;

// Powolne wypisywanie kodu
void Function::write(const std::string& text, int speed)
{
    using namespace std::chrono_literals;

    for (auto letter : text)
    {
        std::cout << letter;
        std::cout.flush();
        std::this_thread::sleep_for(std::chrono::milliseconds(speed));
    }
}

// Powolne wypisywanie kodu (narracja)
void Function::writeNarration(std::string text, int speed)
{
    changeConsoleColor(narration);
    Function::write(text, speed);
    changeConsoleColor();
}

// Powolne wypisywanie kodu (dialog)
void Function::writeDialogue(std::string text, int speed)
{
    changeConsoleColor(dialogue);
    Function::write(text, speed);
    changeConsoleColor();
}

void Function::actionOption(int nr, std::string text)
{
    std::string str = "\t[" + std::to_string(nr) + "] " + text;
    Function::write(str, 25);
    std::cout << std::endl;
}

void Function::showHeroAction(std::string text)
{
    std::cout << std::endl;
    changeConsoleColor();
    std::string str = "\t> " + text;
    std::cout << str << std::endl;
}

void Function::clearChoices()
{
    //Logger::out("Value of choice before reset: " + std::to_string(choiceNr), "Function::clearChoices");
    choices.clear();
    choiceNr = 0;
    //Logger::out("Value of choice after reset: " + std::to_string(choiceNr), "Function::clearChoices");
}

void Function::addChoice(std::string description)
{
    choices[choiceNr] = description;
    choiceNr += 1;
}

void Function::showChoices()
{
    std::map<int, std::string>::size_type choicesSize;
    choicesSize = choices.size();
    Function::changeConsoleColor();

    for (int j = 0; j < choices.size(); j++)
    {
        Function::actionOption(j+1, choices[j]);
    }

    Function::write("\t> ", 25);
}

void Function::selectChoice(int nr)
{
    std::cin >> nr;
}

// Zmiana koloru tekstu i t³a konsoli
void Function::changeConsoleColor(int color)
{
    HANDLE hOut;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hOut, color);
}

void Function::waitForUserInput()
{
#pragma warning(suppress : 6031)
    _getch();
}

void Function::clearScreen()
{
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
    system("cls");
#else
    system("clear");
#endif
}
