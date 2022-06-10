#include "../events.hpp"

bool bobRecommendsZed       = false,
     zedKnowsAboutBobAndZed = false,
     heroIsOnDanceFloor     = false,
     heroIsAtBar            = false,
     heroKnowsVincentCode   = false;

// MROCZNY ZAUŁEK
void Event::prologue()
{
    Logger::startFuncLog(__FUNCTION__);
    Display::write(jWriter["Prologue"]["Title"]);
    Console::wait(2000);
    Display::write(jWriter["Prologue"]["Subtitle"]);
    Console::wait(5000);
    Console::clearScreen();
    storyIntroduction();
}

void Event::storyIntroduction()
{
    Logger::startFuncLog(__FUNCTION__);
    Display::writeNarration(jWriter["Prologue"]["StoryIntro"][0]);
    Console::wait(1000);
    Display::writeNarration(jWriter["Prologue"]["StoryIntro"][1], 20);
    Game::pause();
    Console::clearScreen();
    Console::wait(2500);
    Display::writeNarration(jWriter["Prologue"]["PrologueDream"][0], 75);
    Console::wait(2500);
    Display::writeNarration(jWriter["Prologue"]["PrologueDream"][1], 75);
    Console::wait(2500);
    Display::writeNarration(jWriter["Prologue"]["PrologueDream"][2], 75);
    Console::wait(3000);
    Console::clearScreen();
    wakeUpInDarkAlley();
}

void Event::wakeUpInDarkAlley()
{
    Logger::startFuncLog(__FUNCTION__);
    Menu menu1;
    Console::wait(2000);
    Display::writeNarration(jWriter["Prologue"]["WakeUpInDarkAlley"][0]);
    Console::wait(1000);
    Display::writeNarration(jWriter["Prologue"]["WakeUpInDarkAlley"][1]);
    Console::wait(1500);
    Display::writeNarration(jWriter["Prologue"]["WakeUpInDarkAlley"][2]);
    Console::wait(1000);
    Display::writeNarration(jWriter["Prologue"]["WakeUpInDarkAlley"][3]);
    Console::wait(3000);
    Display::writeNarration(jWriter["Prologue"]["WakeUpInDarkAlley"][4]);
    Console::wait(500);
    Display::writeNarration(jWriter["Prologue"]["WakeUpInDarkAlley"][5]);
    Console::wait(3000);
    Display::writeNarration(jWriter["Prologue"]["WakeUpInDarkAlley"][6]);
    Console::wait(1000);
    Display::writeNarration(jWriter["Prologue"]["WakeUpInDarkAlley"][7]);
    Console::wait(2500);
    Display::writeNarration(jWriter["Prologue"]["WakeUpInDarkAlley"][8]);
    //--------------------------------
    menu1.addOptions({ jWriter["Prologue"]["Menu1"][0], jWriter["Prologue"]["Menu1"][1] });
    menu1.showOptions();
    //--------------------------------

    while (true)
    {
        heroChoice = menu1.inputChoice();

        if (heroChoice == 1)
        {
            Console::clearScreen();
            menu1.showHeroChoice();
            rubbishSearch();
            break;
        }
        else if (heroChoice == 2)
        {
            Console::clearScreen();
            menu1.showHeroChoice();
            outOfTheAlley();
            break;
        }
        else Logger::invalidHeroChoiceError(__FUNCTION__); continue;
    }
}

void Event::acceleratorFinding()
{
    Logger::startFuncLog(__FUNCTION__);
    Display::writeNarration(jWriter["Prologue"]["AcceleratorFinding"][0]);
    Console::wait(1500);
    Display::writeNarration(jWriter["Prologue"]["AcceleratorFinding"][1]);
    Console::wait(2000);

    Hero::heroes[0].addItem(&Item::items["AD13"]);
    Hero::heroes[0].addMoney(5.0);
    Console::setConsoleColor(ConsoleColor::CC_Item);
    Display::write("\n\n\t" + Item::items["AD13"].getName());
    Console::resetConsoleColor();
    Display::write(jWriter["Infos"]["And"]);
    Console::setConsoleColor(ConsoleColor::CC_Green);
    Display::write("5$");
    Console::resetConsoleColor();
    Display::write(jWriter["Infos"]["WasFound"]);

    Display::write(jWriter["InventoryInfos"]["InvTip"], 15);
    Console::wait(4000);
    Display::writeNarration(jWriter["Prologue"]["AcceleratorFinding"][2]);
    Console::wait(1000);
}

void Event::rubbishSearch()
{
    Logger::startFuncLog(__FUNCTION__);
    acceleratorFinding();
    outOfTheAlley();
}

void Event::outOfTheAlley()
{
    Logger::startFuncLog(__FUNCTION__);

    if (!Hero::heroes[0].hasItem(&Item::items["AD13"]))
    {
        Display::writeNarration(jWriter["Prologue"]["OutOfTheAlley"][0]);
        Console::wait(1500);
        Display::writeNarration(jWriter["Prologue"]["OutOfTheAlley"][1]);
        Display::writeNarration(jWriter["Prologue"]["OutOfTheAlley"][2]);
    }
    else {
        Display::writeNarration(jWriter["Prologue"]["OutOfTheAlley"][3]);
    }

    Console::wait(3000);
    Display::writeNarration(jWriter["Prologue"]["OutOfTheAlley"][4]);
    Display::writeDialogue(jWriter["Prologue"]["DIA_Bob"][0]);
    //--------------------------------
    Menu menu2;
    menu2.addOptions({ jWriter["Prologue"]["Menu2"][0], jWriter["Prologue"]["Menu2"][1] });
    menu2.showOptions();
    //--------------------------------
    while (true)
    {
        heroChoice = menu2.inputChoice();

        if (heroChoice == 1)
        {
            Console::clearScreen();
            menu2.showHeroChoice();
            Display::writeNarration(jWriter["Prologue"]["OutOfTheAlley"][5]);
            Console::wait(1500);
            Display::writeNarration(jWriter["Prologue"]["OutOfTheAlley"][6]);
            Console::wait(1000);
            dialogueWithBob();
            break;
        }
        else if (heroChoice == 2)
        {
            Console::clearScreen();
            menu2.showHeroChoice();
            Display::writeNarration(jWriter["Prologue"]["OutOfTheAlley"][7]);
            Display::writeDialogue(jWriter["Prologue"]["DIA_Bob"][1]);
            Display::writeNarration(jWriter["Prologue"]["OutOfTheAlley"][8]);
            Console::wait(1000);
            Game::game[0].setCurrentLocation(&Location::locations["Street"]);
            break;
        }
        else Logger::invalidHeroChoiceError(__FUNCTION__); continue;
    }
}

