#pragma once
#include "../Console/Console.hpp"
#include <iostream>
#include <string>
#include <thread>
#include <chrono>

class Display
{
public:
	static void write(const std::string& text, int speed = 50); // powolne wypisywanie kodu - (tekst, szybkość)
	static void writeNarration(std::string text, int speed = 50); // powolne wypisywanie kodu - (tekst, szybkość)
	static void writeDialogue(std::string text, int speed = 50); // powolne wypisywanie kodu - (tekst, szybkość)
};