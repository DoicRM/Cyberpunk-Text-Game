#pragma once
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
#include "enums.h"

using namespace std;

class Function
{
public:
	// powolne wypisywanie kodu - (tekst, szybkoœæ)
	static void write(const string& sentence, int speed = 60);
	// powolne wypisywanie kodu - (tekst, szybkoœæ)
	static void writeNarration(string st, int sp = 60);
	// powolne wypisywanie kodu - (tekst, szybkoœæ)
	static void writeDialogue(string st, int sp = 60);

	// tworzenie akcji gracza - (numer, opis)
	static void actionOption(int nr, string text);
	// tworzenie dialogu gracza - (numer, opis)
	static void dialogueOption(int nr, string text);
	// wyœwietlanie akcji gracza - (opis)
	static void showHeroAction(string text);

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

	// inicjowanie
	static void initHeroEQ(); // ekwipunku gracza
	static void initQuestsList(); // zadañ gracza

	static void waitForUserInput();

	// czyszczenie ekranu
	static void clearScreen();

	// zatrzymanie gry
	static void pauseGame();
};