void Event::dialogueWithBob()
{
    Logger::startFuncLog(__FUNCTION__);
    Display::writeDialogue(jWriter["Prologue"]["DIA_Bob"][2]);

    if (!Npc::npcs["Bob"].knowsHero() && !Npc::npcs["Caden"].knowsHero() && !Npc::npcs["CadenPartner"].knowsHero())
    {
        //--------------------------------
        Menu nameMenu;
        nameMenu.addOptions({ jWriter["Prologue"]["NameMenu"][0], jWriter["Prologue"]["NameMenu"][1] });
        nameMenu.showOptions();
        //--------------------------------
        while (true)
        {
            heroChoice = nameMenu.inputChoice();

            if (heroChoice == 1)
            {
                Console::clearScreen();
                nameMenu.showHeroChoice();
                std::cout << std::endl;
                namingHero();
                Npc::npcs["Bob"].setToKnowHero();
                Display::writeDialogue((std::string)jWriter["Prologue"]["DIA_Bob"][3] + Hero::heroes[0].getName() + (std::string)jWriter["Prologue"]["DIA_Bob"][4]);
                Console::wait(1500);
                Display::writeDialogue((std::string)jWriter["Prologue"]["DIA_Bob"][5] + Npc::npcs["Bob"].getName() + ".");
                Console::wait(1500);
                Display::writeDialogue(jWriter["Prologue"]["DIA_Bob"][6]);
                Display::writeNarration(jWriter["Prologue"]["DialogueWithBob"][0]);
                break;
            }
            else if (heroChoice == 2)
            {
                Console::clearScreen();
                nameMenu.showHeroChoice();
                std::cout << std::endl;

                if (Npc::npcs["Bob"].getAttitude() != Attitude::Angry)
                {
                    Npc::npcs["Bob"].setAttitude(Attitude::Angry); // Angry / Hostile / Friendly / Neutral
                }

                Console::wait(500);
                Display::writeDialogue(jWriter["Prologue"]["DIA_Bob"][7]);

                break;
            }
            else Logger::invalidHeroChoiceError(__FUNCTION__); continue;
        }
        //--------------------------------
        Menu menu3;
        menu3.addOptions({ jWriter["Prologue"]["Menu3"][0], jWriter["Prologue"]["Menu3"][1], jWriter["Prologue"]["Menu3"][2] });
        menu3.showOptions();
        //--------------------------------
        while (true)
        {
            heroChoice = menu3.inputChoice();

            if (heroChoice == 1)
            {
                Console::clearScreen();
                menu3.showHeroChoice();
                bobRecommendsZed = true; // Bob poleca bohaterowi sklep z bronią Zeda
                Display::writeDialogue(jWriter["Prologue"]["DIA_Bob"][8]);
                Console::wait(1000);
                Display::writeDialogue(jWriter["Prologue"]["DIA_Bob"][9]);
                Console::wait(1000);
                Display::writeDialogue(jWriter["Prologue"]["DIA_Bob"][10]);
                break;
            }
            else if (heroChoice == 2)
            {
                Console::clearScreen();
                menu3.showHeroChoice();
                Display::writeDialogue(jWriter["Prologue"]["DIA_Bob"][11]);
                Console::wait(1000);
                Display::writeDialogue(jWriter["Prologue"]["DIA_Bob"][12]);
                Console::wait(1500);
                Display::writeDialogue(jWriter["Prologue"]["DIA_Bob"][13]);
                Console::wait(1500);
                Display::writeDialogue(jWriter["Prologue"]["DIA_Bob"][14]);
                Console::wait(1000);
                Display::writeDialogue(jWriter["Prologue"]["DIA_Bob"][15]);
                break;
            }
            else if (heroChoice == 3)
            {
                Console::clearScreen();
                menu3.showHeroChoice();
                std::cout << std::endl;

                if (Npc::npcs["Bob"].getAttitude() != Attitude::Angry)
                {
                    Npc::npcs["Bob"].setAttitude(Attitude::Angry); // Angry / Hostile / Friendly / Neutral
                }

                Console::wait(500);
                Display::writeDialogue(jWriter["Prologue"]["DIA_Bob"][16]);
                break;
            }
            else Logger::invalidHeroChoiceError(__FUNCTION__); continue;
        }

        if (!streetWasVisited)
        {
            Display::writeNarration("\tFinally, an old, wrinkled face surrounded by gray fuzz emerges from the darkness. An artificial,\n\tcybernetic eye watches you vigilantly.");
            Console::wait(1000);
            Display::writeNarration(" You start to feel strangely uncomfortable.");
            Console::wait(2000);
            Display::writeNarration("\n\tIn an instant the alley is filled with the howling of a police siren.");
            Console::wait(1000);
            Display::writeNarration(" On the wall in front of\n\tyou, red and blue begin to dance with each other.");
            Display::writeDialogue("\n\t- 'Shit");
            Console::wait(500);
            Display::writeDialogue(", cops!");
            Console::wait(500);
            Display::writeDialogue(" Well, that's super. I think it's time for me to go.'");
            Console::wait(1500);
            Display::writeNarration("\n\tThe aging beggar dives into the embrace of darkness in a flash.");
            Console::wait(1500);
            Display::writeNarration(" Does this mean you see him for\n\tthe last time?");
            Console::wait(3500);
            Game::game[0].setCurrentLocation(&Location::locations["Street"]);
        }
        else {
            Display::writeDialogue("\t - 'All right, that is enough.");
            Console::wait(1500);
            Display::writeDialogue("I saw the cops hanging around. It stopped being safe here, at\n\tleast for me.");

            if (Npc::npcs["Bob"].getAttitude() == Attitude::Angry || Npc::npcs["Bob"].getAttitude() == Attitude::Hostile)
            {
                Display::writeDialogue(" Be glad we don't have more of it left.'");
            }
            else {
                Display::writeDialogue(" Take care, kid.'");
            }

            Console::wait(1500);
            Display::writeNarration("\n\tThe aging beggar dives into the embrace of darkness in a flash.");
            Console::wait(1500);
            Display::writeNarration(" Does this mean you see him for\n\tthe last time?\n\n");
            Game::pause();
            Console::clearScreen();
            Game::game[0].setCurrentLocation(&Location::locations["Street"]);
        }
    }
}

void Event::darkAlleyCrossroads()
{
    Logger::startFuncLog(__FUNCTION__);

    if (!Npc::npcs["Bob"].knowsHero())
    {
        Display::writeNarration("\n\tWhen you enter the alley, you hear a familiar voice.");
        Display::writeDialogue("\n\t- 'It's you again. Why don't you tell me something for one this time?'\n\n");
        //--------------------------------
        Menu menu2;
        menu2.addOptions({ jWriter.at("Menu3").at(0), jWriter.at("Menu3").at(1) });
        menu2.showOptions();
        //--------------------------------
        while (true)
        {
            heroChoice = menu2.inputChoice();

            if (heroChoice == 1)
            {
                Console::clearScreen();
                menu2.showHeroChoice();
                Display::writeNarration(jWriter.at("OutOfTheAlley").at(5));
                Console::wait(1500);
                Display::writeNarration(jWriter.at("OutOfTheAlley").at(6));
                dialogueWithBob();
                break;
            }
            else if (heroChoice == 2)
            {
                Console::clearScreen();
                menu2.showHeroChoice();
                Display::writeNarration(jWriter.at("OutOfTheAlley").at(7));
                Display::writeDialogue(jWriter.at("DIA_Bob").at(7));
                Console::clearScreen();
                Game::game[0].setCurrentLocation(&Location::locations["Street"]);
                break;
            }
            else Logger::invalidHeroChoiceError(__FUNCTION__); continue;
        }
    }
    else
    {
        Display::writeNarration("\tWhen you enter an alley, you notice a sea of trash around you.");
        Console::wait(1000);
        Display::writeNarration(jWriter.at("Prologue").at("WakeUpInDarkAlley").at(7));
    
        if (!Hero::heroes[0].hasItem(&Item::items["AD13"]))
        {
            Console::wait(1500);
            Display::writeNarration(jWriter.at("Prologue").at("WakeUpInDarkAlley").at(8));
            //--------------------------------
            Menu menu1;
            menu1.addOptions({ jWriter.at("Prologue").at("Menu1").at(0), jWriter.at("Prologue").at("Menu1").at(1) });
            menu1.showOptions();
            //--------------------------------
            while (true)
            {
                heroChoice = menu1.inputChoice();

                if (heroChoice == 1)
                {
                    Console::clearScreen();
                    menu1.showHeroChoice();
                    acceleratorFinding();
                    Display::writeNarration("\n\tThere is nothing interesting here any more. Time to go back...\n");
                    Console::wait(1500);
                    Console::clearScreen();
                    Game::game[0].setCurrentLocation(&Location::locations["Street"]);
                    break;
                }
                else if (heroChoice == 2)
                {
                    Console::clearScreen();
                    menu1.showHeroChoice();
                    Console::wait(1500);
                    Console::clearScreen();
                    Game::game[0].setCurrentLocation(&Location::locations["Street"]);
                    break;
                }
                else Logger::invalidHeroChoiceError(__FUNCTION__); continue;
            }
        }
        else
        {
            Display::writeNarration("\n\tThere is nothing interesting here. Time to go back...\n\n");
            Game::pause();
            Console::clearScreen();
            Game::game[0].setCurrentLocation(&Location::locations["Street"]);
        }
    }
}

