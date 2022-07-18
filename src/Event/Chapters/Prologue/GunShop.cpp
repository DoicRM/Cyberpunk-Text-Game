// ************************************************************
// 		ZED'S GUN SHOP
// ************************************************************

#include "Prologue.hpp"

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

        if (Hero::heroes["Hero"].hasItem(&Item::items["Pistol"]))
        {
            Display::writeDialogue("\n\t- 'What's up? How's the gun working out?'");
        }

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

        Menu menu8;
        std::vector<std::pair<std::string, std::function<void()>>> options;
        options.push_back(std::make_pair("'What do you have?'", dialogueWithZed_1));
        options.push_back(std::make_pair("'How's business going?'", dialogueWithZed_2));

        if (bobRecommendsZed && !zedKnowsAboutBobAndZed)
        {
            options.push_back(std::make_pair("'You're Zed? I come from Bob.'", dialogueWithZed_3));
        }

        if (Quest::quests["ZedAccelerator"].getIsRunning() && Hero::heroes["Hero"].hasItem(&Item::items["AD13"]))
        {
            options.push_back(std::make_pair("'I have an accelerator for you.'", dialogueWithZed_4));
        }

        options.push_back(std::make_pair("'I have to go...'", dialogueWithZed_5));
        menu8.addOptions(options);
        menu8.showOptions();
        menu8.inputChoice();

        if (menu8.getChoice() <= menu8.getOptionsSize() && menu8.getChoice() > 0)
        {
            break;
        }
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

    dialogueWithZed();
}

void Event::dialogueWithZed_3()
{
    Logger::startFuncLog(__FUNCTION__);
    zedKnowsAboutBobAndZed = true;
    Display::writeDialogue("\n\t- 'Yes, that is correct. I'm Zed, and this is my little shop.");
    Console::wait(1000);
    Display::writeDialogue(" Since you know Bob,\n\tyou can get a small discount here.'");
    Npc::npcs["Zed"].setAttitude(Attitude::Friendly);
    dialogueWithZed();
}

void Event::dialogueWithZed_4()
{
    zedGetsAnAccelerator();
    dialogueWithZed();
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
    Hero::heroes["Hero"].removeItem(&Item::items["AD13"]);
    Display::writeDialogue("\n\t- 'Well done!");
    Console::wait(1000);
    Display::writeDialogue(" I don't know where you found it, but now the gun is yours.'\n");

    Hero::heroes["Hero"].addItem(&Item::items["Pistol"]);
    Console::setConsoleColor(ConsoleColor::CC_Item);
    Display::write("\n\t" + Item::items["AD13"].getName());
    Console::resetConsoleColor();
    Display::write(" given and ");
    Console::setConsoleColor(ConsoleColor::CC_Item);
    Display::write(Item::items["Pistol"].getName());
    Console::resetConsoleColor();
    Display::write(" gained.\n");

    Hero::heroes["Hero"].endQuest(&Quest::quests["ZedAccelerator"], Log::Success);
}

void Event::zedTrade()
{
    Logger::startFuncLog(__FUNCTION__);
    bool ZedTellsAboutWeapons = false;

    if (!Hero::heroes["Hero"].hasItem(&Item::items["Pistol"]))
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

            Menu menu9({
                std::make_pair("Buy: pistol (250 $).", buyPistol),
                std::make_pair("'I have made up my mind.'", zedTrade_1)
                });
        }
        else
        {
            std::cout << std::endl;

            Menu menu10({
                std::make_pair("Buy: pistol (250 $).", buyPistol),
                std::make_pair("'I have made up my mind.'", zedTrade_1)
                });
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

    if (Hero::heroes["Hero"].getMoney() != 250.0)
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

            Hero::heroes["Hero"].addItem(&Item::items["Pistol"]);
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
            Hero::heroes["Hero"].addQuest(&Quest::quests["ZedAccelerator"]);
        }
    }
    else
    {
        Display::writeDialogue("\n\t- 'A pistol is a good start. Here, it's yours.'");

        Hero::heroes["Hero"].addItem(&Item::items["Pistol"]);
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
