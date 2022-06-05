#pragma once
#include "../utilities/logger/logger.hpp"
#include <iostream>
#include <fstream>
#include <thread>
#include <cmath>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <string>
#include <map>
#include <limits>

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

enum GameLanguage
{
	EN = 1, PL = 2
};

enum Sex
{
	Undefined, Male, Female
};

enum Attitude
{
	Neutral, Angry, Hostile, Friendly
};

enum CharacterStatus
{
	Normal, Unconscious, Dead
};

enum QuestStatus
{
	NotStarted, Ongoing, Completed
};

enum ItemType
{
	NONE, WEAPON, CLOTHES, FOOD, OTHER, QUEST
};

enum ArmorType
{
	HEAD, CHEST, ARMS, LEGS
};

class Console
{
public:
	static void initConsole(LPCSTR lpConsoleTitle, UINT wCodePageID);
	static void preventResizeConsole();
	static void setConsoleTitle(LPCSTR lpConsoleTitle);
	static void clearScreen(); // czyszczenie ekranu
	static void setConsoleColor(int color = CC_Default); // zmiana koloru tekstu i tła konsoli
	static void resetConsoleColor();
	static void resetConsoleEncoding(UINT input, UINT output);

	//	1 czarny tekst na czarnym tle
	//	1 ciemno niebieski tekst na czarnym tle
	//	2 ciemno zielony tekst na czarnym tle
	//	3 zielono-niebieski tekst na czarnym tle
	//	4 ciemno czerwony tekst na czarnym tle
	//	5 magenta ciemna tekst na czarnym tle
	//	6 oliwkowy tekst na czarnym tle
	//	7 jasny szary tekst na czarnym tle
	//	8 szary tekst na czarnym tle
	//	9 niebieski tekst na czarnym tle
	//	10 zielony tekst na czarnym tle
	//	11 jasno niebieski tekst na czarnym tle
	//	12 czerwony tekst na czarnym tle
	//	13 magenta tekst na czarnym tle
	//	14 żółty tekst na czarnym tle
	//	15 biały tekst na czarnym tle

	static void waitForUserInput();
};

class Display
{
public:
	static void write(const std::string& text, int speed = 50); // powolne wypisywanie kodu - (tekst, szybkość)
	static void writeNarration(std::string text, int speed = 50); // powolne wypisywanie kodu - (tekst, szybkość)
	static void writeDialogue(std::string text, int speed = 50); // powolne wypisywanie kodu - (tekst, szybkość)
};

class Input
{
public:
	static int getChoice();
	static std::string getString();
};

class RandUtil
{
public:
	static int randBetween(int min, int max);
};