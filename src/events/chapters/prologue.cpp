#include "../eventManager.hpp"

bool bobRecommendsZed       = false,
     zedKnowsAboutBobAndZed = false,
     heroIsOnDanceFloor     = false,
     heroIsAtBar            = false,
     heroKnowsVincentCode   = false;

// MROCZNY ZAUŁEK
void Event::prologue()
{
    Logger::startFuncLog(__FUNCTION__);
    Display::write(jWriter["prologue"]["title"]);
    Console::wait(2000);
    Display::write(jWriter["prologue"]["subtitle"]);
    Console::wait(5000);
    Console::clearScreen();
    storyIntroduction();
}

void Event::storyIntroduction()
{
    Logger::startFuncLog(__FUNCTION__);
    Display::writeNarration(jWriter["prologue"]["storyIntro"][0]);
    Console::wait(1000);
    Display::writeNarration(jWriter["prologue"]["storyIntro"][1], 20);
    Game::pause();
    Console::clearScreen();
    Console::wait(2500);
    Display::writeNarration(jWriter["prologue"]["dream"][0], 75);
    Console::wait(2500);
    Display::writeNarration(jWriter["prologue"]["dream"][1], 75);
    Console::wait(2500);
    Display::writeNarration(jWriter["prologue"]["dream"][2], 75);
    Console::wait(3000);
    Console::clearScreen();
    wakeUpInDarkAlley();
}

void Event::wakeUpInDarkAlley()
{
    Logger::startFuncLog(__FUNCTION__);
    Menu menu1;
    Console::wait(2000);
    Display::writeNarration(jWriter["prologue"]["wakeUp"][0]);
    Console::wait(1000);
    Display::writeNarration(jWriter["prologue"]["wakeUp"][1]);
    Console::wait(1500);
    Display::writeNarration(jWriter["prologue"]["wakeUp"][2]);
    Console::wait(1000);
    Display::writeNarration(jWriter["prologue"]["wakeUp"][3]);
    Console::wait(3000);
    Display::writeNarration(jWriter["prologue"]["wakeUp"][4]);
    Console::wait(500);
    Display::writeNarration(jWriter["prologue"]["wakeUp"][5]);
    Console::wait(3000);
    Display::writeNarration(jWriter["prologue"]["wakeUp"][6]);
    Console::wait(1000);
    Display::writeNarration(jWriter["prologue"]["wakeUp"][7]);
    Console::wait(2500);
    Display::writeNarration(jWriter["prologue"]["wakeUp"][8]);
    //--------------------------------
    menu1.addOptions({
        std::make_pair(jWriter["prologue"]["menu1"][0], rubbishSearch),
        std::make_pair(jWriter["prologue"]["menu1"][1], outOfAlley)
    });
    menu1.showOptions();
    //--------------------------------

    while (true)
    {
        menu1.inputChoice();
    }
}

void Event::acceleratorFinding()
{
    Logger::startFuncLog(__FUNCTION__);
    Display::writeNarration(jWriter["prologue"]["findingAccelerator"][0]);
    Console::wait(1500);
    Display::writeNarration(jWriter["prologue"]["findingAccelerator"][1]);
    Console::wait(2000);

    Hero::heroes[0].addItem(&Item::items["AD13"]);
    Hero::heroes[0].addMoney(5.0);

    if (Game::game[0].getLang() == GameLanguage::EN)
    {
        Console::setConsoleColor(ConsoleColor::CC_Item);
        Display::write("\n\n\t" + Item::items["AD13"].getName());
        Console::resetConsoleColor();
        Display::write(jWriter["main"]["and"]);
        Console::setConsoleColor(ConsoleColor::CC_Green);
        Display::write("5$");
        Console::resetConsoleColor();
        Display::write(jWriter["main"]["wasFound"]);
    }
    else if (Game::game[0].getLang() == GameLanguage::PL)
    {
        Console::resetConsoleColor();
        Display::write("\n\n\t" + (std::string)jWriter["main"]["wasFound"]);
        Console::setConsoleColor(ConsoleColor::CC_Item);
        Display::write(Item::items["AD13"].getName());
        Console::resetConsoleColor();
        Display::write(jWriter["main"]["and"]);
        Console::setConsoleColor(ConsoleColor::CC_Green);
        Display::write("5$");
        Console::resetConsoleColor();
        Display::write(".");
    }

    Display::write(jWriter["inventory"]["tip"], 15);
    Console::wait(4000);
    Display::writeNarration(jWriter["prologue"]["findingAccelerator"][2]);
    Console::wait(1000);
}

void Event::rubbishSearch()
{
    Logger::startFuncLog(__FUNCTION__);
    acceleratorFinding();
    outOfAlley();
}