// ULICA
void Event::lookAtAmnesia()
{
    Logger::startFuncLog(__FUNCTION__);

    if (!Npc::npcs["Bob"].knowsHero())
    {
        Display::writeNarration("\n\tYou walk out of the alley onto a street lit by neon lights on the opposite side. A large sign\n\tthat reads 'Amnesia' belongs to a nightclub.");
        Console::wait(1000);
        Display::writeNarration(" A small crowd gathers outside the entrance to the\n\tbuilding. Some people are arguing with the bouncers.");
        Console::wait(1500);
        Display::writeNarration(" Something smells here, it's probably trouble...\n\n");
    }
    else {
        Display::writeNarration("\n\tYou walk out of the alley onto a street lit by neon lights and the lamp of a police car on the\n\topposite side. A large sign that reads 'Amnesia' belongs to a nightclub.");
        Display::writeNarration(" Two cops interrogate\n\ta small crowd outside the entrance to the building.");
        Console::wait(1500);
        Display::writeNarration(" Something smells here, it's probably trouble...\n\n");
    }
    //--------------------------------
    Menu menu4;
    menu4.addOptions({ "Come closer and see what it's all about.", "Take a look around the area." });
    menu4.showOptions();
    //--------------------------------
    while (true)
    {
        heroChoice = menu4.inputChoice();

        if (heroChoice == 1)
        {
            Console::clearScreen();
            menu4.showHeroChoice();
            std::cout << std::endl;

            if (!Npc::npcs["Bob"].knowsHero())
            {
                meetingWithSecurityGuards();
                meetingWithPolicemans();
            }
            else meetingWithPolicemans();

            break;
        }
        else if (heroChoice == 2)
        {
            Console::clearScreen();
            menu4.showHeroChoice();
            Game::game[0].setCurrentLocation(&Location::locations["GunShop"]);
            break;
        }
        else Logger::invalidHeroChoiceError(__FUNCTION__); continue;
    }
}

void Event::encounterGunStore()
{
    Logger::startFuncLog(__FUNCTION__);
    Display::writeNarration("\n\tYou go to the right side of the street. After walking several meters you come across a small\n\tbooth between blocks of flats.");

    if (bobRecommendsZed) Display::writeNarration(" Could it be that the famous gun store managed by Bob's friend?");

    std::cout << std::endl << std::endl;
    //--------------------------------
    Menu menu5;
    menu5.addOptions({ "Go inside.", "Turn back." });
    menu5.showOptions();
    //--------------------------------
    while (true)
    {
        heroChoice = menu5.inputChoice();

        if (heroChoice == 1)
        {
            Console::clearScreen();
            menu5.showHeroChoice();
            enterGunShop();
            break;
        }
        else if (heroChoice == 2)
        {
            Console::clearScreen();
            menu5.showHeroChoice();
            std::cout << std::endl;

            if (!Npc::npcs["Caden"].knowsHero() && !Npc::npcs["CadensPartner"].knowsHero())
            {
                if (!Npc::npcs["Bob"].knowsHero())
                {
                    meetingWithSecurityGuards();
                    meetingWithPolicemans();
                }
                else meetingWithPolicemans();
            }
            else Game::game[0].setCurrentLocation(&Location::locations["Street"]);

            break;
        }
        else Logger::error("Entered invalid value of <b>heroChoice</b>", __FUNCTION__); continue;
    }
}

void Event::meetingWithSecurityGuards()
{
    Logger::startFuncLog(__FUNCTION__);
    Display::writeNarration("\tWhen you get closer, the faces turn toward you and start looking at you intently.");
    Console::wait(1000);
    Display::writeNarration(" You pass\n\tthem in silenceand are confronted by a broad-shouldered security guard.");
    Display::writeDialogue("\n\t- 'What are you looking for here?");
    Console::wait(1500);
    Display::writeDialogue(" Trouble, maybe?'");
    Display::writeNarration("\n\tThe man clenches his hands into fists and smiles unpleasantly.");
    Display::writeDialogue("\n\t- 'You asshole, better let us in! I want a drink and for fuck's sake. I'm losing my patience!");
    Display::writeNarration("\n\tOne of the men waiting in the queue rushes forward and threatens the bouncer with his fist.");
    Console::wait(1500);
    Display::writeNarration("\n\tThe security guard's attention shifts from you to the furious guy next to you.");
    Display::writeDialogue("\n\t- 'I'll say it one last time: get the fuck out of here or you'll get fucked.'\n");
}

void Event::meetingWithPolicemans()
{
    Logger::startFuncLog(__FUNCTION__);

    if (Npc::npcs["Bob"].knowsHero())
        Display::writeNarration("\tWhen you get closer, one of the police officers in a dark blue uniform turns toward you.");
    else {
        Display::writeNarration("\tIn an instant the street is filled with the howling of a police siren.");
        Console::wait(1000);
        Display::writeNarration(" The reds and blues\n\tbegin to dance with each other on the sidewalk and the silhouettes of the people around you.");
        Console::wait(2000);
        Display::writeNarration("\n\tTwo grim-looking guys in dark blue uniforms get out of a police car and walk towards you.\n\tOne of them points at you, taking out a tablet from behind his belt.");
    }

    Display::writeDialogue("\n\t- 'Who are you?");
    Console::wait(1500);
    Display::writeDialogue(" And what are you doing here? Please show me your ID card.'");

    if (Hero::heroes[0].hasItem(&Item::items["AD13"])) Display::writeNarration("\n\tYou start searching through the pockets of your jacket and pants, but other than the accelerator\n\tyou found in the trash, there's nothing else there.");
    else Display::writeNarration("\n\tYou start searching through the pockets of your jacket and pants, but there's nothing there.");

    Display::writeDialogue("\n\t- 'I see that we have a problem.");
    Console::wait(1500);
    Display::writeDialogue(" Okay, then what's your name, citizen?");

    if (!Npc::npcs["Bob"].knowsHero())
    {
        Display::writeDialogue("'\n");
        namingHero();
        Console::wait(1500);
        Display::writeDialogue("\t- '" + Hero::heroes[0].getName() + "...");
        Console::wait(1000);
        Display::writeDialogue(" Caden, check it out in the database.");
    }
    else {
        Display::writeDialogue(" " + Hero::heroes[0].getName() + "...");
        Console::wait(1000);
        Display::writeDialogue(" Caden, check\n\tit out in the database.");
    }

    Npc::npcs["CadenPartner"].setToKnowHero();
    Npc::npcs["Caden"].setToKnowHero();
    Console::wait(1500);
    Display::writeDialogue(" And you, stand where you are.'");
    Display::writeNarration("\n\tThe other police officer nods, gets back in the car, and it looks like he's connecting with\n\theadquarters.");
    Console::wait(3000);
    Display::writeNarration("\n\tA minute later, the same policeman returns and whispers something in his partner's ear.");
    Console::wait(1500);
    Display::writeNarration(" That\n\tone nods and turns to look at you.");
    Display::writeDialogue("\n\t- 'I have good news for you.");
    Console::wait(1500);
    Display::writeDialogue(" You're free for now, just don't let it occur to you to do\n\tsomething here, or you'll end up in arrest at the police station.");
    Console::wait(1000);
    Display::writeDialogue(" Caden, take care of the\n\trest of the attendees.'");
    Display::writeNarration("\n\tThe cop walks away to talk to the nearest person standing.");
    Display::writeDialogue("\n\t- 'If you're so pure, get in.'");
    Display::writeNarration("\n\tThe bouncer points to the door behind him.\n\n");
    //--------------------------------
    Menu menu6;
    menu6.addOptions({ "Go inside.", "Turn back." });
    menu6.showOptions();
    //--------------------------------
    while (true)
    {
        heroChoice = menu6.inputChoice();

        if (heroChoice == 1)
        {
            Console::clearScreen();
            menu6.showHeroChoice();
            Game::game[0].setCurrentLocation(&Location::locations["Nightclub"]);
            break;
        }
        else if (heroChoice == 2)
        {
            Console::clearScreen();
            menu6.showHeroChoice();
            Game::game[0].setCurrentLocation(&Location::locations["GunShop"]);
            break;
        }
        else Logger::invalidHeroChoiceError(__FUNCTION__); continue;
    }
}

