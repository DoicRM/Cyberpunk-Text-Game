#pragma once
#include "GameSettings/GameSettings.hpp"
#include "../Fraction/Fraction.hpp"
#include "../Item/Item.hpp"
#include "../Item/Weapon/Weapon.hpp"
#include "../Item/Clothes/Clothes.hpp"
#include "../Npc/Npc.hpp"
#include "../Npc/Ambient/AmbientNpc.hpp"
#include "../Npc/Hero/Hero.hpp"
#include "../Quest/Quest.hpp"
#include "../Event/Event.hpp"
#include "../Location/Location.hpp"
#include "../Utilities/Utilities.hpp"
#include "../Utilities/Logger/Logger.hpp"
#include "../Menu/Menu.hpp"
#include "../Utilities/JsonHandler/JsonHandler.hpp"

enum Weather {
	Sunny, Cloudy, Stormy, Rainy, Snowfall
};

class Game
{
private:
	bool playing;
	int menu, choice;
	Location* currentLocation;
	Weather weather;

public:
	static std::array<std::string, 8> logo;

	Game();
	virtual ~Game();

	static void initLocations();
	static void initHeroIventory();
	static void initHeroJournal();
	static void pause();

	void run();
	void initAll();
	void welcome();
	void writeLogo();
	void mainMenu();
	void newGame();
	void loadGame();
	void changeLanguage();
	void credits();
	void loadLogo();
	void endGame();
	void end() { this->playing = false; }
	void setCurrentLocation(Location* location);
	void setWeather(Weather weather) { this->weather = weather; }

	inline bool getPlaying() const { return this->playing; }
	inline Location* getCurrentLocation() const { return this->currentLocation; }
	inline Weather getWeather() const { return this->weather; }

	static std::map <int, Game> game;
};
