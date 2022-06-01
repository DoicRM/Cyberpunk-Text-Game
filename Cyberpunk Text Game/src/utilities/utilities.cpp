#include "utilities.hpp"

// CONSOLE
void Console::initConsole(LPCSTR lpConsoleTitle, UINT wCodePageID)
{
    SetConsoleTitleA(lpConsoleTitle);
    SetConsoleCP(wCodePageID);
    SetConsoleOutputCP(wCodePageID);
}

void Console::setConsoleTitle(LPCSTR lpConsoleTitle)
{
    SetConsoleTitleA(lpConsoleTitle);
}

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

void Console::resetConsoleEncoding(UINT input, UINT output)
{
    SetConsoleCP(input);
    SetConsoleOutputCP(output);
}

// DISPLAY
void Display::write(const std::string& text, int speed)
{
    using namespace std::chrono_literals;

    for (auto letter : text)
    {
        std::cout << letter;
        std::cout.flush();
        std::this_thread::sleep_for(std::chrono::milliseconds(speed));
    }
}

void Display::writeNarration(std::string text, int speed)
{
    Console::setConsoleColor(CC_Narration);
    Display::write(text, speed);
    Console::resetConsoleColor();
}

void Display::writeDialogue(std::string text, int speed)
{
    Console::setConsoleColor(CC_Dialogue);
    Display::write(text, speed);
    Console::resetConsoleColor();
}

// INPUT
int Input::getChoice()
{
    int choice;
    Display::write("\t> ", 25);
    std::cin >> choice;
    std::cin.clear();
    std::cin.ignore();
    Logger::out("Entered <b>" + std::to_string(choice) + "</b>", __FUNCTION__);
    return choice;
}

std::string Input::getString()
{
    std::string text;
    Display::write("\t> ", 25);
    std::cin >> text;
    std::cin.clear();
    std::cin.ignore();
    Logger::out("Entered <b>" + text + "</b>", __FUNCTION__);
    return text;
}

int RandUtil::randBetween(int min, int max)
{
    return rand() % ((max - min) + 1) + min;
}
