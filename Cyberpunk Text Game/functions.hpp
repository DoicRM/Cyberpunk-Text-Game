#pragma once
#include "enums.hpp"
#include "logger.hpp"
#include <iostream>
#include <fstream>
#include <thread>
#include <cmath>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <locale.h>
#include <string>
#include <map>
#include <limits>

class Function
{
public:
	static void nameGame(LPCSTR name) { SetConsoleTitleA(name); };
	static void initSpecialChars(const char* lang) { setlocale(LC_ALL, lang); };

	// powolne wypisywanie kodu - (tekst, szybkoœæ)
	static void write(const std::string& text, int speed = 60);
	// powolne wypisywanie kodu - (tekst, szybkoœæ)
	static void writeNarration(std::string text, int speed = 60);
	// powolne wypisywanie kodu - (tekst, szybkoœæ)
	static void writeDialogue(std::string text, int speed = 60);

	// tworzenie akcji gracza - (numer, opis)
	static void actionOption(int nr, std::string text);
	// wyœwietlanie akcji gracza - (opis)
	static void showHeroAction(std::string text);

	// Decyzje
	static void clearChoices();
	static void addChoice(std::string description);
	static void showChoices();
	static void selectChoice(int nr);

	// czyszczenie ekranu
	static void clearScreen();

	// Zmiana koloru tekstu i t³a konsoli
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
	//	14 ¿ó³ty tekst na czarnym tle
	//	15 bia³y tekst na czarnym tle
	static void changeConsoleColor(int color = defaultColor);
	static void waitForUserInput();
	static int getChoice();
	static std::string getString();

	static std::map <int, std::string> choices;
};