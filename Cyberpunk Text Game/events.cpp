#include "events.h"

map <string, Hero> heroes;
map <string, Npc> npcs;
map <string, Fraction> fractions;
map <string, Item> items;
map <string, Location> locations;
map <string, Quest> quests;

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// 1. INIT
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// 1.1 Inicjowanie bohatera
void Event::initHero()
{
    Hero hero;
    heroes["Hero"] = hero;
}

// 1.2 Inicjowanie frakcji
void Event::initFractionsNpcsAndLocations()
{
    //if (game.getLang() == en)
    //{
        // Frakcje
        Fraction None("None", 0, "neutral");
        Fraction Beggars("Beggars", 0, "neutral");
        Fraction Police("Police", 0, "neutral");
        Fraction Hammers("Hammers", 0, "neutral");
        Fraction Sleepers("Sleepers", 0, "neutral");

        fractions["None"] = None;
        fractions["Beggars"] = Beggars;
        fractions["Police"] = Police;
        fractions["Hammers"] = Hammers;
        fractions["Sleepers"] = Sleepers;

        // Npc
        Npc Bob("Bob", Beggars);
        Npc Caden("Caden", Police);
        Npc CadensPartner("Policeman", Police);
        Npc Zed("Zed", None);
        Npc Mia("Mia", Sleepers);
        Npc Bodyguard("Bodyguard", Hammers);
        Npc Vincent("Vincent", Hammers);
        Npc Enigma("Enigma", Sleepers);

        npcs["Bob"] = Bob;
        npcs["Caden"] = Caden;
        npcs["CadensPartner"] = CadensPartner;
        npcs["Zed"] = Zed;
        npcs["Mia"] = Mia;
        npcs["Bodyguard"] = Bodyguard;
        npcs["Vincent"] = Vincent;
        npcs["Enigma"] = Enigma;

        // Lokacje
        Location DarkAlley("Dark alley", 0, Beggars, 1, false);
        Location Street("Street", 0, Police, 2, false);
        Location Nightclub("Nightclub 'Amnesia'", 0, Hammers, 3, false);
        Location GunShop("Zed's Gun Shop", 0, None, 3, false);

        locations["DarkAlley"] = DarkAlley;
        locations["Street"] = Street;
        locations["Nightclub"] = Nightclub;
        locations["GunShop"] = GunShop;
    /* }
    else if (Game().getLang() == pl)
    {
        // Frakcje
        Fraction None("Brak", 0, "neutral");
        Fraction Beggars("¯ebracy", 0, "neutral");
        Fraction Police("Policja", 0, "neutral");
        Fraction Hammers("M³oty", 0, "neutral");
        Fraction Sleepers("Œni¹cy", 0, "neutral");

        fractions["None"] = None;
        fractions["Beggars"] = Beggars;
        fractions["Police"] = Police;
        fractions["Hammers"] = Hammers;
        fractions["Sleepers"] = Sleepers;

        // Npc
        Npc Bob("Bob", Beggars);
        Npc Caden("Caden", Police);
        Npc CadensPartner("Policjant", Police);
        Npc Zed("Zed", None);
        Npc Mia("Mia", Sleepers);
        Npc Bodyguard("Ochroniarz", Hammers);
        Npc Vincent("Vincent", Hammers);
        Npc Enigma("Enigma", Sleepers);

        npcs["Bob"] = Bob;
        npcs["Caden"] = Caden;
        npcs["CadensPartner"] = CadensPartner;
        npcs["Zed"] = Zed;
        npcs["Mia"] = Mia;
        npcs["Bodyguard"] = Bodyguard;
        npcs["Vincent"] = Vincent;
        npcs["Enigma"] = Enigma;

        // Lokacje
        Location DarkAlley("Mroczny zau³ek", 0, 1, Beggars, false);
        Location Street("Ulica", 0, 2, Police, false);
        Location Nightclub("Klub nocny 'Amnezja'", 0, 3, Hammers, false);
        Location GunShop("Sklep z broni¹ u Zeda", 0, 3, None, false);

        locations["DarkAlley"] = DarkAlley;
        locations["Street"] = Street;
        locations["Nightclub"] = Nightclub;
        locations["GunShop"] = GunShop;
    }*/
}

// 1.3 Inicjowanie przedmiotów
void Event::initItems()
{
    //if (Game().getLang() == en)
    //{
        Item AD13("Accelerator D-13", "Others", "A long gone accelerator model, though still quite precious.", 50);
        Item AccessCard("Access card", "Others", "It definitely matches the door leading to the locked room in Ramsey's office.", 0);
        Weapon Pistol("Pistol", "Weapons", "A simple weapon that shoots pure energy.", 10, 15, 250);
        //Item Pistol("Pistol", "Weapons", "A simple weapon that shoots pure energy.", 250);

        items["AD13"] = AD13;
        items["AccessCard"] = AccessCard;
        items["Pistol"] = Pistol;
    /* }
    else if (Game().getLang() == pl)
    {
        Item AD13("Akcelerator D-13", "Inne", "Dawno nieu¿ywany model akceleratora, choæ wci¹¿ doœæ cenny.", 50);
        Item AccessCard("Karta dostêpu", "Inne", "Z pewnoœci¹ pasuje do drzwi prowadz¹cych do zablokowanego pomieszczenia w gabinecie Ramseya.", 0);
        Weapon Pistol("Pistol", "Broñ", "Prosta broñ strzelaj¹ca czyst¹ energi¹.", 10, 15, 250);
        Item Pistol("Pistolet", "Broñ", "Prosta broñ strzelaj¹ca czyst¹ energi¹.", 250);

        items["AD13"] = AD13;
        items["AccessCard"] = AccessCard;
        items["Pistol"] = Pistol;
    }
    */
}

// 1.4 Inicjowanie zadañ
void Event::initQuests()
{
    //if (Game().getLang() == en)
    //{
        Quest KillVincent("Beauty and the Beast", "Kill 'Amnesia' nightclub owner Vincent Ramsey at the request of his girlfriend, Mia.");
        Quest ZedAccelerator("Shades of the Past", "Bring Zed an old model of an accelerator. In return you will receive a gun from him.");

        quests["KillVincent"] = KillVincent;
        quests["ZedAccelerator"] = ZedAccelerator;
    /*}
    else if (Game().getLang() == pl)
    {
        Quest KillVincent("Piêkna i bestia", "Zabij w³aœciciela klubu nocnego 'Amnezja', Vincenta Ramseya, na proœbê jego dziewczyny, Mii.");
        Quest ZedAccelerator("Cienie przesz³oœci", "Przynieœ Zedowi stary model akumulatora. W zamian otrzymasz od niego pistolet.");

        quests["KillVincent"] = KillVincent;
        quests["ZedAccelerator"] = ZedAccelerator;
    }*/ 
}

// 1.5 Inicjowanie wszystkiego
void Event::initAll()
{
    Event::initHero();
    Event::initFractionsNpcsAndLocations();
    Event::initItems();
    Event::initQuests();
    Function::initHeroEQ();
    Function::initQuestsList();
}

// 1.6 Inicjowanie zmiennych
bool bobRecommendsZedToHero = false, heroKnowsVincentHideoutCode = false, heroIsOnDanceFloor = false, heroIsAtBar = false, zedKnowsAboutBobFriendshipWithHero = false;
int heroChoice = 0, checkpoint = 0, optionNr = 1;
bool darkAlleyWasVisited = false, streetWasVisited = false, gunShopWasVisited = false, nightclubWasVisited = false;
Location* locationPointer;
Item* itemPointer;