void Event::streetCrossroads()
{
    Logger::startFuncLog(__FUNCTION__);
    Display::writeNarration("\n\tOnce again you are on a street bathed in nighttime darkness.\n\n");
    //--------------------------------
    Menu menu7;
    menu7.clearOptions();
    menu7.addOption("Visit: " + Location::locations["DarkAlley"].getName() + ".");
    menu7.addOption("Visit: " + Location::locations["Nightclub"].getName() + ".");
    menu7.addOption("Visit: " + Location::locations["GunShop"].getName() + ".");
    menu7.showOptions();
    //--------------------------------
    while (true)
    {
        heroChoice = menu7.inputChoice();

        if (heroChoice == 1)
        {
            Console::clearScreen();
            menu7.showHeroChoice();
            Game::game[0].setCurrentLocation(&Location::locations["DarkAlley"]);
            break;
        }
        else if (heroChoice == 2)
        {
            Console::clearScreen();
            menu7.showHeroChoice();
            Display::writeNarration("\n\tYou enter from a fairly well-lit street into a slightly darkened nightclub, trembling with colour.\n\n");
            Game::game[0].setCurrentLocation(&Location::locations["Nightclub"]);
            break;
        }
        else if (heroChoice == 3)
        {
            Console::clearScreen();
            menu7.showHeroChoice();
            Game::game[0].setCurrentLocation(&Location::locations["GunShop"]);
            break;
        }
        else Logger::invalidHeroChoiceError(__FUNCTION__); continue;
    }
}

// SKLEP Z BRONIĄ
void Event::enterGunShop()
{
    Logger::startFuncLog(__FUNCTION__);
    Display::writeNarration("\n\tThe front door hisses open before you.");

    if (!Npc::npcs["Zed"].knowsHero())
    {
        Console::wait(1000);
        Display::writeNarration(" You step over the threshold and enter a small room\n\twith a counter opposite the entrance. Behind it stands a tall, thin man with fatigue painted\n\ton his terribly oblong face.");
        Console::wait(1500);
        Display::writeNarration(" He is dressed in an old corporate commando\n\tsuit. On the wall behind his back hangs a lot of weapons.");
        Display::writeDialogue("\n\t- 'How can I help you, my friend?'\n");
        Npc::npcs["Zed"].setToKnowHero();
        dialogueWithZed();
    }
    else {
        Console::wait(1000);
        Display::writeNarration(" From behind the counter, Zed is already smiling at\n\tyou.");

        if (Hero::heroes[0].hasItem(&Item::items["Pistol"])) Display::writeDialogue("\n\t- 'What's up? How's the gun working out?'");

        std::cout << std::endl;
        dialogueWithZed();
    }
}

void Event::dialogueWithZed()
{
    Logger::startFuncLog(__FUNCTION__);
    bool heroTalkedAboutBusinessWithZed = false;

    while (true)
    {
        std::cout << std::endl;
        //--------------------------------
        Menu menu8;
        menu8.clearOptions();
        menu8.addOption("'What do you have?'");
        menu8.addOption("'How's business going?'");

        if (bobRecommendsZed && !zedKnowsAboutBobAndZed)
            menu8.addOption("'You're Zed? I come from Bob.'");

        if (Quest::quests["ZedAccelerator"].getIsRunning() && Hero::heroes[0].hasItem(&Item::items["AD13"]))
            menu8.addOption("'I have an accelerator for you.'");

        menu8.addOption("'I have to go...'");
        menu8.showOptions();
        //--------------------------------
        heroChoice = menu8.inputChoice();

        if (heroChoice == 1)
        {
            Console::clearScreen();
            menu8.showHeroChoice();
            std::cout << std::endl;
            zedTrade();
            continue;
        }
        else if (heroChoice == 2)
        {
            Console::clearScreen();
            menu8.showHeroChoice();

            if (heroTalkedAboutBusinessWithZed == true) Display::writeDialogue("\n\t- 'Hey, what's up? Are you sclerotic or something? We already talked about this, haha!'\n");
            else {
                heroTalkedAboutBusinessWithZed = true;
                Display::writeDialogue("\n\t- 'What kind of question is that anyway? Business is doing great! Everyone stops by\n\tevery now and then to rearm. It's the natural order of things.'\n");
            }

            continue;
        }
        else if (heroChoice == 3)
        {
            Console::clearScreen();
            menu8.showHeroChoice();

            if (bobRecommendsZed && !zedKnowsAboutBobAndZed)
            {
                zedKnowsAboutBobAndZed = true;
                Display::writeDialogue("\n\t- 'Yes, that is correct. I'm Zed, and this is my little shop.");
                Console::wait(1000);
                Display::writeDialogue(" Since you know Bob,\n\tyou can get a small discount here.'");
                Npc::npcs["Zed"].setAttitude(Attitude::Friendly);
            }
            else if (Quest::quests["ZedAccelerator"].getIsRunning() && Hero::heroes[0].hasItem(&Item::items["AD13"]) && bobRecommendsZed && zedKnowsAboutBobAndZed)
            {
                zedGetsAnAccelerator();
            }
            else if (Quest::quests["ZedAccelerator"].getIsRunning() && Hero::heroes[0].hasItem(&Item::items["AD13"]) && !bobRecommendsZed && !zedKnowsAboutBobAndZed)
            {
                zedGetsAnAccelerator();
            }
            else {
                Display::writeDialogue("\n\t- 'No problem. See you later!'\n");
                Console::wait(1500);
                Console::clearScreen();

                if (!Npc::npcs["Caden"].knowsHero() && !Npc::npcs["CadenPartner"].knowsHero()) meetingWithPolicemans();
                else Game::game[0].setCurrentLocation(&Location::locations["Street"]);
            }

            continue;
        }
        else if (heroChoice == 4 && bobRecommendsZed && !zedKnowsAboutBobAndZed)
        {
            Console::clearScreen();
            menu8.showHeroChoice();

            if (Quest::quests["ZedAccelerator"].getIsRunning() && Hero::heroes[0].hasItem(&Item::items["AD13"]))
            {
                zedGetsAnAccelerator();
                continue;
            }
            else {
                Display::writeDialogue("\n\t- 'No problem. See you later!'\n");
                Console::clearScreen();

                if (!Npc::npcs["Caden"].knowsHero() && !Npc::npcs["CadenPartner"].knowsHero())
                    meetingWithPolicemans();
                else Game::game[0].setCurrentLocation(&Location::locations["Street"]);

                break;
            }
        }
        else if (heroChoice == 5 && Quest::quests["ZedAccelerator"].getIsRunning() && Hero::heroes[0].hasItem(&Item::items["AD13"]) && bobRecommendsZed && !zedKnowsAboutBobAndZed)
        {
            Console::clearScreen();
            menu8.showHeroChoice();
            Display::writeDialogue("\n\t- 'No problem. See you later!'\n");
            Console::clearScreen();

            if (!Npc::npcs["Caden"].knowsHero() && !Npc::npcs["CadenPartner"].knowsHero()) meetingWithPolicemans();
            else Game::game[0].setCurrentLocation(&Location::locations["Street"]);

            break;
        }
        else Logger::invalidHeroChoiceError(__FUNCTION__); continue;
    }
}

void Event::zedGetsAnAccelerator()
{
    Logger::startFuncLog(__FUNCTION__);
    Hero::heroes[0].removeItem(&Item::items["AD13"]);
    Display::writeDialogue("\n\t- 'Well done!");
    Console::wait(1000);
    Display::writeDialogue(" I don't know where you found it, but now the gun is yours.'\n");

    Hero::heroes[0].addItem(&Item::items["Pistol"]);
    Console::setConsoleColor(ConsoleColor::CC_Item);
    Display::write("\n\t" + Item::items["AD13"].getName());
    Console::resetConsoleColor();
    Display::write(" given and ");
    Console::setConsoleColor(ConsoleColor::CC_Item);
    Display::write(Item::items["Pistol"].getName());
    Console::resetConsoleColor();
    Display::write(" gained.\n");

    Hero::heroes[0].endQuest(&Quest::quests["ZedAccelerator"]);
}

