// ************************************************************
// 		RANDOM EVENTS
// ************************************************************

#include "Prologue.hpp"

void RandomEvent::downpourStart()
{
    Game::game[0].setWeather(Weather::Rainy);

    if (Game::game[0].getWeather() == Weather::Rainy)
    {
        Display::writeNarration(json["prologue"]["downpourStart"][0]);
        Console::wait(1000);
        Display::writeNarration(json["prologue"]["downpourStart"][1]);
        Console::wait(500);
        Display::writeNarration(json["prologue"]["downpourStart"][2]);
    }
}

void RandomEvent::nickHandFinding()
{
    Display::writeNarration(json["prologue"]["findingNicksHand"][0]);
    Console::wait(500);
    Display::writeNarration(json["prologue"]["findingNicksHand"][1]);
    Console::wait(1000);
    Display::writeNarration(json["prologue"]["findingNicksHand"][2]);
    Console::wait(500);
    Display::writeNarration(json["prologue"]["findingNicksHand"][3]);
    Console::wait(250);
    Display::writeNarration(json["prologue"]["findingNicksHand"][4]);
    Console::wait(500);
    Display::writeNarration(json["prologue"]["findingNicksHand"][5]);
    Console::wait(250);
    Display::writeNarration(json["prologue"]["findingNicksHand"][6]);
}

void RandomEvent::hookersMeeting()
{
    Display::writeNarration(json["prologue"]["hookersMeeting"][0]);
    Console::wait(500);
    Display::writeNarration(json["prologue"]["hookersMeeting"][1]);
    Console::wait(650);
    Display::writeNarration(json["prologue"]["hookersMeeting"][2]);
    Console::wait(500);
    Display::writeNarration(json["prologue"]["hookersMeeting"][3]);
    Console::wait(800);
    Display::writeNarration(json["prologue"]["hookersMeeting"][4]);
    Console::wait(1000);
    Display::writeDialogue(json["prologue"]["hookersMeeting"][5]);
    Display::writeNarration(json["prologue"]["hookersMeeting"][6]);

    Menu hookersMeetingMenu({
        std::make_pair(json["prologue"]["hookersMeetingMenu"][0], nullptr),
        std::make_pair(json["prologue"]["hookersMeetingMenu"][1], nullptr),
        std::make_pair(json["prologue"]["hookersMeetingMenu"][2], nullptr)
        });
}

void RandomEvent::punksMeeting()
{
    Display::writeNarration(json["prologue"]["punksMeeting"][0]);
    Display::writeNarration("");
}

void RandomEvent::clubOverdose()
{
    Display::writeNarration("");
}
