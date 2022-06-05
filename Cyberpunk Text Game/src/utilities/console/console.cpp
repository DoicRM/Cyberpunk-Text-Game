#include "console.hpp"

void Console::initConsole(LPCSTR lpConsoleTitle, UINT wCodePageID)
{
    preventResizeConsole();
    SetConsoleTitleA(lpConsoleTitle);
    SetConsoleCP(wCodePageID);
    SetConsoleOutputCP(wCodePageID);
}

void Console::preventResizeConsole()
{
    HWND consoleWindow = GetConsoleWindow();
    SetWindowLong(consoleWindow, GWL_STYLE, GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);
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