#pragma once

enum consoleColors
{
	defaultColor = 15,
	item = 3,
	dialogue = 7,
	narration = 8,
	dia_robot = 9,
	green = 10,
	lightblue = 11,
	red = 12,
	yellow = 14
};

enum gameLanguage { en = 1, pl = 2 };

enum sex { undefined, male, female };

enum attitude { neutral, angry, hostile, friendly };

enum status { normal, unconscious, dead };

enum itemType { NONE, WEAPON, ARMOR, FOOD, OTHER, QUEST };

enum armorType { HEAD, CHEST, ARMS, LEGS };