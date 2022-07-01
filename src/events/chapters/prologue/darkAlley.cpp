// ************************************************************
// 		DARK ALLEY in 'Eden' nigthclub area
// ************************************************************

#include "prologue.hpp"

bool bobRecommendsZed       = false,
     zedKnowsAboutBobAndZed = false,
     heroIsOnDanceFloor     = false,
     heroIsAtBar            = false,
     heroKnowsVincentCode   = false;

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

    Menu menu1({
        std::make_pair(jWriter["prologue"]["menu1"][0], rubbishSearch),
        std::make_pair(jWriter["prologue"]["menu1"][1], outOfAlley)
        });
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

    Menu menu2({
        std::make_pair(jWriter["prologue"]["menu2"][0], outOfAlley_1),
        std::make_pair(jWriter["prologue"]["menu2"][1], outOfAlley_2)
        });
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
        Menu nameMenu({
            std::make_pair(jWriter["prologue"]["nameMenu"][0], dialogueWithBob_1),
            std::make_pair(jWriter["prologue"]["nameMenu"][1], dialogueWithBob_2)
            });

        Menu menu3({
            std::make_pair(jWriter["prologue"]["menu3"][0], dialogueWithBob_3),
            std::make_pair(jWriter["prologue"]["menu3"][1], dialogueWithBob_4),
            std::make_pair(jWriter["prologue"]["menu3"][2], dialogueWithBob_5)
            });

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
    std::cout << std::endl;
    Npc::npcs["Bob"].setAttitude(Attitude::Angry); // Angry / Hostile / Friendly / Neutral
    Console::wait(500);
    Display::writeDialogue(jWriter["prologue"]["dialogueWithBob"][8]);
}

void Event::dialogueWithBob_3()
{
    bobRecommendsZed = true; // Bob recommends Zed's gun shop to the hero
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
    std::cout << std::endl;
    Npc::npcs["Bob"].setAttitude(Attitude::Angry); // Angry / Hostile / Friendly / Neutral
    Console::wait(500);
    Display::writeDialogue(jWriter["prologue"]["dialogueWithBob"][17]);
}

void Event::aboutParadiseLost()
{
    std::cout << std::endl;

    Menu paradiseLostMenu({
        std::make_pair(jWriter["prologue"]["paradiseLostMenu"][0], aboutParadiseLost_1),
        std::make_pair(jWriter["prologue"]["paradiseLostMenu"][1], aboutParadiseLost_2)
        });
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
        Display::writeNarration(jWriter["prologue"]["darkAlleyCrossroads"][0]);
        Display::writeDialogue(jWriter["prologue"]["darkAlleyCrossroads"][1]);

        Menu menu2({
            std::make_pair(jWriter["prologue"]["menu2"][2], outOfAlley_1),
            std::make_pair(jWriter["prologue"]["menu2"][1], outOfAlley_2)
            });
    }
    else
    {
        Display::writeNarration(jWriter["prologue"]["darkAlleyCrossroads"][2]);
        Console::wait(1000);
        Display::writeNarration(jWriter["prologue"]["wakeUp"][7]);

        if (!Hero::heroes[0].hasItem(&Item::items["AD13"]))
        {
            Console::wait(1500);
            Display::writeNarration(jWriter["prologue"]["wakeUp"][8]);

            Menu menu1({
                std::make_pair(jWriter["prologue"]["menu1"][0], darkAlleyCrossroads_1),
                std::make_pair(jWriter["prologue"]["menu1"][1], darkAlleyCrossroads_2)
                });
        }
        else
        {
            Display::writeNarration(jWriter["prologue"]["darkAlleyCrossroads"][3]);
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
    Display::writeNarration(jWriter["prologue"]["darkAlleyCrossroads"][3]);
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