// 1.7 Pomocnicza funkcja do wyœwietlania informacji o zdobyciu przedmiotu
/*void Event::showTakeItemInfo(Item findItem)
{
    itemPointer = &findItem;
    heroes["Hero"].addItem(itemPointer);

    Function::changeConsoleColor(item);
    string str = "\t" + findItem.getName();
    Function::write(str);
    Function::changeConsoleColor();
    Function::write(" was found.\n");
}*/
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// 2. WYDARZENIA
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// 2.1 G£ÓWNE
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::darkAlley()
{
    locationPointer = &locations["DarkAlley"];
    Game().setCurrentLocation(locationPointer);

    /*if (Game().getCurrentLocation() == locationPointer)
    {
        
    }*/

    if (!darkAlleyWasVisited)
    {
        prologue();
    }
    else
    {
        darkAlleyCrossroads();
    }
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::street()
{
    locationPointer = &locations["Street"];
    Game().setCurrentLocation(locationPointer);

    if (!streetWasVisited)
    {
        viewOfAmnesia();
    }
    else
    {
        streetCrossroads();
    }
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::gunShop()
{
    locationPointer = &locations["GunShop"];
    Game().setCurrentLocation(locationPointer);

    if (!gunShopWasVisited)
    {
        heroMeetGunStore();
    }
    else
    {
        gunShopCrossroads();
    }
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::nightclub()
{
    locationPointer = &locations["Nightclub"];
    Game().setCurrentLocation(locationPointer);

    if (!nightclubWasVisited)
    {
        Function::showHeroAction("Go inside.");
        enterClub();
    }
    else
    {
        Function::showHeroAction("Visit: Nightclub 'Amnesia'.");
        nightclubCrossroads();
    }
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// 2.2 INNE
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// 2.2.1 MROCZNY ZAU£EK
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::darkAlleyCrossroads()
{
    string heroName;

    Function::showHeroAction("Visit: Dark Alley.");
    cout << endl;

    if (!npcs["Bob"].isKnowsHero())
    {
        Function::writeNarration("\tWhen you enter the alley, you hear a familiar voice.");
        cout << endl;
        Function::writeDialogue("\t- 'It's you again. Why don't you tell me something for one this time?'");
        cout << endl;
        cout << "" << endl;
        //-------------------------------------------------------------
        // Decyzja
        Function::actionOption(optionNr, "Stop and finally find out what he wants."); // Opcja nr 1
        optionNr++;
        Function::actionOption(optionNr, "Ignore him again."); // Opcja nr 2
        optionNr = 1;
        Function::write("\t> ", 15);

        while (true)
        {
            cin >> heroChoice;

            if (heroChoice == 1)
            {
                Function::clearScreen();
                Function::showHeroAction("Stop and finally find out what he wants.");
                cout << endl;
                Function::writeNarration("\tYou stop and turn towards the owner of the voice.");
                Sleep(1500);
                Function::writeNarration(" His silhouette looms in the darkness. It's one of the homeless people who live here. What can he have for you?");
                cout << endl;
                conversationWithHomeless();
                break;
            }
            else if (heroChoice == 2)
            {
                Function::clearScreen();
                Function::showHeroAction("Ignore him again.");
                cout << endl;
                Function::writeNarration("\tYou have a mysterious stranger for nothing. You speed up your step and leave him far behind\n\tyou. Whatever he wanted from you is no longer important.");
                cout << endl;
                Function::writeDialogue("\t- 'Don't show up here again if you don't want to get your teeth kicked in!'");
                cout << endl;
                Function::clearScreen();
                street();
                break;
            }
        }
        //-------------------------------------------------------------
    }
    else
    {
        Function::writeNarration("\tWhen you enter an alley, you notice a sea of trash around you.");
        Sleep(1000);
        Function::writeNarration(" It's full of cardboard boxes, old mechanical parts, and god knows what else.");
    }

    itemPointer = &items["AD13"];

    if (!heroes["Hero"].isHaveItem(itemPointer))
    {
        Sleep(1500);
        cout << endl;
        Function::writeNarration("\tWho knows, you might find something interesting there...");
        cout << endl;
        cout << "" << endl;
        //-------------------------------------------------------------
        // Decyzja
        Function::changeConsoleColor();
        Function::actionOption(optionNr, "Search the area for something valuable."); // Opcja nr 1
        optionNr++;
        Function::actionOption(optionNr, "Go out of the alley."); // Opcja nr 2
        optionNr = 1;
        Function::write("\t> ", 15);

        while (true)
        {
            cin >> heroChoice;

            if (heroChoice == 1)
            {
                Sleep(1000);
                cout << endl;
                Function::writeNarration("\tYou start rummaging through the trash.");
                Sleep(1500);
                Function::writeNarration(" The search takes a long while, but eventually you manage to find something.");
                Sleep(2000);
                cout << endl;

                //Event::showTakeItemInfo(items["AD13"]);
                itemPointer = &items["AD13"];
                heroes["Hero"].addItem(itemPointer);

                Function::changeConsoleColor(item);
                string str = "\t" + items["AD13"].getName();
                Function::write(str);
                Function::changeConsoleColor();
                Function::write(" was found.");
                cout << endl;
                Function::write("\t[TIP: This item has been added to your inventory. You can view it in the text file in your game folder.]", 15);
                Sleep(4000);
                cout << endl;
                Function::writeNarration("\tHmm, that might come in handy in the future.");
                Sleep(1000);
                cout << endl;
                Function::writeNarration("\tThere is nothing interesting here any more. Time to go back...");
                cout << endl;
                street();
                break;
            }
            else if (heroChoice == 2)
            {
                cout << endl;
                street();
                break;
            }
        }
        //-------------------------------------------------------------
    }
    else
    {
        cout << endl;
        Function::writeNarration("\tThere is nothing interesting here. Time to go back...");
        cout << endl;
        street();
    }
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::prologue()
{
    //if (Game().getLang() == en)
    //{
        cout << "" << endl;
        Function::write("\tPrologue");
        Sleep(2000);
        cout << endl;
        cout << "" << endl;
        Function::write("\tREQUIEM FOR A DREAM");
        Sleep(5000);
        Function::clearScreen();
        storyIntroduction();
    /* }
    else
    {
        cout << "" << endl;
        Function::write("\tProlog");
        Sleep(2000);
        cout << endl;
        cout << "" << endl;
        Function::write("\tREQUIEM DLA MARZEÑ");
        Sleep(5000);
    }
    */
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::storyIntroduction()
{
    //if (Game().getLang() == en)
    //{
        cout << "" << endl;
        Function::writeNarration("\tIt's 2050.");
        Sleep(1000);
        Function::writeNarration(" Megacity is a place overrun by poverty and feuding gangs, where powerful\n\tcorporations have the most influence. The violence in the streets is a clear sign of\n\tan impending war. Government operating from behind the secure walls of City Hall are\n\ttrying to combat this, but so far without success. There are rumors that they themselves\n\tare secretly supporting the chaos to create a New Order on the ruins of the city.", 20);
        cout << endl;
        cout << "" << endl;
        Function::pauseGame();
        Function::clearScreen();
        cout << "" << endl;
        Sleep(2500);
        Function::writeDialogue("\tStanding at the edge of the tallest tower...", 75);
        Sleep(2500);
        cout << endl;
        Function::writeDialogue("\tHolding your hand and dive...", 75);
        Sleep(2500);
        cout << endl;
        Function::writeDialogue("\tFalling and falling for what feels like hours...", 75);
        Sleep(3000);
        Function::clearScreen();
        //cout << endl;
        cout << "" << endl;
        wakeUpAloneInDarkAlley();
    /* }
    else
    {
        Function::clearScreen();
        Sleep(2000);
        cout << "" << endl;
        Function::writeNarration("\tJest rok 2050.");
        Sleep(1000);
        Function::writeNarration(" Megacity to miejsce opanowane przez biedê i zwaœnione gangi, gdzie najwiêksze wp³ywy maj¹ potê¿ne korporacje. Przemoc na ulicach jest wyraŸnym znakiem zbli¿aj¹cej siê wojny. Rz¹d dzia³aj¹cy zza bezpiecznych murów ratusza próbuje z tym walczyæ, ale jak na razie bezskutecznie. Kr¹¿¹ plotki, ¿e sam potajemnie wspiera chaos, by na gruzach miasta stworzyæ Nowy Porz¹dek.", 20);
        cout << endl;
        cout << "" << endl;
        system("pause");
        Function::clearScreen();
        cout << "" << endl;
        Sleep(2500);
        Function::writeDialogue("\tStoj¹c na krawêdzi najwy¿szej wie¿y...", 75);
        Sleep(1500);
        cout << endl;
        Function::writeDialogue("\tTrzymam ciê za rêkê i skaczê...", 75);
        Sleep(1500);
        cout << endl;
        Function::writeDialogue("\tSpadam i spadam jakby godzinami ...", 75);
        Sleep(2500);
        cout << endl;
        cout << "" << endl;
    }*/
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::wakeUpAloneInDarkAlley()
{
    //if (Game().getLang() == en)
    //{
        darkAlleyWasVisited = true;
        Sleep(2000);
        Function::writeNarration("\tYou wake up dazed from a restless slumber.");
        Sleep(1000);
        Function::writeNarration(" It was the same dream again...");
        Sleep(1500);
        cout << endl;
        Function::writeNarration("\tYou are somewhere in a dark alley. Above your head, among the smoggy haze, as if torn from\n\ta dream, rise the monumental skyscrapers of large corporations.");
        Sleep(1000);
        Function::writeNarration(" Their divine majesty beats\n\tyou to the eyes.");
        Sleep(3000);
        cout << endl;
        Function::writeNarration("\tYour heart beats so hard that only the stinging touch of the wind protects you from a sudden\n\theart attack.");
        Sleep(500);
        Function::writeNarration(" Suddenly a wave of shivers comes over your body, you start shaking like an\n\taspen, and realize that you are lying on a lair made of some old newspapers.");
        Sleep(3000);
        cout << endl;
        Function::writeNarration("\tWhen you rise from the ground, you notice a sea of trash around you.");
        Sleep(1000);
        Function::writeNarration(" It's full of cardboard\n\tboxes, old mechanical parts, and god knows what else.");
        Sleep(2500);
        cout << endl;
        Function::writeNarration("\tWho knows, you might find something interesting there...");
        cout << endl;
        cout << "" << endl;
        //-------------------------------------------------------------
        // Decyzja
        Function::actionOption(optionNr, "Search the area for something valuable."); // Opcja nr 1
        optionNr++;
        Function::actionOption(optionNr, "Find the exit from the alley."); // Opcja nr 2
        optionNr = 1;
        Function::write("\t> ", 15);
    /* }
    else
    {
        Function::writeNarration("\tBudzisz siê oszo³omiony z niespokojnej drzemki.");
        Sleep(1000);
        Function::writeNarration(" To by³ znowu ten sam sen...");
        Sleep(1500);
        cout << endl;
        Function::writeNarration("\tZnajdujesz siê gdzieœ w ciemnym zau³ku. Nad twoj¹ g³ow¹, wœród smogowej mg³y, niczym wyrwane ze snu, wznosz¹ siê monumentalne drapacze chmur wielkich korporacji.");
        Sleep(1000);
        Function::writeNarration(" Ich boski majestat bije ciê po oczach.");
        Sleep(2500);
        cout << endl;
        Function::writeNarration("\tSerce bije ci tak mocno, ¿e tylko szczypi¹cy dotyk wiatru chroni ciê przed nag³ym atakiem serca.");
        Sleep(500);
        Function::writeNarration(" Nagle przez twoje cia³o przechodzi fala dreszczy, zaczynasz trz¹œæ siê jak osika i uœwiadamiasz sobie, ¿e le¿ysz na legowisku zrobionym ze starych gazet.");
        Sleep(2000);
        cout << endl;
        Function::writeNarration("\tKiedy podnosisz siê z ziemi, zauwa¿asz wokó³ siebie morze œmieci.");
        Sleep(1000);
        Function::writeNarration(" Jest pe³ne kartonów, starych czêœci mechanicznych i Bóg wie czego jeszcze.");
        Sleep(1500);
        cout << endl;
        Function::writeNarration("\tKto wie, mo¿e znajdziesz tam coœ interesuj¹cego...");
        cout << endl;
        cout << "" << endl;
        //-------------------------------------------------------------
        // Decyzja
        Function::actionOption(optionNr, "Rozejrzyj siê po okolicy w poszukiwaniu czegoœ cennego."); // Opcja nr 1
        optionNr++;
        Function::actionOption(optionNr, "ZnajdŸ wyjœcie z zau³ka."); // Opcja nr 2
        optionNr = 1;
        Function::write("\t> ", 15);
    }*/

    while (true)
    {
        cin >> heroChoice;

        if (heroChoice == 1)
        {
            Sleep(1000);
            Function::clearScreen();
            inSeaOfRubbish();
            break;
        }
        else if (heroChoice == 2)
        {
            Sleep(1000);
            Function::clearScreen();
            outOfTheAlley();
            break;
        }
    }
    //-------------------------------------------------------------
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::inSeaOfRubbish()
{
    Function::showHeroAction("Search the area for something valuable.");
    cout << endl;
    Function::writeNarration("\tYou start rummaging through the trash.");
    Sleep(1500);
    Function::writeNarration(" The search takes a long while, but eventually you\n\tmanage to find something.");
    Sleep(2000);
    cout << endl << endl;
    //Event::showTakeItemInfo(items["AD13"]);
    itemPointer = &items["AD13"];
    heroes["Hero"].addItem(itemPointer);

    Function::changeConsoleColor(item);
    string str = "\t" + items["AD13"].getName();
    Function::write(str);
    Function::changeConsoleColor();
    Function::write(" was found.");
    Function::write("\t[TIP: This item has been added to your inventory. You can view it in the text file in your\n\tgame folder.]", 15);
    Sleep(4000);
    cout << endl << endl;
    Function::writeNarration("\tHmm, that might come in handy in the future.");
    Sleep(1000);

    outOfTheAlley();
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::outOfTheAlley()
{
    itemPointer = &items["AD13"];

    if (!heroes["Hero"].isHaveItem(itemPointer))
    {
        Function::showHeroAction("Find the exit from the alley.");
        cout << endl;
        Function::writeNarration("\tYou're not going to rummage through the trash.");
        Sleep(1500);
        Function::writeNarration(" And that's okay, you probably wouldn't find\n\tanything there anyway.");
        Function::writeNarration(" Instead, you slowly toddle toward the neon color bombs at the end of\n\tthe alley.");
    }
    else {
        cout << endl;
        Function::writeNarration("\tYou slowly toddle toward the neon color bombs at the end of the alley.");
    }

    Sleep(3000);
    cout << endl;
    Function::writeNarration("\tYou are getting closer and closer to your goal when from the right, from behind a veil of\n\tshadows, a low, not very pleasant voice belonging to a man speaks up.");
    cout << endl;
    Function::writeDialogue("\t- 'Hey, kid. Wait for a second.'");
    cout << endl;
    cout << "" << endl;
    //-------------------------------------------------------------
    // Decyzja
    Function::actionOption(optionNr, "Stop and find out what he wants."); // Opcja nr 1
    optionNr++;
    Function::actionOption(optionNr, "Ignore him and keep walking."); // Opcja nr 2
    optionNr = 1;
    Function::write("\t> ", 15);

    while (true)
    {
        cin >> heroChoice;

        if (heroChoice == 1)
        {
            Function::clearScreen();
            Function::showHeroAction("Stop and find out what he wants.");
            cout << endl;
            Function::writeNarration("\tYou stop and turn towards the owner of the voice.");
            Sleep(1500);
            Function::writeNarration(" His silhouette looms in the darkness. It's\n\tone of the homeless people who live here. What can he have for you?");
            cout << endl;
            Sleep(1000);
            conversationWithHomeless();
            break;
        }
        else if (heroChoice == 2)
        {
            Function::clearScreen();
            Function::showHeroAction("Ignore him and keep walking.");
            cout << endl;
            Function::writeNarration("\tYou have a mysterious stranger for nothing. You speed up your step and leave him far behind you.\n\tWhatever he wanted from you is no longer important.");
            Sleep(1000);
            street();
            break;
        }
    }
    //-------------------------------------------------------------
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::conversationWithHomeless()
{
    string heroName, str;

    Function::writeDialogue("\t- 'What's your name, boy?'");

    if (!npcs["Bob"].isKnowsHero() && !npcs["Caden"].isKnowsHero() && !npcs["CadenPartner"].isKnowsHero())
    {
        Function::changeConsoleColor();
        cout << endl;
        cout << "\t> ";
        cin >> heroName;
        heroes["Hero"].setName(heroName);
    }

    npcs["Bob"].setToKnowHero();
    str = "\t- 'So you're " + heroes["Hero"].getName() + ", huh?";
    Function::writeDialogue(str);
    Sleep(1500);
    str = " All right. I'm " + npcs["Bob"].getName() + ".";
    Function::writeDialogue(str);
    Sleep(1500);
    Function::writeDialogue(" What are you doin' here?'");
    cout << endl;
    Function::writeNarration("\tThe shadows in front of you, begin to ripple when your caller stands up.");
    //-------------------------------------------------------------
    // Decyzja
    cout << endl;
    cout << "" << endl;
    Function::dialogueOption(optionNr, "I'm not looking for trouble."); // Opcja nr 1
    optionNr++;
    Function::dialogueOption(optionNr, "I'm just looking around. Where are we actually?"); // Opcja nr 2
    optionNr++;
    Function::dialogueOption(optionNr, "It's not your business."); // Opcja nr 3
    optionNr = 1;
    Function::write("\t> ", 15);

    while (true)
    {
        cin >> heroChoice;

        if (heroChoice == 1)
        {
            Function::clearScreen();
            Function::showHeroAction("'I'm not looking for trouble.'");
            bobRecommendsZedToHero = true; // Bob poleca bohaterowi sklep z broni¹ Zeda
            cout << endl;
            Function::writeDialogue("\t- 'Ha-ha, that's what I thought. To tell you the truth, you don't look very threatening.");
            Sleep(1000);
            Function::writeDialogue(" Well,\n\tyou could use some gat. I happen to know a guy who deals guns. His name is Zed, and his store is\n\tright around the corner.");
            Sleep(1000);
            Function::writeDialogue(" Tell him you're coming from old Bob and he'll find something for you.'");
            cout << endl;
            break;
        }
        else if (heroChoice == 2)
        {
            Function::clearScreen();
            Function::showHeroAction("'I'm just looking around. Where are we actually?'");
            cout << endl;
            Function::writeDialogue("\t- 'What's wrong with you?");
            Sleep(1000);
            Function::writeDialogue(" Anyway, it doesn't matter.");
            Sleep(1500);
            Function::writeDialogue(" Have you ever heard of Megacity?");
            Sleep(1500);
            Function::writeDialogue(" Well,\n\tit's right here. The neighborhood we are currently in is called Gunce Deep.");
            Sleep(1000);
            Function::writeDialogue(" Did I make your\n\thead clearer?'");
            cout << endl;
            break;
        }
        else if (heroChoice == 3)
        {
            Function::clearScreen();
            Function::showHeroAction("'It's not your business.'");
            cout << endl;
            npcs["Bob"].setAttitude(angry); // angry / hostile / friendly / neutral
            Function::writeDialogue("\t- 'You're wrong. It's absolutely my business, kid. Don't shut your mouth like that, or you might\n\tlose a few teeth. Got it?'");
            cout << endl;
            break;
        }
    }
    //-------------------------------------------------------------
    if (!streetWasVisited)
    {
        Function::writeNarration("\tFinally, an old, wrinkled face surrounded by gray fuzz emerges from the darkness. An artificial,\n\tcybernetic eye watches you vigilantly.");
        Sleep(1000);
        Function::writeNarration(" You start to feel strangely uncomfortable.");
        Sleep(2000);
        cout << endl;
        Function::writeNarration("\tIn an instant the alley is filled with the howling of a police siren.");
        Sleep(1000);
        Function::writeNarration(" On the wall in front of\n\tyou, red and blue begin to dance with each other.");
        cout << endl;
        Function::writeDialogue("\t- 'Shit");
        Sleep(500);
        Function::writeDialogue(", cops!");
        Sleep(500);
        Function::writeDialogue(" Well, that's super. I think it's time for me to go.'");
        Sleep(1500);
        cout << endl;
        Function::writeNarration("\tThe aging beggar dives into the embrace of darkness in a flash.");
        Sleep(1500);
        Function::writeNarration(" Does this mean you see him for\n\tthe last time?");
        Sleep(3500);
        viewOfAmnesia();
    }
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// 2.2.2 ULICA
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::streetCrossroads()
{
    //-------------------------------------------------------------
    // Decyzja
    Function::showHeroAction("Visit: Street.");
    cout << endl;
    Function::writeNarration("\tOnce again you are on a street bathed in nighttime darkness.");
    cout << endl << endl;
    Function::changeConsoleColor();
    Function::actionOption(optionNr, "Visit: Dark Alley."); // Opcja nr 1
    optionNr++;
    Function::actionOption(optionNr, "Visit: Nightclub 'Amnesia'."); // Opcja nr 2
    optionNr++;
    Function::actionOption(optionNr, "Visit: Gun Shop."); // Opcja nr 3
    optionNr = 1;
    Function::write("\t> ", 15);

    while (true)
    {
        cin >> heroChoice;

        if (heroChoice == 1)
        {
            Function::clearScreen();
            darkAlley();
            break;
        }
        else if (heroChoice == 2)
        {
            Function::clearScreen();
            nightclub();
            break;
        }
        else if (heroChoice == 3)
        {
            Function::clearScreen();
            gunShop();
            break;
        }
    }
    //-------------------------------------------------------------
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::viewOfAmnesia()
{
    streetWasVisited = true;

    cout << endl;

    if (!npcs["Bob"].isKnowsHero())
    {
        Function::writeNarration("\tYou walk out of the alley onto a street lit by neon lights on the opposite side. A large sign\n\tthat reads 'Amnesia' belongs to a nightclub.");
        Sleep(1000);
        Function::writeNarration(" A small crowd gathers outside the entrance to the\n\tbuilding. Some people are arguing with the bouncers.");
        Sleep(1500);
        Function::writeNarration(" Something smells here, it's probably trouble...");
    }
    else {
        Function::writeNarration("\tYou walk out of the alley onto a street lit by neon lights and the lamp of a police car on the\n\topposite side. A large sign that reads 'Amnesia' belongs to a nightclub.");
        Function::writeNarration(" Two cops interrogate\n\ta small crowd outside the entrance to the building.");
        Sleep(1500);
        Function::writeNarration(" Something smells here, it's probably trouble...");
    }

    cout << endl;
    //-------------------------------------------------------------
    // Decyzja
    cout << "" << endl;
    Function::actionOption(optionNr, "Come closer and see what it's all about.");
    optionNr++;
    Function::actionOption(optionNr, "Take a look around the area.");
    optionNr = 1;
    Function::write("\t> ", 15);

    while (true)
    {
        cin >> heroChoice;

        if (heroChoice == 1)
        {
            Function::clearScreen();
            Function::showHeroAction("Come closer and see what it's all about.");
            cout << endl;

            if (!npcs["Bob"].isKnowsHero())
            {
                heroMeetSecurityGuards();
                heroMeetsPolicemans();
            }
            else {
                heroMeetsPolicemans();
            }
            break;
        }
        else if (heroChoice == 2)
        {
            Function::clearScreen();
            Function::showHeroAction("Take a look around the area.");
            heroMeetGunStore();
            break;
        }
    }
    //-------------------------------------------------------------
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::heroMeetGunStore()
{
    cout << endl;
    Function::writeNarration("\tYou go to the right side of the street. After walking several meters you come across a small booth\n\tbetween blocks of flats.");

    if (bobRecommendsZedToHero)
    {
        Function::writeNarration(" Could it be that the famous gun store managed by Bob's friend?");
    }

    cout << endl;
    Function::changeConsoleColor();
    //-------------------------------------------------------------
    // Decyzja
    cout << "" << endl;
    Function::actionOption(optionNr, "Go inside."); // Opcja nr 1
    optionNr++;
    Function::actionOption(optionNr, "Turn back."); // Opcja nr 2
    optionNr = 1;
    Function::write("\t> ", 15);

    while (true)
    {
        cin >> heroChoice;

        if (heroChoice == 1)
        {
            Function::clearScreen();
            Function::showHeroAction("Go inside.");
            cout << endl;
            enterGunShop();
            break;
        }
        else if (heroChoice == 2)
        {
            Function::clearScreen();
            Function::showHeroAction("Turn back.");
            cout << endl;

            if (!npcs["Bob"].isKnowsHero())
            {
                heroMeetSecurityGuards();
                heroMeetsPolicemans();
            }
            else {
                heroMeetsPolicemans();
            }
            break;
        }
    }
    //-------------------------------------------------------------
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::heroMeetSecurityGuards()
{
    Function::writeNarration("\tWhen you get closer, the faces turn toward you and start looking at you intently.");
    Sleep(1000);
    Function::writeNarration(" You pass them in silenceand are confronted by a broad - shouldered security guard.");
    cout << endl;
    Function::writeDialogue("\t- 'What are you looking for here?");
    Sleep(1500);
    Function::writeDialogue(" Trouble, maybe?'");
    cout << endl;
    Function::writeNarration("\tThe man clenches his hands into fists and smiles unpleasantly.");
    cout << endl;
    Function::writeDialogue("\t- 'You asshole, better let us in! I want a drink and for fuck's sake. I'm losing my patience!");
    cout << endl;
    Function::writeNarration("\tOne of the men waiting in the queue rushes forward and threatens the bouncer with his fist.");
    Sleep(1500);
    Function::writeNarration(" The security guard's attention shifts from you to the furious guy next to you.");
    cout << endl;
    Function::writeDialogue("\t- 'I'll say it one last time: get the fuck out of here or you'll get fucked.'");
    cout << endl;
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::heroMeetsPolicemans()
{
    string heroName;
    string str;

    if (npcs["Bob"].isKnowsHero())
    {
        Function::writeNarration("\tWhen you get closer, one of the police officers in a dark blue uniform turns toward you.");
    }
    else {
        Function::writeNarration("\tIn an instant the street is filled with the howling of a police siren.");
        Sleep(1000);
        Function::writeNarration(" The reds and blues begin to\n\tdance with each other on the sidewalk and the silhouettes of the people around you.");
        Sleep(2000);
        cout << endl;
        Function::writeNarration("\tTwo grim-looking guys in dark blue uniforms get out of a police car and walk towards you. One of them\n\tpoints at you, taking out a tablet from behind his belt.");
    }

    cout << endl;
    Function::writeDialogue("\t- 'Who are you?");
    Sleep(1500);
    Function::writeDialogue(" And what are you doing here? Please show me your ID card.'");
    cout << endl;

    itemPointer = &items["AD13"];

    if (heroes["Hero"].isHaveItem(itemPointer))
    {
        Function::writeNarration("\tYou start searching through the pockets of your jacket and pants, but other than the accelerator\n\tyou found in the trash, there's nothing else there.");
    }
    else {
        Function::writeNarration("\tYou start searching through the pockets of your jacket and pants, but there's nothing there.");
    }

    cout << endl;
    Function::writeDialogue("\t- 'I see that we have a problem.");
    Sleep(1500);
    Function::writeDialogue(" Okay, then what's your name, citizen?");

    if (!npcs["Bob"].isKnowsHero())
    {
        Function::writeDialogue("'");
        cout << endl;
        cout << "\t> ";
        cin >> heroName;
        heroes["Hero"].setName(heroName);
        cout << endl;
        str = "\t- '" + heroes["Hero"].getName() + "...";
        Function::writeDialogue(str);
        Sleep(1000);
        Function::writeDialogue(" Caden, check it out in the database.");
    }
    else {
        str = " " + heroes["Hero"].getName() + "...";
        Function::writeDialogue(str);
        Sleep(1000);
        Function::writeDialogue(" Caden, check\n\tit out in the database.");
    }

    npcs["CadenPartner"].setToKnowHero();
    npcs["Caden"].setToKnowHero();
    Sleep(1500);
    Function::writeDialogue(" And you, stand where you are.'");
    cout << endl;
    Function::writeNarration("\tThe other police officer nods, gets back in the car, and it looks like he's connecting with headquarters.");
    Sleep(3000);
    cout << endl;
    Function::writeNarration("\tA minute later, the same policeman returns and whispers something in his partner's ear.");
    Sleep(1500);
    Function::writeNarration(" That one nods and turns to look at you.");
    cout << endl;
    Function::writeDialogue("\t- 'I have good news for you.");
    Sleep(1500);
    Function::writeDialogue(" You're free for now, just don't let it occur to you to do something here, or you'll end up in arrest at the police station.");
    Sleep(1000);
    Function::writeDialogue(" Caden, take care of the rest of the attendees.'");
    cout << endl;
    Function::writeNarration("\tThe cop walks away to talk to the nearest person standing.");
    cout << endl;
    Function::writeDialogue("\t- 'If you're so pure, get in.'");
    cout << endl;
    Function::writeNarration("\tThe bouncer points to the door behind him.");
    cout << endl;
    //-------------------------------------------------------------
    // Decyzja
    Function::changeConsoleColor();
    cout << "" << endl;
    Function::actionOption(optionNr, "Go inside."); // Opcja nr 1
    optionNr++;
    Function::actionOption(optionNr, "Turn back."); // Opcja nr 2
    optionNr = 1;
    Function::write("\t> ", 15);

    while (true)
    {
        cin >> heroChoice;

        if (heroChoice == 1)
        {
            Function::clearScreen();
            Function::showHeroAction("Go inside.");
            cout << endl;
            nightclub();
            break;
        }
        else if (heroChoice == 2)
        {
            Function::clearScreen();
            Function::showHeroAction("Turn back.");
            cout << endl;
            heroMeetGunStore();
            break;
        }
    }
    //-------------------------------------------------------------
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// 2.2.3 SKLEP Z BRONI¥
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::gunShopCrossroads()
{

}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::enterGunShop()
{
    gunShopWasVisited = true;

    Function::writeNarration("\tThe front door hisses open before you.");

    if (!npcs["Zed"].isKnowsHero())
    {
        Sleep(1000);
        Function::writeNarration(" You step over the threshold and enter a small room with a counter opposite the entrance. Behind it stands a tall, thin man with fatigue painted on his terribly oblong face.");
        Sleep(1500);
        Function::writeNarration(" He is dressed in an old corporate commando suit. On the wall behind his back hangs a lot of weapons.");
        cout << endl;
        Function::writeDialogue("\t- 'How can I help you, my friend?'");
        cout << endl;
        npcs["Zed"].setToKnowHero();
        dialogueWithZed();
    }
    else {
        Sleep(1000);
        Function::writeNarration(" From behind the counter, Zed is already smiling at you.");

        itemPointer = &items["Pistol"];

        if (heroes["Hero"].isHaveItem(itemPointer))
        {
            cout << endl;
            Function::writeDialogue("\t- 'What's up? How's the gun working out?'");
        }

        if (quests["ZedAccelerator"].isRunning() && !quests["ZedAccelerator"].isCompleted())
        {
            itemPointer = &items["AD13"];

            if (!heroes["Hero"].isHaveItem(itemPointer))
            {
                dialogueWithZed();
            }
            else
            {

            }
        }
        else
        {

        }
    }
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::dialogueWithZed()
{
    bool heroTalkedAboutBusinessWithZed = false;

    while (true)
    {
        //-------------------------------------------------------------
        // Decyzja
        Function::changeConsoleColor();
        cout << "" << endl;

        Function::dialogueOption(optionNr, "What do you have?");
        optionNr++;
        Function::dialogueOption(optionNr, "How's business going?");
        optionNr++;

        if (bobRecommendsZedToHero && !zedKnowsAboutBobFriendshipWithHero)
        {
            Function::dialogueOption(optionNr, "You're Zed? I come from Bob.");
            optionNr++;
        }

        Function::dialogueOption(optionNr, "I have to go...");
        optionNr = 1;
        Function::write("\t> ", 15);

        cin >> heroChoice;

        if (heroChoice == 1)
        {
            cout << endl;
            zedTrade();
            continue;
        }
        else if (heroChoice == 2)
        {
            cout << endl;

            if (heroTalkedAboutBusinessWithZed == true)
            {
                Function::writeDialogue("\t- 'Hey, what's up? Are you sclerotic or something? We already talked about this, haha!'");
                cout << endl;
            }
            else {
                heroTalkedAboutBusinessWithZed = true;
                Function::writeDialogue("\t- 'What kind of question is that anyway? Business is doing great! Everyone stops by every now and then to rearm. It's the natural order of things.'");
                cout << endl;
            }

            continue;
        }
        else if (heroChoice == 3)
        {
            cout << endl;

            if (bobRecommendsZedToHero && !zedKnowsAboutBobFriendshipWithHero)
            {
                zedKnowsAboutBobFriendshipWithHero = true;
                cout << endl;
                Function::writeDialogue("\t- 'Yes, that is correct. I'm Zed, and this is my little shop.");
                npcs["Zed"].setAttitude(friendly);
                Sleep(1000);
                Function::writeDialogue(" Since you know Bob, you can get a small discount here'.");
                continue;
            }
            else {
                Function::writeDialogue("\t- 'No problem. See you later!'");
                cout << endl;
                Function::clearScreen();

                if (!npcs["Caden"].isKnowsHero() && !npcs["CadenPartner"].isKnowsHero())
                {
                    heroMeetsPolicemans();
                }
                else
                {
                    street();
                }

                break;
            }
        }
        else if (heroChoice == 4 && bobRecommendsZedToHero && !zedKnowsAboutBobFriendshipWithHero)
        {
            cout << endl;
            Function::writeDialogue("\t- 'No problem. See you later!'");
            cout << endl;

            if (!npcs["Caden"].isKnowsHero() && !npcs["CadenPartner"].isKnowsHero())
            {
                heroMeetsPolicemans();
            }
            else
            {
                street();
            }

            break;
        }
    }
    //-------------------------------------------------------------
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::zedTrade()
{
    bool ZedTellsAboutWeapons = false;

    itemPointer = &items["Pistol"];

    if (!heroes["Hero"].isHaveItem(itemPointer))
    {
        if (!ZedTellsAboutWeapons)
        {
            ZedTellsAboutWeapons = true;
            Function::writeDialogue("\t- 'Better ask what I don't have!");
            Sleep(1000);
            Function::writeDialogue(" Look - ");
            Sleep(1000);
            Function::writeDialogue("rifles, pistols, machine guns, shotguns. I have a melee weapons as well. Knives, hammers, long blades like katanas...");
            Sleep(1500);
            Function::writeDialogue(" Anything you want, my friend!");
            Sleep(1500);
            Function::writeDialogue(" Tell me, what do you like?'");
            // Decyzja
            cout << endl;
            Function::changeConsoleColor();
            cout << "" << endl;
            Function::actionOption(optionNr, "Buy: pistol (250 $)."); // Opcja nr 1
            optionNr++;
            Function::dialogueOption(optionNr, "I have made up my mind."); // Opcja nr 2
            optionNr = 1;
            Function::write("\t> ", 15);

            while (true)
            {
                cin >> heroChoice;

                if (heroChoice == 1)
                {
                    buyPistol();

                    break;
                }
                else if (heroChoice == 2)
                {
                    cout << endl;
                    Function::writeNarration("Zed looks at you pityingly and shrugs his shoulders.");
                    cout << endl;
                    Function::writeDialogue("\t- 'No problem. It can happen to anyone.'");
                    cout << endl;
                    dialogueWithZed();
                    break;
                }
            }
        }
        else
        {
            // Decyzja
            Function::changeConsoleColor();
            cout << "" << endl;
            Function::actionOption(optionNr, "Buy: pistol (250 $)."); // Opcja nr 1
            optionNr++;
            Function::dialogueOption(optionNr, "I have made up my mind."); // Opcja nr 2
            optionNr = 1;
            Function::write("  > ", 15);

            while (true)
            {
                cin >> heroChoice;

                if (heroChoice == 1)
                {
                    buyPistol();

                    break;
                }
                else if (heroChoice == 2)
                {
                    cout << endl;
                    Function::writeNarration("Zed looks at you pityingly and shrugs his shoulders.");
                    cout << endl;
                    Function::writeDialogue("\t- 'No problem. It can happen to anyone.'");
                    cout << endl;
                    dialogueWithZed();
                    break;
                }
            }
        }
    }
    else
    {
        Function::changeConsoleColor();
        Function::write("You have everything you need. There's no point in bothering Zed.");
        cout << endl;
        dialogueWithZed();
    }
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::buyPistol()
{
    string str;

    cout << endl;

    if (heroes["Hero"].getMoney() != 250.0)
    {
        Function::writeDialogue("\t- 'I see you're low on cash.");
        Sleep(1000);
        Function::writeDialogue(" But don't worry, we'll sort it out somehow.");
        Sleep(1500);

        if (zedKnowsAboutBobFriendshipWithHero)
        {
            Function::writeDialogue(" Hmm, you know Old Bob, that already means something.");
            Sleep(1000);
            Function::writeDialogue(" Let's just say I'll loan you this gun on a friendly basis.");

            itemPointer = &items["Pistol"];
            heroes["Hero"].addItem(itemPointer);

            cout << endl;
            Function::changeConsoleColor(item);
            str = "\t" + items["Pistol"].getName();
            Function::write(str);
            Function::changeConsoleColor();
            Function::write(" gained.");
            cout << endl;
        }
        else
        {
            quests["ZedAccelerator"].start();

            Function::writeDialogue(" It so happens that I have been looking for a good accelerator for some time.");
            Sleep(1000);
            Function::writeDialogue(" I don't mean the crap produced by corporations these days.");
            Sleep(1000);
            Function::writeDialogue(" I mean the good old accelerator!");
            Sleep(1500);
            Function::writeDialogue(" Find me such a device and you will get that gun. Okay?");
        }
    }
    else
    {
        Function::writeDialogue("\t- 'A pistol is a good start. Here, it's yours.'");

        itemPointer = &items["Pistol"];
        heroes["Hero"].addItem(itemPointer);

        cout << endl;
        Function::changeConsoleColor(item);
        str = "\t" + items["Pistol"].getName();
        Function::write(str);
        Function::changeConsoleColor();
        Function::write(" was bought.");
        cout << endl;
    }
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// 2.2.4 KLUB NOCNY
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::nightclubCrossroads()
{
    //-------------------------------------------------------------
    // Decyzja
    Function::showHeroAction("Visit: Nightclub 'Amnesia'.");
    cout << endl;
    Function::writeNarration("\tYou enter from a fairly well-lit street into a slightly darkened nightclub, trembling with colour.");
    cout << endl << endl;
    Function::changeConsoleColor();
    Function::actionOption(optionNr, "Go to the dance floor."); // Opcja nr 1
    optionNr++;
    Function::actionOption(optionNr, "Go to the bar."); // Opcja nr 2
    optionNr++;
    Function::actionOption(optionNr, "Go upstairs."); // Opcja nr 3
    optionNr++;
    Function::actionOption(optionNr, "Visit: Street."); // Opcja nr 4
    optionNr = 1;
    Function::write("\t> ", 15);

    while (true)
    {
        cin >> heroChoice;

        if (heroChoice == 1)
        {
            cout << endl;
            darkAlley();
            break;
        }
        else if (heroChoice == 2)
        {
            cout << endl;
            nightclub();
            break;
        }
        else if (heroChoice == 3)
        {
            cout << endl;
            gunShop();
            break;
        }
        else if (heroChoice == 4)
        {
            cout << endl;
            street();
            break;
        }
    }
    //-------------------------------------------------------------
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::enterClub()
{
    nightclubWasVisited = true;
    cout << endl;
    Function::writeNarration("\tAfter passing through the entrance your eardrums are slowly bursting from the loud music in the club.");
    Sleep(1000);
    Function::writeNarration(" You walk through a short lobby and so arrive at a crowded room full of dancing people.");
    Sleep(1000);
    Function::writeNarration(" Disco balls hung from the ceiling net everything around with streaks of multi-colored light.");
    Sleep(1000);
    Function::writeNarration(" Next to the dance floor is a bar, and behind it are several mechanically streamlined bartenders.");
    cout << endl;
    //-------------------------------------------------------------
    // Decyzja
    Function::changeConsoleColor();
    cout << "" << endl;
    Function::actionOption(optionNr, "Go dance on the dance floor."); // Opcja nr 1
    optionNr++;
    Function::actionOption(optionNr, "Go to the bar."); // Opcja nr 2
    optionNr = 1;
    Function::write("\t> ", 15);

    while (true)
    {
        cin >> heroChoice;

        if (heroChoice == 1)
        {
            cout << endl;
            clubDanceFloor();
            break;
        }
        else if (heroChoice == 2)
        {
            cout << endl;
            clubBar();
            break;
        }
    }
    //-------------------------------------------------------------
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::clubDanceFloor()
{
    Function::showHeroAction("Go dance on the dance floor.");
    cout << endl;

    if (!npcs["Mia"].isKnowsHero())
    {
        Function::writeNarration("\tYou get on the dance floor.");
        Sleep(1000);
        Function::writeNarration(" A crowd of dancing people stretches out around you, rubbing\n\tagainst each other to the rhythm of the music.");
        Sleep(1500);
        Function::writeNarration(" Half-naked beauties are dancing in places\n\tthat look like pillars supporting the ceiling. You are not sure if they are real. There\n\tis a definite possibility that they are women, but somewhere in the back of your mind you\n\tthink they are just androids.");
        Sleep(1500);
        Function::writeNarration("\n\tYou start dancing yourself.");
        Sleep(1000); 
        Function::writeNarration(" You are doing quite well when an attractive girl appears in\n\tfront of you. She's wearing a see-through, brightly coloured dress.");
        Sleep(1500);
        Function::writeNarration(" Is it a coincidence\n\tthat she has just appeared and is dancing so close to you?");
        //-------------------------------------------------------------
        // Decyzja
        Function::changeConsoleColor();
        cout << endl << endl;
        Function::actionOption(optionNr, "'What do you want?'"); // Opcja nr 1
        optionNr++;
        Function::actionOption(optionNr, "'Hey, baby.'"); // Opcja nr 2
        optionNr++;
        Function::actionOption(optionNr, "Keep dancing with no words."); // Opcja nr 3
        optionNr = 1;
        Function::write("\t> ", 15);

        while (true)
        {
            cin >> heroChoice;

            if (heroChoice == 1)
            {
                Function::clearScreen();
                cout << endl;
                Function::showHeroAction("'What do you want?'");
                cout << endl;
                Function::writeNarration("\tThe girl turns towards you and smiles with her snow-white teeth.");
                Function::writeDialogue("\n\t- 'Nothing will escape your attention. I am Mia. Vincent, the owner, is my boyfriend. I\n\tthink you can help me.'");
                break;
            }
            else if (heroChoice == 2)
            {
                Function::clearScreen();
                cout << endl;
                Function::showHeroAction("'Hey, baby.'");
                cout << endl;
                break;
            }
            else if (heroChoice == 3)
            {
                Function::clearScreen();
                cout << endl;
                Function::showHeroAction("Keep dancing with no words.");
                cout << endl;
                break;
            }
        }
        //-------------------------------------------------------------
        miaMeeting();
    }
    else
    {
        Function::writeNarration("\tYou get on the dance floor.");
        Sleep(1000);
        Function::writeNarration(" It's quite crowded, but at least you can enjoy the beautiful\n\tviews. You try to keep up with the rest of the people dancing there. However, you quickly\n\tget tired and head for the exit.");
        Sleep(1500);
        Function::clearScreen();
        nightclubCrossroads();
    }
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::clubBar()
{
    heroIsAtBar = true;

    Function::writeNarration("\tWith a slow step, you approach the counter, settle comfortably on a stool, and lift your gaze to the barman in front of you.");
    cout << endl;
    Function::writeDialogue("\t- 'What's for you?'");
    cout << endl;
    //-------------------------------------------------------------
    // Decyzja
    Function::changeConsoleColor();
    cout << "" << endl;
    Function::dialogueOption(optionNr, "'Give me anything.'"); // Opcja nr 1
    optionNr++;
    Function::dialogueOption(optionNr, "'Who's in charge?'"); // Opcja nr 2
    optionNr++;
    Function::dialogueOption(optionNr, "'Bye.'"); // Opcja nr 3
    optionNr = 1;
    Function::write("\t> ", 15);

    while (true)
    {
        cin >> heroChoice;

        if (heroChoice == 1)
        {
            cout << endl;
            Function::writeDialogue("\t- 'Okay.");
            Sleep(1000);
            Function::writeDialogue(" Let's see...'");
            Sleep(1500);
            cout << endl;
            Function::writeNarration("\tThe barman turns his back on you and looks through the bottles of alcohol. Finally, he selects one of them and pours its contents into a glass before placing it on the counter in front of you.");
            Sleep(1500);
            cout << endl;
            Function::writeNarration("\tYou reach for the vessel and empty it.");
            Sleep(1000);
            Function::writeNarration(" You feel a pleasant warmth spreading up your throat and further down your gullet.");
            break;
        }
        else if (heroChoice == 2)
        {
            cout << endl;
            Function::writeNarration("\tThe bartender squints, hearing your question.");
            cout << endl;
            Function::writeDialogue("\t- 'You're not from around here, are you?");
            Sleep(1500);
            Function::writeDialogue(" My boss is Vincent Ramsey.");
            Sleep(1000);
            Function::writeDialogue(" He's a tough guy, so you'd better not make trouble, or it could end badly for you.'");
            break;
        }
        else if (heroChoice == 3)
        {
            cout << endl;
            Function::writeNarration("\tThe bartender reaches for a glass from under the counter and starts wiping it down.");
            cout << endl;
            Function::writeDialogue("\t- 'Yeah, have fun.'");
            break;
        }
    }
    //-------------------------------------------------------------
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::miaMeeting()
{

}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::vincentAssassination()
{
    vincentOffice();
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::vincentOffice()
{
    Function::writeNarration("\tYou enter the manager's office immersed in twilight. In the middle of the room stands a sizable desk, and on it are stacks of documents and computer. To the left of the entrance is a window to the street below. On the right you will notice a door to another room.");
    cout << endl;
    //-------------------------------------------------------------
    // Decyzja
    Function::changeConsoleColor();
    cout << "" << endl;
    Function::actionOption(optionNr, "Open the door and go into the other room."); // Opcja nr 1
    optionNr++;
    Function::actionOption(optionNr, "Stay and search the office."); // Opcja nr 2
    optionNr = 1;
    Function::write("\t> ", 15);

    while (true)
    {
        cin >> heroChoice;

        if (heroChoice == 1)
        {
            vincentHideoutCode();
            break;
        }
        else if (heroChoice == 2)
        {
            checkVincentDesk();
            break;
        }
    }
    //-------------------------------------------------------------
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::checkVincentDesk()
{
    heroKnowsVincentHideoutCode = true;
    Function::showHeroAction("Stay and search the office.");
    cout << endl;
    Function::writeNarration("\tYou walk up to the desk. You start flipping through the e-papers one by one and finally your gaze falls on the flickering blue monitor.");
    cout << endl;
    Function::write("\t");

    vincentHideoutCode();
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::vincentHideoutCode()
{
    cout << endl;
    Function::writeNarration("\tYou walk closer and spot the terminal. It looks like you'll need to use a code to get through.");
    Sleep(1500);

    if (!heroKnowsVincentHideoutCode)
    {
        Function::writeNarration(" You have to look around the office though, whether you want to or not.");
    }
    else {
        cout << endl;
        Function::changeConsoleColor();
        cout << "" << endl;
        Function::actionOption(optionNr, "Use code '2021'."); // Opcja nr 1
        optionNr++;
        Function::actionOption(optionNr, "Search the office."); // Opcja nr 2
        Function::write("\t> ", 15);
    }
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::vincentHideout()
{
    cout << endl;
    Function::writeNarration("\tThe door closes behind you, hissing quietly.");
    Sleep(2000);
    Function::writeNarration(" The room you're in is full of smaller and larger\n\tcables that merge into a single monitor that hangs above the sim-chair. On it lies a big guy\n\tin a tailored suit and a stimulation helmet on his head that obscures his face.");
    Sleep(1500);
    Function::writeNarration(" You guess it's\n\tVincent, the club owner.");
    Sleep(2000);
    cout << endl;
    Function::writeNarration("\tCreeping up, you come closer. Your goal is within reach. The question is what will you do?");
    cout << endl;
    //-------------------------------------------------------------
    // Decyzja
    Function::changeConsoleColor();
    cout << "" << endl;
    Function::actionOption(optionNr, "Disconnect his consciousness from the neuronet. (Kill him)"); // Opcja nr 1
    optionNr++;
    Function::actionOption(optionNr, "Wait for his consciousness to leave the neuronet."); // Opcja nr 2
    optionNr = 1;
    Function::write("\t> ", 15);

    while (true)
    {
        cin >> heroChoice;

        if (heroChoice == 1)
        {
            Function::clearScreen();
            Function::showHeroAction("Disconnect his consciousness from the neuronet. (Kill him)");
            cout << endl;
            Function::writeNarration("\tYou lean over Vincent and, in a fluid motion without hesitation, pull the stimulation helmet\n\toff his head. You witness the nightclub owner being shaken by a wave of convulsions. Foam\n\tbegins to come out of his mouth and after a moment the man freezes.");
            Sleep(1500);
            Function::writeNarration(" He's probably dead, just like\n\tMia wanted.");
            npcs["Vincent"].kill();
            break;
        }
        else if (heroChoice == 2)
        {
            Function::clearScreen();
            Function::showHeroAction("Wait for his consciousness to leave the neuronet.");
            cout << endl;
            Function::writeNarration("\tYou are not a coward.");
            Sleep(1000);
            Function::writeNarration(" You don't stab people in the back. That's not your style. You prefer an\n\topen fight.");
            Sleep(1500);
            Function::writeNarration(" After a while, you notice Vincent moving slightly in his seat. He opens his eyes -\n\tthey are shining with the excitement of his online adventure.");
            Sleep(1000);
            Function::writeNarration(" It is only a matter of time before\n\tVincent notices your presence. There is no turning back now.");
            cout << endl;
            Function::writeDialogue("\t- 'What the fuck are you doing here, dickhead?'");
            cout << endl;
            dialogueWithVincent();
            break;
        }
    }
    //-------------------------------------------------------------
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::dialogueWithVincent()
{
    //-------------------------------------------------------------
    // Decyzja
    cout << endl;
    Function::changeConsoleColor();
    cout << "" << endl;
    Function::dialogueOption(optionNr, "Die!"); // Opcja nr 1
    optionNr++;
    Function::dialogueOption(optionNr, "I don't want to fight with you."); // Opcja nr 2
    optionNr++;
    Function::dialogueOption(optionNr, "Mia wants you dead."); // Opcja nr 3
    optionNr = 1;
    Function::write("\t> ", 15);

    while (true)
    {
        cin >> heroChoice;

        if (heroChoice == 1)
        {
            Function::clearScreen();
            Function::showHeroAction("'Die!'");
            cout << endl;
            Function::writeNarration("\tWith a shout, you bring out your gun and aim it at Vincent's chest.");
            cout << endl;
            Function::writeDialogue("\t- 'Are you such a hero?");
            Sleep(1000);
            Function::writeDialogue(" Would you kill an unarmed man?");
            Sleep(1000);
            Function::writeDialogue(" All right, can I at least find out who\n\tsent you? I know you're not working alone. I'm seeing you for the first time in my life.'");
            break;
        }
        else if (heroChoice == 2)
        {
            Function::clearScreen();
            Function::showHeroAction("'I don't want to fight with you.'");
            cout << endl;
            Function::writeNarration("\tYou are not a coward.");
            Sleep(1000);
            Function::writeNarration(" You don't stab people in the back. That's not your style. You prefer an\n\topen fight.");
            break;
        }
        else if (heroChoice == 3)
        {
            Function::clearScreen();
            Function::showHeroAction("'Mia wants you dead.'");
            cout << endl;
            Function::writeNarration("\tYou are not a coward. You don't stab people in the back. That's not your style. You prefer an open fight.");
            break;
        }
    }
    //-------------------------------------------------------------
    // Decyzja
    cout << endl;
    Function::changeConsoleColor();
    cout << "" << endl;
    Function::dialogueOption(optionNr, "It doesn't matter."); // Opcja nr 1
    optionNr++;
    Function::dialogueOption(optionNr, "Your girlfriend, Mia."); // Opcja nr 2
    optionNr = 1;
    Function::write("\t> ", 15);

    while (true)
    {
        cin >> heroChoice;
        
        if (heroChoice == 1)
        {
            Function::clearScreen();
            Function::showHeroAction("'It doesn't matter.'");
            cout << endl;
            Function::writeDialogue("\t- 'Ugh, you little prick. I'll get you from beyond the grave. There will be no peace. I won't let that happen!'");
            Sleep(1500);
            cout << endl;
            Function::writeNarration("\tThe last word spoken synchronizes with the bang of a gunshot as a bullet of energy pierces the club owner's chest.");
            Sleep(1000);
            Function::writeNarration(" The recoil knocks him from his seat. The lifeless body clatters against the floor.");
            Sleep(1500);
            Function::writeNarration(" He's dead, just like Mia wanted.");
            npcs["Vincent"].kill();
            cout << endl;
            Function::writeNarration("\tOut of curiosity, you walk closer and spot the corpse holding a small pistol.");
            Sleep(1000);
            Function::writeNarration(" That bastard was playing for time after all!");
            break;
        }
        else if (heroChoice == 2)
        {
            Function::clearScreen();
            Function::showHeroAction("'Your girlfriend, Mia.'");
            cout << endl;
            Function::writeDialogue("\t- 'Traitorous bitch! She'll get her due someday.");
            Function::writeDialogue(" All right, shithead, let's get this over with.'");
            cout << endl;
            Function::writeNarration("\tThe last word spoken synchronizes with the bang of a gunshot as a bullet of energy pierces the club owner's chest.");
            Sleep(1000);
            Function::writeNarration(" The recoil knocks him from his seat. The lifeless body clatters against the floor.");
            Sleep(1500);
            Function::writeNarration(" He's dead, just like Mia wanted.");
            npcs["Vincent"].kill();
            cout << endl;
            Function::writeNarration("\tOut of curiosity, you walk closer and spot the corpse holding a small pistol.");
            Sleep(1000);
            Function::writeNarration(" That bastard was playing for time after all!");
            break;
        }
    }
    //-------------------------------------------------------------
    cout << endl;
    Function::writeNarration("\tThe passage behind your back is opened.");
    Sleep(1000);
    Function::writeNarration(" You turn around, in front of you is Mia.");
    cout << endl;
    Function::writeDialogue("\t- 'Did you do what I asked you to do...'");
    Sleep(1500);
    cout << endl;
    Function::writeNarration("\tThe girl's gaze wanders from you to the body of her ex-boyfriend behind you.");
    Sleep(1000);
    cout << endl;
    Function::writeDialogue("\t- 'You did it... You really did it... Is he - is he dead?'");
    Sleep(1000);
    cout << endl;
    Function::writeNarration("\tMia walks past you and kneels by the dead man. She starts searching his pockets for something.");
    //-------------------------------------------------------------
    // Decyzja
    cout << endl;
    Function::changeConsoleColor();
    cout << "" << endl;
    Function::actionOption(optionNr, "Do nothing."); // Opcja nr 1
    optionNr++;
    Function::dialogueOption(optionNr, "What is this all about?"); // Opcja nr 2
    optionNr = 1;
    Function::write("\t> ", 15);

    while (true)
    {
        cin >> heroChoice;

        if (heroChoice == 1)
        {
            cout << endl;
            Function::writeNarration("\tYou let the girl quietly plunder the corpse. This gives you more time to look at her shapes more closely.");
            cout << endl;
            Function::writeDialogue("\t- 'Spare me, if you please.'");
            break;
        }
        else if (heroChoice == 2)
        {
            cout << endl;
            Function::writeDialogue("\t- 'Well, now I think I owe you an explanation.'");
            Function::writeNarration("\tA girl talks to you without even looking at you.");
            cout << endl;
            break;
        }
    }
    //-------------------------------------------------------------
    vincentResurrection();
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::vincentResurrection()
{
    cout << endl;
    Function::writeNarration("\tSuddenly, the maze of cables begins to vibrate and move in a strange dance.");
    Sleep(1000);
    Function::writeNarration(" Hisses reach you and Mia, forming a gibberish that is difficult to understand.");
    cout << endl;
    Function::changeConsoleColor(dia_robot);
    Function::write("\t<You scum! You thought you got rid of me.");
    Sleep(1000);
    Function::write(" But you didn't.");
    Sleep(1000);
    Function::write(" I'm immortal now!>");
    cout << endl;
    Function::writeNarration("\tYou exchange a look with Mia. You both can't believe what's happening.");
    cout << endl;
    Function::writeDialogue("\t- 'What the fuck?!'");
    cout << endl;
    Function::changeConsoleColor(dia_robot);
    Function::write("\t<Before your new lover killed me, sweatheart, I managed to pour some of my consciousness into the net. I don't need my body anymore, nothing limits me anymore.");
    Sleep(1500);
    Function::changeConsoleColor(dia_robot);
    Function::write(" Now you will get what you deserve. The time for payment has come!");
    Sleep(1000);
    Function::write(" DIE!>");
    Function::waitForUserInput();
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::loadingFiles()
{
    Function::changeConsoleColor(dialogue);
    Function::write("\t||", 100);
    Sleep(1000);
    Function::write("=", 100);
    Sleep(1000);
    Function::write("=", 100);
    Sleep(1000);
    Function::write("=", 100);
    Sleep(1000);
    Function::write("=", 100);
    Sleep(1000);
    Function::write("=", 100);
    Sleep(1000);
    Function::write("=", 100);
    Sleep(1000);
    Function::write("=", 100);
    Sleep(1000);
    Function::write("=", 100);
    Sleep(1000);
    Function::write("=", 100);
    Sleep(1000);
    Function::write("=", 100);
    Sleep(1000);
    Function::write("=", 100);
    Sleep(1000);
    Function::write("=", 100);
    Sleep(1000);
    Function::write("=", 100);
    Sleep(1000);
    Function::write("=", 100);
    Sleep(1000);
    Function::write("=", 100);
    Sleep(1000);
    Function::write("=", 100);
    Sleep(1000);
    Function::write("=", 100);
    Sleep(1000);
    Function::write("=", 100);
    Sleep(1000);
    Function::write("=", 100);
    Sleep(1000);
    Function::write("=", 100);
    Function::write("||", 100);
    Sleep(1000);
    cout << endl;
    Function::write("\tDownload completed.");
    Function::changeConsoleColor();
}

// Komendy
/*
void Event::commands()
{
    if (heroChoice == 'help')
    {
        cout << endl;
        Function::write("\tUse the 'exit' command to leave the current session.");
    }
    else if (heroChoice == 'exit')
    {
        Function::clearScreen();
        Game().logo();
    }
}
*/

// Œmieræ bohatera
void Event::heroDeath()
{
    Sleep(500);
    Function::clearScreen();
    Function::changeConsoleColor(red);
    cout << endl;

    if (Game().getLang() == en)  Function::write("\tYOU ARE DEAD!", 25);
    else Function::write("\tNIE ¯YJESZ!", 25);

    Sleep(1000);
    cout << endl;
    cout << "" << endl;
    Function::changeConsoleColor();

    if (Game().getLang() == en)  Function::write("\tBack to menu...", 25);
    else Function::write("\tWróæ do menu...", 25);

    Function::waitForUserInput();
    Function::clearScreen();
    Game().logo();
}

// Koniec gry
void Event::gameOver()
{
    Sleep(500);
    Function::clearScreen();
    Function::changeConsoleColor(lightblue);
    cout << endl;

    if (Game().getLang() == en)  Function::write("\tTHE END", 25);
    else Function::write("\tKONIEC", 25);

    Sleep(1000);
    cout << endl << endl;
    Function::changeConsoleColor();
    Game().credits();

    cout << endl << endl;
    if (Game().getLang() == en)  Function::write("\tBack to menu...", 25);
    else Function::write("\tWróæ do menu...", 25);

    Function::waitForUserInput();
    Function::clearScreen();
    Game().logo();
}