void Event::zedTrade()
{
    Logger::startFuncLog(__FUNCTION__);
    bool ZedTellsAboutWeapons = false;

    if (!Hero::heroes[0].hasItem(&Item::items["Pistol"]))
    {
        if (!ZedTellsAboutWeapons)
        {
            ZedTellsAboutWeapons = true;
            Display::writeDialogue("\t- 'Better ask what I don't have!");
            Console::wait(1000);
            Display::writeDialogue(" Look - ");
            Console::wait(1000);
            Display::writeDialogue("rifles, pistols, machine guns, shotguns. I\n\thave a melee weapons as well. Knives, hammers, long blades like katanas...");
            Console::wait(1500);
            Display::writeDialogue(" Anything\n\tyou want, my friend!");
            Console::wait(1500);
            Display::writeDialogue(" Tell me, what do you like?'\n\n");
            //--------------------------------
            Menu menu9;
            menu9.addOptions({ "Buy: pistol (250 $).", "'I have made up my mind.'" });
            menu9.showOptions();
            //--------------------------------
            while (true)
            {
                heroChoice = menu9.inputChoice();

                if (heroChoice == 1)
                {
                    Console::clearScreen();
                    menu9.showHeroChoice();
                    buyPistol();
                    break;
                }
                else if (heroChoice == 2)
                {
                    Console::clearScreen();
                    menu9.showHeroChoice();
                    Display::writeNarration("\n\tZed looks at you pityingly and shrugs his shoulders.");
                    Display::writeDialogue("\n\t- 'No problem. It can happen to anyone.'\n");
                    dialogueWithZed();
                    break;
                }
                else Logger::error("Entered invalid value of <b>heroChoice</b>", __FUNCTION__); continue;
            }
        }
        else
        {
            std::cout << std::endl;
            //--------------------------------
            Menu menu10;
            menu10.addOptions({ "Buy: pistol (250 $).", "'I have made up my mind.'" });
            menu10.showOptions();
            //--------------------------------
            while (true)
            {
                heroChoice = menu10.inputChoice();

                if (heroChoice == 1)
                {
                    Console::clearScreen();
                    menu10.showHeroChoice();
                    buyPistol();
                    break;
                }
                else if (heroChoice == 2)
                {
                    Console::clearScreen();
                    menu10.showHeroChoice();
                    Display::writeNarration("\n\tZed looks at you pityingly and shrugs his shoulders.");
                    Display::writeDialogue("\n\t- 'No problem. It can happen to anyone.'\n");
                    dialogueWithZed();
                    break;
                }
                else Logger::invalidHeroChoiceError(__FUNCTION__); continue;
            }
        }
    }
    else
    {
        Console::resetConsoleColor();
        Display::write("\tYou have everything you need. There's no point in bothering Zed.\n");
        dialogueWithZed();
    }
}

void Event::buyPistol()
{
    Logger::startFuncLog(__FUNCTION__);

    if (Hero::heroes[0].getMoney() != 250.0)
    {
        Display::writeDialogue("\n\t- 'I see you're low on cash.");
        Console::wait(1000);
        Display::writeDialogue(" But don't worry, we'll sort it out somehow.");
        Console::wait(1500);

        if (zedKnowsAboutBobAndZed)
        {
            Display::writeDialogue(" Hmm, you know Old Bob, that already means something.");
            Console::wait(1000);
            Display::writeDialogue(" Let's just say I'll loan you this gun on a friendly basis.");

            Hero::heroes[0].addItem(&Item::items["Pistol"]);
            Console::setConsoleColor(ConsoleColor::CC_Item);
            Display::write("\n\t" + Item::items["Pistol"].getName());
            Console::resetConsoleColor();
            Display::write(" gained.\n");
        }
        else
        {
            Display::writeDialogue(" It so happens that\n\tI have been looking for a good accelerator for some time.");
            Console::wait(1000);
            Display::writeDialogue(" I don't mean the crap produced by\n\tcorporations these days.");
            Console::wait(1000);
            Display::writeDialogue(" I mean the good old accelerator!");
            Console::wait(1500);
            Display::writeDialogue(" Find me such a device and you will\n\tget that gun. Okay?");
            Hero::heroes[0].addQuest(&Quest::quests["ZedAccelerator"]);
        }
    }
    else
    {
        Display::writeDialogue("\n\t- 'A pistol is a good start. Here, it's yours.'");

        Hero::heroes[0].addItem(&Item::items["Pistol"]);
        Console::setConsoleColor(ConsoleColor::CC_Item);
        Display::write("\n\t" + Item::items["Pistol"].getName());
        Console::resetConsoleColor();
        Display::write(" was bought.\n");
    }
}

void Event::gunShopCrossroads()
{
    Logger::startFuncLog(__FUNCTION__);
    enterGunShop();
}

// KLUB NOCNY
void Event::enterClub()
{
    Logger::startFuncLog(__FUNCTION__);
    Display::writeNarration("\n\tAfter passing through the entrance your eardrums are slowly bursting from the loud music in\n\tthe club.");
    Console::wait(1000);
    Display::writeNarration(" You walk through a short lobby and so arrive at a crowded room full of dancing\n\tpeople.");
    Console::wait(1000);
    Display::writeNarration(" Disco balls hung from the ceiling net everything around with streaks of multi-colored\n\tlight.");
    Console::wait(1000);
    Display::writeNarration(" Next to the dance floor is a bar, and behind it are several mechanically streamlined\n\tbartenders.\n\n");
    //--------------------------------
    Menu menu11;
    menu11.addOptions({ "Go to the dance floor.", "Go to the bar.", "Go upstairs.", "Back on the street." });
    menu11.showOptions();
    //--------------------------------
    while (true)
    {
        heroChoice = menu11.inputChoice();

        if (heroChoice == 1)
        {
            Console::clearScreen();
            menu11.showHeroChoice();
            clubDanceFloor();
            break;
        }
        else if (heroChoice == 2)
        {
            Console::clearScreen();
            menu11.showHeroChoice();
            clubBar();
            break;
        }
        else if (heroChoice == 3)
        {
            Console::clearScreen();
            menu11.showHeroChoice();
            clubUpstairs();
            break;
        }
        else if (heroChoice == 4)
        {
            Console::clearScreen();
            menu11.showHeroChoice();
            Game::game[0].setCurrentLocation(&Location::locations["Street"]);
            break;
        }
        else Logger::invalidHeroChoiceError(__FUNCTION__); continue;
    }
}

void Event::clubDanceFloor()
{
    Logger::startFuncLog(__FUNCTION__);

    if (!Npc::npcs["Nyx"].knowsHero())
    {
        Display::writeNarration("\n\tYou get on the dance floor.");
        Console::wait(1000);
        Display::writeNarration(" A crowd of dancing people stretches out around you, rubbing\n\tagainst each other to the rhythm of the music.");
        Console::wait(1500);
        Display::writeNarration(" Half-naked beauties are dancing in places\n\tthat look like pillars supporting the ceiling. You are not sure if they are real. There\n\tis a definite possibility that they are women, but somewhere in the back of your mind you\n\tthink they are just androids.");
        Console::wait(1500);
        Display::writeNarration("\n\tYou start dancing yourself.");
        Console::wait(1000);
        Display::writeNarration(" You are doing quite well when an attractive girl appears in\n\tfront of you. She's wearing a see-through, brightly coloured dress.");
        Console::wait(1500);
        Display::writeNarration(" Is it a coincidence\n\tthat she has just appeared and is dancing so close to you?\n\n");
        //--------------------------------
        Menu menu12;
        menu12.addOptions({ "'What do you want?'", "'Hey, baby.'", "Keep dancing with no words." });
        menu12.showOptions();
        //--------------------------------
        while (true)
        {
            heroChoice = menu12.inputChoice();

            if (heroChoice == 1)
            {
                Console::clearScreen();
                menu12.showHeroChoice();
                Display::writeNarration("\n\tThe girl turns towards you and smiles with her snow-white teeth.");
                Display::writeDialogue("\n\t- 'Nothing will escape your attention. I am Nyx. I think you can help me.'");
                break;
            }
            else if (heroChoice == 2)
            {
                Console::clearScreen();
                menu12.showHeroChoice();
                Display::writeNarration("\n\tThe girl turns towards you and smiles with her snow-white teeth.");
                Display::writeDialogue("\n\t- 'Hi, stud. I've been watching you since you came in. I am Nyx.'");
                Display::writeNarration("\n\tWith the last word she comes closer to you turns her back on you and starts dancing very\n\tclose to you.");
                Display::writeDialogue("\n\t- 'I am looking for someone like you. I think you can help me.'");
                break;
            }
            else if (heroChoice == 3)
            {
                Console::clearScreen();
                menu12.showHeroChoice();
                Display::writeNarration("\n\tThe girl turns towards you and smiles with her snow-white teeth.");
                Display::writeDialogue("\n\t- 'Hi, I am Nyx. Vinc, the owner, is my boyfriend. I think you can help me.'");
                break;
            }
            else Logger::invalidHeroChoiceError(__FUNCTION__); continue;
        }

        miaMeeting();
    }
    else
    {
        Display::writeNarration("\n\tYou get on the dance floor.");
        Console::wait(1000);
        Display::writeNarration(" It's quite crowded, but at least you can enjoy the beautiful views. You try to keep up with\n\tthe rest of the people dancing there. However, you quickly get tired and head for the exit.");
        Console::wait(1500);
        Console::clearScreen();
        nightclubCrossroads();
    }
}