void Event::outOfAlley()
{
    Logger::startFuncLog(__FUNCTION__);

    if (!Hero::heroes[0].hasItem(&Item::items["AD13"]))
    {
        Display::writeNarration(jWriter["prologue"]["outOfAlley"][0]);
        Console::wait(1500);
        Display::writeNarration(jWriter["prologue"]["outOfAlley"][1]);
        Display::writeNarration(jWriter["prologue"]["outOfAlley"][2]);
    }
    else {
        Display::writeNarration(jWriter["prologue"]["outOfAlley"][3]);
    }

    Console::wait(3000);
    Display::writeNarration(jWriter["prologue"]["outOfAlley"][4]);
    Display::writeDialogue(jWriter["prologue"]["dialogueWithBob"][1]);
    //--------------------------------
    Menu menu2;
    menu2.addOptions({
        std::make_pair(jWriter["prologue"]["menu2"][0], outOfAlley_1),
        std::make_pair(jWriter["prologue"]["menu2"][1], outOfAlley_2)
    });
    menu2.showOptions();
    //--------------------------------
    while (true)
    {
        menu2.inputChoice();
    }
}

void Event::outOfAlley_1()
{
    Display::writeNarration(jWriter["prologue"]["outOfAlley"][5]);
    Console::wait(1500);
    Display::writeNarration(jWriter["prologue"]["outOfAlley"][6]);
    Console::wait(1000);
    dialogueWithBob();
}

void Event::outOfAlley_2()
{
    Display::writeNarration(jWriter["prologue"]["outOfAlley"][7]);
    Display::writeDialogue(jWriter["prologue"]["dialogueWithBob"][2]);
    Display::writeNarration(jWriter["prologue"]["outOfAlley"][8]);
    Console::wait(1000);
    Game::game[0].setCurrentLocation(&Location::locations["Street"]);
}

void Event::dialogueWithBob()
{
    Logger::startFuncLog(__FUNCTION__);
    Display::writeDialogue(jWriter["prologue"]["dialogueWithBob"][3]);

    if (!Npc::npcs["Bob"].knowsHero() && !Npc::npcs["Caden"].knowsHero() && !Npc::npcs["CadenPartner"].knowsHero())
    {
        //--------------------------------
        Menu nameMenu;
        nameMenu.addOptions({
            std::make_pair(jWriter["prologue"]["nameMenu"][0], dialogueWithBob_1),
            std::make_pair(jWriter["prologue"]["nameMenu"][1], dialogueWithBob_2)
        });
        nameMenu.showOptions();
        //--------------------------------
        while (true)
        {
            nameMenu.inputChoice();
        }
        //--------------------------------
        Menu menu3;
        menu3.addOptions({
            std::make_pair(jWriter["prologue"]["menu3"][0], dialogueWithBob_3),
            std::make_pair(jWriter["prologue"]["menu3"][1], dialogueWithBob_4),
            std::make_pair(jWriter["prologue"]["menu3"][2], dialogueWithBob_5)
        });
        menu3.showOptions();
        //--------------------------------
        while (true)
        {
            menu3.inputChoice();
        }

        if (!streetWasVisited)
        {
            Display::writeNarration(jWriter["prologue"]["dialogueWithBob"][19]);
            Console::wait(1000);
            Display::writeNarration(jWriter["prologue"]["dialogueWithBob"][20]);
            Console::wait(2000);
            Display::writeNarration(jWriter["prologue"]["dialogueWithBob"][21]);
            Console::wait(1000);
            Display::writeNarration(jWriter["prologue"]["dialogueWithBob"][22]);
            Display::writeDialogue(jWriter["prologue"]["dialogueWithBob"][23]);
            Console::wait(500);
            Display::writeDialogue(jWriter["prologue"]["dialogueWithBob"][24]);
            Console::wait(500);
            Display::writeDialogue(jWriter["prologue"]["dialogueWithBob"][25]);
            Console::wait(1500);
            Display::writeNarration(jWriter["prologue"]["dialogueWithBob"][26]);
            Console::wait(1500);
            Display::writeNarration(jWriter["prologue"]["dialogueWithBob"][27]);
            Console::wait(3500);
            Game::game[0].setCurrentLocation(&Location::locations["Street"]);
        }
        else {
            Display::writeDialogue(jWriter["prologue"]["dialogueWithBob"][28]);
            Console::wait(1500);
            Display::writeDialogue(jWriter["prologue"]["dialogueWithBob"][29]);

            if (Npc::npcs["Bob"].getAttitude() == Attitude::Angry || Npc::npcs["Bob"].getAttitude() == Attitude::Hostile)
            {
                Display::writeDialogue(jWriter["prologue"]["dialogueWithBob"][30]);
            }
            else {
                Display::writeDialogue(jWriter["prologue"]["dialogueWithBob"][31]);
            }

            Console::wait(1500);
            Display::writeNarration(jWriter["prologue"]["dialogueWithBob"][26]);
            Console::wait(1500);
            Display::writeNarration(jWriter["prologue"]["dialogueWithBob"][27]);
            Game::pause();
            Console::clearScreen();
            Game::game[0].setCurrentLocation(&Location::locations["Street"]);
        }
    }
}

