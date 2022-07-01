// ************************************************************
// 		RANDOM EVENTS
// ************************************************************

#include "../../events.hpp"

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
    Display::writeNarration(jWriter["prologue"]["hookersMeeting"][0]);
    Console::wait(500);
    Display::writeNarration(jWriter["prologue"]["hookersMeeting"][1]);
    Console::wait(650);
    Display::writeNarration(jWriter["prologue"]["hookersMeeting"][2]);
    Console::wait(500);
    Display::writeNarration(jWriter["prologue"]["hookersMeeting"][3]);
    Console::wait(800);
    Display::writeNarration(jWriter["prologue"]["hookersMeeting"][4]);
    Console::wait(1000);
    Display::writeDialogue(jWriter["prologue"]["hookersMeeting"][5]);
    Display::writeNarration(jWriter["prologue"]["hookersMeeting"][6]);

    Menu hookersMeetingMenu({
        std::make_pair(jWriter["prologue"]["hookersMeetingMenu"][0], nullptr),
        std::make_pair(jWriter["prologue"]["hookersMeetingMenu"][1], nullptr),
        std::make_pair(jWriter["prologue"]["hookersMeetingMenu"][2], nullptr)
    });
}

void RandomEvent::punksMeeting()
{
    // TODO
}

void RandomEvent::clubOverdose()
{
    // TODO
}