void Event::clubBar()
{
    Logger::startFuncLog(__FUNCTION__);
    heroIsAtBar = true;
    Display::writeNarration("\n\tWith a slow step, you approach the counter, settle comfortably on a stool, and lift your\n\tgaze to the barman in front of you.");
    Display::writeDialogue("\n\t- 'What's for you?'\n\n");

    while (true)
    {
        //--------------------------------
        Menu menu13;
        menu13.addOptions({ "'Give me anything.'", "'Who's in charge?'", "'Bye.'" });
        menu13.showOptions();
        //--------------------------------
        heroChoice = menu13.inputChoice();

        if (heroChoice == 1)
        {
            Console::clearScreen();
            menu13.showHeroChoice();
            Display::writeDialogue("\n\t- 'Okay.");
            Console::wait(1000);
            Display::writeDialogue(" Let's see...'");
            Console::wait(1500);
            Display::writeNarration("\n\tThe barman turns his back on you and looks through the bottles of alcohol. Finally, he selects\n\tone of them and pours its contents into a glass before placing it on the counter in front of\n\tyou.");
            Console::wait(1500);
            Display::writeNarration("\n\tYou reach for the vessel and empty it.");
            Console::wait(1000);
            Display::writeNarration(" You feel a pleasant warmth spreading up your throat and further down your gullet.\n\n");
            Display::writeDialogue("\n\t- 'Anything else?'\n\n");
            continue;
        }
        else if (heroChoice == 2)
        {
            Console::clearScreen();
            menu13.showHeroChoice();
            Display::writeNarration("\n\tThe bartender squints, hearing your question.");
            Display::writeDialogue("\n\t- 'You're not from around here, are you?");
            Console::wait(1500);
            Display::writeDialogue(" My boss is Vincent Ramsey.");
            Console::wait(1000);
            Display::writeDialogue(" He's a tough guy, so you'd better not make trouble, or it could end badly for you.'\n\n");
            continue;
        }
        else if (heroChoice == 3)
        {
            Console::clearScreen();
            menu13.showHeroChoice();
            Display::writeNarration("\n\tThe bartender reaches for a glass from under the counter and starts wiping it down.");
            Display::writeDialogue("\n\t- 'Yeah, have fun.'\n\n");
            Game::game[0].setCurrentLocation(&Location::locations["Nightclub"]);
            break;
        }
        else Logger::invalidHeroChoiceError(__FUNCTION__); continue;
    }
}

void Event::miaMeeting()
{
    Logger::startFuncLog(__FUNCTION__);
    std::cout << std::endl << std::endl;
    //--------------------------------
    Menu menu14;
    menu14.addOptions({ "'What is it about?'", "Be silent and let her speak." });
    menu14.showOptions();
    //--------------------------------
    while (true)
    {
        heroChoice = menu14.inputChoice();

        if (heroChoice == 1)
        {
            Console::clearScreen();
            menu14.showHeroChoice();
            break;
        }
        else if (heroChoice == 2)
        {
            Console::clearScreen();
            menu14.showHeroChoice();
            break;
        }
        else Logger::invalidHeroChoiceError(__FUNCTION__); continue;
    }

    Display::writeDialogue("\n\t- 'Vinc, the owner, is my boyfriend.");
    Console::wait(1000);
    Display::writeDialogue(" I want him dead.'");
    Hero::heroes[0].addQuest(&Quest::quests["KillVincent"]);
    Console::wait(1500);
    Display::writeNarration("\n\tNyx takes your hand and leads you towards the toilet.");
    Display::writeDialogue("\n\t- 'Do you have a gun?'");

    if (Hero::heroes[0].hasItem(&Item::items["Pistol"]))
    {
        Display::writeDialogue("\n\t- 'Good.");
        Console::wait(1000);
        Display::writeDialogue(" So you already know what and how.'");
    }
    else
    {
        Display::writeDialogue("\n\t- 'You know how to use it, don't you?");
        Console::wait(1000);
        Display::writeDialogue(" Get it for yourself, you'll need it. Here's 200 bucks.'");
        Hero::heroes[0].addMoney(200);

        Console::setConsoleColor(ConsoleColor::CC_Green);
        Display::write("\n\t200$");
        Console::resetConsoleColor();
        Display::write(" has been received.");

        Display::writeDialogue("\n\t- 'There is a gun shop nearby.");
        Display::writeDialogue(" It's run by a guy named Zed. Visit him before you head upstairs.");
        Console::wait(1000);
        Display::writeDialogue("\n\tI'll meet you when you've sorted this out.'");
    }
}

void Event::clubUpstairs()
{
    Logger::startFuncLog(__FUNCTION__);
    Display::writeNarration("\n\tYou go up a winding staircase. At the end of a short banister you will see a closed door\n\tguarded by another bulky individual.\n\n");
    //--------------------------------
    Menu menu15;
    menu15.addOptions({ "Come closer.", "Go back downstairs." });
    menu15.showOptions();
    //--------------------------------
    while (true)
    {
        heroChoice = menu15.inputChoice();

        if (heroChoice == 1)
        {
            Console::clearScreen();
            menu15.showHeroChoice();
            Display::writeNarration("\n\tAre you brave or foolish enough to face the hammer man. You are stopped from taking another\n\tstep by his firm voice.");
            Display::writeDialogue("\n\t- 'What here?'");
            Npc::npcs["Jet"].setToKnowHero();
            dialogueWithJet();
            break;
        }
        else if (heroChoice == 2)
        {
            Console::clearScreen();
            menu15.showHeroChoice();
            Display::writeNarration("\n\tYou don't dare to come closer, so like the last coward you turn back and return to the kingdom\n\tof loud music and dancing people.\n");
            nightclub();
            break;
        }
        else Logger::invalidHeroChoiceError(__FUNCTION__); continue;
    }
}