void Event::dialogueWithBob_1()
{
    namingHero();
    Npc::npcs["Bob"].setToKnowHero();
    Display::writeDialogue((std::string)jWriter["prologue"]["dialogueWithBob"][4] + Hero::heroes[0].getName() + (std::string)jWriter["prologue"]["dialogueWithBob"][5]);
    Console::wait(1500);
    Display::writeDialogue((std::string)jWriter["prologue"]["dialogueWithBob"][6] + Npc::npcs["Bob"].getName() + ".");
    Console::wait(1500);
    Display::writeDialogue(jWriter["prologue"]["dialogueWithBob"][7]);
    Display::writeNarration(jWriter["prologue"]["dialogueWithBob"][0]);
}

void Event::dialogueWithBob_2()
{
    Npc::npcs["Bob"].setAttitude(Attitude::Angry); // Angry / Hostile / Friendly / Neutral
    Console::wait(500);
    Display::writeDialogue(jWriter["prologue"]["dialogueWithBob"][8]);
}

void Event::dialogueWithBob_3()
{
    bobRecommendsZed = true; // Bob poleca bohaterowi sklep z bronią Zeda
    Display::writeDialogue(jWriter["prologue"]["dialogueWithBob"][9]);
    Console::wait(1000);
    Display::writeDialogue(jWriter["prologue"]["dialogueWithBob"][10]);
    Console::wait(1000);
    Display::writeDialogue(jWriter["prologue"]["dialogueWithBob"][11]);
}

void Event::dialogueWithBob_4()
{
    Display::writeDialogue(jWriter["prologue"]["dialogueWithBob"][12]);
    Console::wait(1000);
    Display::writeDialogue(jWriter["prologue"]["dialogueWithBob"][13]);
    Console::wait(1500);
    Display::writeDialogue(jWriter["prologue"]["dialogueWithBob"][14]);
    Console::wait(1500);
    Display::writeDialogue(jWriter["prologue"]["dialogueWithBob"][15]);
    Console::wait(1000);
    Display::writeDialogue(jWriter["prologue"]["dialogueWithBob"][16]);
    aboutParadiseLost();
}

void Event::dialogueWithBob_5()
{
    Npc::npcs["Bob"].setAttitude(Attitude::Angry); // Angry / Hostile / Friendly / Neutral
    Console::wait(500);
    Display::writeDialogue(jWriter["prologue"]["dialogueWithBob"][17]);
}

void Event::aboutParadiseLost()
{
    std::cout << std::endl;
    //--------------------------------
    Menu paradiseLostMenu;
    paradiseLostMenu.addOptions({
        std::make_pair(jWriter["prologue"]["paradiseLostMenu"][0], aboutParadiseLost_1),
        std::make_pair(jWriter["prologue"]["paradiseLostMenu"][1], aboutParadiseLost_2)
    });
    paradiseLostMenu.showOptions();
    //--------------------------------
    while (true)
    {
        paradiseLostMenu.inputChoice();
    }
}

void Event::aboutParadiseLost_1()
{
    Display::writeDialogue(jWriter["prologue"]["aboutParadiseLost"][0]);
    Console::wait(500);
    Display::writeDialogue(jWriter["prologue"]["aboutParadiseLost"][1]);
    Console::wait(1000);
    Display::writeDialogue(jWriter["prologue"]["aboutParadiseLost"][2]);
    Console::wait(1000);
    Display::writeDialogue(jWriter["prologue"]["aboutParadiseLost"][3]);
    Console::wait(1000);
    Display::writeDialogue(jWriter["prologue"]["aboutParadiseLost"][4]);
    Console::wait(1500);
    Display::writeDialogue(jWriter["prologue"]["aboutParadiseLost"][5]);
}

