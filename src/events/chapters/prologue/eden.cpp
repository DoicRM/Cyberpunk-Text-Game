// ************************************************************
// 		NIGHTCLUB 'EDEN'
// ************************************************************

#include "../../events.hpp"

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

    Menu menu11({
        std::make_pair("Go to the dance floor.", clubDanceFloor),
        std::make_pair("Go to the bar.", clubBar),
        std::make_pair("Go upstairs.", clubUpstairs),
        std::make_pair("Back on the street.", visitStreet)
        });
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

        Menu menu12({
            std::make_pair("'What do you want?'", clubDanceFloor_1),
            std::make_pair("'Hey, baby.'", clubDanceFloor_2),
            std::make_pair("Keep dancing with no words.", clubDanceFloor_3)
            });

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
        Menu menu13({
            std::make_pair("'Give me anything.'", clubBar_1),
            std::make_pair("'Who's in charge?'", clubBar_2),
            std::make_pair("'Bye.'", clubBar_3)
            });

        if (menu13.getChoice() <= menu13.getOptionsSize() && menu13.getChoice() > 0)
        {
            break;
        }
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

    Menu menu14({
        std::make_pair("'What is it about?'", miaMeeting_1),
        std::make_pair("Be silent and let her speak.", miaMeeting_2)
        });

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

    Menu menu15({
        std::make_pair("Come closer.", clubUpstairs_1),
        std::make_pair("Go back downstairs.", clubUpstairs_2)
        });
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
        menu16.inputChoice();

        if (menu16.getChoice() <= menu16.getOptionsSize() && menu16.getChoice() > 0)
        {
            break;
        }
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
    // TODO: add description of killing Jet!
    vincentOffice();
}

void Event::dialogueWithJet_4()
{
    // TODO: add description of Jet's stun!
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

    Menu menu17({
        std::make_pair("Open the door and go into the other room.", vincentHideoutCode),
        std::make_pair("Stay and search the office.", checkVincentDesk)
        });
}

void Event::checkVincentDesk()
{
    Logger::startFuncLog(__FUNCTION__);
    heroKnowsVincentCode = true;
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

        Menu menu18({
            std::make_pair("Use code '2021'.", nullptr),
            std::make_pair("Search the office.", nullptr)
            });
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

    Menu menu19({
        std::make_pair("Disconnect his consciousness from the neuronet. (Kill him)", vincentHideout_1),
        std::make_pair("Wait for his consciousness to leave the neuronet.", vincentHideout_2)
        });
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

    Menu menu20({
        std::make_pair("'Die!'", dialogueWithVincent_1),
        std::make_pair("'I don't want to fight with you.'", dialogueWithVincent_2),
        std::make_pair("'Nyx wants you dead.'", dialogueWithVincent_3)
        });

    std::cout << std::endl << std::endl;

    Menu menu21({
        std::make_pair("'It doesn't matter.'", dialogueWithVincent_4),
        std::make_pair("'Your girlfriend, Nyx.'", dialogueWithVincent_5)
        });

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

    Menu menu22({
        std::make_pair("Do nothing.", dialogueWithVincent_6),
        std::make_pair("'What is this all about?'", dialogueWithVincent_7)
        });

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

    Menu menu23({
        std::make_pair("Go to the dance floor.", clubDanceFloor),
        std::make_pair("Go to the bar.", clubBar),
        std::make_pair("Go upstairs.", clubUpstairs),
        std::make_pair("Back on the street.", visitStreet)
        });
}