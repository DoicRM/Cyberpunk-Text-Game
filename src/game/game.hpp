#pragma once
#include "../fraction/fraction.hpp"
#include "../item/item.hpp"
#include "../item/weapon/weapon.hpp"
#include "../item/clothes/clothes.hpp"
#include "../hero/hero.hpp"
#include "../npc/npc.hpp"
#include "../npc/ambient/ambientNpc.hpp"
#include "../quest/quest.hpp"
#include "../events/events.hpp"
#include "../location/location.hpp"
#include "../weather/weather.hpp"
#include "../utilities/utilities.hpp"
#include "../utilities/logger/logger.hpp"
#include "../utilities/menu/menu.hpp"
#include "../utilities/languageHandler/languageHandler.hpp"

class Game
{
private:
	bool playing;
	int menu, choice, gameLang;
	Location* currentLocation;
	Weather weather;

	static std::array<std::string, 8> logo;

public:
	Game();
	virtual ~Game();

	static void init();
	static void initLocations();
	static void initHeroIventory();
	static void initHeroJournal();
	static void pause();

	void run();
	void initAll();
	void selectLanguage(); 
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
	void setWeather(WeatherType weather) { this->weather.setType(weather); };

	inline bool getPlaying() const { return this->playing; }
	inline int getLang() const { return this->gameLang; }
	inline Location* getCurrentLocation() const { return this->currentLocation; }
	inline Weather getWeather() const { return this->weather; }
	inline WeatherType getWeatherType() const { return this->weather.getType(); }

	static std::map <int, Game> game;
};
