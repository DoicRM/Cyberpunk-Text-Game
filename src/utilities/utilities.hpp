#pragma once
#include "../utilities/console/console.hpp"
#include "../utilities/input/input.hpp"
#include "../utilities/randomize/randomize.hpp"
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
