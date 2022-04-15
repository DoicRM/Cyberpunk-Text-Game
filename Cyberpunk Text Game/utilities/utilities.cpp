#include "utilities.hpp"

// CONSOLE
void Console::setConsoleColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void Console::resetConsoleColor()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), CC_Default);
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
    Console::setConsoleColor(CC_Narration);
    Output::write(text, speed);
    Console::resetConsoleColor();
}

void Output::writeDialogue(std::string text, int speed)
{
    Console::setConsoleColor(CC_Dialogue);
    Output::write(text, speed);
    Console::resetConsoleColor();
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