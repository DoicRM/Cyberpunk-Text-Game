#pragma once
#include "Console/Console.hpp"
#include "Input/Input.hpp"
#include <iostream>
#include <fstream>
#include <thread>
#include <cmath>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <map>
#include <limits>
#include <random>

enum GameLanguage
{
	EN = 1, PL = 2
};

enum Attitude
{
	Neutral, Angry, Hostile, Friendly
};

class Utilities
{
public:
	static int randInt(int min, int max);
};