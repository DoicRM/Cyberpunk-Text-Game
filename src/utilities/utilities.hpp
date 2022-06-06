#pragma once
#include "../utilities/logger/logger.hpp"
#include "../utilities/console/console.hpp"
#include <iostream>
#include <fstream>
#include <thread>
#include <cmath>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <map>
#include <limits>

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