#pragma once
#include <Windows.h>
#include <conio.h>
#include <chrono>
#include <thread>

enum ConsoleColor
{
	CC_Default = 15,
	CC_Item = 3,
	CC_Dialogue = 7,
	CC_Narration = 8,
	CC_Robot = 9,
	CC_Green = 10,
	CC_Lightblue = 11,
	CC_Red = 12,
	CC_Yellow = 14
};

class Console
{
public:
	static void initConsole(LPCSTR lpConsoleTitle, UINT wCodePageID);
	static void clearScreen();
	static void waitForUserInput();
	static void setConsoleColor(int color = CC_Default);
	static void resetConsoleColor();
	static void resetConsoleEncoding(UINT input, UINT output);
	static void wait(int ms);
private:
	static void preventResizeConsole();
	static void setConsoleTitle(LPCSTR lpConsoleTitle);
};
