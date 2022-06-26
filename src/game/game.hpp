#pragma once
#include "../fraction/fraction.hpp"
#include "../item/item.hpp"
#include "../item/weapon/weapon.hpp"
#include "../item/clothes/clothes.hpp"
#include "../hero/hero.hpp"
#include "../npc/npc.hpp"
#include "../npc/ambient/ambientNpc.hpp"
#include "../quest/quest.hpp"
#include "../events/eventManager.hpp"
#include "../location/location.hpp"
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

	static std::array<std::string, 8> logo;

public:
	Game();
	virtual ~Game();

	static void init();
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
	void laodGame();
	void changeLanguage(); 
	void credits(); 
	void loadLogo(); 
	void endGame(); 
	void end() { this->playing = false; } 
	void setCurrentLocation(Location* location); 
	void startEventsByLocation();

	inline bool getPlaying() const { return this->playing; }
	inline int getLang() const { return this->gameLang; }
	inline Location* getCurrentLocation() const { return this->currentLocation; }

	static std::map <int, Game> game;
};
