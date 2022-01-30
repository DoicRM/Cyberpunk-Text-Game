#include "events.h"

map <string, Hero> heroes;
map <string, Npc> npcs;
map <string, Fraction> fractions;
map <string, Item> items;
map <string, Location> locations;
map <string, Quest> quests;

// INIT
// Inicjowanie bohatera
void Event::initHero()
{
    Hero hero;
    heroes["Hero"] = hero;
    //Inventory* heroInv = new Inventory;
    //EQ["HeroInv"] = heroInv;
}

// Inicjowanie frakcji
void Event::initFractionsNpcsAndLocations()
{
    //if (Game().getLang() == en)
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
        Location DarkAlley("Dark alley", 0, 1, Beggars, false);
        Location Street("Street", 0, 2, Police, false);
        Location Nightclub("Nightclub 'Amnesia'", 0, 3, Hammers, false);
        Location GunShop("Zed's Gun Shop", 0, 3, None, false);

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

// Inicjowanie przedmiotów
void Event::initItems()
{
    //if (Game().getLang() == en)
    //{
        Item AD13("Accelerator D-13", "Others", "A long gone accelerator model, though still quite precious.", 50);
        Item AccessCard("Access card", "Others", "It definitely matches the door leading to the locked room in Ramsey's office.", 0);
        Item Pistol("Pistol", "Weapons", "A simple weapon that shoots pure energy.", 250);

        items["AD13"] = AD13;
        items["AccessCard"] = AccessCard;
        items["Pistol"] = Pistol;
    /* }
    else if (Game().getLang() == pl)
    {
        Item AD13("Akcelerator D-13", "Inne", "Dawno nieu¿ywany model akceleratora, choæ wci¹¿ doœæ cenny.", 50);
        Item AccessCard("Karta dostêpu", "Inne", "Z pewnoœci¹ pasuje do drzwi prowadz¹cych do zablokowanego pomieszczenia w gabinecie Ramseya.", 0);
        Item Pistol("Pistolet", "Broñ", "Prosta broñ strzelaj¹ca czyst¹ energi¹.", 500);

        items["AD13"] = AD13;
        items["AccessCard"] = AccessCard;
        items["Pistol"] = Pistol;
    }
    */
}

// Inicjowanie zadañ
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

// Inicjowanie wszystkiego
void Event::initAll()
{
    Event::initHero();
    Event::initFractionsNpcsAndLocations();
    Event::initItems();
    Event::initQuests();
    Function::initHeroEQ();
    Function::initQuestsList();
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// INICJOWANIE
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+ Inicjowanie zmiennych
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
bool BobRecommendsZedToHero = false, heroKnowsVincentHideoutCode = false, heroIsOnDanceFloor = false, heroIsAtBar = false, ZedKnowsAboutBobFriendshipWithHero = false;
int heroChoice = 0, checkpoint = 0, optionNr = 1;
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// SCENY
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+ Pomocne komendy
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::Commands()
{
    if (heroChoice == 'help')
    {
        cout << endl;
        Function::write("  Use the 'exit' command to leave the current session.");
    }
    else if (heroChoice == 'exit')
    {
        Function::clearScreen();
        Game().logo();
        //Game().mainMenu();
    }
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+ Œmieræ bohatera
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::heroDeath()
{
    Sleep(500);
    Function::clearScreen();
    Function::changeConsoleColor(red);
    cout << endl;

    if (Game().getLang() == en)  Function::write("  YOU ARE DEAD!", 25);
    else Function::write("  NIE ¯YJESZ!", 25);

    Sleep(1000);
    cout << endl;
    cout << "" << endl;
    Function::changeConsoleColor();

    if (Game().getLang() == en)  Function::write("  Back to menu...", 25);
    else Function::write("  Wróæ do menu...", 25);

    Function::waitForUserInput();
    Function::clearScreen();
    Game().logo();
    //Game().mainMenu();
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+ Koniec gry
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::gameOver()
{
    Sleep(500);
    Function::clearScreen();
    Function::changeConsoleColor(lightblue);
    cout << endl;

    if (Game().getLang() == en)  Function::write("  THE END", 25);
    else Function::write("  KONIEC", 25);

    Sleep(1000);
    cout << endl;
    cout << "" << endl;
    Function::changeConsoleColor();

    if (Game().getLang() == en)  Function::write("  Back to menu...", 25);
    else Function::write("  Wróæ do menu...", 25);

    Function::waitForUserInput();
    Function::clearScreen();
    Game().logo();
    //Game().mainMenu();
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::OnStreet()
{
    //-------------------------------------------------------------
    // Decyzja
    Function::write_narration("Once again you are on a street bathed in nighttime darkness.");
    cout << "" << endl;
    Function::changeConsoleColor();
    Function::actionOption(optionNr, "Visit Dark Alley."); // Opcja nr 1
    optionNr++;
    Function::actionOption(optionNr, "Visit Nightclub 'Amnesia'."); // Opcja nr 2
    optionNr++;
    Function::actionOption(optionNr, "Go back to the gun shop."); // Opcja nr 3
    optionNr = 1;
    Function::write("  > ", 15);

    while (true)
    {
        cin >> heroChoice;

        if (heroChoice == 1)
        {
            cout << endl;
            enterClub();
            break;
        }
        else if (heroChoice == 2)
        {
            cout << endl;
            enterClub();
            break;
        }
        else if (heroChoice == 3)
        {
            cout << endl;
            enterGunShop();
            break;
        }
    }
    //-------------------------------------------------------------
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::DarkAlley()
{
    string heroName;

    cout << endl;

    if (!npcs["Bob"].isKnowsHero())
    {
        Function::write_narration("When you enter the alley, you hear a familiar voice.");
        Function::changeConsoleColor(dialogue);
        Function::write("  - 'It's you again. Why don't you tell me something for one this time?'");
        cout << endl;
        cout << "" << endl;
        //-------------------------------------------------------------
        // Decyzja
        Function::actionOption(optionNr, "Stop and finally find out what he wants."); // Opcja nr 1
        optionNr++;
        Function::actionOption(optionNr, "Ignore him again."); // Opcja nr 2
        optionNr = 1;
        Function::write("  > ", 15);

        while (true)
        {
            cin >> heroChoice;

            if (heroChoice == 1)
            {
                cout << endl;
                Function::write_narration("  You stop and turn towards the owner of the voice.");
                Sleep(1500);
                Function::write_narration(" His silhouette looms in the darkness. It's one of the homeless people who live here. What can he have for you?");
                cout << endl;
                Sleep(1000);

                if (!npcs["Caden"].isKnowsHero() && !npcs["CadenPartner"].isKnowsHero())
                {
                    Function::changeConsoleColor();
                    cout << endl;
                    cout << "  > ";
                    cin >> heroName;
                    heroes["Hero"].setName(heroName);
                    Function::changeConsoleColor(dialogue);
                }
                else
                {
                    cout << endl;
                }

                string str = "  - 'So you're " + heroes["Hero"].getName() + ", huh?";
                Function::write(str);
                Sleep(1500);
                str = " All right. I'm " + npcs["Bob"].getName() + ".";
                Function::write(str);
                Sleep(1500);
                Function::write(" What are you doin' here?'");
                cout << endl;
                Function::write_narration("  The shadows in front of you, begin to ripple when your caller stands up.");

                break;
            }
            else if (heroChoice == 2)
            {
                cout << endl;
                Function::write_narration("  You have a mysterious stranger for nothing. You speed up your step and leave him far behind you. Whatever he wanted from you is no longer important.");
                Sleep(1000);

                scene002();
                break;
            }
        }
        //-------------------------------------------------------------
    }
    else
    {
        Function::write_narration("  When you enter an alley, you notice a sea of trash around you.");
        Sleep(1000);
        Function::write_narration(" It's full of cardboard boxes, old mechanical parts, and god knows what else.");
    }

    Item* Item_Pointer = &items["AD13"];

    if (!heroes["Hero"].isHaveItem(Item_Pointer))
    {
        Sleep(1500);
        cout << endl;
        Function::write_narration("  Who knows, you might find something interesting there...");
        cout << endl;
        cout << "" << endl;
        //-------------------------------------------------------------
        // Decyzja
        Function::changeConsoleColor();
        Function::actionOption(optionNr, "Search the area for something valuable."); // Opcja nr 1
        optionNr++;
        Function::actionOption(optionNr, "Go out of the alley."); // Opcja nr 2
        optionNr = 1;
        Function::write("  > ", 15);

        while (true)
        {
            cin >> heroChoice;

            if (heroChoice == 1)
            {
                Sleep(1000);
                cout << endl;
                Function::write_narration("  You start rummaging through the trash.");
                Sleep(1500);
                Function::write_narration(" The search takes a long while, but eventually you manage to find something.");
                Sleep(2000);
                cout << endl;

                Item* Item_Pointer = &items["AD13"];
                heroes["Hero"].addItem(Item_Pointer);

                Function::changeConsoleColor(item);
                string str = "  " + items["AD13"].getName();
                Function::write(str);
                Function::changeConsoleColor();
                Function::write(" was found.");
                cout << endl;
                Function::write("  [TIP: This item has been added to your inventory. You can view it in the text file in your game folder.]", 15); // TODO: or display information about it with the 'view _ItemName_' command
                Sleep(4000);
                cout << endl;
                Function::write_narration("  Hmm, that might come in handy in the future.");
                Sleep(1000);
                cout << endl;
                Function::write_narration("  There is nothing interesting here any more. Time to go back...");
                cout << endl;
                OnStreet();
                break;
            }
            else if (heroChoice == 2)
            {
                cout << endl;
                OnStreet();
                break;
            }
        }
        //-------------------------------------------------------------
    }
    else
    {
        cout << endl;
        Function::write_narration("  There is nothing interesting here. Time to go back...");
        cout << endl;
        OnStreet();
    }
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::prologue()
{
    //if (Game().getLang() == en)
    //{
        cout << "" << endl;
        Function::write("  Prologue");
        Sleep(2000);
        cout << endl;
        cout << "" << endl;
        Function::write("  REQUIEM FOR A DREAM");
        Sleep(5000);
    /* }
    else
    {
        cout << "" << endl;
        Function::write("  Prolog");
        Sleep(2000);
        cout << endl;
        cout << "" << endl;
        Function::write("  REQUIEM DLA MARZEÑ");
        Sleep(5000);
    }*/
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::storyIntroduction()
{
    //if (Game().getLang() == en)
    //{
        Function::clearScreen();
        Sleep(2000);
        cout << "" << endl;
        Function::write_narration("  It's 2050.");
        Sleep(1000);
        Function::write_narration(" Megacity is a place overrun by poverty and feuding gangs, where powerful corporations have the most influence. The violence in the streets is a clear sign of an impending war. Government operating from behind the secure walls of City Hall are trying to combat this, but so far without success. There are rumors that they themselves are secretly supporting the chaos to create a New Order on the ruins of the city.", 20);
        cout << endl;
        cout << "" << endl;
        Function::pauseGame();
        Function::clearScreen();
        cout << "" << endl;
        Sleep(2500);
        Function::changeConsoleColor(dialogue);
        Function::write("  Standing at the edge of the tallest tower...", 80);
        Sleep(1500);
        cout << endl;
        Function::write("  Holding your hand and dive...", 80);
        Sleep(1500);
        cout << endl;
        Function::write("  Falling and falling for what feels like hours...", 80);
        Function::changeConsoleColor();
        Sleep(2500);
        cout << endl;
        cout << "" << endl;
    /* }
    else
    {
        Function::clearScreen();
        Sleep(2000);
        cout << "" << endl;
        Function::write_narration("  Jest rok 2050.");
        Sleep(1000);
        Function::write_narration(" Megacity to miejsce opanowane przez biedê i zwaœnione gangi, gdzie najwiêksze wp³ywy maj¹ potê¿ne korporacje. Przemoc na ulicach jest wyraŸnym znakiem zbli¿aj¹cej siê wojny. Rz¹d dzia³aj¹cy zza bezpiecznych murów ratusza próbuje z tym walczyæ, ale jak na razie bezskutecznie. Kr¹¿¹ plotki, ¿e sam potajemnie wspiera chaos, by na gruzach miasta stworzyæ Nowy Porz¹dek.", 20);
        cout << endl;
        cout << "" << endl;
        system("pause");
        Function::clearScreen();
        cout << "" << endl;
        Sleep(2500);
        Function::changeConsoleColor(dialogue);
        Function::write("  Stoj¹c na krawêdzi najwy¿szej wie¿y...", 80);
        Sleep(1500);
        cout << endl;
        Function::write("  Trzymaj¹c ciê za rêkê i nurkuj¹c...", 80);
        Sleep(1500);
        cout << endl;
        Function::write("  Spadaæ i spadaæ przez to, co wydaje siê godzinami...", 80);
        Function::changeConsoleColor();
        Sleep(2500);
        cout << endl;
        cout << "" << endl;
    }*/
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::scene001()
{
    //if (Game().getLang() == en)
    //{
        Function::write_narration("  You wake up dazed from a restless slumber.");
        Sleep(1000);
        Function::write_narration(" It was the same dream again...");
        Sleep(1500);
        cout << endl;
        Function::write_narration("  You are somewhere in a dark alley. Above your head, among the smoggy haze, as if torn from a dream, rise the monumental skyscrapers of large corporations.");
        Sleep(1000);
        Function::write_narration(" Their divine majesty beats you to the eyes.");
        Sleep(2500);
        cout << endl;
        Function::write_narration("  Your heart beats so hard that only the stinging touch of the wind protects you from a sudden heart attack.");
        Sleep(500);
        Function::write_narration(" Suddenly a wave of shivers comes over your body, you start shaking like an aspen, and realize that you are lying on a lair made of some old newspapers.");
        Sleep(2000);
        cout << endl;
        Function::write_narration("  When you rise from the ground, you notice a sea of trash around you.");
        Sleep(1000);
        Function::write_narration(" It's full of cardboard boxes, old mechanical parts, and god knows what else.");
        Sleep(1500);
        cout << endl;
        Function::write_narration("  Who knows, you might find something interesting there...");
        cout << endl;
        cout << "" << endl;
        //-------------------------------------------------------------
        // Decyzja
        Function::actionOption(optionNr, "Search the area for something valuable."); // Opcja nr 1
        optionNr++;
        Function::actionOption(optionNr, "Find the exit from the alley."); // Opcja nr 2
        optionNr = 1;
        Function::write("  > ", 15);
    /* }
    else
    {
        Function::write_narration("  Budzisz siê oszo³omiony z niespokojnej drzemki.");
        Sleep(1000);
        Function::write_narration(" To by³ znowu ten sam sen...");
        Sleep(1500);
        cout << endl;
        Function::write_narration("  Znajdujesz siê gdzieœ w ciemnym zau³ku. Nad twoj¹ g³ow¹, wœród smogowej mg³y, niczym wyrwane ze snu, wznosz¹ siê monumentalne drapacze chmur wielkich korporacji.");
        Sleep(1000);
        Function::write_narration(" Ich boski majestat bije ciê po oczach.");
        Sleep(2500);
        cout << endl;
        Function::write_narration("  Serce bije ci tak mocno, ¿e tylko szczypi¹cy dotyk wiatru chroni ciê przed nag³ym atakiem serca.");
        Sleep(500);
        Function::write_narration(" Nagle przez twoje cia³o przechodzi fala dreszczy, zaczynasz trz¹œæ siê jak osika i uœwiadamiasz sobie, ¿e le¿ysz na legowisku zrobionym ze starych gazet.");
        Sleep(2000);
        cout << endl;
        Function::write_narration("  Kiedy podnosisz siê z ziemi, zauwa¿asz wokó³ siebie morze œmieci.");
        Sleep(1000);
        Function::write_narration(" Jest pe³ne kartonów, starych czêœci mechanicznych i Bóg wie czego jeszcze.");
        Sleep(1500);
        cout << endl;
        Function::write_narration("  Kto wie, mo¿e znajdziesz tam coœ interesuj¹cego...");
        cout << endl;
        cout << "" << endl;
        //-------------------------------------------------------------
        // Decyzja
        Function::actionOption(optionNr, "Rozejrzyj siê po okolicy w poszukiwaniu czegoœ cennego."); // Opcja nr 1
        optionNr++;
        Function::actionOption(optionNr, "ZnajdŸ wyjœcie z zau³ka."); // Opcja nr 2
        optionNr = 1;
        Function::write("  > ", 15);
    }*/

    while (true)
    {
        cin >> heroChoice;

        if (heroChoice == 1)
        {
            Sleep(1000);
            scene001_01();
            break;
        }
        else if (heroChoice == 2)
        {
            Sleep(1000);
            scene001_02();
            break;
        }
    }
    //-------------------------------------------------------------
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::scene001_01()
{
    cout << endl;
    Function::write_narration("  You start rummaging through the trash.");
    Sleep(1500);
    Function::write_narration(" The search takes a long while, but eventually you manage to find something.");
    Sleep(2000);
    cout << endl;

    Item* Item_Pointer = &items["AD13"];
    heroes["Hero"].addItem(Item_Pointer);

    //cout << endl;
    //Function::changeConsoleColor(15);
    //heroInv->showInv();

    //cout << endl;
    Function::changeConsoleColor(item);
    string str = "  " + items["AD13"].getName();
    Function::write(str);
    Function::changeConsoleColor();
    Function::write(" was found.");
    cout << endl;
    Function::write("  [TIP: This item has been added to your inventory. You can view it in the text file in your game folder.]", 15); // TODO: or display information about it with the 'view _ItemName_' command
    Sleep(4000);
    cout << endl;
    Function::write_narration("  Hmm, that might come in handy in the future.");
    Sleep(1000);

    scene001_02();
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::scene001_02()
{
    cout << endl;

    Item* Item_Pointer = &items["AD13"];

    if (!heroes["Hero"].isHaveItem(Item_Pointer))
    {
        Function::write_narration("  You're not going to rummage through the trash.");
        Sleep(1000);
        Function::write_narration(" And that's okay, you probably wouldn't find anything there anyway.");
        Function::write_narration(" Instead, you slowly toddle toward the neon color bombs at the end of the alley.");
    }
    else {
        Function::write_narration("  You slowly toddle toward the neon color bombs at the end of the alley.");
    }

    Sleep(3000);
    cout << endl;
    Function::write_narration("  You are getting closer and closer to your goal when from the right, from behind a veil of shadows, a low, not very pleasant voice belonging to a man speaks up.");
    cout << endl;
    Function::changeConsoleColor(dialogue);
    Function::write("  - 'Hey, kid. Wait for a second.'");
    Function::changeConsoleColor();
    cout << endl;
    cout << "" << endl;
    //-------------------------------------------------------------
    // Decyzja
    Function::actionOption(optionNr, "Stop and find out what he wants."); // Opcja nr 1
    optionNr++;
    Function::actionOption(optionNr, "Ignore him and keep walking."); // Opcja nr 2
    optionNr = 1;
    Function::write("  > ", 15);

    while (true)
    {
        cin >> heroChoice;

        if (heroChoice == 1)
        {
            cout << endl;
            Function::write_narration("  You stop and turn towards the owner of the voice.");
            Sleep(1500);
            Function::write_narration(" His silhouette looms in the darkness. It's one of the homeless people who live here. What can he have for you?");
            cout << endl;
            Sleep(1000);

            conversationWithHomeless();
            break;
        }
        else if (heroChoice == 2)
        {
            cout << endl;
            Function::write_narration("  You have a mysterious stranger for nothing. You speed up your step and leave him far behind you. Whatever he wanted from you is no longer important.");
            Sleep(1000);

            scene002();
            break;
        }
    }
    //-------------------------------------------------------------
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::conversationWithHomeless()
{
    string heroName, str;

    Function::changeConsoleColor(dialogue);
    Function::write("  - 'What's your name, boy?'");
    Function::changeConsoleColor();
    cout << endl;
    cout << "  > ";
    cin >> heroName;
    heroes["Hero"].setName(heroName);
    npcs["Bob"].setToKnowHero();
    Function::changeConsoleColor(dialogue);
    str = "  - 'So you're " + heroes["Hero"].getName() + ", huh?";
    Function::write(str);
    Sleep(1500);
    str = " All right. I'm " + npcs["Bob"].getName() + ".";
    Function::write(str);
    Sleep(1500);
    Function::write(" What are you doin' here?'");
    cout << endl;
    Function::write_narration("  The shadows in front of you, begin to ripple when your caller stands up.");
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
    Function::write("  > ", 15);

    while (true)
    {
        cin >> heroChoice;

        if (heroChoice == 1)
        {
            BobRecommendsZedToHero = true; // Bob poleca bohaterowi sklep z broni¹ Zeda
            cout << endl;
            Function::changeConsoleColor(dialogue);
            Function::write("  - 'Ha-ha, that's what I thought. To tell you the truth, you don't look very threatening.");
            Sleep(1000);
            Function::write(" Well, you could use some gat. I happen to know a guy who deals guns. His name is Zed, and his store is right around the corner.");
            Sleep(1000);
            Function::write(" Tell him you're coming from old Bob and he'll find something for you.'");
            cout << endl;
            break;
        }
        else if (heroChoice == 2)
        {
            cout << endl;
            Function::changeConsoleColor(dialogue);
            Function::write("  - 'What's wrong with you?");
            Sleep(1000);
            Function::write(" Anyway, it doesn't matter.");
            Sleep(1500);
            Function::write(" Have you ever heard of Megacity?");
            Sleep(1500);
            Function::write(" Well, it's right here. The neighborhood we are currently in is called Ramsey Deep.");
            Sleep(1000);
            Function::write(" Did I make your head clearer?'");
            cout << endl;
            break;
        }
        else if (heroChoice == 3)
        {
            cout << endl;
            npcs["Bob"].setAttitude(angry);
            Function::changeConsoleColor(dialogue);
            Function::write("  - 'You're wrong. It's absolutely my business, kid. Don't shut your mouth like that, or you might lose a few teeth. Got it?'");
            cout << endl;
            break;
        }
    }
    //-------------------------------------------------------------
    Function::write_narration("  Finally, an old, wrinkled face surrounded by gray fuzz emerges from the darkness. An artificial, cybernetic eye watches you vigilantly.");
    Sleep(1000);
    Function::write_narration(" You start to feel strangely uncomfortable.");
    Sleep(2000);
    cout << endl;
    Function::write_narration("  In an instant the alley is filled with the howling of a police siren.");
    Sleep(1000);
    Function::write_narration(" On the wall in front of you, red and blue begin to dance with each other.");
    cout << endl;
    Function::changeConsoleColor(dialogue);
    Function::write("  - 'Shit");
    Sleep(500);
    Function::write(", cops!");
    Sleep(500);
    Function::write(" Well, that's super. I think it's time for me to go.'");
    Sleep(1500);
    cout << endl;
    Function::write_narration("  The aging beggar dives into the embrace of darkness in a flash.");
    Sleep(1500);
    Function::write_narration(" Does this mean you see him for the last time?");
    Sleep(3500);
    scene002();
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::scene002()
{
    cout << endl;

    if (!npcs["Bob"].isKnowsHero())
    {
        Function::write_narration("  You walk out of the alley onto a street lit by neon lights on the opposite side. A large sign that reads 'Amnesia' belongs to a nightclub.");
        Sleep(1000);
        Function::write_narration(" A small crowd gathers outside the entrance to the building. Some people are arguing with the bouncers.");
        Sleep(1500);
        Function::write_narration(" Something smells here, it's probably trouble...");
    }
    else {
        Function::write_narration("  You walk out of the alley onto a street lit by neon lights and the lamp of a police car on the opposite side. A large sign that reads 'Amnesia' belongs to a nightclub.");
        Function::write_narration(" Two cops interrogate a small crowd outside the entrance to the building.");
        Sleep(1500);
        Function::write_narration(" Something smells here, it's probably trouble...");
    }

    cout << endl;
    //-------------------------------------------------------------
    // Decyzja
    cout << "" << endl;
    Function::actionOption(optionNr, "Come closer and see what it's all about.");
    optionNr++;
    Function::actionOption(optionNr, "Take a look around the area.");
    optionNr = 1;
    Function::write("  > ", 15);

    while (true)
    {
        cin >> heroChoice;

        if (heroChoice == 1)
        {
            cout << endl;
            Function::changeConsoleColor(narration);

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
            cout << endl;
            heroMeetGunStore();
            break;
        }
    }
    //-------------------------------------------------------------
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::heroMeetGunStore()
{
    Function::changeConsoleColor(narration);
    Function::write("  You go to the right side of the street. After walking several meters you come across a small booth between blocks of flats.");

    if (BobRecommendsZedToHero)
    {
        Function::write(" Could it be that the famous gun store managed by Bob's friend?");
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
    Function::write("  > ", 15);

    while (true)
    {
        cin >> heroChoice;

        if (heroChoice == 1)
        {
            cout << endl;
            enterGunShop();
            break;
        }
        else if (heroChoice == 2)
        {
            cout << endl;
            Function::changeConsoleColor(narration);

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
    Function::write("  When you get closer, the faces turn toward you and start looking at you intently.");
    Sleep(1000);
    Function::write(" You pass them in silenceand are confronted by a broad - shouldered security guard.");
    cout << endl;
    Function::changeConsoleColor(dialogue);
    Function::write("  - 'What are you looking for here?");
    Sleep(1500);
    Function::write(" Trouble, maybe?'");
    cout << endl;
    Function::changeConsoleColor(narration);
    Function::write("  The man clenches his hands into fists and smiles unpleasantly.");
    cout << endl;
    Function::changeConsoleColor(dialogue);
    Function::write("  - 'You asshole, better let us in! I want a drink and for fuck's sake. I'm losing my patience!");
    cout << endl;
    Function::changeConsoleColor(narration);
    Function::write("  One of the men waiting in the queue rushes forward and threatens the bouncer with his fist.");
    Sleep(1500);
    Function::write(" The security guard's attention shifts from you to the furious guy next to you.");
    cout << endl;
    Function::changeConsoleColor(dialogue);
    Function::write("  - 'I'll say it one last time: get the fuck out of here or you'll get fucked.'");
    cout << endl;
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::heroMeetsPolicemans()
{
    string heroName;

    Function::changeConsoleColor(narration);

    if (npcs["Bob"].isKnowsHero())
    {
        Function::write("  When you get closer, one of the police officers in a dark blue uniform turns toward you.");
    }
    else {
        Function::write("  In an instant the street is filled with the howling of a police siren.");
        Sleep(1000);
        Function::write(" The reds and blues begin to dance with each other on the sidewalk and the silhouettes of the people around you.");
        Sleep(2000);
        cout << endl;
        Function::write("  Two grim-looking guys in dark blue uniforms get out of a police car and walk towards you. One of them points at you, taking out a tablet from behind his belt.");
    }

    cout << endl;
    Function::changeConsoleColor(dialogue);
    Function::write("  - 'Who are you?");
    Sleep(1500);
    Function::write(" And what are you doing here? Please show me your ID card.'");
    cout << endl;
    Function::changeConsoleColor(narration);

    Item* Item_Pointer = &items["AD13"];

    if (heroes["Hero"].isHaveItem(Item_Pointer))
    {
        Function::write("  You start searching through the pockets of your jacket and pants, but other than the accelerator you found in the trash, there's nothing else there.");
    }
    else {
        Function::write("  You start searching through the pockets of your jacket and pants, but there's nothing there.");
    }

    cout << endl;
    Function::changeConsoleColor(dialogue);
    Function::write("  - 'I see that we have a problem.");
    Sleep(1500);
    Function::write(" Okay, then what's your name, citizen?'");

    if (!npcs["Bob"].isKnowsHero())
    {
        Function::changeConsoleColor();
        cout << endl;
        cout << "  > ";
        cin >> heroName;
        heroes["Hero"].setName(heroName);
        Function::changeConsoleColor(dialogue);
    }
    else {
        cout << endl;
    }

    npcs["CadenPartner"].setToKnowHero();
    npcs["Caden"].setToKnowHero();
    string str = "  - '" + heroes["Hero"].getName() + "...";
    Function::write(str);
    Sleep(1000);
    Function::write(" Caden, check it out in the database.");
    Sleep(1500);
    Function::write(" And you, stand where you are.'");
    cout << endl;
    Function::changeConsoleColor(narration);
    Function::write("  The other police officer nods, gets back in the car, and it looks like he's connecting with headquarters.");
    Sleep(3000);
    cout << endl;
    Function::write("  A minute later, the same policeman returns and whispers something in his partner's ear.");
    Sleep(1500);
    Function::write(" That one nods and turns to look at you.");
    cout << endl;
    Function::changeConsoleColor(dialogue);
    Function::write("  - 'I have good news for you.");
    Sleep(1500);
    Function::write(" You're free for now, just don't let it occur to you to do something here, or you'll end up in arrest at the police station.");
    Sleep(1000);
    Function::write(" Caden, take care of the rest of the attendees.'");
    cout << endl;
    Function::changeConsoleColor(narration);
    Function::write("  The cop walks away to talk to the nearest person standing.");
    cout << endl;
    Function::changeConsoleColor(dialogue);
    Function::write("  - 'If you're so pure, get in.'");
    cout << endl;
    Function::changeConsoleColor(narration);
    Function::write("  The bouncer points to the door behind him.");
    cout << endl;
    //-------------------------------------------------------------
    // Decyzja
    Function::changeConsoleColor();
    cout << "" << endl;
    Function::actionOption(optionNr, "Go inside."); // Opcja nr 1
    optionNr++;
    Function::actionOption(optionNr, "Turn back."); // Opcja nr 2
    optionNr = 1;
    Function::write("  > ", 15);

    while (true)
    {
        cin >> heroChoice;

        if (heroChoice == 1)
        {
            cout << endl;
            enterClub();
            break;
        }
        else if (heroChoice == 2)
        {
            cout << endl;
            heroMeetGunStore();
            break;
        }
    }
    //-------------------------------------------------------------
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::enterClub()
{
    Function::changeConsoleColor(narration);
    Function::write("  After passing through the entrance your eardrums are slowly bursting from the loud music in the club.");
    Sleep(1000);
    Function::write(" You walk through a short lobby and so arrive at a crowded room full of dancing people.");
    Sleep(1000);
    Function::write(" Disco balls hung from the ceiling net everything around with streaks of multi-colored light.");
    Sleep(1000);
    Function::write(" Next to the dance floor is a bar, and behind it are several mechanically streamlined bartenders.");
    cout << endl;
    //-------------------------------------------------------------
    // Decyzja
    Function::changeConsoleColor();
    cout << "" << endl;
    Function::actionOption(optionNr, "Go dance on the dance floor."); // Opcja nr 1
    optionNr++;
    Function::actionOption(optionNr, "Go to the bar."); // Opcja nr 2
    optionNr = 1;
    Function::write("  > ", 15);

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

    MiaMeeting();
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::clubDanceFloor()
{
    heroIsOnDanceFloor = true;

    Function::changeConsoleColor(narration);
    Function::write("  You walk onto the dance floor with a dance step.");
    Sleep(1000);
    Function::write(" It's quite crowded, but at least you can enjoy the beautiful views.");
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::clubBar()
{
    heroIsAtBar = true;

    Function::changeConsoleColor(narration);
    Function::write("  With a slow step, you approach the counter, settle comfortably on a stool, and lift your gaze to the barman in front of you.");
    cout << endl;
    Function::changeConsoleColor(dialogue);
    Function::write("  - 'What's for you?'");
    cout << endl;
    //-------------------------------------------------------------
    // Decyzja
    Function::changeConsoleColor();
    cout << "" << endl;
    Function::dialogueOption(optionNr, "Give me anything."); // Opcja nr 1
    optionNr++;
    Function::dialogueOption(optionNr, "Who's in charge?"); // Opcja nr 2
    optionNr++;
    Function::dialogueOption(optionNr, "Bye."); // Opcja nr 3
    optionNr = 1;
    Function::write("  > ", 15);

    while (true)
    {
        cin >> heroChoice;

        if (heroChoice == 1)
        {
            cout << endl;
            Function::changeConsoleColor(dialogue);
            Function::write("  - 'Okay.");
            Sleep(1000);
            Function::write(" Let's see...'");
            Sleep(1500);
            cout << endl;
            Function::changeConsoleColor(narration);
            Function::write("  The barman turns his back on you and looks through the bottles of alcohol. Finally, he selects one of them and pours its contents into a glass before placing it on the counter in front of you.");
            Sleep(1500);
            cout << endl;
            Function::write("  You reach for the vessel and empty it.");
            Sleep(1000);
            Function::write(" You feel a pleasant warmth spreading up your throat and further down your gullet.");
            break;
        }
        else if (heroChoice == 2)
        {
            cout << endl;
            Function::changeConsoleColor(narration);
            Function::write("  The bartender squints, hearing your question.");
            cout << endl;
            Function::changeConsoleColor(dialogue);
            Function::write("  - 'You're not from around here, are you?");
            Sleep(1500);
            Function::write(" My boss is Vincent Ramsey.");
            Sleep(1000);
            Function::write(" He's a tough guy, so you'd better not make trouble, or it could end badly for you.");
            break;
        }
        else if (heroChoice == 3)
        {
            cout << endl;
            Function::changeConsoleColor(narration);
            Function::write("  The bartender reaches for a glass from under the counter and starts wiping it down.");
            cout << endl;
            Function::changeConsoleColor(dialogue);
            Function::write("  - 'Yeah, have fun.'");
            break;
        }
    }
    //-------------------------------------------------------------
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::MiaMeeting()
{
    if (heroIsAtBar)
    {

    }
    else if (heroIsOnDanceFloor)
    {

    }
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::enterGunShop()
{
    Function::changeConsoleColor(narration);
    Function::write("  The front door hisses open before you.");

    if (!npcs["Zed"].isKnowsHero())
    {
        Sleep(1000);
        Function::write(" You step over the threshold and enter a small room with a counter opposite the entrance. Behind it stands a tall, thin man with fatigue painted on his terribly oblong face.");
        Sleep(1500);
        Function::write(" He is dressed in an old corporate commando suit. On the wall behind his back hangs a lot of weapons.");
        cout << endl;
        Function::changeConsoleColor(dialogue);
        Function::write("  - 'How can I help you, my friend?'");
        cout << endl;
        npcs["Zed"].setToKnowHero();
        dialogueWithZed();
    }
    else {
        Sleep(1000);
        Function::write(" From behind the counter, Zed is already smiling at you.");

        Item* Item_Pointer = &items["Pistol"];

        if (heroes["Hero"].isHaveItem(Item_Pointer))
        {
            cout << endl;
            Function::changeConsoleColor(dialogue);
            Function::write("  - 'What's up? How's the gun working out?'");
        }

        if (quests["ZedAccelerator"].isQuestRunning() && !quests["ZedAccelerator"].isQuestCompleted())
        {
            Item* Item_Pointer = &items["AD13"];

            if (!heroes["Hero"].isHaveItem(Item_Pointer))
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

        if (BobRecommendsZedToHero && !ZedKnowsAboutBobFriendshipWithHero)
        {
            Function::dialogueOption(optionNr, "You're Zed? I come from Bob.");
            optionNr++;
        }

        Function::dialogueOption(optionNr, "I have to go...");
        optionNr = 1;
        Function::write("  > ", 15);

        cin >> heroChoice;

        if (heroChoice == 1)
        {
            cout << endl;
            ZedTrade();
            continue;
        }
        else if (heroChoice == 2)
        {
            cout << endl;
            Function::changeConsoleColor(dialogue);

            if (heroTalkedAboutBusinessWithZed == true)
            {
                Function::write("  - 'Hey, what's up? Are you sclerotic or something? We already talked about this, haha!'");
                cout << endl;
            }
            else {
                heroTalkedAboutBusinessWithZed = true;
                Function::write("  - 'What kind of question is that anyway? Business is doing great! Everyone stops by every now and then to rearm. It's the natural order of things.'");
                cout << endl;
            }

            continue;
        }
        else if (heroChoice == 3)
        {
            cout << endl;

            if (BobRecommendsZedToHero && !ZedKnowsAboutBobFriendshipWithHero)
            {
                ZedKnowsAboutBobFriendshipWithHero = true;
                cout << endl;
                Function::changeConsoleColor(dialogue);
                Function::write("  - 'Yes, that is correct. I'm Zed, and this is my little shop.");
                npcs["Zed"].setAttitude(friendly);
                Sleep(1000);
                Function::write(" Since you know Bob, you can get a small discount here'.");
                continue;
            }
            else {
                Function::changeConsoleColor(dialogue);
                Function::write("  - 'No problem. See you later!'");
                cout << endl;

                if (!npcs["Caden"].isKnowsHero() && !npcs["CadenPartner"].isKnowsHero())
                {
                    heroMeetsPolicemans();
                }
                else
                {
                    Event::OnStreet();
                }

                break;
            }
        }
        else if (heroChoice == 4 && BobRecommendsZedToHero && !ZedKnowsAboutBobFriendshipWithHero)
        {
            cout << endl;
            Function::changeConsoleColor(dialogue);
            Function::write("  - 'No problem. See you later!'");
            cout << endl;

            if (!npcs["Caden"].isKnowsHero() && !npcs["CadenPartner"].isKnowsHero())
            {
                heroMeetsPolicemans();
            }
            else
            {
                Event::OnStreet();
            }

            break;
        }
    }
    //-------------------------------------------------------------
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::ZedTrade()
{
    bool ZedTellsAboutWeapons = false;

    Item* Item_Pointer = &items["Pistol"];

    if (!heroes["Hero"].isHaveItem(Item_Pointer))
    {
        if (!ZedTellsAboutWeapons)
        {
            ZedTellsAboutWeapons = true;
            Function::changeConsoleColor(dialogue);
            Function::write("  - 'Better ask what I don't have!");
            Sleep(1000);
            Function::write(" Look - ");
            Sleep(1000);
            Function::write("rifles, pistols, machine guns, shotguns. I have a melee weapons as well. Knives, hammers, long blades like katanas...");
            Sleep(1500);
            Function::write(" Anything you want, my friend!");
            Sleep(1500);
            Function::write(" Tell me, what do you like?'");
            // Decyzja
            cout << endl;
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
                    Function::write_narration("Zed looks at you pityingly and shrugs his shoulders.");
                    cout << endl;
                    Function::changeConsoleColor(dialogue);
                    Function::write("  - 'No problem. It can happen to anyone.'");
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
                    Function::write_narration("Zed looks at you pityingly and shrugs his shoulders.");
                    cout << endl;
                    Function::changeConsoleColor(dialogue);
                    Function::write("  - 'No problem. It can happen to anyone.'");
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

void Event::buyPistol()
{
    string str;

    cout << endl;

    if (heroes["Hero"].getMoney() != 250.0)
    {
        Function::changeConsoleColor(dialogue);
        Function::write("  - 'I see you're low on cash.");
        Sleep(1000);
        Function::write(" But don't worry, we'll sort it out somehow.");
        Sleep(1500);

        if (ZedKnowsAboutBobFriendshipWithHero)
        {
            Function::write(" Hmm, you know Old Bob, that already means something.");
            Sleep(1000);
            Function::write(" Let's just say I'll loan you this gun on a friendly basis.");

            Item* Item_Pointer = &items["Pistol"];
            heroes["Hero"].addItem(Item_Pointer);

            cout << endl;
            Function::changeConsoleColor(3);
            str = "  " + items["Pistol"].getName();
            Function::write(str);
            Function::changeConsoleColor(15);
            Function::write(" gained.");
            cout << endl;
        }
        else
        {
            quests["ZedAccelerator"].addQuest();

            Function::write(" It so happens that I have been looking for a good accelerator for some time.");
            Sleep(1000);
            Function::write(" I don't mean the crap produced by corporations these days.");
            Sleep(1000);
            Function::write(" I mean the good old accelerator!");
            Sleep(1500);
            Function::write(" Find me such a device and you will get that gun. Okay?");
        }
    }
    else
    {
        Function::changeConsoleColor(dialogue);
        Function::write("  - 'A pistol is a good start. Here, it's yours.'");

        Item* Item_Pointer = &items["Pistol"];
        heroes["Hero"].addItem(Item_Pointer);

        cout << endl;
        Function::changeConsoleColor(item);
        str = "  " + items["Pistol"].getName();
        Function::write(str);
        Function::changeConsoleColor(15);
        Function::write(" was bought.");
        cout << endl;
    }
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::VincentAssassination()
{
    VincentOffice();
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::VincentOffice()
{
    Function::changeConsoleColor(narration);
    Function::write("  You enter the manager's office immersed in twilight. In the middle of the room stands a sizable desk, and on it are stacks of documents and computer. To the left of the entrance is a window to the street below. On the right you will notice a door to another room.");
    cout << endl;
    //-------------------------------------------------------------
    // Decyzja
    Function::changeConsoleColor();
    cout << "" << endl;
    Function::actionOption(optionNr, "Open the door and go into the other room."); // Opcja nr 1
    optionNr++;
    Function::actionOption(optionNr, "Stay and search the office."); // Opcja nr 2
    optionNr = 1;
    Function::write("  > ", 15);

    while (true)
    {
        cin >> heroChoice;

        if (heroChoice == 1)
        {
            VincentHideoutCode();
            break;
        }
        else if (heroChoice == 2)
        {
            checkVincentDesk();
            VincentHideoutCode();
            break;
        }
    }
    //-------------------------------------------------------------
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::checkVincentDesk()
{
    cout << endl;
    Function::changeConsoleColor(narration);
    Function::write("  You walk up to the desk. You start flipping through the e-papers one by one and finally your gaze falls on the flickering blue monitor.");
    cout << endl;
    Function::write("  ");

    heroKnowsVincentHideoutCode = true;
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::VincentHideoutCode()
{
    cout << endl;
    Function::changeConsoleColor(narration);
    Function::write("  You walk closer and spot the terminal. It looks like you'll need to use a code to get through.");
    Sleep(1500);

    if (!heroKnowsVincentHideoutCode)
    {
        Function::write(" You have to look around the office though, whether you want to or not.");
    }
    else {
        cout << endl;
        Function::changeConsoleColor();
        cout << "" << endl;
        Function::actionOption(optionNr, "Use code '2021'."); // Opcja nr 1
        optionNr++;
        Function::actionOption(optionNr, "Search the office."); // Opcja nr 2
        Function::write("  > ", 15);
    }
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::VincentHideout()
{
    cout << endl;
    Function::changeConsoleColor(narration);
    Function::write("  The door closes behind you, hissing quietly.");
    Sleep(2000);
    Function::write(" The room you're in is full of smaller and larger cables that merge into a single monitor that hangs above the sim-chair. On it lies a big guy in a tailored suit and a stimulation helmet on his head that obscures his face.");
    Sleep(1500);
    Function::write(" You guess it's Vincent, the club owner.");
    Sleep(2000);
    cout << endl;
    Function::write("  Creeping up, you come closer. Your goal is within reach. The question is what will you do?");
    cout << endl;
    //-------------------------------------------------------------
    // Decyzja
    Function::changeConsoleColor();
    cout << "" << endl;
    Function::actionOption(optionNr, "Disconnect his consciousness from the neuronet. (Kill him)"); // Opcja nr 1
    optionNr++;
    Function::actionOption(optionNr, "Wait for his consciousness to leave the neuronet."); // Opcja nr 2
    optionNr = 1;
    Function::write("  > ", 15);

    while (true)
    {
        cin >> heroChoice;

        if (heroChoice == 1)
        {
            cout << endl;
            Function::changeConsoleColor(narration);
            Function::write("  You lean over Vincent and, in a fluid motion without hesitation, pull the stimulation helmet off his head. You witness the nightclub owner being shaken by a wave of convulsions. Foam begins to come out of his mouth and after a moment the man freezes.");
            Sleep(1500);
            Function::write(" He's probably dead, just like Mia wanted.");
            npcs["Vincent"].setStatus(dead);
            break;
        }
        else if (heroChoice == 2)
        {
            cout << endl;
            Function::changeConsoleColor(narration);
            Function::write("  You are not a coward. You don't stab people in the back. That's not your style. You prefer an open fight.");
            Sleep(1500);
            Function::write(" After a while, you notice Vincent moving slightly in his seat. He opens his eyes - they are shining with the excitement of his online adventure.");
            Sleep(1000);
            Function::write(" It is only a matter of time before Vincent notices your presence. There is no turning back now.");
            cout << endl;
            Function::changeConsoleColor(dialogue);
            Function::write("  - 'What the fuck are you doing here, dickhead?'");
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
    Function::write("  > ", 15);

    while (true)
    {
        cin >> heroChoice;

        if (heroChoice == 1)
        {
            cout << endl;
            Function::changeConsoleColor(narration);
            Function::write("  With a shout, you bring out your gun and aim it at Vincent's chest.");
            cout << endl;
            Function::changeConsoleColor(dialogue);
            Function::write("  - 'Are you such a hero?");
            Sleep(1000);
            Function::write(" Would you kill an unarmed man?");
            Sleep(1000);
            Function::write(" All right, can I at least find out who sent you? I know you're not working alone. I'm seeing you for the first time in my life.'");
            break;
        }
        else if (heroChoice == 2)
        {
            cout << endl;
            Function::changeConsoleColor(narration);
            Function::write("  You are not a coward. You don't stab people in the back. That's not your style. You prefer an open fight.");
            break;
        }
        else if (heroChoice == 3)
        {
            cout << endl;
            Function::changeConsoleColor(narration);
            Function::write("  You are not a coward. You don't stab people in the back. That's not your style. You prefer an open fight.");
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
    Function::write("  > ", 15);

    while (true)
    {
        cin >> heroChoice;

        if (heroChoice == 1)
        {
            cout << endl;
            Function::changeConsoleColor(dialogue);
            Function::write("  - 'Ugh, you little prick. I'll get you from beyond the grave. There will be no peace. I won't let that happen!'");
            Sleep(1500);
            cout << endl;
            Function::changeConsoleColor(narration);
            Function::write("  The last word spoken synchronizes with the bang of a gunshot as a bullet of energy pierces the club owner's chest.");
            Sleep(1000);
            Function::write(" The recoil knocks him from his seat. The lifeless body clatters against the floor.");
            Sleep(1500);
            Function::write(" He's dead, just like Mia wanted.");
            npcs["Vincent"].setStatus(dead);
            cout << endl;
            Function::write("  Out of curiosity, you walk closer and spot the corpse holding a small pistol.");
            Sleep(1000);
            Function::write(" That bastard was playing for time after all!");
            break;
        }
        else if (heroChoice == 2)
        {
            cout << endl;
            Function::changeConsoleColor(dialogue);
            Function::write("  - 'Traitorous bitch! She'll get her due someday.");
            Function::write(" All right, shithead, let's get this over with.'");
            cout << endl;
            Function::changeConsoleColor(narration);
            Function::write("  The last word spoken synchronizes with the bang of a gunshot as a bullet of energy pierces the club owner's chest.");
            Sleep(1000);
            Function::write(" The recoil knocks him from his seat. The lifeless body clatters against the floor.");
            Sleep(1500);
            Function::write(" He's dead, just like Mia wanted.");
            npcs["Vincent"].setStatus(dead);
            cout << endl;
            Function::write("  Out of curiosity, you walk closer and spot the corpse holding a small pistol.");
            Sleep(1000);
            Function::write(" That bastard was playing for time after all!");
            break;
        }
    }
    //-------------------------------------------------------------
    cout << endl;
    Function::changeConsoleColor(narration);
    Function::write("  The passage behind your back is opened.");
    Sleep(1000);
    Function::write(" You turn around, in front of you is Mia.");
    cout << endl;
    Function::changeConsoleColor(dialogue);
    Function::write("  - 'Did you do what I asked you to do...'");
    Sleep(1500);
    cout << endl;
    Function::changeConsoleColor(narration);
    Function::write("  The girl's gaze wanders from you to the body of her ex-boyfriend behind you.");
    Sleep(1000);
    cout << endl;
    Function::changeConsoleColor(dialogue);
    Function::write("  - 'You did it... You really did it... Is he - is he dead?'");
    Sleep(1000);
    cout << endl;
    Function::changeConsoleColor(narration);
    Function::write("  Mia walks past you and kneels by the dead man. She starts searching his pockets for something.");
    //-------------------------------------------------------------
    // Decyzja
    cout << endl;
    Function::changeConsoleColor();
    cout << "" << endl;
    Function::actionOption(optionNr, "Do nothing."); // Opcja nr 1
    optionNr++;
    Function::dialogueOption(optionNr, "What is this all about?"); // Opcja nr 2
    optionNr = 1;
    Function::write("  > ", 15);

    while (true)
    {
        cin >> heroChoice;

        if (heroChoice == 1)
        {
            cout << endl;
            Function::changeConsoleColor(narration);
            Function::write("  You let the girl quietly plunder the corpse. This gives you more time to look at her shapes more closely.");
            cout << endl;
            Function::changeConsoleColor(dialogue);
            Function::write("  - 'Spare me, if you please.'");
            break;
        }
        else if (heroChoice == 2)
        {
            cout << endl;
            Function::changeConsoleColor(dialogue);
            Function::write("  - 'Well, now I think I owe you an explanation.'");
            Function::changeConsoleColor(narration);
            Function::write("  A girl talks to you without even looking at you.");
            cout << endl;
            break;
        }
    }
    //-------------------------------------------------------------
    VincentResurrection();
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::VincentResurrection()
{
    cout << endl;
    Function::changeConsoleColor(narration);
    Function::write("  Suddenly, the maze of cables begins to vibrate and move in a strange dance.");
    Sleep(1000);
    Function::write(" Hisses reach you and Mia, forming a gibberish that is difficult to understand.");
    cout << endl;
    Function::changeConsoleColor(dia_robot);
    Function::write("  <You scum! You thought you got rid of me.");
    Sleep(1000);
    Function::write(" But you didn't.");
    Sleep(1000);
    Function::write(" I'm immortal now!>");
    cout << endl;
    Function::changeConsoleColor(narration);
    Function::write("  You exchange a look with Mia. You both can't believe what's happening.");
    cout << endl;
    Function::changeConsoleColor(dialogue);
    Function::write("  - 'What the fuck?!'");
    cout << endl;
    Function::changeConsoleColor(dia_robot);
    Function::write("  <Before your new lover killed me, sweatheart, I managed to pour some of my consciousness into the net. I don't need my body anymore, nothing limits me anymore.");
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
    Function::write("  ||", 100);
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
    Function::write("  Download completed.");
    Function::changeConsoleColor();
}