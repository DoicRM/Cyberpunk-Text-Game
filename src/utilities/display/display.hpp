#pragma once
#include "../console/console.hpp"
#include <iostream>
#include <string>
#include <thread>
#include <chrono>

class Display
{
public:
	static void write(const std::string& text, int speed = 50); // powolne wypisywanie kodu - (tekst, szybkoœæ)
	static void writeNarration(std::string text, int speed = 50); // powolne wypisywanie kodu - (tekst, szybkoœæ)
	static void writeDialogue(std::string text, int speed = 50); // powolne wypisywanie kodu - (tekst, szybkoœæ)
};