#include "events.h"

int heroChoice = 0, optionNr = 1;
bool bobRecommendsZed = false, zedKnowsAboutBobAndZed = false, heroIsOnDanceFloor = false, heroIsAtBar = false, heroKnowsVincentCode = false;
Item* itemPtr;

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::darkAlleyCrossroads()
{
    Logger::out("Function start", "Event::darkAlleyCrossroads");
    std::string heroName;
    Function::showHeroAction("Visit: " + Location::locations["DarkAlley"].getName());
    std::cout << std::endl;

    if (!Npc::npcs["Bob"].knowsHero())
    {
        Function::writeNarration("\tWhen you enter the alley, you hear a familiar voice.");
        std::cout << std::endl;
        Function::writeDialogue("\t- 'It's you again. Why don't you tell me something for one this time?'");
        std::cout << std::endl;
        std::cout << "" << std::endl;
        //-------------------------------------------------------------
        // Decyzja
        Function::actionOption(optionNr, "Stop and finally find out what he wants.");
        optionNr++;
        Function::actionOption(optionNr, "Ignore him again.");
        optionNr = 1;
        Function::write("\t> ", 15);

        while (true)
        {
            std::cin >> heroChoice;

            if (heroChoice == 1)
            {
                Function::clearScreen();
                Function::showHeroAction("Stop and finally find out what he wants.");
                std::cout << std::endl;
                Function::writeNarration("\tYou stop and turn towards the owner of the voice.");
                Sleep(1500);
                Function::writeNarration(" His silhouette looms in the darkness. It's one of the homeless people who live here. What can he have for you?");
                std::cout << std::endl;
                dialogueWithBob();
                break;
            }
            else if (heroChoice == 2)
            {
                Function::clearScreen();
                Function::showHeroAction("Ignore him again.");
                std::cout << std::endl;
                Function::writeNarration("\tYou have a mysterious stranger for nothing. You speed up your step and leave him far behind\n\tyou. Whatever he wanted from you is no longer important.");
                std::cout << std::endl;
                Function::writeDialogue("\t- 'Don't show up here again if you don't want to get your teeth kicked in!'");
                std::cout << std::endl;
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

    if (!Hero::heroes["Hero"].hasItem(&Item::items["AD13"]))
    {
        Sleep(1500);
        std::cout << std::endl;
        Function::writeNarration("\tWho knows, you might find something interesting there...");
        std::cout << std::endl;
        std::cout << "" << std::endl;
        //-------------------------------------------------------------
        // Decyzja
        Function::changeConsoleColor();
        Function::actionOption(optionNr, "Search the area for something valuable.");
        optionNr++;
        Function::actionOption(optionNr, "Go out of the alley.");
        optionNr = 1;
        Function::write("\t> ", 15);

        while (true)
        {
            std::cin >> heroChoice;

            if (heroChoice == 1)
            {
                Sleep(1000);
                std::cout << std::endl;
                Function::writeNarration("\tYou start rummaging through the trash.");
                Sleep(1500);
                Function::writeNarration(" The search takes a long while, but eventually you manage to find something.");
                Sleep(2000);
                std::cout << std::endl;

                Hero::heroes["Hero"].addItem(&Item::items["AD13"]);
                Function::changeConsoleColor(item);
                std::string str = "\t" + Item::items["AD13"].getName();
                Function::write(str);
                Function::changeConsoleColor();
                Function::write(" was found.");

                if (Hero::heroes["Hero"].hasItem(&Item::items["AD13"]))
                {
                    Logger::out(Item::items["AD13"].getName() + " added to EQ", "Event::inSeaOfRubbish");
                }
                else {
                    Logger::error(Item::items["AD13"].getName() + " not added to EQ", "Event::inSeaOfRubbish");
                }

                std::cout << std::endl;
                Function::write("\t[TIP: This item has been added to your inventory. You can view it in the text file in your game folder.]", 15);
                Sleep(4000);
                std::cout << std::endl;
                Function::writeNarration("\tHmm, that might come in handy in the future.");
                Sleep(1000);
                std::cout << std::endl;
                Function::writeNarration("\tThere is nothing interesting here any more. Time to go back...");
                std::cout << std::endl;
                street();
                break;
            }
            else if (heroChoice == 2)
            {
                std::cout << std::endl;
                street();
                break;
            }
        }
        //-------------------------------------------------------------
    }
    else
    {
        std::cout << std::endl;
        Function::writeNarration("\tThere is nothing interesting here. Time to go back...");
        std::cout << std::endl;
        street();
    }
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::prologue()
{
    Logger::out("Function start", "Event::prologue");
    //if (Game().getLang() == en)
    //{
    std::cout << "" << std::endl;
    Function::write("\tPrologue");
    Sleep(2000);
    std::cout << std::endl;
    std::cout << "" << std::endl;
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
        Function::write("\tREQUIEM DLA MARZE�");
        Sleep(5000);
    }
    */
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::storyIntroduction()
{
    Logger::out("Function start", "Event::storyIntroduction");
    //if (Game().getLang() == en)
    //{
    std::cout << "" << std::endl;
    Function::writeNarration("\tIt's 2050.");
    Sleep(1000);
    Function::writeNarration(" Megacity is a place overrun by poverty and feuding gangs, where powerful\n\tcorporations have the most influence. The violence in the streets is a clear sign of\n\tan impending war. Government operating from behind the secure walls of City Hall are\n\ttrying to combat this, but so far without success. There are rumors that they themselves\n\tare secretly supporting the chaos to create a New Order on the ruins of the city.", 20);
    std::cout << std::endl;
    std::cout << "" << std::endl;
    Function::pauseGame();
    Function::clearScreen();
    std::cout << "" << std::endl;
    Sleep(2500);
    Function::writeDialogue("\tStanding at the edge of the tallest tower...", 75);
    Sleep(2500);
    std::cout << std::endl;
    Function::writeDialogue("\tHolding your hand and dive...", 75);
    Sleep(2500);
    std::cout << std::endl;
    Function::writeDialogue("\tFalling and falling for what feels like hours...", 75);
    Sleep(3000);
    Function::clearScreen();
    //cout << endl;
    std::cout << "" << std::endl;
    wakeUpInDarkAlley();
    /* }
    else
    {
        Function::clearScreen();
        Sleep(2000);
        std::cout << "" << std::endl;
        Function::writeNarration("\tJest rok 2050.");
        Sleep(1000);
        Function::writeNarration(" Megacity to miejsce opanowane przez bied� i zwa�nione gangi, gdzie najwi�ksze wp�ywy maj� pot�ne korporacje. Przemoc na ulicach jest wyra�nym znakiem zbli�aj�cej si� wojny. Rz�d dzia�aj�cy zza bezpiecznych mur�w ratusza pr�buje z tym walczy�, ale jak na razie bezskutecznie. Kr��� plotki, �e sam potajemnie wspiera chaos, by na gruzach miasta stworzy� Nowy Porz�dek.", 20);
        std::cout << std::endl;
        std::cout << "" << std::endl;
        system("pause");
        Function::clearScreen();
        std::cout << "" << std::endl;
        Sleep(2500);
        Function::writeDialogue("\tStoj�c na kraw�dzi najwy�szej wie�y...", 75);
        Sleep(1500);
        std::cout << std::endl;
        Function::writeDialogue("\tTrzymam ci� za r�k� i skacz�...", 75);
        Sleep(1500);
        std::cout << std::endl;
        Function::writeDialogue("\tSpadam i spadam jakby godzinami ...", 75);
        Sleep(2500);
        std::cout << std::endl;
        std::cout << "" << std::endl;
    }*/
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::wakeUpInDarkAlley()
{
    Logger::out("Function start", "Event::wakeUpInDarkAlley");
    //if (Game().getLang() == en)
    //{
    darkAlleyWasVisited = true;
    Sleep(2000);
    Function::writeNarration("\tYou wake up dazed from a restless slumber.");
    Sleep(1000);
    Function::writeNarration(" It was the same dream again...");
    Sleep(1500);
    std::cout << std::endl;
    Function::writeNarration("\tYou are somewhere in a dark alley. Above your head, among the smoggy haze, as if torn from\n\ta dream, rise the monumental skyscrapers of large corporations.");
    Sleep(1000);
    Function::writeNarration(" Their divine majesty beats\n\tyou to the eyes.");
    Sleep(3000);
    std::cout << std::endl;
    Function::writeNarration("\tYour heart beats so hard that only the stinging touch of the wind protects you from a sudden\n\theart attack.");
    Sleep(500);
    Function::writeNarration(" Suddenly a wave of shivers comes over your body, you start shaking like an\n\taspen, and realize that you are lying on a lair made of some old newspapers.");
    Sleep(3000);
    std::cout << std::endl;
    Function::writeNarration("\tWhen you rise from the ground, you notice a sea of trash around you.");
    Sleep(1000);
    Function::writeNarration(" It's full of cardboard\n\tboxes, old mechanical parts, and god knows what else.");
    Sleep(2500);
    std::cout << std::endl;
    Function::writeNarration("\tWho knows, you might find something interesting there...");
    std::cout << std::endl;
    std::cout << "" << std::endl;
    //-------------------------------------------------------------
    // Decyzja
    Function::actionOption(optionNr, "Search the area for something valuable.");
    optionNr++;
    Function::actionOption(optionNr, "Find the exit from the alley.");
    optionNr = 1;
    Function::write("\t> ", 15);
    /* }
    else
    {
        Function::writeNarration("\tBudzisz si� oszo�omiony z niespokojnej drzemki.");
        Sleep(1000);
        Function::writeNarration(" To by� znowu ten sam sen...");
        Sleep(1500);
        cout << endl;
        Function::writeNarration("\tZnajdujesz si� gdzie� w ciemnym zau�ku. Nad twoj� g�ow�, w�r�d smogowej mg�y, niczym wyrwane ze snu, wznosz� si� monumentalne drapacze chmur wielkich korporacji.");
        Sleep(1000);
        Function::writeNarration(" Ich boski majestat bije ci� po oczach.");
        Sleep(2500);
        cout << endl;
        Function::writeNarration("\tSerce bije ci tak mocno, �e tylko szczypi�cy dotyk wiatru chroni ci� przed nag�ym atakiem serca.");
        Sleep(500);
        Function::writeNarration(" Nagle przez twoje cia�o przechodzi fala dreszczy, zaczynasz trz��� si� jak osika i u�wiadamiasz sobie, �e le�ysz na legowisku zrobionym ze starych gazet.");
        Sleep(2000);
        cout << endl;
        Function::writeNarration("\tKiedy podnosisz si� z ziemi, zauwa�asz wok� siebie morze �mieci.");
        Sleep(1000);
        Function::writeNarration(" Jest pe�ne karton�w, starych cz�ci mechanicznych i B�g wie czego jeszcze.");
        Sleep(1500);
        cout << endl;
        Function::writeNarration("\tKto wie, mo�e znajdziesz tam co� interesuj�cego...");
        cout << endl;
        cout << "" << endl;
        //-------------------------------------------------------------
        // Decyzja
        Function::actionOption(optionNr, "Rozejrzyj si� po okolicy w poszukiwaniu czego� cennego."); // Opcja nr 1
        optionNr++;
        Function::actionOption(optionNr, "Znajd� wyj�cie z zau�ka."); // Opcja nr 2
        optionNr = 1;
        Function::write("\t> ", 15);
    }*/

    while (true)
    {
        std::cin >> heroChoice;

        if (heroChoice == 1)
        {
            Sleep(1000);
            Function::clearScreen();
            rubbishSearch();
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
void Event::rubbishSearch()
{
    Logger::out("Function start", "Event::rubbishSearch");
    Function::showHeroAction("Search the area for something valuable.");
    std::cout << std::endl;
    Function::writeNarration("\tYou start rummaging through the trash.");
    Sleep(1500);
    Function::writeNarration(" The search takes a long while, but eventually you\n\tmanage to find something.");
    Sleep(2000);
    std::cout << std::endl << std::endl;

    Hero::heroes["Hero"].addItem(&Item::items["AD13"]);
    Function::changeConsoleColor(item);
    std::string str = "\t" + Item::items["AD13"].getName();
    Function::write(str);
    Function::changeConsoleColor();
    Function::write(" was found.");

    if (Hero::heroes["Hero"].hasItem(&Item::items["AD13"]))
    {
        Logger::out(Item::items["AD13"].getName() + " added to EQ", "Event::inSeaOfRubbish");
    }
    else {
        Logger::error(Item::items["AD13"].getName() + " not added to EQ", "Event::inSeaOfRubbish");
    }

    std::cout << std::endl;
    Function::write("\t[TIP: This item has been added to your inventory. You can view it in the text file in your\n\tgame folder.]", 15);
    Sleep(4000);
    std::cout << std::endl << std::endl;
    Function::writeNarration("\tHmm, that might come in handy in the future.");
    Sleep(1000);

    outOfTheAlley();
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::outOfTheAlley()
{
    Logger::out("Function start", "Event::outOfTheAlley");

    if (!Hero::heroes["Hero"].hasItem(&Item::items["AD13"]))
    {
        Function::showHeroAction("Find the exit from the alley.");
        std::cout << std::endl;
        Function::writeNarration("\tYou're not going to rummage through the trash.");
        Sleep(1500);
        Function::writeNarration(" And that's okay, you probably wouldn't find\n\tanything there anyway.");
        Function::writeNarration(" Instead, you slowly toddle toward the neon color bombs at the end of\n\tthe alley.");
    }
    else {
        std::cout << std::endl;
        Function::writeNarration("\tYou slowly toddle toward the neon color bombs at the end of the alley.");
    }

    Sleep(3000);
    std::cout << std::endl;
    Function::writeNarration("\tYou are getting closer and closer to your goal when from the right, from behind a veil of\n\tshadows, a low, not very pleasant voice belonging to a man speaks up.");
    std::cout << std::endl;
    Function::writeDialogue("\t- 'Hey, kid. Wait for a second.'");
    std::cout << std::endl;
    std::cout << "" << std::endl;
    //-------------------------------------------------------------
    // Decyzja
    Function::actionOption(optionNr, "Stop and find out what he wants.");
    optionNr++;
    Function::actionOption(optionNr, "Ignore him and keep walking.");
    optionNr = 1;
    Function::write("\t> ", 15);

    while (true)
    {
        std::cin >> heroChoice;

        if (heroChoice == 1)
        {
            Function::clearScreen();
            Function::showHeroAction("Stop and find out what he wants.");
            std::cout << std::endl;
            Function::writeNarration("\tYou stop and turn towards the owner of the voice.");
            Sleep(1500);
            Function::writeNarration(" His silhouette looms in the darkness. It's\n\tone of the homeless people who live here. What can he have for you?");
            std::cout << std::endl;
            Sleep(1000);
            dialogueWithBob();
            break;
        }
        else if (heroChoice == 2)
        {
            Function::clearScreen();
            Function::showHeroAction("Ignore him and keep walking.");
            std::cout << std::endl;
            Function::writeNarration("\tYou have a mysterious stranger for nothing. You speed up your step and leave him far behind you.\n\tWhatever he wanted from you is no longer important.");
            Sleep(1000);
            street();
            break;
        }
    }
    //-------------------------------------------------------------
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::dialogueWithBob()
{
    Logger::out("Function start", "Event::dialogueWithBob");
    std::string heroName, str;

    Function::writeDialogue("\t- 'What's your name, boy?'");

    if (!Npc::npcs["Bob"].knowsHero() && !Npc::npcs["Caden"].knowsHero() && !Npc::npcs["CadenPartner"].knowsHero())
    {
        Function::changeConsoleColor();
        std::cout << std::endl;
        std::cout << "\t> ";
        std::cin >> heroName;
        Hero::heroes["Hero"].setName(heroName);
        Logger::out("Hero's name is " + Hero::heroes["Hero"].getName(), "Event::conversationWithHomeless");
    }

    Npc::npcs["Bob"].setToKnowHero();
    str = "\t- 'So you're " + Hero::heroes["Hero"].getName() + ", huh?";
    Function::writeDialogue(str);
    Sleep(1500);
    str = " All right. I'm " + Npc::npcs["Bob"].getName() + ".";
    Function::writeDialogue(str);
    Sleep(1500);
    Function::writeDialogue(" What are you doin' here?'");
    std::cout << std::endl;
    Function::writeNarration("\tThe shadows in front of you, begin to ripple when your caller stands up.");
    //-------------------------------------------------------------
    // Decyzja
    std::cout << std::endl;
    std::cout << "" << std::endl;
    Function::dialogueOption(optionNr, "I'm not looking for trouble.");
    optionNr++;
    Function::dialogueOption(optionNr, "I'm just looking around. Where are we actually?");
    optionNr++;
    Function::dialogueOption(optionNr, "It's not your business.");
    optionNr = 1;
    Function::write("\t> ", 15);

    while (true)
    {
        std::cin >> heroChoice;

        if (heroChoice == 1)
        {
            Function::clearScreen();
            Function::showHeroAction("'I'm not looking for trouble.'");
            bobRecommendsZed = true; // Bob poleca bohaterowi sklep z broni� Zeda
            std::cout << std::endl;
            Function::writeDialogue("\t- 'Ha-ha, that's what I thought. To tell you the truth, you don't look very threatening.");
            Sleep(1000);
            Function::writeDialogue(" Well,\n\tyou could use some gat. I happen to know a guy who deals guns. His name is Zed, and his store is\n\tright around the corner.");
            Sleep(1000);
            Function::writeDialogue(" Tell him you're coming from old Bob and he'll find something for you.'");
            std::cout << std::endl;
            break;
        }
        else if (heroChoice == 2)
        {
            Function::clearScreen();
            Function::showHeroAction("'I'm just looking around. Where are we actually?'");
            std::cout << std::endl;
            Function::writeDialogue("\t- 'What's wrong with you?");
            Sleep(1000);
            Function::writeDialogue(" Anyway, it doesn't matter.");
            Sleep(1500);
            Function::writeDialogue(" Have you ever heard of Megacity?");
            Sleep(1500);
            Function::writeDialogue(" Well,\n\tit's right here. The neighborhood we are currently in is called Gunce Deep.");
            Sleep(1000);
            Function::writeDialogue(" Did I make your\n\thead clearer?'");
            std::cout << std::endl;
            break;
        }
        else if (heroChoice == 3)
        {
            Function::clearScreen();
            Function::showHeroAction("'It's not your business.'");
            std::cout << std::endl;
            Npc::npcs["Bob"].setAttitude(angry); // angry / hostile / friendly / neutral

            if (Npc::npcs["Bob"].getAttitude() == angry)
            {
                Logger::out("Bob is angry", "Event::conversationWithHomeless");
            }
            else {
                Logger::error("Bob is not angry", "Event::conversationWithHomeless");
            }

            Function::writeDialogue("\t- 'You're wrong. It's absolutely my business, kid. Don't shut your mouth like that, or you might\n\tlose a few teeth. Got it?'");
            std::cout << std::endl;
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
        std::cout << std::endl;
        Function::writeNarration("\tIn an instant the alley is filled with the howling of a police siren.");
        Sleep(1000);
        Function::writeNarration(" On the wall in front of\n\tyou, red and blue begin to dance with each other.");
        std::cout << std::endl;
        Function::writeDialogue("\t- 'Shit");
        Sleep(500);
        Function::writeDialogue(", cops!");
        Sleep(500);
        Function::writeDialogue(" Well, that's super. I think it's time for me to go.'");
        Sleep(1500);
        std::cout << std::endl;
        Function::writeNarration("\tThe aging beggar dives into the embrace of darkness in a flash.");
        Sleep(1500);
        Function::writeNarration(" Does this mean you see him for\n\tthe last time?");
        Sleep(3500);
        lookAtAmnesia();
    }
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// 2.2.2 ULICA
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::streetCrossroads()
{
    Logger::out("Function start", "Event::streetCrossroads");
    //-------------------------------------------------------------
    // Decyzja
    Function::showHeroAction("Visit: " + Location::locations["Street"].getName());
    std::cout << std::endl;
    Function::writeNarration("\tOnce again you are on a street bathed in nighttime darkness.");
    std::cout << std::endl << std::endl;
    Function::changeConsoleColor();
    Function::actionOption(optionNr, "Visit: " + Location::locations["DarkAlley"].getName());
    optionNr++;
    Function::actionOption(optionNr, "Visit: " + Location::locations["Nightclub"].getName());
    optionNr++;
    Function::actionOption(optionNr, "Visit: " + Location::locations["GunShop"].getName());
    optionNr = 1;
    Function::write("\t> ", 15);

    while (true)
    {
        std::cin >> heroChoice;

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
void Event::lookAtAmnesia()
{
    Logger::out("Function start", "Event::lookAtAmnesia");
    streetWasVisited = true;

    std::cout << std::endl;

    if (!Npc::npcs["Bob"].knowsHero())
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

    std::cout << std::endl;
    //-------------------------------------------------------------
    // Decyzja
    std::cout << "" << std::endl;
    Function::actionOption(optionNr, "Come closer and see what it's all about.");
    optionNr++;
    Function::actionOption(optionNr, "Take a look around the area.");
    optionNr = 1;
    Function::write("\t> ", 15);

    while (true)
    {
        std::cin >> heroChoice;

        if (heroChoice == 1)
        {
            Function::clearScreen();
            Function::showHeroAction("Come closer and see what it's all about.");
            std::cout << std::endl;

            if (!Npc::npcs["Bob"].knowsHero())
            {
                meetingWithSecurityGuards();
                meetingWithPolicemans();
            }
            else {
                meetingWithPolicemans();
            }
            break;
        }
        else if (heroChoice == 2)
        {
            Function::clearScreen();
            Function::showHeroAction("Take a look around the area.");
            encounterGunStore();
            break;
        }
    }
    //-------------------------------------------------------------
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::encounterGunStore()
{
    Logger::out("Function start", "Event::encounterGunStore");
    std::cout << std::endl;
    Function::writeNarration("\tYou go to the right side of the street. After walking several meters you come across a small booth\n\tbetween blocks of flats.");

    if (bobRecommendsZed)
    {
        Function::writeNarration(" Could it be that the famous gun store managed by Bob's friend?");
    }

    std::cout << std::endl;
    Function::changeConsoleColor();
    //-------------------------------------------------------------
    // Decyzja
    std::cout << "" << std::endl;
    Function::actionOption(optionNr, "Go inside.");
    optionNr++;
    Function::actionOption(optionNr, "Turn back.");
    optionNr = 1;
    Function::write("\t> ", 15);

    while (true)
    {
        std::cin >> heroChoice;

        if (heroChoice == 1)
        {
            Function::clearScreen();
            Function::showHeroAction("Go inside.");
            std::cout << std::endl;
            enterGunShop();
            break;
        }
        else if (heroChoice == 2)
        {
            Function::clearScreen();
            Function::showHeroAction("Turn back.");
            std::cout << std::endl;

            if (!Npc::npcs["Bob"].knowsHero())
            {
                meetingWithSecurityGuards();
                meetingWithPolicemans();
            }
            else {
                meetingWithPolicemans();
            }
            break;
        }
    }
    //-------------------------------------------------------------
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::meetingWithSecurityGuards()
{
    Logger::out("Function start", "Event::meetingWithSecurityGuards");
    Function::writeNarration("\tWhen you get closer, the faces turn toward you and start looking at you intently.");
    Sleep(1000);
    Function::writeNarration(" You pass them in silenceand are confronted by a broad - shouldered security guard.");
    std::cout << std::endl;
    Function::writeDialogue("\t- 'What are you looking for here?");
    Sleep(1500);
    Function::writeDialogue(" Trouble, maybe?'");
    std::cout << std::endl;
    Function::writeNarration("\tThe man clenches his hands into fists and smiles unpleasantly.");
    std::cout << std::endl;
    Function::writeDialogue("\t- 'You asshole, better let us in! I want a drink and for fuck's sake. I'm losing my patience!");
    std::cout << std::endl;
    Function::writeNarration("\tOne of the men waiting in the queue rushes forward and threatens the bouncer with his fist.");
    Sleep(1500);
    Function::writeNarration(" The security guard's attention shifts from you to the furious guy next to you.");
    std::cout << std::endl;
    Function::writeDialogue("\t- 'I'll say it one last time: get the fuck out of here or you'll get fucked.'");
    std::cout << std::endl;
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::meetingWithPolicemans()
{
    Logger::out("Function start", "Event::meetingWithPolicemans");
    std::string heroName, str;

    if (Npc::npcs["Bob"].knowsHero())
    {
        Function::writeNarration("\tWhen you get closer, one of the police officers in a dark blue uniform turns toward you.");
    }
    else {
        Function::writeNarration("\tIn an instant the street is filled with the howling of a police siren.");
        Sleep(1000);
        Function::writeNarration(" The reds and blues begin to\n\tdance with each other on the sidewalk and the silhouettes of the people around you.");
        Sleep(2000);
        std::cout << std::endl;
        Function::writeNarration("\tTwo grim-looking guys in dark blue uniforms get out of a police car and walk towards you. One of them\n\tpoints at you, taking out a tablet from behind his belt.");
    }

    std::cout << std::endl;
    Function::writeDialogue("\t- 'Who are you?");
    Sleep(1500);
    Function::writeDialogue(" And what are you doing here? Please show me your ID card.'");
    std::cout << std::endl;

    if (Hero::heroes["Hero"].hasItem(&Item::items["AD13"]))
    {
        Function::writeNarration("\tYou start searching through the pockets of your jacket and pants, but other than the accelerator\n\tyou found in the trash, there's nothing else there.");
    }
    else {
        Function::writeNarration("\tYou start searching through the pockets of your jacket and pants, but there's nothing there.");
    }

    std::cout << std::endl;
    Function::writeDialogue("\t- 'I see that we have a problem.");
    Sleep(1500);
    Function::writeDialogue(" Okay, then what's your name, citizen?");

    if (!Npc::npcs["Bob"].knowsHero())
    {
        Function::writeDialogue("'");
        std::cout << std::endl;
        std::cout << "\t> ";
        std::cin >> heroName;
        Hero::heroes["Hero"].setName(heroName);
        Logger::out("Hero's name is " + Hero::heroes["Hero"].getName(), "Event::conversationWithHomeless");
        std::cout << std::endl;
        str = "\t- '" + Hero::heroes["Hero"].getName() + "...";
        Function::writeDialogue(str);
        Sleep(1000);
        Function::writeDialogue(" Caden, check it out in the database.");
    }
    else {
        str = " " + Hero::heroes["Hero"].getName() + "...";
        Function::writeDialogue(str);
        Sleep(1000);
        Function::writeDialogue(" Caden, check\n\tit out in the database.");
    }

    Npc::npcs["CadenPartner"].setToKnowHero();
    Npc::npcs["Caden"].setToKnowHero();
    Sleep(1500);
    Function::writeDialogue(" And you, stand where you are.'");
    std::cout << std::endl;
    Function::writeNarration("\tThe other police officer nods, gets back in the car, and it looks like he's connecting with headquarters.");
    Sleep(3000);
    std::cout << std::endl;
    Function::writeNarration("\tA minute later, the same policeman returns and whispers something in his partner's ear.");
    Sleep(1500);
    Function::writeNarration(" That one nods and turns to look at you.");
    std::cout << std::endl;
    Function::writeDialogue("\t- 'I have good news for you.");
    Sleep(1500);
    Function::writeDialogue(" You're free for now, just don't let it occur to you to do something here, or you'll end up in arrest at the police station.");
    Sleep(1000);
    Function::writeDialogue(" Caden, take care of the rest of the attendees.'");
    std::cout << std::endl;
    Function::writeNarration("\tThe cop walks away to talk to the nearest person standing.");
    std::cout << std::endl;
    Function::writeDialogue("\t- 'If you're so pure, get in.'");
    std::cout << std::endl;
    Function::writeNarration("\tThe bouncer points to the door behind him.");
    std::cout << std::endl;
    //-------------------------------------------------------------
    // Decyzja
    Function::changeConsoleColor();
    std::cout << "" << std::endl;
    Function::actionOption(optionNr, "Go inside.");
    optionNr++;
    Function::actionOption(optionNr, "Turn back.");
    optionNr = 1;
    Function::write("\t> ", 15);

    while (true)
    {
        std::cin >> heroChoice;

        if (heroChoice == 1)
        {
            Function::clearScreen();
            Function::showHeroAction("Go inside.");
            std::cout << std::endl;
            nightclub();
            break;
        }
        else if (heroChoice == 2)
        {
            Function::clearScreen();
            Function::showHeroAction("Turn back.");
            std::cout << std::endl;
            encounterGunStore();
            break;
        }
    }
    //-------------------------------------------------------------
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// 2.2.3 SKLEP Z BRONI�
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::gunShopCrossroads()
{
    Logger::out("Function start", "Event::gunShopCrossroads");
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::enterGunShop()
{
    Logger::out("Function start", "Event::enterGunShop");
    gunShopWasVisited = true;

    Function::writeNarration("\tThe front door hisses open before you.");

    if (!Npc::npcs["Zed"].knowsHero())
    {
        Sleep(1000);
        Function::writeNarration(" You step over the threshold and enter a small room with a counter opposite the entrance. Behind it stands a tall, thin man with fatigue painted on his terribly oblong face.");
        Sleep(1500);
        Function::writeNarration(" He is dressed in an old corporate commando suit. On the wall behind his back hangs a lot of weapons.");
        std::cout << std::endl;
        Function::writeDialogue("\t- 'How can I help you, my friend?'");
        std::cout << std::endl;
        Npc::npcs["Zed"].setToKnowHero();
        dialogueWithZed();
    }
    else {
        Sleep(1000);
        Function::writeNarration(" From behind the counter, Zed is already smiling at you.");

        if (Hero::heroes["Hero"].hasItem(&Item::items["Pistol"]))
        {
            std::cout << std::endl;
            Function::writeDialogue("\t- 'What's up? How's the gun working out?'");
        }

        if (Quest::quests["ZedAccelerator"].isRunning() && !Quest::quests["ZedAccelerator"].isCompleted())
        {
            if (!Hero::heroes["Hero"].hasItem(&Item::items["AD13"]))
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
    Logger::out("Function start", "Event::dialogueWithZed");
    bool heroTalkedAboutBusinessWithZed = false;

    while (true)
    {
        //-------------------------------------------------------------
        // Decyzja
        Function::changeConsoleColor();
        std::cout << "" << std::endl;

        Function::dialogueOption(optionNr, "What do you have?");
        optionNr++;
        Function::dialogueOption(optionNr, "How's business going?");
        optionNr++;

        if (bobRecommendsZed && !zedKnowsAboutBobAndZed)
        {
            Function::dialogueOption(optionNr, "You're Zed? I come from Bob.");
            optionNr++;
        }

        Function::dialogueOption(optionNr, "I have to go...");
        optionNr = 1;
        Function::write("\t> ", 15);

        std::cin >> heroChoice;

        if (heroChoice == 1)
        {
            std::cout << std::endl;
            zedTrade();
            continue;
        }
        else if (heroChoice == 2)
        {
            std::cout << std::endl;

            if (heroTalkedAboutBusinessWithZed == true)
            {
                Function::writeDialogue("\t- 'Hey, what's up? Are you sclerotic or something? We already talked about this, haha!'");
                std::cout << std::endl;
            }
            else {
                heroTalkedAboutBusinessWithZed = true;
                Function::writeDialogue("\t- 'What kind of question is that anyway? Business is doing great! Everyone stops by every now and then to rearm. It's the natural order of things.'");
                std::cout << std::endl;
            }

            continue;
        }
        else if (heroChoice == 3)
        {
            std::cout << std::endl;

            if (bobRecommendsZed && !zedKnowsAboutBobAndZed)
            {
                zedKnowsAboutBobAndZed = true;
                std::cout << std::endl;
                Function::writeDialogue("\t- 'Yes, that is correct. I'm Zed, and this is my little shop.");
                Npc::npcs["Zed"].setAttitude(friendly);
                Sleep(1000);
                Function::writeDialogue(" Since you know Bob, you can get a small discount here'.");
                continue;
            }
            else {
                Function::writeDialogue("\t- 'No problem. See you later!'");
                std::cout << std::endl;
                Function::clearScreen();

                if (!Npc::npcs["Caden"].knowsHero() && !Npc::npcs["CadenPartner"].knowsHero())
                {
                    meetingWithPolicemans();
                }
                else
                {
                    street();
                }

                break;
            }
        }
        else if (heroChoice == 4 && bobRecommendsZed && !zedKnowsAboutBobAndZed)
        {
            std::cout << std::endl;
            Function::writeDialogue("\t- 'No problem. See you later!'");
            std::cout << std::endl;

            if (!Npc::npcs["Caden"].knowsHero() && !Npc::npcs["CadenPartner"].knowsHero())
            {
                meetingWithPolicemans();
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
    Logger::out("Function start", "Event::zedTrade");
    bool ZedTellsAboutWeapons = false;

    if (!Hero::heroes["Hero"].hasItem(&Item::items["Pistol"]))
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
            std::cout << std::endl;
            Function::changeConsoleColor();
            std::cout << "" << std::endl;
            Function::actionOption(optionNr, "Buy: pistol (250 $).");
            optionNr++;
            Function::dialogueOption(optionNr, "I have made up my mind.");
            optionNr = 1;
            Function::write("\t> ", 15);

            while (true)
            {
                std::cin >> heroChoice;

                if (heroChoice == 1)
                {
                    buyPistol();
                    break;
                }
                else if (heroChoice == 2)
                {
                    std::cout << std::endl;
                    Function::writeNarration("Zed looks at you pityingly and shrugs his shoulders.");
                    std::cout << std::endl;
                    Function::writeDialogue("\t- 'No problem. It can happen to anyone.'");
                    std::cout << std::endl;
                    dialogueWithZed();
                    break;
                }
            }
        }
        else
        {
            // Decyzja
            Function::changeConsoleColor();
            std::cout << "" << std::endl;
            Function::actionOption(optionNr, "Buy: pistol (250 $).");
            optionNr++;
            Function::dialogueOption(optionNr, "I have made up my mind.");
            optionNr = 1;
            Function::write("\t> ", 15);

            while (true)
            {
                std::cin >> heroChoice;

                if (heroChoice == 1)
                {
                    buyPistol();

                    break;
                }
                else if (heroChoice == 2)
                {
                    std::cout << std::endl;
                    Function::writeNarration("Zed looks at you pityingly and shrugs his shoulders.");
                    std::cout << std::endl;
                    Function::writeDialogue("\t- 'No problem. It can happen to anyone.'");
                    std::cout << std::endl;
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
        std::cout << std::endl;
        dialogueWithZed();
    }
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::buyPistol()
{
    Logger::out("Function start", "Event::buyPistol");
    std::string str;

    std::cout << std::endl;

    if (Hero::heroes["Hero"].getMoney() != 250.0)
    {
        Function::writeDialogue("\t- 'I see you're low on cash.");
        Sleep(1000);
        Function::writeDialogue(" But don't worry, we'll sort it out somehow.");
        Sleep(1500);

        if (zedKnowsAboutBobAndZed)
        {
            Function::writeDialogue(" Hmm, you know Old Bob, that already means something.");
            Sleep(1000);
            Function::writeDialogue(" Let's just say I'll loan you this gun on a friendly basis.");

            Hero::heroes["Hero"].addItem(&Item::items["Pistol"]);
            std::cout << std::endl;
            Function::changeConsoleColor(item);
            str = "\t" + Item::items["Pistol"].getName();
            Function::write(str);
            Function::changeConsoleColor();
            Function::write(" gained.");
            std::cout << std::endl;
        }
        else
        {
            Quest::quests["ZedAccelerator"].start();
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

        Hero::heroes["Hero"].addItem(&Item::items["Pistol"]);
        std::cout << std::endl;
        Function::changeConsoleColor(item);
        str = "\t" + Item::items["Pistol"].getName();
        Function::write(str);
        Function::changeConsoleColor();
        Function::write(" was bought.");
        std::cout << std::endl;
    }
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// 2.2.4 KLUB NOCNY
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::nightclubCrossroads()
{
    Logger::out("Function start", "Event::nightclubCrossroads");
    //-------------------------------------------------------------
    // Decyzja
    Function::showHeroAction("Visit: " + Location::locations["Nightclub"].getName());
    std::cout << std::endl;
    Function::writeNarration("\tYou enter from a fairly well-lit street into a slightly darkened nightclub, trembling with colour.");
    std::cout << std::endl << std::endl;
    Function::changeConsoleColor();
    Function::actionOption(optionNr, "Go to the dance floor.");
    optionNr++;
    Function::actionOption(optionNr, "Go to the bar.");
    optionNr++;
    Function::actionOption(optionNr, "Go upstairs.");
    optionNr++;
    Function::actionOption(optionNr, "Visit: " + Location::locations["Street"].getName());
    optionNr = 1;
    Function::write("\t> ", 15);

    while (true)
    {
        std::cin >> heroChoice;

        if (heroChoice == 1)
        {
            std::cout << std::endl;
            darkAlley();
            break;
        }
        else if (heroChoice == 2)
        {
            std::cout << std::endl;
            nightclub();
            break;
        }
        else if (heroChoice == 3)
        {
            std::cout << std::endl;
            gunShop();
            break;
        }
        else if (heroChoice == 4)
        {
            std::cout << std::endl;
            street();
            break;
        }
    }
    //-------------------------------------------------------------
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::enterClub()
{
    Logger::out("Function start", "Event::enterClub");
    nightclubWasVisited = true;
    std::cout << std::endl;
    Function::writeNarration("\tAfter passing through the entrance your eardrums are slowly bursting from the loud music in the club.");
    Sleep(1000);
    Function::writeNarration(" You walk through a short lobby and so arrive at a crowded room full of dancing people.");
    Sleep(1000);
    Function::writeNarration(" Disco balls hung from the ceiling net everything around with streaks of multi-colored light.");
    Sleep(1000);
    Function::writeNarration(" Next to the dance floor is a bar, and behind it are several mechanically streamlined bartenders.");
    std::cout << std::endl;
    //-------------------------------------------------------------
    // Decyzja
    Function::changeConsoleColor();
    std::cout << "" << std::endl;
    Function::actionOption(optionNr, "Go dance on the dance floor.");
    optionNr++;
    Function::actionOption(optionNr, "Go to the bar.");
    optionNr = 1;
    Function::write("\t> ", 15);

    while (true)
    {
        std::cin >> heroChoice;

        if (heroChoice == 1)
        {
            std::cout << std::endl;
            clubDanceFloor();
            break;
        }
        else if (heroChoice == 2)
        {
            std::cout << std::endl;
            clubBar();
            break;
        }
    }
    //-------------------------------------------------------------
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::clubDanceFloor()
{
    Logger::out("Function start", "Event::clubDanceFloor");
    Function::showHeroAction("Go dance on the dance floor.");
    std::cout << std::endl;

    if (!Npc::npcs["Nyx"].knowsHero())
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
        std::cout << std::endl << std::endl;
        Function::dialogueOption(optionNr, "What do you want?"); // Opcja nr 1
        optionNr++;
        Function::dialogueOption(optionNr, "Hey, baby."); // Opcja nr 2
        optionNr++;
        Function::actionOption(optionNr, "Keep dancing with no words."); // Opcja nr 3
        optionNr = 1;
        Function::write("\t> ", 15);

        while (true)
        {
            std::cin >> heroChoice;

            if (heroChoice == 1)
            {
                Function::clearScreen();
                std::cout << std::endl;
                Function::showHeroAction("'What do you want?'");
                std::cout << std::endl;
                Function::writeNarration("\tThe girl turns towards you and smiles with her snow-white teeth.");
                Function::writeDialogue("\n\t- 'Nothing will escape your attention. I am Nyx. I\n\think you can help me.'");
                break;
            }
            else if (heroChoice == 2)
            {
                Function::clearScreen();
                std::cout << std::endl;
                Function::showHeroAction("'Hey, baby.'");
                std::cout << std::endl;
                Function::writeNarration("\tThe girl turns towards you and smiles with her snow-white teeth.");
                Function::writeDialogue("\n\t- 'Hi, stud. I've been watching you since you came in. I am Nyx.'");
                Function::writeNarration("\n\tWith the last word she comes closer to you turns her back on you and starts dancing very close to you.");
                Function::writeDialogue("\n\t- 'I am looking for someone like you. I\n\tthink you can help me.'");
                break;
            }
            else if (heroChoice == 3)
            {
                Function::clearScreen();
                std::cout << std::endl;
                Function::showHeroAction("Keep dancing with no words.");
                std::cout << std::endl;
                Function::writeNarration("\tThe girl turns towards you and smiles with her snow-white teeth.");
                Function::writeDialogue("\n\t- 'Hi, I am Nyx. Vinc, the owner, is my boyfriend. I\n\tthink you can help me.'");
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
    Logger::out("Function start", "Event::clubBar");
    heroIsAtBar = true;

    Function::writeNarration("\tWith a slow step, you approach the counter, settle comfortably on a stool, and lift your gaze to the barman in front of you.");
    std::cout << std::endl;
    Function::writeDialogue("\t- 'What's for you?'");
    std::cout << std::endl;
    //-------------------------------------------------------------
    // Decyzja
    Function::changeConsoleColor();
    std::cout << "" << std::endl;
    Function::dialogueOption(optionNr, "Give me anything.");
    optionNr++;
    Function::dialogueOption(optionNr, "Who's in charge?");
    optionNr++;
    Function::dialogueOption(optionNr, "Bye.");
    optionNr = 1;
    Function::write("\t> ", 15);

    while (true)
    {
        std::cin >> heroChoice;

        if (heroChoice == 1)
        {
            std::cout << std::endl;
            Function::writeDialogue("\t- 'Okay.");
            Sleep(1000);
            Function::writeDialogue(" Let's see...'");
            Sleep(1500);
            std::cout << std::endl;
            Function::writeNarration("\tThe barman turns his back on you and looks through the bottles of alcohol. Finally, he selects one of them and pours its contents into a glass before placing it on the counter in front of you.");
            Sleep(1500);
            std::cout << std::endl;
            Function::writeNarration("\tYou reach for the vessel and empty it.");
            Sleep(1000);
            Function::writeNarration(" You feel a pleasant warmth spreading up your throat and further down your gullet.");
            break;
        }
        else if (heroChoice == 2)
        {
            std::cout << std::endl;
            Function::writeNarration("\tThe bartender squints, hearing your question.");
            std::cout << std::endl;
            Function::writeDialogue("\t- 'You're not from around here, are you?");
            Sleep(1500);
            Function::writeDialogue(" My boss is Vincent Ramsey.");
            Sleep(1000);
            Function::writeDialogue(" He's a tough guy, so you'd better not make trouble, or it could end badly for you.'");
            break;
        }
        else if (heroChoice == 3)
        {
            std::cout << std::endl;
            Function::writeNarration("\tThe bartender reaches for a glass from under the counter and starts wiping it down.");
            std::cout << std::endl;
            Function::writeDialogue("\t- 'Yeah, have fun.'");
            break;
        }
    }
    //-------------------------------------------------------------
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::miaMeeting()
{
    Logger::out("Function start", "Event::miaMeeting");
    //-------------------------------------------------------------
    // Decyzja
    Function::changeConsoleColor();
    std::cout << std::endl << std::endl;
    Function::dialogueOption(optionNr, "What is it about?");
    optionNr++;
    Function::actionOption(optionNr, "Be silent and let her speak.");
    optionNr = 1;
    Function::write("\t> ", 15);

    while (true)
    {
        std::cin >> heroChoice;

        if (heroChoice == 1)
        {
            Function::clearScreen();
            std::cout << std::endl;
            Function::showHeroAction("'What is it about?'");
            std::cout << std::endl;
            break;
        }
        else if (heroChoice == 2)
        {
            Function::clearScreen();
            std::cout << std::endl;
            Function::showHeroAction("Be silent and let her speak.");
            std::cout << std::endl;
            break;
        }
    }

    Function::writeDialogue("\n\t- 'Vinc, the owner, is my boyfriend.");
    Sleep(1000);
    Function::writeDialogue(" I want him dead.'");
    Quest::quests["KillVincent"].start();
    Sleep(1500);
    Function::writeNarration("\n\tNyx takes your hand and leads you towards the toilet.");
    Function::writeDialogue("\n\t- 'Do you have a gun?'");

    if (Hero::heroes["Hero"].hasItem(&Item::items["Pistol"]))
    {
        Function::writeDialogue("\n\t- 'Good.");
        Sleep(1000);
        Function::writeDialogue(" So you already know what and how.'");
    }
    else
    {
        Function::writeDialogue("\n\t- 'You know how to use it, don't you?");
        Sleep(1000);
        Function::writeDialogue(" Get it for yourself, you'll need it. Here's 200 bucks.'");
        Hero::heroes["Hero"].addMoney(200);
        std::cout << std::endl;
        Function::changeConsoleColor(green);
        Function::write("\t200$");
        Function::changeConsoleColor();
        Function::write(" has been received.");
        Function::writeDialogue("\n\t- 'There is a gun shop nearby.");
        Function::writeDialogue(" It is run by a guy named Zed. Visit him before you head upstairs.'");
    }
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::clubUpstairs()
{
    Logger::out("Function start", "Event::clubUpstairs");
    Function::writeNarration("\n\tYou go up a winding staircase. At the end of a short banister you will see a closed door guarded by another bulky individual.");
    //-------------------------------------------------------------
    // Decyzja
    Function::changeConsoleColor();
    std::cout << std::endl << std::endl;
    Function::actionOption(optionNr, "Come closer.");
    optionNr++;
    Function::actionOption(optionNr, "Go back downstairs.");
    optionNr = 1;
    Function::write("\t> ", 15);

    while (true)
    {
        std::cin >> heroChoice;

        if (heroChoice == 1)
        {
            Function::clearScreen();
            std::cout << std::endl;
            Function::showHeroAction("Come closer.");
            std::cout << std::endl;
            Function::writeNarration("\tAre you brave or foolish enough to face the hammer man. You are stopped from taking another step by his firm voice.");
            std::cout << std::endl;
            Function::writeDialogue("\t- 'What here?'");
            Npc::npcs["Jet"].setToKnowHero();
            dialogueWithJet();
            break;
        }
        else if (heroChoice == 2)
        {
            Function::clearScreen();
            std::cout << std::endl;
            Function::showHeroAction("Go back downstairs.");
            std::cout << std::endl;
            Function::writeNarration("\tYou don't dare to come closer, so like the last coward you turn back and return to the kingdom of loud music and dancing people.");
            std::cout << std::endl;
            nightclub();
            break;
        }
    }
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::dialogueWithJet()
{
    Logger::out("Function start", "Event::dialogueWithJet");
    int jetPoints = 0;
    //-------------------------------------------------------------
    // Decyzja
    Function::changeConsoleColor();
    std::cout << std::endl << std::endl;
    Function::dialogueOption(optionNr, "I want to pass.");
    optionNr++;
    Function::dialogueOption(optionNr, "What is behind that door?");
    optionNr++;

    if (Hero::heroes["Hero"].hasItem(&Item::items["Pistol"]))
    {
        Function::actionOption(optionNr, "Kill him with a pistol.");
        optionNr++;
        Function::actionOption(optionNr, "Stun him with a pistol.");
        optionNr++;
    }

    Function::dialogueOption(optionNr, "It's time for me to go.");
    optionNr++;
    optionNr = 1;
    Function::write("\t> ", 15);

    while (true)
    {
        std::cin >> heroChoice;

        if (heroChoice == 1)
        {
            Function::clearScreen();
            std::cout << std::endl;
            Function::showHeroAction("'I want to pass.'");
            std::cout << std::endl;
            jetPoints += 1;
            break;
        }
        else if (heroChoice == 2)
        {
            Function::clearScreen();
            std::cout << std::endl;
            Function::showHeroAction("'What is behind that door?'");
            std::cout << std::endl;
            jetPoints += 1;
            break;
        }
        else if (heroChoice == 3 && !Hero::heroes["Hero"].hasItem(&Item::items["Pistol"]))
        {
            Function::clearScreen();
            std::cout << std::endl;
            Function::showHeroAction("'It's time for me to go.'");
            std::cout << std::endl;
            Function::clearScreen();
            nightclub();
            break;
        }
        else if (heroChoice == 3 && Hero::heroes["Hero"].hasItem(&Item::items["Pistol"]))
        {
            Function::clearScreen();
            std::cout << std::endl;
            Function::showHeroAction("Kill him with a pistol.");
            std::cout << std::endl;
            break;
        }
        else if (heroChoice == 4 && Hero::heroes["Hero"].hasItem(&Item::items["Pistol"]))
        {
            Function::clearScreen();
            std::cout << std::endl;
            Function::showHeroAction("Stun him with a pistol.");
            std::cout << std::endl;
            break;
        }
        else if (heroChoice == 5 && Hero::heroes["Hero"].hasItem(&Item::items["Pistol"]))
        {
            Function::clearScreen();
            std::cout << std::endl;
            Function::showHeroAction("'It's time for me to go.'");
            std::cout << std::endl;
            Function::clearScreen();
            nightclub();
            break;
        }
    }
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::vincentAssassination()
{
    Logger::out("Function start", "Event::vincentAssassination");
    vincentOffice();
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::vincentOffice()
{
    Logger::out("Function start", "Event::vincentOffice");
    Function::writeNarration("\tYou enter the manager's office immersed in twilight. In the middle of the room stands a sizable desk, and on it are stacks of documents and computer. To the left of the entrance is a window to the street below. On the right you will notice a door to another room.");
    std::cout << std::endl;
    //-------------------------------------------------------------
    // Decyzja
    Function::changeConsoleColor();
    std::cout << "" << std::endl;
    Function::actionOption(optionNr, "Open the door and go into the other room.");
    optionNr++;
    Function::actionOption(optionNr, "Stay and search the office.");
    optionNr = 1;
    Function::write("\t> ", 15);

    while (true)
    {
        std::cin >> heroChoice;

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
    Logger::out("Function start", "Event::checkVincentDesk");
    heroKnowsVincentCode = true;
    Function::showHeroAction("Stay and search the office.");
    std::cout << std::endl;
    Function::writeNarration("\tYou walk up to the desk. You start flipping through the e-papers one by one and finally your gaze falls on the flickering blue monitor.");
    std::cout << std::endl;
    Function::write("\t");

    vincentHideoutCode();
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::vincentHideoutCode()
{
    Logger::out("Function start", "Event::vincentHideoutCode");
    std::cout << std::endl;
    Function::writeNarration("\tYou walk closer and spot the terminal. It looks like you'll need to use a code to get through.");
    Sleep(1500);

    if (!heroKnowsVincentCode)
    {
        Function::writeNarration(" You have to look around the office though, whether you want to or not.");
    }
    else {
        std::cout << std::endl;
        Function::changeConsoleColor();
        std::cout << "" << std::endl;
        Function::actionOption(optionNr, "Use code '2021'.");
        optionNr++;
        Function::actionOption(optionNr, "Search the office.");
        Function::write("\t> ", 15);
    }
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::vincentHideout()
{
    Logger::out("Function start", "Event::vincentHideout");
    Npc::npcs["Vincent"].setStatus(unconscious);
    std::cout << std::endl;
    Function::writeNarration("\tThe door closes behind you, hissing quietly.");
    Sleep(2000);
    Function::writeNarration(" The room you're in is full of smaller and larger\n\tcables that merge into a single monitor that hangs above the sim-chair. On it lies a big guy\n\tin a tailored suit and a stimulation helmet on his head that obscures his face.");
    Sleep(1500);
    Function::writeNarration(" You guess it's\n\tVincent, the club owner.");
    Sleep(2000);
    std::cout << std::endl;
    Function::writeNarration("\tCreeping up, you come closer. Your goal is within reach. The question is what will you do?");
    std::cout << std::endl;
    //-------------------------------------------------------------
    // Decyzja
    Function::changeConsoleColor();
    std::cout << "" << std::endl;
    Function::actionOption(optionNr, "Disconnect his consciousness from the neuronet. (Kill him)");
    optionNr++;
    Function::actionOption(optionNr, "Wait for his consciousness to leave the neuronet.");
    optionNr = 1;
    Function::write("\t> ", 15);

    while (true)
    {
        std::cin >> heroChoice;

        if (heroChoice == 1)
        {
            Function::clearScreen();
            Function::showHeroAction("Disconnect his consciousness from the neuronet. (Kill him)");
            std::cout << std::endl;
            Function::writeNarration("\tYou lean over Vincent and, in a fluid motion without hesitation, pull the stimulation helmet\n\toff his head. You witness the nightclub owner being shaken by a wave of convulsions. Foam\n\tbegins to come out of his mouth and after a moment the man freezes.");
            Sleep(1500);
            Npc::npcs["Vincent"].setStatus(dead);
            Function::writeNarration(" He's probably dead, just like\n\tNyx wanted.");
            break;
        }
        else if (heroChoice == 2)
        {
            Function::clearScreen();
            Function::showHeroAction("Wait for his consciousness to leave the neuronet.");
            std::cout << std::endl;
            Function::writeNarration("\tYou are not a coward.");
            Sleep(1000);
            Function::writeNarration(" You don't stab people in the back. That's not your style. You prefer an\n\topen fight.");
            Sleep(1500);
            Npc::npcs["Vincent"].setStatus(normal);
            Function::writeNarration(" After a while, you notice Vincent moving slightly in his seat. He opens his eyes -\n\tthey are shining with the excitement of his online adventure.");
            Sleep(1000);
            Function::writeNarration(" It is only a matter of time before\n\tVincent notices your presence. There is no turning back now.");
            std::cout << std::endl;
            Function::writeDialogue("\t- 'What the fuck are you doing here, dickhead?'");
            std::cout << std::endl;
            dialogueWithVincent();
            break;
        }
    }
    //-------------------------------------------------------------
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::dialogueWithVincent()
{
    Logger::out("Function start", "Event::dialogueWithVincent");
    //-------------------------------------------------------------
    // Decyzja
    std::cout << std::endl;
    Function::changeConsoleColor();
    std::cout << "" << std::endl;
    Function::dialogueOption(optionNr, "Die!");
    optionNr++;
    Function::dialogueOption(optionNr, "I don't want to fight with you.");
    optionNr++;
    Function::dialogueOption(optionNr, "Nyx wants you dead.");
    optionNr = 1;
    Function::write("\t> ", 15);

    while (true)
    {
        std::cin >> heroChoice;

        if (heroChoice == 1)
        {
            Function::clearScreen();
            Function::showHeroAction("'Die!'");
            std::cout << std::endl;
            Function::writeNarration("\tWith a shout, you bring out your gun and aim it at Vincent's chest.");
            std::cout << std::endl;
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
            std::cout << std::endl;
            Function::writeNarration("\tYou are not a coward.");
            Sleep(1000);
            Function::writeNarration(" You don't stab people in the back. That's not your style. You prefer an\n\topen fight.");
            break;
        }
        else if (heroChoice == 3)
        {
            Function::clearScreen();
            Function::showHeroAction("'Nyx wants you dead.'");
            std::cout << std::endl;
            Function::writeNarration("\tYou are not a coward. You don't stab people in the back. That's not your style. You prefer an open fight.");
            break;
        }
    }
    //-------------------------------------------------------------
    // Decyzja
    std::cout << std::endl;
    Function::changeConsoleColor();
    std::cout << "" << std::endl;
    Function::dialogueOption(optionNr, "It doesn't matter.");
    optionNr++;
    Function::dialogueOption(optionNr, "Your girlfriend, Nyx.");
    optionNr = 1;
    Function::write("\t> ", 15);

    while (true)
    {
        std::cin >> heroChoice;

        if (heroChoice == 1)
        {
            Function::clearScreen();
            Function::showHeroAction("'It doesn't matter.'");
            std::cout << std::endl;
            Function::writeDialogue("\t- 'Ugh, you little prick. I'll get you from beyond the grave. There will be no peace. I won't let that happen!'");
            Sleep(1500);
            std::cout << std::endl;
            Function::writeNarration("\tThe last word spoken synchronizes with the bang of a gunshot as a bullet of energy pierces the club owner's chest.");
            Sleep(1000);
            Function::writeNarration(" The recoil knocks him from his seat. The lifeless body clatters against the floor.");
            Sleep(1500);
            Function::writeNarration(" He's dead, just like Nyx wanted.");
            Npc::npcs["Vincent"].setStatus(dead);
            std::cout << std::endl;
            Function::writeNarration("\tOut of curiosity, you walk closer and spot the corpse holding a small pistol.");
            Sleep(1000);
            Function::writeNarration(" That bastard was playing for time after all!");
            break;
        }
        else if (heroChoice == 2)
        {
            Function::clearScreen();
            Function::showHeroAction("'Your girlfriend, Nyx.'");
            std::cout << std::endl;
            Function::writeDialogue("\t- 'Traitorous bitch! She'll get her due someday.");
            Function::writeDialogue(" All right, shithead, let's get this over with.'");
            std::cout << std::endl;
            Function::writeNarration("\tThe last word spoken synchronizes with the bang of a gunshot as a bullet of energy pierces the club owner's chest.");
            Sleep(1000);
            Function::writeNarration(" The recoil knocks him from his seat. The lifeless body clatters against the floor.");
            Sleep(1500);
            Function::writeNarration(" He's dead, just like Nyx wanted.");
            Npc::npcs["Vincent"].setStatus(dead);
            std::cout << std::endl;
            Function::writeNarration("\tOut of curiosity, you walk closer and spot the corpse holding a small pistol.");
            Sleep(1000);
            Function::writeNarration(" That bastard was playing for time after all!");
            break;
        }
    }
    //-------------------------------------------------------------
    std::cout << std::endl;
    Function::writeNarration("\tThe passage behind your back is opened.");
    Sleep(1000);
    Function::writeNarration(" You turn around, in front of you is Nyx.");
    std::cout << std::endl;
    Function::writeDialogue("\t- 'Did you do what I asked you to do...'");
    Sleep(1500);
    std::cout << std::endl;
    Function::writeNarration("\tThe girl's gaze wanders from you to the body of her ex-boyfriend behind you.");
    Sleep(1000);
    std::cout << std::endl;
    Function::writeDialogue("\t- 'You did it... You really did it... Is he - is he dead?'");
    Sleep(1000);
    std::cout << std::endl;
    Function::writeNarration("\tNyx walks past you and kneels by the dead man. She starts searching his pockets for something.");
    //-------------------------------------------------------------
    // Decyzja
    std::cout << std::endl;
    Function::changeConsoleColor();
    std::cout << "" << std::endl;
    Function::actionOption(optionNr, "Do nothing.");
    optionNr++;
    Function::dialogueOption(optionNr, "What is this all about?");
    optionNr = 1;
    Function::write("\t> ", 15);

    while (true)
    {
        std::cin >> heroChoice;

        if (heroChoice == 1)
        {
            std::cout << std::endl;
            Function::writeNarration("\tYou let the girl quietly plunder the corpse. This gives you more time to look at her shapes more closely.");
            std::cout << std::endl;
            Function::writeDialogue("\t- 'Spare me, if you please.'");
            break;
        }
        else if (heroChoice == 2)
        {
            std::cout << std::endl;
            Function::writeDialogue("\t- 'Well, now I think I owe you an explanation.'");
            Function::writeNarration("\tA girl talks to you without even looking at you.");
            std::cout << std::endl;
            break;
        }
    }
    //-------------------------------------------------------------
    vincentResurrection();
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::vincentResurrection()
{
    Logger::out("Function start", "Event::vincentResurrection");
    std::cout << std::endl;
    Function::writeNarration("\tSuddenly, the maze of cables begins to vibrate and move in a strange dance.");
    Sleep(1000);
    Function::writeNarration(" Hisses reach you and Nyx, forming a gibberish that is difficult to understand.");
    std::cout << std::endl;
    Function::changeConsoleColor(dia_robot);
    Function::write("\t<You scum! You thought you got rid of me.");
    Sleep(1000);
    Function::write(" But you didn't.");
    Sleep(1000);
    Function::write(" I'm immortal now!>");
    std::cout << std::endl;
    Function::writeNarration("\tYou exchange a look with Nyx. You both can't believe what's happening.");
    std::cout << std::endl;
    Function::writeDialogue("\t- 'What the fuck?!'");
    std::cout << std::endl;
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
    Logger::out("Function start", "Event::loadingFiles");
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
    std::cout << std::endl;
    Function::write("\tDownload completed.");
    Function::changeConsoleColor();
}