void Event::dialogueWithJet()
{
    Logger::startFuncLog(__FUNCTION__);
    int jetPoints = 0;
    std::cout << "\n\n";
    Menu menu16;

    while (true)
    {
        jetGetsAngry(jetPoints);
        //--------------------------------
        menu16.clearOptions();
        menu16.addOption("'I want to pass.'");
        menu16.addOption("'What is behind that door?'");

        if (Hero::heroes[0].hasItem(&Item::items["Pistol"]))
        {
            menu16.addOption("Kill him with a pistol.");
            menu16.addOption("Stun him with a pistol.");
        }

        menu16.addOption("'It's time for me to go.'");
        menu16.showOptions();
        //--------------------------------
        heroChoice = menu16.inputChoice();

        if (heroChoice == 1)
        {
            Console::clearScreen();
            menu16.showHeroChoice();
            Display::writeNarration("\n\tWhen you say this a big paw blocks your way.");
            Display::writeDialogue("\n\t- 'You don't get what you're looking for here, mate.'\n\n");
            jetPoints += 1;
            continue;
        }
        else if (heroChoice == 2)
        {
            Console::clearScreen();
            menu16.showHeroChoice();
            Display::writeNarration("\n\tThe security guard instinctively peeks towards the door.");
            Display::writeDialogue("\n\t- 'You shouldn't be interested in this.'\n\n");
            jetPoints += 1;
            continue;
        }
        else if (heroChoice == 3 && !Hero::heroes[0].hasItem(&Item::items["Pistol"]))
        {
            Console::clearScreen();
            menu16.showHeroChoice();
            Display::writeDialogue("\n\t- 'Yeah. Get lost.'");
            Display::writeNarration("\n\tAnd so you turn back and return to the kingdom of loud music and dancing people.\n\n");
            nightclub();
            break;
        }
        else if (heroChoice == 3 && Hero::heroes[0].hasItem(&Item::items["Pistol"]))
        {
            Console::clearScreen();
            menu16.showHeroChoice();
            // TODO: dodać opis zabicia Jeta!
            vincentOffice();
            break;
        }
        else if (heroChoice == 4 && Hero::heroes[0].hasItem(&Item::items["Pistol"]))
        {
            Console::clearScreen();
            menu16.showHeroChoice();
            // TODO: dodać opis ogłuszenia Jeta!
            vincentOffice();
            break;
        }
        else if (heroChoice == 5 && Hero::heroes[0].hasItem(&Item::items["Pistol"]))
        {
            Console::clearScreen();
            menu16.showHeroChoice();
            Display::writeDialogue("\n\t- 'Yeah. Get lost.'");
            Display::writeNarration("\n\tAnd so you turn back and return to the kingdom of loud music and dancing people.\n\n");
            nightclub();
            break;
        }
        else Logger::invalidHeroChoiceError(__FUNCTION__); continue;
    }
}

void Event::jetGetsAngry(int angerPoints)
{
    bool jetWarnHero = false, jetBeatsHero = false;

    if (angerPoints < 2 && !jetWarnHero && !jetBeatsHero)
    {
        return;
    }

    if (angerPoints == 2 && !jetWarnHero)
    {
        jetWarnHero = true;
        Npc::npcs["Jet"].setAttitude(Attitude::Angry);
        Display::writeDialogue("\t- 'I don't like your questions. Get out of here while you still can.'\n\n");
        return;
    }

    jetBeatsHero = true;
    Npc::npcs["Jet"].setAttitude(Attitude::Hostile);
    Display::writeDialogue("\t- 'I warned you. Now we're going to have some fun.'");
    Display::writeNarration("\n\tBefore you can blink, you get a right hook to the stomach accompanied by a left hook aimed\n\tat the jaw.");
    Console::wait(2500);
    Console::clearScreen();
    Console::wait(2500);
    wakeUpBeforeMeetingWithJet();
}

void Event::wakeUpBeforeMeetingWithJet()
{
    Logger::startFuncLog(__FUNCTION__);
    Display::writeNarration("\n\tEmptiness...", 65);
    Console::wait(1000);
    Display::writeNarration(" Various sounds are coming from the darkness", 60);
    Console::wait(1500);
    Display::writeNarration(", getting louder by the second.");
    Console::wait(1500);
    Display::writeNarration("\n\tFinally, single colours appear before your eyes.");
    Console::wait(1000);
    Display::writeNarration(" In the darkness of the night you see the\n\toutline of a street.");
    Console::wait(500);
    Display::writeNarration("You remember only how " + Npc::npcs["Jet"].getName() + " put you down with one blow...");
    Console::wait(1000);
    Display::writeNarration("\n\tWith difficulty you pick yourself up in the ground and, walking slowly, you come to a street\n\tbathed in light.");

    int rand = Randomize::randInt(0, 10);
    // random event

    Game::game[0].setCurrentLocation(&Location::locations["Street"]);
}

void Event::vincentOffice()
{
    Logger::startFuncLog(__FUNCTION__);
    Display::writeNarration("\tYou enter the manager's office immersed in twilight. In the middle of the room stands a sizable desk, and on it are stacks of documents and computer. To the left of the entrance is a window to the street below. On the right you will notice a door to another room.\n\n");
    //--------------------------------
    Menu menu17;
    menu17.addOptions({ "Open the door and go into the other room.", "Stay and search the office." });
    menu17.showOptions();
    //--------------------------------
    while (true)
    {
        heroChoice = menu17.inputChoice();

        if (heroChoice == 1)
        {
            menu17.clearOptions();
            vincentHideoutCode();
            break;
        }
        else if (heroChoice == 2)
        {
            menu17.clearOptions();
            checkVincentDesk();
            break;
        }
        else Logger::invalidHeroChoiceError(__FUNCTION__); continue;
    }
}

void Event::checkVincentDesk()
{
    Logger::startFuncLog(__FUNCTION__);
    heroKnowsVincentCode = true;
    Menu::showHeroAction("Stay and search the office.");
    Display::writeNarration("\n\tYou walk up to the desk. You start flipping through the e-papers one by one and finally your gaze falls on the flickering blue monitor.");
    Display::write("\n\t");

    vincentHideoutCode();
}

void Event::vincentHideoutCode()
{
    Logger::startFuncLog(__FUNCTION__);
    Display::writeNarration("\n\tYou walk closer and spot the terminal. It looks like you'll need to use a code to get through.");
    Console::wait(1500);

    if (!heroKnowsVincentCode)
    {
        Display::writeNarration(" You have to look around the office though, whether you want to or not.");
    }
    else {
        std::cout << std::endl << std::endl;
        //--------------------------------
        Menu menu18;
        menu18.addOptions({ "Use code '2021'.", "Search the office." });
        menu18.showOptions();
        //--------------------------------
    }
}

void Event::vincentHideout()
{
    Logger::startFuncLog(__FUNCTION__);
    Npc::npcs["Vincent"].setStatus(Unconscious);
    Display::writeNarration("\n\tThe door closes behind you, hissing quietly.");
    Console::wait(2000);
    Display::writeNarration(" The room you're in is full of smaller and larger\n\tcables that merge into a single monitor that hangs above the sim-chair. On it lies a big guy\n\tin a tailored suit and a stimulation helmet on his head that obscures his face.");
    Console::wait(1500);
    Display::writeNarration(" You guess it's\n\tVincent, the club owner.");
    Console::wait(2000);
    Display::writeNarration("\n\tCreeping up, you come closer. Your goal is within reach. The question is what will you do?\n\n");
    //--------------------------------
    Menu menu19;
    menu19.addOptions({ "Disconnect his consciousness from the neuronet. (Kill him)", "Wait for his consciousness to leave the neuronet." });
    menu19.showOptions();
    //--------------------------------
    while (true)
    {
        heroChoice = menu19.inputChoice();

        if (heroChoice == 1)
        {
            Console::clearScreen();
            menu19.showHeroChoice();
            Display::writeNarration("\n\tYou lean over Vincent and, in a fluid motion without hesitation, pull the stimulation helmet\n\toff his head. You witness the nightclub owner being shaken by a wave of convulsions. Foam\n\tbegins to come out of his mouth and after a moment the man freezes.");
            Console::wait(1500);
            Npc::npcs["Vincent"].setStatus(Dead);
            Display::writeNarration(" He's probably dead, just like\n\tNyx wanted.");
            break;
        }
        else if (heroChoice == 2)
        {
            Console::clearScreen();
            menu19.showHeroChoice();
            Display::writeNarration("\n\tYou are not a coward.");
            Console::wait(1000);
            Display::writeNarration(" You don't stab people in the back. That's not your style. You prefer an\n\topen fight.");
            Console::wait(1500);
            Npc::npcs["Vincent"].setStatus(Normal);
            Display::writeNarration(" After a while, you notice Vincent moving slightly in his seat. He opens his eyes -\n\tthey are shining with the excitement of his online adventure.");
            Console::wait(1000);
            Display::writeNarration(" It is only a matter of time before\n\tVincent notices your presence. There is no turning back now.");
            Display::writeDialogue("\n\t- 'What the fuck are you doing here, dickhead?'\n");
            dialogueWithVincent();
            break;
        }
        else Logger::invalidHeroChoiceError(__FUNCTION__); continue;
    }
}

