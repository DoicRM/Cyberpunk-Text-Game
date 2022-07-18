// ************************************************************
// 		STREET in front of the nightclub 'Eden'
// ************************************************************

#include "Prologue.hpp"

void Event::lookAtEden()
{
    Logger::startFuncLog(__FUNCTION__);

    if (!Npc::npcs["Bob"].knowsHero())
    {
        Display::writeNarration(json["prologue"]["lookAtEden"][0]);
        Console::wait(1000);
        Display::writeNarration(json["prologue"]["lookAtEden"][1]);
        Console::wait(1500);
        Display::writeNarration(json["prologue"]["lookAtEden"][2]);
    }
    else {
        Display::writeNarration(json["prologue"]["lookAtEden"][3]);
        Display::writeNarration(json["prologue"]["lookAtEden"][4]);
        Console::wait(1500);
        Display::writeNarration(json["prologue"]["lookAtEden"][5]);
    }

    Menu menu4({
        std::make_pair(json["prologue"]["menu4"][0], lookAtEden_1),
        std::make_pair(json["prologue"]["menu4"][1], lookAtEden_2)
        });
}

void Event::lookAtEden_1()
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

void Event::lookAtEden_2()
{
    Logger::startFuncLog(__FUNCTION__);
    Game::game[0].setCurrentLocation(&Location::locations["GunShop"]);
}

void Event::encounterGunStore()
{
    Logger::startFuncLog(__FUNCTION__);
    Display::writeNarration(json["prologue"]["encounterGunStore"][0]);

    if (bobRecommendsZed)
    {
        Display::writeNarration(json["prologue"]["encounterGunStore"][1]);
    }

    int rand = Utilities::randInt(0, 20);

    if (rand > 10 && rand <= 15)
    {
        RandomEvent::hookersMeeting();
    }
    else if (rand > 15 && rand <= 20)
    {
        std::cout << std::endl;
        RandomEvent::punksMeeting();
    }

    std::cout << std::endl << std::endl;

    Menu menu5({
        std::make_pair(json["prologue"]["menu5"][0], enterGunShop),
        std::make_pair(json["prologue"]["menu4"][1], encounterGunStore_1)
        });
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

    if (Hero::heroes["Hero"].hasItem(&Item::items["AD13"])) {
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
        Display::writeDialogue("\t- '" + Npc::npcs["Hero"].getName() + "...");
        Console::wait(1000);
        Display::writeDialogue(" Caden, check it out in the database.");
    }
    else {
        Display::writeDialogue(" " + Npc::npcs["Hero"].getName() + "...");
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

    Menu menu6({
        std::make_pair(json["prologue"]["menu6"][0], meetingWithPolicemans_1),
        std::make_pair(json["prologue"]["menu6"][1], meetingWithPolicemans_2)
        });
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

    Menu menu7({
        std::make_pair((std::string)json["main"]["visit"] + Location::locations["DarkAlley"].getName() + ".", visitDarkAlley),
        std::make_pair((std::string)json["main"]["visit"] + Location::locations["Nightclub"].getName() + ".", visitNightclub),
        std::make_pair((std::string)json["main"]["visit"] + Location::locations["GunShop"].getName() + ".", visitGunShop)
        });
}