void Event::aboutParadiseLost_2()
{
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
        menu2.addOptions({
            std::make_pair(jWriter["prologue"]["menu2"][2], outOfAlley_1),
            std::make_pair(jWriter["prologue"]["menu2"][1], outOfAlley_2)
        });
        menu2.showOptions();
        //--------------------------------
        while (true)
        {
            menu2.inputChoice();
        }
    }
    else
    {
        Display::writeNarration("\tWhen you enter an alley, you notice a sea of trash around you.");
        Console::wait(1000);
        Display::writeNarration(jWriter["prologue"]["wakeUp"][7]);
    
        if (!Hero::heroes[0].hasItem(&Item::items["AD13"]))
        {
            Console::wait(1500);
            Display::writeNarration(jWriter["prologue"]["wakeUp"][8]);
            //--------------------------------
            Menu menu1;
            menu1.addOptions({
                std::make_pair(jWriter["prologue"]["menu1"][0], darkAlleyCrossroads_1),
                std::make_pair(jWriter["prologue"]["menu1"][1], darkAlleyCrossroads_2)
            });
            menu1.showOptions();
            //--------------------------------
            while (true)
            {
                menu1.inputChoice();
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

void Event::darkAlleyCrossroads_1()
{
    Logger::startFuncLog(__FUNCTION__);
    acceleratorFinding();
    Display::writeNarration("\n\tThere is nothing interesting here any more. Time to go back...\n");
    Console::wait(1500);
    Console::clearScreen();
    Game::game[0].setCurrentLocation(&Location::locations["Street"]);
}

void Event::darkAlleyCrossroads_2()
{
    Logger::startFuncLog(__FUNCTION__);
    Console::clearScreen();
    Game::game[0].setCurrentLocation(&Location::locations["Street"]);
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
    menu4.addOptions({
        std::make_pair("Come closer and see what it's all about.", lookAtAmnesia_1),
        std::make_pair("Take a look around the area.", lookAtAmnesia_2)
    });
    menu4.showOptions();
    //--------------------------------
    while (true)
    {
        menu4.inputChoice();
    }
}

void Event::lookAtAmnesia_1()
{
    Logger::startFuncLog(__FUNCTION__);
    std::cout << std::endl;

    if (!Npc::npcs["Bob"].knowsHero())
    {
        meetingWithSecurityGuards();
        meetingWithPolicemans();
    }
    else {
        meetingWithPolicemans();
    }
}

void Event::lookAtAmnesia_2()
{
    Logger::startFuncLog(__FUNCTION__);
    Game::game[0].setCurrentLocation(&Location::locations["GunShop"]);
}

void Event::encounterGunStore()
{
    Logger::startFuncLog(__FUNCTION__);
    Display::writeNarration("\n\tYou go to the right side of the street. After walking several meters you come across a small\n\tbooth between blocks of flats.");

    if (bobRecommendsZed)
    {
        Display::writeNarration(" Could it be that the famous gun store managed by Bob's friend?");
    }

    std::cout << std::endl << std::endl;
    //--------------------------------
    Menu menu5;
    menu5.addOptions({
        std::make_pair("Go inside.", enterGunShop),
        std::make_pair("Turn back.", encounterGunStore_1)
    });
    menu5.showOptions();
    //--------------------------------
    while (true)
    {
        menu5.inputChoice();
    }
}

void Event::encounterGunStore_1()
{
    Logger::startFuncLog(__FUNCTION__);
    std::cout << std::endl;

    if (!Npc::npcs["Caden"].knowsHero() && !Npc::npcs["CadensPartner"].knowsHero())
    {
        if (!Npc::npcs["Bob"].knowsHero())
        {
            meetingWithSecurityGuards();
            meetingWithPolicemans();
        }
        else {
            meetingWithPolicemans();
        }
    }
    else {
        Game::game[0].setCurrentLocation(&Location::locations["Street"]);
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

    if (Npc::npcs["Bob"].knowsHero()) {
        Display::writeNarration("\tWhen you get closer, one of the police officers in a dark blue uniform turns toward you.");
    }
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

    if (Hero::heroes[0].hasItem(&Item::items["AD13"])) {
        Display::writeNarration("\n\tYou start searching through the pockets of your jacket and pants, but other than the accelerator\n\tyou found in the trash, there's nothing else there.");
    }
    else {
        Display::writeNarration("\n\tYou start searching through the pockets of your jacket and pants, but there's nothing there.");
    }

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
    menu6.addOptions({
        std::make_pair("Go inside.", meetingWithPolicemans_1),
        std::make_pair("Turn back.", meetingWithPolicemans_2)
    });
    menu6.showOptions();
    //--------------------------------
    while (true)
    {
        menu6.inputChoice();
    }
}

void Event::meetingWithPolicemans_1()
{
    Logger::startFuncLog(__FUNCTION__);
    Game::game[0].setCurrentLocation(&Location::locations["Nightclub"]);
}

void Event::meetingWithPolicemans_2()
{
    Logger::startFuncLog(__FUNCTION__);
    Game::game[0].setCurrentLocation(&Location::locations["GunShop"]);
}

void Event::streetCrossroads()
{
    Logger::startFuncLog(__FUNCTION__);
    Display::writeNarration("\n\tOnce again you are on a street bathed in nighttime darkness.\n\n");
    //--------------------------------
    Menu menu7;
    menu7.addOptions({
        std::make_pair("Visit: " + Location::locations["DarkAlley"].getName() + ".", visitDarkAlley),
        std::make_pair("Visit: " + Location::locations["Nightclub"].getName() + ".", visitNightclub),
        std::make_pair("Visit: " + Location::locations["GunShop"].getName() + ".", visitGunShop)
    });
    menu7.showOptions();
    //--------------------------------
    while (true)
    {
        menu7.inputChoice();
    }
}

void Event::visitDarkAlley()
{
    Logger::startFuncLog(__FUNCTION__);
    Game::game[0].setCurrentLocation(&Location::locations["DarkAlley"]);
}

void Event::visitStreet()
{
    Logger::startFuncLog(__FUNCTION__);
    Game::game[0].setCurrentLocation(&Location::locations["Street"]);
}

void Event::visitNightclub()
{
    Logger::startFuncLog(__FUNCTION__);
    Display::writeNarration("\n\tYou enter from a fairly well-lit street into a slightly darkened nightclub, trembling with colour.\n\n");
    Game::game[0].setCurrentLocation(&Location::locations["Nightclub"]);
}

void Event::visitGunShop()
{
    Logger::startFuncLog(__FUNCTION__);
    Game::game[0].setCurrentLocation(&Location::locations["GunShop"]);
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
        std::vector<std::pair<std::string, std::function<void()>>> options;
        options.push_back(std::make_pair("'What do you have?'", dialogueWithZed_1));
        options.push_back(std::make_pair("'How's business going?'", dialogueWithZed_2));

        if (bobRecommendsZed && !zedKnowsAboutBobAndZed)
        {
            options.push_back(std::make_pair("'You're Zed? I come from Bob.'", dialogueWithZed_3));
        }

        if (Quest::quests["ZedAccelerator"].getIsRunning() && Hero::heroes[0].hasItem(&Item::items["AD13"]))
        {
            options.push_back(std::make_pair("'I have an accelerator for you.'", dialogueWithZed_4));
        }

        options.push_back(std::make_pair("'I have to go...'", dialogueWithZed_5));
        menu8.addOptions(options);
        menu8.showOptions();
        //--------------------------------
        menu8.inputChoice();
    }
}

void Event::dialogueWithZed_1()
{
    Logger::startFuncLog(__FUNCTION__);
    std::cout << std::endl;
    zedTrade();
}

void Event::dialogueWithZed_2()
{
    Logger::startFuncLog(__FUNCTION__);
    bool heroTalkedAboutBusinessWithZed = false;

    if (heroTalkedAboutBusinessWithZed) {
        Display::writeDialogue("\n\t- 'Hey, what's up? Are you sclerotic or something? We already talked about this, haha!'\n");
    }
    else {
        heroTalkedAboutBusinessWithZed = true;
        Display::writeDialogue("\n\t- 'What kind of question is that anyway? Business is doing great! Everyone stops by\n\tevery now and then to rearm. It's the natural order of things.'\n");
    }
}

void Event::dialogueWithZed_3()
{
    Logger::startFuncLog(__FUNCTION__);
    zedKnowsAboutBobAndZed = true;
    Display::writeDialogue("\n\t- 'Yes, that is correct. I'm Zed, and this is my little shop.");
    Console::wait(1000);
    Display::writeDialogue(" Since you know Bob,\n\tyou can get a small discount here.'");
    Npc::npcs["Zed"].setAttitude(Attitude::Friendly);
}

void Event::dialogueWithZed_4()
{
    zedGetsAnAccelerator();
}

void Event::dialogueWithZed_5()
{
    Logger::startFuncLog(__FUNCTION__);
    Display::writeDialogue("\n\t- 'No problem. See you later!'\n");
    Console::clearScreen();

    if (!Npc::npcs["Caden"].knowsHero() && !Npc::npcs["CadenPartner"].knowsHero())
    {
        meetingWithPolicemans();
    }
    else {
        Game::game[0].setCurrentLocation(&Location::locations["Street"]);
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
            menu9.addOptions({
                std::make_pair("Buy: pistol (250 $).", buyPistol),
                std::make_pair("'I have made up my mind.'", zedTrade_1)
            });
            menu9.showOptions();
            //--------------------------------
            while (true)
            {
                menu9.inputChoice();
            }
        }
        else
        {
            std::cout << std::endl;
            //--------------------------------
            Menu menu10;
            menu10.addOptions({
                std::make_pair("Buy: pistol (250 $).", buyPistol),
                std::make_pair("'I have made up my mind.'", zedTrade_1)
            });
            menu10.showOptions();
            //--------------------------------
            while (true)
            {
                menu10.inputChoice();
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

void Event::zedTrade_1()
{
    Logger::startFuncLog(__FUNCTION__);
    Display::writeNarration("\n\tZed looks at you pityingly and shrugs his shoulders.");
    Display::writeDialogue("\n\t- 'No problem. It can happen to anyone.'\n");
    dialogueWithZed();
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
    menu11.addOptions({
        std::make_pair("Go to the dance floor.", clubDanceFloor),
        std::make_pair("Go to the bar.", clubBar),
        std::make_pair("Go upstairs.", clubUpstairs),
        std::make_pair("Back on the street.", visitStreet)
    });
    menu11.showOptions();
    //--------------------------------
    while (true)
    {
        menu11.inputChoice();
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
        menu12.addOptions({
            std::make_pair("'What do you want?'", clubDanceFloor_1),
            std::make_pair("'Hey, baby.'", clubDanceFloor_2),
            std::make_pair("Keep dancing with no words.", clubDanceFloor_3)
        });
        menu12.showOptions();
        //--------------------------------
        while (true)
        {
            menu12.inputChoice();
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

void Event::clubDanceFloor_1()
{
    Display::writeNarration("\n\tThe girl turns towards you and smiles with her snow-white teeth.");
    Display::writeDialogue("\n\t- 'Nothing will escape your attention. I am Nyx. I think you can help me.'");
}

void Event::clubDanceFloor_2()
{
    Display::writeNarration("\n\tThe girl turns towards you and smiles with her snow-white teeth.");
    Display::writeDialogue("\n\t- 'Hi, stud. I've been watching you since you came in. I am Nyx.'");
    Display::writeNarration("\n\tWith the last word she comes closer to you turns her back on you and starts dancing very\n\tclose to you.");
    Display::writeDialogue("\n\t- 'I am looking for someone like you. I think you can help me.'");
}

void Event::clubDanceFloor_3()
{
    Display::writeNarration("\n\tThe girl turns towards you and smiles with her snow-white teeth.");
    Display::writeDialogue("\n\t- 'Hi, I am Nyx. Vinc, the owner, is my boyfriend. I think you can help me.'");
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
        menu13.addOptions({
            std::make_pair("'Give me anything.'", clubBar_1),
            std::make_pair("'Who's in charge?'", clubBar_2),
            std::make_pair("'Bye.'", clubBar_3)
        });
        menu13.showOptions();
        //--------------------------------
        menu13.inputChoice();
    }
}

void Event::clubBar_1()
{
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
}

void Event::clubBar_2()
{
    Display::writeNarration("\n\tThe bartender squints, hearing your question.");
    Display::writeDialogue("\n\t- 'You're not from around here, are you?");
    Console::wait(1500);
    Display::writeDialogue(" My boss is Vincent Ramsey.");
    Console::wait(1000);
    Display::writeDialogue(" He's a tough guy, so you'd better not make trouble, or it could end badly for you.'\n\n");
}

void Event::clubBar_3()
{
    Display::writeNarration("\n\tThe bartender reaches for a glass from under the counter and starts wiping it down.");
    Display::writeDialogue("\n\t- 'Yeah, have fun.'\n\n");
    Game::game[0].setCurrentLocation(&Location::locations["Nightclub"]);
}

void Event::miaMeeting()
{
    Logger::startFuncLog(__FUNCTION__);
    std::cout << std::endl << std::endl;
    //--------------------------------
    Menu menu14;
    menu14.addOptions({
        std::make_pair("'What is it about?'", miaMeeting_1),
        std::make_pair("Be silent and let her speak.", miaMeeting_2)
    });
    menu14.showOptions();
    //--------------------------------
    while (true)
    {
        menu14.inputChoice();
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

void Event::miaMeeting_1()
{
}

void Event::miaMeeting_2()
{
}

void Event::clubUpstairs()
{
    Logger::startFuncLog(__FUNCTION__);
    Display::writeNarration("\n\tYou go up a winding staircase. At the end of a short banister you will see a closed door\n\tguarded by another bulky individual.\n\n");
    //--------------------------------
    Menu menu15;
    menu15.addOptions({
        std::make_pair("Come closer.", clubUpstairs_1),
        std::make_pair("Go back downstairs.", clubUpstairs_2)
    });
    menu15.showOptions();
    //--------------------------------
    while (true)
    {
        menu15.inputChoice();
    }
}

void Event::clubUpstairs_1()
{
    Display::writeNarration("\n\tAre you brave or foolish enough to face the hammer man. You are stopped from taking another\n\tstep by his firm voice.");
    Display::writeDialogue("\n\t- 'What here?'");
    Npc::npcs["Jet"].setToKnowHero();
    dialogueWithJet();
}

void Event::clubUpstairs_2()
{
    Display::writeNarration("\n\tYou don't dare to come closer, so like the last coward you turn back and return to the kingdom\n\tof loud music and dancing people.\n");
    nightclub();
}

int jetPoints = 0;
void Event::dialogueWithJet()
{
    Logger::startFuncLog(__FUNCTION__);
    std::cout << std::endl << std::endl;
    Menu menu16;

    while (true)
    {
        jetGetsAngry(jetPoints);
        //--------------------------------
        std::vector<std::pair<std::string, std::function<void()>>> options;
        options.push_back(std::make_pair("'I want to pass.'", dialogueWithJet_1));
        options.push_back(std::make_pair("'What is behind that door?'", dialogueWithJet_2));

        if (Hero::heroes[0].hasItem(&Item::items["Pistol"]))
        {
            options.push_back(std::make_pair("Kill him with a pistol.", dialogueWithJet_3));
            options.push_back(std::make_pair("Stun him with a pistol.", dialogueWithJet_4));
        }

        options.push_back(std::make_pair("'It's time for me to go.'", dialogueWithJet_5));
        menu16.addOptions(options);
        menu16.showOptions();
        //--------------------------------
        menu16.inputChoice();
    }
}

void Event::dialogueWithJet_1()
{
    Display::writeNarration("\n\tWhen you say this a big paw blocks your way.");
    Display::writeDialogue("\n\t- 'You don't get what you're looking for here, mate.'\n\n");
    jetPoints += 1;
}

void Event::dialogueWithJet_2()
{
    Display::writeNarration("\n\tThe security guard instinctively peeks towards the door.");
    Display::writeDialogue("\n\t- 'You shouldn't be interested in this.'\n\n");
    jetPoints += 1;
}

void Event::dialogueWithJet_3()
{
    // TODO: dodać opis zabicia Jeta!
    vincentOffice();
}

void Event::dialogueWithJet_4()
{
    // TODO: dodać opis ogłuszenia Jeta!
    vincentOffice();
}

void Event::dialogueWithJet_5()
{
    Display::writeDialogue("\n\t- 'Yeah. Get lost.'");
    Display::writeNarration("\n\tAnd so you turn back and return to the kingdom of loud music and dancing people.\n\n");
    nightclub();
}


void Event::jetGetsAngry(int angerPoints)
{
    Logger::startFuncLog(__FUNCTION__);
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
    
    if (rand > 5 && rand <= 10)
    {
        RandomEvent::nickHandFinding();
    }

    Game::game[0].setCurrentLocation(&Location::locations["Street"]);
}

void Event::vincentOffice()
{
    Logger::startFuncLog(__FUNCTION__);
    Display::writeNarration("\tYou enter the manager's office immersed in twilight. In the middle of the room stands a sizable desk, and on it are stacks of documents and computer. To the left of the entrance is a window to the street below. On the right you will notice a door to another room.\n\n");
    //--------------------------------
    Menu menu17;
    menu17.addOptions({
        std::make_pair("Open the door and go into the other room.", vincentHideoutCode),
        std::make_pair("Stay and search the office.", checkVincentDesk)
    });
    menu17.showOptions();
    //--------------------------------
    while (true)
    {
        menu17.inputChoice();
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
        menu18.addOptions({
            std::make_pair("Use code '2021'.", nullptr),
            std::make_pair("Search the office.", nullptr)
        });
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
    menu19.addOptions({
        std::make_pair("Disconnect his consciousness from the neuronet. (Kill him)", vincentHideout_1),
        std::make_pair("Wait for his consciousness to leave the neuronet.", vincentHideout_2)
    });
    menu19.showOptions();
    //--------------------------------
    while (true)
    {
        menu19.inputChoice();
    }
}

void Event::vincentHideout_1()
{
    Display::writeNarration("\n\tYou lean over Vincent and, in a fluid motion without hesitation, pull the stimulation helmet\n\toff his head. You witness the nightclub owner being shaken by a wave of convulsions. Foam\n\tbegins to come out of his mouth and after a moment the man freezes.");
    Console::wait(1500);
    Npc::npcs["Vincent"].setStatus(Dead);
    Display::writeNarration(" He's probably dead, just like\n\tNyx wanted.");
}

void Event::vincentHideout_2()
{
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
}

void Event::dialogueWithVincent()
{
    Logger::startFuncLog(__FUNCTION__);
    std::cout << std::endl << std::endl;
    //--------------------------------
    Menu menu20;
    menu20.addOptions({
        std::make_pair("'Die!'", dialogueWithVincent_1),
        std::make_pair("'I don't want to fight with you.'", dialogueWithVincent_2),
        std::make_pair("'Nyx wants you dead.'", dialogueWithVincent_3)
    });
    menu20.showOptions();
    //--------------------------------
    while (true)
    {
        menu20.inputChoice();
    }

    std::cout << std::endl << std::endl;
    //--------------------------------
    Menu menu21;
    menu21.addOptions({
        std::make_pair("'It doesn't matter.'", dialogueWithVincent_4),
        std::make_pair("'Your girlfriend, Nyx.'", dialogueWithVincent_5)
    });
    menu21.showOptions();
    //--------------------------------
    while (true)
    {
        menu21.inputChoice();
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
    menu22.addOptions({
        std::make_pair("Do nothing.", dialogueWithVincent_6),
        std::make_pair("'What is this all about?'", dialogueWithVincent_7)
    });
    menu22.showOptions();
    //--------------------------------
    while (true)
    {
        menu22.inputChoice();
    }

    vincentResurrection();
}

void Event::dialogueWithVincent_1()
{
    Display::writeNarration("\n\tWith a shout, you bring out your gun and aim it at Vincent's chest.");
    Display::writeDialogue("\n\t- 'Are you such a hero?");
    Console::wait(1000);
    Display::writeDialogue(" Would you kill an unarmed man?");
    Console::wait(1000);
    Display::writeDialogue(" All right, can I at least find out who\n\tsent you? I know you're not working alone. I'm seeing you for the first time in my life.'");
}

void Event::dialogueWithVincent_2()
{
    Display::writeNarration("\n\tYou are not a coward.");
    Console::wait(1000);
    Display::writeNarration(" You don't stab people in the back. That's not your style. You prefer an\n\topen fight.");
}

void Event::dialogueWithVincent_3()
{
    Display::writeNarration("\n\tYou are not a coward. You don't stab people in the back. That's not your style. You prefer an open fight.");
}

void Event::dialogueWithVincent_4()
{
    Display::writeDialogue("\n\t- 'Ugh, you little prick. I'll get you from beyond the grave. There will be no peace. I won't let that happen!'");
    Console::wait(1500);
    vincentDeath();
}

void Event::dialogueWithVincent_5()
{
    Display::writeDialogue("\n\t- 'Traitorous bitch! She'll get her due someday.");
    Display::writeDialogue(" All right, shithead, let's get this over with.'");
    vincentDeath();
}

void Event::dialogueWithVincent_6()
{
    Display::writeNarration("\n\tYou let the girl quietly plunder the corpse. This gives you more time to look at her shapes more closely.");
    Display::writeDialogue("\n\t- 'Spare me, if you please.'");
}

void Event::dialogueWithVincent_7()
{
    Display::writeDialogue("\n\t- 'Well, now I think I owe you an explanation.'");
    Display::writeNarration("\n\tA girl talks to you without even looking at you.\n");
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
    menu23.addOptions({
        std::make_pair("Go to the dance floor.", clubDanceFloor),
        std::make_pair("Go to the bar.", clubBar),
        std::make_pair("Go upstairs.", clubUpstairs),
        std::make_pair("Back on the street.", visitStreet)
    });
    menu23.showOptions();
    //--------------------------------
    while (true)
    {
        menu23.inputChoice();
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
    Display::write(jWriter["main"]["downloadCompleted"]);
    Console::resetConsoleColor();
}

void Event::namingHero()
{
    Logger::startFuncLog(__FUNCTION__);
    std::string heroName;
    Display::writeNarration(jWriter["prologue"]["rememberYourName"]);
    Console::resetConsoleColor();
    heroName = Input::getString();
    Hero::heroes[0].setName(heroName);
    Logger::out("Set <b>" + Hero::heroes[0].getName() + "</b> to hero's name", __FUNCTION__);
}

void RandomEvent::downpourStart()
{
    Display::writeNarration(jWriter["prologue"]["downpourStart"][0]);
    Console::wait(1000);
    Display::writeNarration(jWriter["prologue"]["downpourStart"][1]);
    Console::wait(500);
    Display::writeNarration(jWriter["prologue"]["downpourStart"][2]);
}

void RandomEvent::nickHandFinding()
{
    Display::writeNarration(jWriter["prologue"]["findingNicksHand"][0]);
    Console::wait(500);
    Display::writeNarration(jWriter["prologue"]["findingNicksHand"][1]);
    Console::wait(1000);
    Display::writeNarration(jWriter["prologue"]["findingNicksHand"][2]);
    Console::wait(500);
    Display::writeNarration(jWriter["prologue"]["findingNicksHand"][3]);
    Console::wait(250);
    Display::writeNarration(jWriter["prologue"]["findingNicksHand"][4]);
    Console::wait(500);
    Display::writeNarration(jWriter["prologue"]["findingNicksHand"][5]);
    Console::wait(250);
    Display::writeNarration(jWriter["prologue"]["findingNicksHand"][6]);
}

void RandomEvent::hookersMeeting()
{
    // TODO
}

void RandomEvent::punksMeeting()
{
    // TODO
}