void Event::dialogueWithVincent()
{
    Logger::startFuncLog(__FUNCTION__);
    std::cout << std::endl << std::endl;
    //--------------------------------
    Menu menu20;
    menu20.addOptions({ "'Die!'", "'I don't want to fight with you.'", "'Nyx wants you dead.'" });
    menu20.showOptions();
    //--------------------------------
    while (true)
    {
        heroChoice = menu20.inputChoice();

        if (heroChoice == 1)
        {
            Console::clearScreen();
            menu20.showHeroChoice();
            Display::writeNarration("\n\tWith a shout, you bring out your gun and aim it at Vincent's chest.");
            Display::writeDialogue("\n\t- 'Are you such a hero?");
            Console::wait(1000);
            Display::writeDialogue(" Would you kill an unarmed man?");
            Console::wait(1000);
            Display::writeDialogue(" All right, can I at least find out who\n\tsent you? I know you're not working alone. I'm seeing you for the first time in my life.'");
            break;
        }
        else if (heroChoice == 2)
        {
            Console::clearScreen();
            menu20.showHeroChoice();
            Display::writeNarration("\n\tYou are not a coward.");
            Console::wait(1000);
            Display::writeNarration(" You don't stab people in the back. That's not your style. You prefer an\n\topen fight.");
            break;
        }
        else if (heroChoice == 3)
        {
            Console::clearScreen();
            menu20.showHeroChoice();
            Display::writeNarration("\n\tYou are not a coward. You don't stab people in the back. That's not your style. You prefer an open fight.");
            break;
        }
        else Logger::invalidHeroChoiceError(__FUNCTION__); continue;
    }

    std::cout << std::endl << std::endl;
    //--------------------------------
    Menu menu21;
    menu21.addOptions({ "'It doesn't matter.'", "'Your girlfriend, Nyx.'" });
    menu21.showOptions();
    //--------------------------------
    while (true)
    {
        heroChoice = menu21.inputChoice();

        if (heroChoice == 1)
        {
            Console::clearScreen();
            menu21.showHeroChoice();
            Display::writeDialogue("\n\t- 'Ugh, you little prick. I'll get you from beyond the grave. There will be no peace. I won't let that happen!'");
            Console::wait(1500);
            vincentDeath();
            break;
        }
        else if (heroChoice == 2)
        {
            Console::clearScreen();
            menu21.showHeroChoice();
            Display::writeDialogue("\n\t- 'Traitorous bitch! She'll get her due someday.");
            Display::writeDialogue(" All right, shithead, let's get this over with.'");
            vincentDeath();
            break;
        }
        else Logger::invalidHeroChoiceError(__FUNCTION__); continue;
    }

    Display::writeNarration("\n\tThe passage behind your back is opened.");
    Console::wait(1000);
    Display::writeNarration(" You turn around, in front of you is Nyx.");
    Display::writeDialogue("\n\t- 'Did you do what I asked you to do...'");
    Console::wait(1500);
    Display::writeNarration("\n\tThe girl's gaze wanders from you to the body of her ex-boyfriend behind you.");
    Console::wait(1000);
    Display::writeDialogue("\n\t- 'You did it... You really did it... Is he - is he dead?'");
    Console::wait(1000);
    Display::writeNarration("\n\tNyx walks past you and kneels by the dead man. She starts searching his pockets for something.\n\n");
    //--------------------------------
    Menu menu22;
    menu22.addOptions({ "Do nothing.", "'What is this all about?'" });
    menu22.showOptions();
    //--------------------------------
    while (true)
    {
        heroChoice = menu22.inputChoice();

        if (heroChoice == 1)
        {
            Console::clearScreen();
            menu22.showHeroChoice();
            Display::writeNarration("\n\tYou let the girl quietly plunder the corpse. This gives you more time to look at her shapes more closely.");
            Display::writeDialogue("\n\t- 'Spare me, if you please.'");
            break;
        }
        else if (heroChoice == 2)
        {
            Console::clearScreen();
            menu22.showHeroChoice();
            Display::writeDialogue("\n\t- 'Well, now I think I owe you an explanation.'");
            Display::writeNarration("\n\tA girl talks to you without even looking at you.\n");
            break;
        }
        else Logger::invalidHeroChoiceError(__FUNCTION__); continue;
    }

    vincentResurrection();
}

void Event::vincentDeath()
{
    Display::writeNarration("\n\tThe last word spoken synchronizes with the bang of a gunshot as a bullet of energy pierces the club owner's chest.");
    Console::wait(1000);
    Display::writeNarration(" The recoil knocks him from his seat. The lifeless body clatters against the floor.");
    Console::wait(1500);
    Display::writeNarration(" He's dead, just like Nyx wanted.");
    Npc::npcs["Vincent"].setStatus(Dead);
    Display::writeNarration("\n\tOut of curiosity, you walk closer and spot the corpse holding a small pistol.");
    Console::wait(1000);
    Display::writeNarration(" That bastard was playing for time after all!");
}

void Event::vincentResurrection()
{
    Logger::startFuncLog(__FUNCTION__);
    Display::writeNarration("\n\tSuddenly, the maze of cables begins to vibrate and move in a strange dance.");
    Console::wait(1000);
    Display::writeNarration(" Hisses reach you and Nyx, forming a gibberish that is difficult to understand.");
    Console::setConsoleColor(ConsoleColor::CC_Robot);
    Display::write("\n\t<You scum! You thought you got rid of me.");
    Console::wait(1000);
    Display::write(" But you didn't.");
    Console::wait(1000);
    Display::write(" I'm immortal now!>");
    Display::writeNarration("\n\tYou exchange a look with Nyx. You both can't believe what's happening.");
    Display::writeDialogue("\n\t- 'What the fuck?!'");
    Console::setConsoleColor(ConsoleColor::CC_Robot);
    Display::write("\n\t<Before your new lover killed me, sweatheart, I managed to pour some of my consciousness into the net. I don't need my body anymore, nothing limits me anymore.");
    Console::wait(1500);
    Console::setConsoleColor(ConsoleColor::CC_Robot);
    Display::write(" Now you will get what you deserve. The time for payment has come!");
    Console::wait(1000);
    Display::write(" DIE!>");
    Console::waitForUserInput();
}

void Event::nightclubCrossroads()
{
    Logger::startFuncLog(__FUNCTION__);
    //--------------------------------
    Menu menu23;
    menu23.addOptions({ "Go to the dance floor.", "Go to the bar.", "Go upstairs.", "Back on the street." });
    menu23.showOptions();
    //--------------------------------
    while (true)
    {
        heroChoice = menu23.inputChoice();

        if (heroChoice == 1)
        {
            Console::clearScreen();
            menu23.showHeroChoice();
            clubDanceFloor();
            break;
        }
        else if (heroChoice == 2)
        {
            Console::clearScreen();
            menu23.showHeroChoice();
            clubBar();
            break;
        }
        else if (heroChoice == 3)
        {
            Console::clearScreen();
            menu23.showHeroChoice();
            clubUpstairs();
            break;
        }
        else if (heroChoice == 4)
        {
            Console::clearScreen();
            menu23.showHeroChoice();
            Game::game[0].setCurrentLocation(&Location::locations["Street"]);
            break;
        }
        else Logger::error("Entered invalid value of <b>heroChoice</b>", __FUNCTION__); continue;
    }
}

// INNE
void Event::loadingFiles()
{
    Logger::startFuncLog(__FUNCTION__);
    Console::setConsoleColor(ConsoleColor::CC_Dialogue);
    Display::write("\t||", 100);

    for (int i = 0; i < 21; i++)
    {
        Console::wait(1000);
        Display::write("=", 100);
    }

    Display::write("||", 100);
    Console::wait(1000);
    Display::write(jWriter["Infos"]["DownloadCompleted"]);
    Console::resetConsoleColor();
}

void Event::namingHero()
{
    Logger::startFuncLog(__FUNCTION__);
    std::string heroName;
    Display::writeNarration(jWriter["Prologue"]["RememberYourName"]);
    Console::resetConsoleColor();
    heroName = Input::getString();
    Hero::heroes[0].setName(heroName);
    Logger::out("Set <b>" + Hero::heroes[0].getName() + "</b> to hero's name", __FUNCTION__);
}