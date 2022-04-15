#include "../events.hpp"

int heroChoice = 0;
bool bobRecommendsZed = false, zedKnowsAboutBobAndZed = false, heroIsOnDanceFloor = false, heroIsAtBar = false, heroKnowsVincentCode = false;

// MROCZNY ZAU£EK
void Event::prologue()
{
    Logger::out("Function starts", "Event::prologue");

    if (Game::game[0].getLang() == EN) Output::write("\n\tPrologue");
    else Output::write("\n\tProlog");

    Sleep(2000);

    if (Game::game[0].getLang() == EN) Output::write("\n\n\tREQUIEM FOR A DREAM");
    else Output::write("\n\n\tREQUIEM DLA MARZEÑ");

    Sleep(5000);
    Console::clearScreen();
    storyIntroduction();
}

void Event::storyIntroduction()
{
    Logger::out("Function starts", "Event::storyIntroduction");

    if (Game::game[0].getLang() == EN)
    {
        Output::writeNarration("\n\tIt's 2050.");
        Sleep(1000);
        Output::writeNarration(" Megacity is a place overrun by poverty and feuding gangs, where powerful\n\tcorporations have the most influence. The violence in the streets is a clear sign of\n\tan impending war. Government operating from behind the secure walls of City Hall are\n\ttrying to combat this, but so far without success. There are rumors that they themselves\n\tare secretly supporting the chaos to create a New Order on the ruins of the city.\n\n", 20);
        Game::pause();
        Console::clearScreen();
        Sleep(2500);
        Output::writeDialogue("\n\tStanding at the edge of the tallest tower...", 75);
        Sleep(2500);
        Output::writeDialogue("\n\tHolding your hand and dive...", 75);
        Sleep(2500);
        Output::writeDialogue("\n\tFalling and falling for what feels like hours...", 75);
        Sleep(3000);
        Console::clearScreen();
        wakeUpInDarkAlley();
    }
    else {
        Output::writeNarration("\n\tJest rok 2050.");
        Sleep(1000);
        Output::writeNarration(" Megacity to miejsce opanowane przez biedê i zwaœnione gangi, gdzie najwiêksze\n\twp³ywy maj¹ potê¿ne korporacje. Przemoc na ulicach jest wyraŸnym znakiem zbli¿aj¹cej siê wojny.\n\tRz¹d dzia³aj¹cy zza bezpiecznych murów ratusza próbuje z tym walczyæ, ale jak na razie\n\tbezskutecznie. Kr¹¿¹ plotki, ¿e sam potajemnie wspiera chaos, by na gruzach miasta stworzyæ\n\tNowy Porz¹dek.\n\n", 20);
        Game::pause();
        Console::clearScreen();
        Sleep(2500);
        Output::writeDialogue("\n\tStoj¹c na krawêdzi najwy¿szej wie¿y...", 75);
        Sleep(2500);
        Output::writeDialogue("\n\tTrzymam ciê za rêkê i skaczê...", 75);
        Sleep(2500);
        Output::writeDialogue("\n\tSpadam i spadam jakby godzinami...", 75);
        Sleep(3000);
        Console::clearScreen();
        std::cout << std::endl;
        wakeUpInDarkAlley();
    }
}

void Event::wakeUpInDarkAlley()
{
    Logger::out("Function starts", "Event::wakeUpInDarkAlley");
    Menu menu1;

    if (Game::game[0].getLang() == EN)
    {
        Sleep(2000);
        Output::writeNarration("\n\tYou wake up dazed from a restless slumber.");
        Sleep(1000);
        Output::writeNarration(" It was the same dream again...");
        Sleep(1500);
        Output::writeNarration("\n\tYou are somewhere in a dark alley. Above your head, among the smoggy haze, as if torn from\n\ta dream, rise the monumental skyscrapers of large corporations.");
        Sleep(1000);
        Output::writeNarration(" Their divine majesty beats\n\tyou to the eyes.");
        Sleep(3000);
        Output::writeNarration("\n\tYour heart beats so hard that only the stinging touch of the wind protects you from a sudden\n\theart attack.");
        Sleep(500);
        Output::writeNarration(" Suddenly a wave of shivers comes over your body, you start shaking like an\n\taspen, and realize that you are lying on a lair made of some old newspapers.");
        Sleep(3000);
        Output::writeNarration("\n\tWhen you rise from the ground, you notice a sea of trash around you.");
        Sleep(1000);
        Output::writeNarration(" It's full of cardboard\n\tboxes, old mechanical parts, and god knows what else.");
        Sleep(2500);
        Output::writeNarration("\n\tMaybe you will find something interesting there...\n\n");
        //--------------------------------
        menu1.clearOptions();
        menu1.addOption("Search the area for something valuable.");
        menu1.addOption("Find the exit from the alley.");
        menu1.showOptions();
        //--------------------------------
    }
    else {
        Output::writeNarration("\n\tBudzisz siê oszo³omiony z niespokojnej drzemki.");
        Sleep(1000);
        Output::writeNarration(" To by³ znowu ten sam sen...");
        Sleep(1500);
        Output::writeNarration("\n\tZnajdujesz siê gdzieœ w ciemnym zau³ku. Nad twoj¹ g³ow¹, wœród smogowej mg³y, niczym wyrwane\n\tze snu, wznosz¹ siê monumentalne drapacze chmur wielkich korporacji.");
        Sleep(1000);
        Output::writeNarration(" Ich boski majestat bije\n\tciê po oczach.");
        Sleep(2500);
        Output::writeNarration("\n\tSerce bije ci tak mocno, ¿e tylko szczypi¹cy dotyk wiatru chroni ciê przed nag³ym atakiem\n\tserca.");
        Sleep(500);
        Output::writeNarration(" Nagle przez twoje cia³o przechodzi fala dreszczy, zaczynasz trz¹œæ siê jak osika i\n\tuœwiadamiasz sobie, ¿e le¿ysz na legowisku zrobionym ze starych gazet.");
        Sleep(2000);
        Output::writeNarration("\n\tKiedy podnosisz siê z ziemi, zauwa¿asz wokó³ siebie morze œmieci.");
        Sleep(1000);
        Output::writeNarration(" Jest pe³ne kartonów, starych\n\tczêœci mechanicznych i Bóg wie czego jeszcze.");
        Sleep(1500);
        Output::writeNarration("\n\tMo¿e znajdziesz tam coœ interesuj¹cego...\n\n");
        //--------------------------------
        menu1.clearOptions();
        menu1.addOption("Rozejrzyj siê po okolicy w poszukiwaniu czegoœ cennego.");
        menu1.addOption("ZnajdŸ wyjœcie z zau³ka.");
        menu1.showOptions();
        //--------------------------------
    }

    while (true)
    {
        heroChoice = menu1.getChoice();

        if (heroChoice == 1)
        {
            Sleep(1000);
            Console::clearScreen();
            rubbishSearch();
            break;
        }
        else if (heroChoice == 2)
        {
            Sleep(1000);
            Console::clearScreen();
            outOfTheAlley();
            break;
        }
        else Logger::error("Entered invalid value of <b>heroChoice</b>", "Event::wakeUpInDarkAlley"); continue;
    }
}

void Event::acceleratorFinding()
{
    Logger::out("Function starts", "Event::acceleratorFinding");
    Output::writeNarration("\n\tYou start rummaging through the trash.");
    Sleep(1500);
    Output::writeNarration(" The search takes a long while, but eventually you\n\tmanage to find something.");
    Sleep(2000);

    Hero::heroes[0].addItem(&Item::items["AD13"]);
    Console::setConsoleColor(CC_Item);
    Output::write("\n\n\t" + Item::items["AD13"].getName());
    Console::resetConsoleColor();
    Output::write(" was found.");

    if (Hero::heroes[0].hasItem(&Item::items["AD13"])) Logger::out(Item::items["AD13"].getName() + " added to EQ", "Event::acceleratorFinding");
    else Logger::error(Item::items["AD13"].getName() + " not added to EQ", "Event::accelelatorFinding");

    Output::write("\n\t[TIP: This item has been added to your inventory. You can view it in the text file in your\n\tgame folder.]", 15);
    Sleep(4000);
    Output::writeNarration("\n\n\tHmm, that might come in handy in the future.");
    Sleep(1000);
}

void Event::rubbishSearch()
{
    Logger::out("Function starts", "Event::rubbishSearch");
    Menu::showHeroAction("Search the area for something valuable.");
    acceleratorFinding();
    outOfTheAlley();
}

void Event::outOfTheAlley()
{
    Logger::out("Function starts", "Event::outOfTheAlley");

    if (!Hero::heroes[0].hasItem(&Item::items["AD13"]))
    {
        Menu::showHeroAction("Find the exit from the alley.");
        Output::writeNarration("\n\tYou're not going to rummage through the trash.");
        Sleep(1500);
        Output::writeNarration(" And that's okay, you probably wouldn't find\n\tanything there anyway.");
        Output::writeNarration(" Instead, you slowly toddle toward the neon color bombs at the end of\n\tthe alley.");
    }
    else Output::writeNarration("\n\tYou slowly toddle toward the neon color bombs at the end of the alley.");

    Sleep(3000);
    Output::writeNarration("\n\tYou are getting closer and closer to your goal when from the right, from behind a veil of\n\tshadows, a low, not very pleasant voice belonging to a man speaks up.");
    Output::writeDialogue("\n\t- 'Hey, kid. Wait for a second.'\n\n");
    //--------------------------------
    Menu menu2;
    menu2.clearOptions();
    menu2.addOption("Stop and find out what he wants.");
    menu2.addOption("Ignore him and keep walking.");
    menu2.showOptions();
    //--------------------------------
    while (true)
    {
        heroChoice = menu2.getChoice();

        if (heroChoice == 1)
        {
            Console::clearScreen();
            Menu::showHeroAction("Stop and find out what he wants.");
            Output::writeNarration("\n\tYou stop and turn towards the owner of the voice.");
            Sleep(1500);
            Output::writeNarration(" His silhouette looms in the darkness. It's\n\tone of the homeless people who live here. What can he have for you?\n");
            Sleep(1000);
            dialogueWithBob();
            break;
        }
        else if (heroChoice == 2)
        {
            Console::clearScreen();
            Menu::showHeroAction("Ignore him and keep walking.");
            Output::writeNarration("\n\tYou have a mysterious stranger for nothing. You speed up your step and leave him far behind you.");
            Output::writeDialogue("\n\t- 'Hey, you! Come back here!'");
            Output::writeNarration("\n\tWhatever he wanted from you is no longer important.");
            Sleep(1000);
            Game::game[0].setCurrentLocation(&Location::locations["Street"]);
            break;
        }
        else Logger::error("Entered invalid value of <b>heroChoice</b>", "Event::outOfTheAlley"); continue;
    }
}

void Event::dialogueWithBob()
{
    Logger::out("Function starts", "Event::dialogueWithBob");
    Output::writeDialogue("\t- 'What's your name, boy?'");

    if (!Npc::npcs["Bob"].knowsHero() && !Npc::npcs["Caden"].knowsHero() && !Npc::npcs["CadenPartner"].knowsHero()) namingHero();
    else std::cout << std::endl;

    Npc::npcs["Bob"].setToKnowHero();
    Output::writeDialogue("\t- 'So you're " + Hero::heroes[0].getName() + ", huh?");
    Sleep(1500);
    Output::writeDialogue(" All right. I'm " + Npc::npcs["Bob"].getName() + ".");
    Sleep(1500);
    Output::writeDialogue(" What are you doin' here?'");
    Output::writeNarration("\n\tThe shadows in front of you, begin to ripple when your caller stands up.\n\n");
    //--------------------------------
    Menu menu3;
    menu3.clearOptions();
    menu3.addOption("'I'm not looking for trouble.'");
    menu3.addOption("'I'm just looking around. Where are we actually?'");
    menu3.addOption("'It's not your business.'");
    menu3.showOptions();
    //--------------------------------
    while (true)
    {
        heroChoice = menu3.getChoice();

        if (heroChoice == 1)
        {
            Console::clearScreen();
            Menu::showHeroAction("'I'm not looking for trouble.'");
            bobRecommendsZed = true; // Bob poleca bohaterowi sklep z broni¹ Zeda
            Output::writeDialogue("\n\t- 'Ha-ha, that's what I thought. To tell you the truth, you don't look very threatening.");
            Sleep(1000);
            Output::writeDialogue(" Well,\n\tyou could use some gat. I happen to know a guy who deals guns. His name is Zed, and his store is\n\tright around the corner.");
            Sleep(1000);
            Output::writeDialogue(" Tell him you're coming from old Bob and he'll find something for you.'\n");
            break;
        }
        else if (heroChoice == 2)
        {
            Console::clearScreen();
            Menu::showHeroAction("'I'm just looking around. Where are we actually?'");
            Output::writeDialogue("\n\t- 'What's wrong with you?");
            Sleep(1000);
            Output::writeDialogue(" Anyway, it doesn't matter.");
            Sleep(1500);
            Output::writeDialogue(" Have you ever heard of Megacity?");
            Sleep(1500);
            Output::writeDialogue(" Well,\n\tit's right here. The neighborhood we are currently in is called Gunce Deep.");
            Sleep(1000);
            Output::writeDialogue(" Did I make your\n\thead clearer?'\n");
            break;
        }
        else if (heroChoice == 3)
        {
            Console::clearScreen();
            Menu::showHeroAction("'It's not your business.'\n");
            Npc::npcs["Bob"].setAttitude(Angry); // angry / hostile / friendly / neutral
            Output::writeDialogue("\t- 'You're wrong. It's absolutely my business, kid. Don't shut your mouth like that, or you might\n\tlose a few teeth. Got it?'\n");
            break;
        }
        else Logger::error("Entered invalid value of <b>heroChoice</b>", "Event::outOfTheAlley"); continue;
    }

    if (!streetWasVisited)
    {
        Output::writeNarration("\tFinally, an old, wrinkled face surrounded by gray fuzz emerges from the darkness. An artificial,\n\tcybernetic eye watches you vigilantly.");
        Sleep(1000);
        Output::writeNarration(" You start to feel strangely uncomfortable.");
        Sleep(2000);
        Output::writeNarration("\n\tIn an instant the alley is filled with the howling of a police siren.");
        Sleep(1000);
        Output::writeNarration(" On the wall in front of\n\tyou, red and blue begin to dance with each other.");
        Output::writeDialogue("\n\t- 'Shit");
        Sleep(500);
        Output::writeDialogue(", cops!");
        Sleep(500);
        Output::writeDialogue(" Well, that's super. I think it's time for me to go.'");
        Sleep(1500);
        Output::writeNarration("\n\tThe aging beggar dives into the embrace of darkness in a flash.");
        Sleep(1500);
        Output::writeNarration(" Does this mean you see him for\n\tthe last time?");
        Sleep(3500);
        Game::game[0].setCurrentLocation(&Location::locations["Street"]);
    }
    else {
        Output::writeDialogue("\t - 'All right, that is enough.");
        Sleep(1500);
        Output::writeDialogue("I saw the cops hanging around. It stopped\n\tbeing safe here, at least for me.");

        if (Npc::npcs["Bob"].getAttitude() == Angry || Npc::npcs["Bob"].getAttitude() == Hostile) Output::writeDialogue(" Be glad we don't have more of it left.'");
        else Output::writeDialogue(" Take care, kid.'");

        Sleep(1500);
        Output::writeNarration("\n\tThe aging beggar dives into the embrace of darkness in a flash.");
        Sleep(1500);
        Output::writeNarration(" Does this mean you see him for\n\tthe last time?\n\n");
        Game::pause();
        Game::game[0].setCurrentLocation(&Location::locations["Street"]);
    }
}

void Event::darkAlleyCrossroads()
{
    Logger::out("Function starts", "Event::darkAlleyCrossroads");
    Menu::showHeroAction("Visit: " + Location::locations["DarkAlley"].getName() + ".\n");

    if (!Npc::npcs["Bob"].knowsHero())
    {
        Output::writeNarration("\tWhen you enter the alley, you hear a familiar voice.");
        Output::writeDialogue("\n\t- 'It's you again. Why don't you tell me something for one this time?'\n\n");
        //--------------------------------
        Menu menu2;
        menu2.clearOptions();
        menu2.addOption("Stop and finally find out what he wants.");
        menu2.addOption("Ignore him and keep walking.");
        menu2.showOptions();
        //--------------------------------
        while (true)
        {
            heroChoice = Input::getChoice();

            if (heroChoice == 1)
            {
                Console::clearScreen();
                Menu::showHeroAction("Stop and finally find out what he wants.");
                Output::writeNarration("\n\tYou stop and turn towards the owner of the voice.");
                Sleep(1500);
                Output::writeNarration(" His silhouette looms in the darkness. It's one of the homeless people who live here. What can he have for you?\n");
                dialogueWithBob();
                break;
            }
            else if (heroChoice == 2)
            {
                Console::clearScreen();
                Menu::showHeroAction("Ignore him again.");
                Output::writeNarration("\n\tYou have a mysterious stranger for nothing. You speed up your step and leave him far behind\n\tyou. Whatever he wanted from you is no longer important.");
                Output::writeDialogue("\n\t- 'Don't show up here again if you don't want to get your teeth kicked in!'\n");
                Console::clearScreen();
                Game::game[0].setCurrentLocation(&Location::locations["Street"]);
                break;
            }
            else Logger::error("Entered invalid value of <b>heroChoice</b>", "Event::darkAlleyCrossroads"); continue;
        }
    }
    else
    {
        Output::writeNarration("\tWhen you enter an alley, you notice a sea of trash around you.");
        Sleep(1000);
        Output::writeNarration(" It's full of cardboard boxes,\n\told mechanical parts, and god knows what else.");

        if (!Hero::heroes[0].hasItem(&Item::items["AD13"]))
        {
            Sleep(1500);
            Output::writeNarration("\n\tMaybe you will find something interesting there...\n\n");
            //--------------------------------
            Menu menu1;
            menu1.clearOptions();
            menu1.addOption("Search the area for something valuable.");
            menu1.addOption("Go out of the alley.");
            menu1.showOptions();
            //--------------------------------
            while (true)
            {
                heroChoice = menu1.getChoice();

                if (heroChoice == 1)
                {
                    Sleep(1000);
                    acceleratorFinding();
                    Output::writeNarration("\n\tThere is nothing interesting here any more. Time to go back...\n");
                    Console::clearScreen();
                    Game::game[0].setCurrentLocation(&Location::locations["Street"]);
                    break;
                }
                else if (heroChoice == 2)
                {
                    std::cout << std::endl;
                    Console::clearScreen();
                    Game::game[0].setCurrentLocation(&Location::locations["Street"]);
                    break;
                }
                else Logger::error("Entered invalid value of <b>heroChoice</b>", "Event::darkAlleyCrossroads"); continue;
            }
        }
        else
        {
            Output::writeNarration("\n\tThere is nothing interesting here. Time to go back...\n\n");
            Game::pause();
            Console::clearScreen();
            Game::game[0].setCurrentLocation(&Location::locations["Street"]);
        }
    }
}

// ULICA
void Event::lookAtAmnesia()
{
    Logger::out("Function starts", "Event::lookAtAmnesia");

    if (!Npc::npcs["Bob"].knowsHero())
    {
        Output::writeNarration("\n\tYou walk out of the alley onto a street lit by neon lights on the opposite side. A large sign\n\tthat reads 'Amnesia' belongs to a nightclub.");
        Sleep(1000);
        Output::writeNarration(" A small crowd gathers outside the entrance to the\n\tbuilding. Some people are arguing with the bouncers.");
        Sleep(1500);
        Output::writeNarration(" Something smells here, it's probably trouble...\n\n");
    }
    else {
        Output::writeNarration("\n\tYou walk out of the alley onto a street lit by neon lights and the lamp of a police car on the\n\topposite side. A large sign that reads 'Amnesia' belongs to a nightclub.");
        Output::writeNarration(" Two cops interrogate\n\ta small crowd outside the entrance to the building.");
        Sleep(1500);
        Output::writeNarration(" Something smells here, it's probably trouble...\n\n");
    }
    //--------------------------------
    Menu menu4;
    menu4.clearOptions();
    menu4.addOption("Come closer and see what it's all about.");
    menu4.addOption("Take a look around the area.");
    menu4.showOptions();
    //--------------------------------
    while (true)
    {
        heroChoice = menu4.getChoice();

        if (heroChoice == 1)
        {
            Console::clearScreen();
            Menu::showHeroAction("Come closer and see what it's all about.\n");

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
            Menu::showHeroAction("Take a look around the area.");
            Game::game[0].setCurrentLocation(&Location::locations["GunShop"]);
            break;
        }
        else Logger::error("Entered invalid value of <b>heroChoice</b>", "Event::lookAtAmnesia"); continue;
    }
}

void Event::encounterGunStore()
{
    Logger::out("Function starts", "Event::encounterGunStore");
    Output::writeNarration("\n\tYou go to the right side of the street. After walking several meters you come across a small\n\tbooth between blocks of flats.");

    if (bobRecommendsZed) Output::writeNarration(" Could it be that the famous gun store managed by Bob's friend?");

    std::cout << std::endl << std::endl;
    //--------------------------------
    Menu menu5;
    menu5.clearOptions();
    menu5.addOption("Go inside.");
    menu5.addOption("Turn back.");
    menu5.showOptions();
    //--------------------------------
    while (true)
    {
        heroChoice = menu5.getChoice();

        if (heroChoice == 1)
        {
            Console::clearScreen();
            Menu::showHeroAction("Go inside.\n");
            enterGunShop();
            break;
        }
        else if (heroChoice == 2)
        {
            Console::clearScreen();
            Menu::showHeroAction("Turn back.\n");

            if (!Npc::npcs["Bob"].knowsHero())
            {
                meetingWithSecurityGuards();
                meetingWithPolicemans();
            }
            else meetingWithPolicemans();

            break;
        }
        else Logger::error("Entered invalid value of <b>heroChoice</b>", "Event::encounterGunStore"); continue;
    }
}

void Event::meetingWithSecurityGuards()
{
    Logger::out("Function starts", "Event::meetingWithSecurityGuards");
    Output::writeNarration("\tWhen you get closer, the faces turn toward you and start looking at you intently.");
    Sleep(1000);
    Output::writeNarration(" You pass\n\tthem in silenceand are confronted by a broad -\n\tshouldered security guard.");
    Output::writeDialogue("\n\t- 'What are you looking for here?");
    Sleep(1500);
    Output::writeDialogue(" Trouble, maybe?'");
    Output::writeNarration("\n\tThe man clenches his hands into fists and smiles unpleasantly.");
    Output::writeDialogue("\n\t- 'You asshole, better let us in! I want a drink and for fuck's sake. I'm losing my patience!");
    Output::writeNarration("\n\tOne of the men waiting in the queue rushes forward and threatens the bouncer with his fist.");
    Sleep(1500);
    Output::writeNarration("\n\tThe security guard's attention shifts from you to the furious guy next to you.");
    Output::writeDialogue("\n\t- 'I'll say it one last time: get the fuck out of here or you'll get fucked.'\n");
}

void Event::meetingWithPolicemans()
{
    Logger::out("Function starts", "Event::meetingWithPolicemans");

    if (Npc::npcs["Bob"].knowsHero()) Output::writeNarration("\tWhen you get closer, one of the police officers in a dark blue uniform turns toward you.");
    else {
        Output::writeNarration("\tIn an instant the street is filled with the howling of a police siren.");
        Sleep(1000);
        Output::writeNarration(" The reds and blues\n\tbegin to dance with each other on the sidewalk and the silhouettes of the people around you.");
        Sleep(2000);
        Output::writeNarration("\n\tTwo grim-looking guys in dark blue uniforms get out of a police car and walk towards you.\n\tOne of them points at you, taking out a tablet from behind his belt.");
    }

    Output::writeDialogue("\n\t- 'Who are you?");
    Sleep(1500);
    Output::writeDialogue(" And what are you doing here? Please show me your ID card.'");

    if (Hero::heroes[0].hasItem(&Item::items["AD13"])) Output::writeNarration("\n\tYou start searching through the pockets of your jacket and pants, but other than the accelerator\n\tyou found in the trash, there's nothing else there.");
    else Output::writeNarration("\n\tYou start searching through the pockets of your jacket and pants, but there's nothing there.");

    Output::writeDialogue("\n\t- 'I see that we have a problem.");
    Sleep(1500);
    Output::writeDialogue(" Okay, then what's your name, citizen?");

    if (!Npc::npcs["Bob"].knowsHero())
    {
        Output::writeDialogue("'\n");
        namingHero();
        Sleep(1500);
        Output::writeDialogue("\t- '" + Hero::heroes[0].getName() + "...");
        Sleep(1000);
        Output::writeDialogue(" Caden, check it out in the database.");
    }
    else {
        Output::writeDialogue(" " + Hero::heroes[0].getName() + "...");
        Sleep(1000);
        Output::writeDialogue(" Caden, check\n\tit out in the database.");
    }

    Npc::npcs["CadenPartner"].setToKnowHero();
    Npc::npcs["Caden"].setToKnowHero();
    Sleep(1500);
    Output::writeDialogue(" And you, stand where you are.'");
    Output::writeNarration("\n\tThe other police officer nods, gets back in the car, and it looks like he's connecting with\n\theadquarters.");
    Sleep(3000);
    Output::writeNarration("\n\tA minute later, the same policeman returns and whispers something in his partner's ear.");
    Sleep(1500);
    Output::writeNarration(" That\n\tone nods and turns to look at you.");
    Output::writeDialogue("\n\t- 'I have good news for you.");
    Sleep(1500);
    Output::writeDialogue(" You're free for now, just don't let it occur to you to do\n\tsomething here, or you'll end up in arrest at the police station.");
    Sleep(1000);
    Output::writeDialogue(" Caden, take care of the\n\trest of the attendees.'");
    Output::writeNarration("\n\tThe cop walks away to talk to the nearest person standing.");
    Output::writeDialogue("\n\t- 'If you're so pure, get in.'");
    Output::writeNarration("\n\tThe bouncer points to the door behind him.\n\n");
    //--------------------------------
    Menu menu6;
    menu6.clearOptions();
    menu6.addOption("Go inside.");
    menu6.addOption("Turn back.");
    menu6.showOptions();
    //--------------------------------
    while (true)
    {
        heroChoice = menu6.getChoice();

        if (heroChoice == 1)
        {
            menu6.clearOptions();
            Console::clearScreen();
            Menu::showHeroAction("Go inside.\n");
            Game::game[0].setCurrentLocation(&Location::locations["Nightclub"]);
            break;
        }
        else if (heroChoice == 2)
        {
            menu6.clearOptions();
            Console::clearScreen();
            Menu::showHeroAction("Turn back.\n");
            Game::game[0].setCurrentLocation(&Location::locations["GunShop"]);
            break;
        }
        else Logger::error("Entered invalid value of <b>heroChoice</b>", "Event::meetingWithPolicemans"); continue;
    }
}

void Event::streetCrossroads()
{
    Logger::out("Function starts", "Event::streetCrossroads");
    Menu::showHeroAction("Visit: " + Location::locations["Street"].getName() + '.');
    Output::writeNarration("\n\tOnce again you are on a street bathed in nighttime darkness.\n\n");
    //--------------------------------
    Menu menu7;
    menu7.clearOptions();
    menu7.addOption("Visit: " + Location::locations["DarkAlley"].getName() + '.');
    menu7.addOption("Visit: " + Location::locations["Nightclub"].getName() + '.');
    menu7.addOption("Visit: " + Location::locations["GunShop"].getName() + '.');
    menu7.showOptions();
    //--------------------------------
    while (true)
    {
        heroChoice = menu7.getChoice();

        if (heroChoice == 1)
        {
            Console::clearScreen();
            Game::game[0].setCurrentLocation(&Location::locations["DarkAlley"]);
            break;
        }
        else if (heroChoice == 2)
        {
            Console::clearScreen();
            Game::game[0].setCurrentLocation(&Location::locations["Nightclub"]);
            break;
        }
        else if (heroChoice == 3)
        {
            Console::clearScreen();
            Game::game[0].setCurrentLocation(&Location::locations["GunShop"]);
            break;
        }
        else Logger::error("Entered invalid value of <b>heroChoice</b>", "Event::streetCrossroads"); continue;
    }
}

// SKLEP Z BRONI¥
void Event::enterGunShop()
{
    Logger::out("Function starts", "Event::enterGunShop");
    Output::writeNarration("\tThe front door hisses open before you.");

    if (!Npc::npcs["Zed"].knowsHero())
    {
        Sleep(1000);
        Output::writeNarration(" You step over the threshold and enter a small room\n\twith a counter opposite the entrance. Behind it stands a tall, thin man with fatigue painted\n\ton his terribly oblong face.");
        Sleep(1500);
        Output::writeNarration(" He is dressed in an old corporate commando\n\tsuit. On the wall behind his back hangs a lot of weapons.");
        Output::writeDialogue("\n\t- 'How can I help you, my friend?'\n");
        Npc::npcs["Zed"].setToKnowHero();
        dialogueWithZed();
    }
    else {
        Sleep(1000);
        Output::writeNarration(" From behind the counter, Zed is already smiling at\n\tyou.");

        if (Hero::heroes[0].hasItem(&Item::items["Pistol"])) Output::writeDialogue("\n\t- 'What's up? How's the gun working out?'");

        std::cout << std::endl;

        if (Quest::quests["ZedAccelerator"].getIsRunning() && !Quest::quests["ZedAccelerator"].getIsCompleted())
        {
            if (!Hero::heroes[0].hasItem(&Item::items["AD13"]))
            {
                dialogueWithZed();
            }
            else
            {
                // TODO
            }
        }
        else
        {
            // TODO
        }
    }
}

void Event::dialogueWithZed()
{
    Logger::out("Function starts", "Event::dialogueWithZed");
    bool heroTalkedAboutBusinessWithZed = false;

    while (true)
    {
        std::cout << std::endl;
        //--------------------------------
        Menu menu8;
        menu8.clearOptions();
        menu8.addOption("'What do you have?'");
        menu8.addOption("'How's business going?'");

        if (bobRecommendsZed && !zedKnowsAboutBobAndZed) menu8.addOption("'You're Zed? I come from Bob.'");

        menu8.addOption("'I have to go...'");
        menu8.showOptions();
        //--------------------------------
        heroChoice = menu8.getChoice();

        if (heroChoice == 1)
        {
            Console::clearScreen();
            Menu::showHeroAction("'What do you have?'\n");
            zedTrade();
            continue;
        }
        else if (heroChoice == 2)
        {
            Console::clearScreen();
            Menu::showHeroAction("'How's business going?'\n");

            if (heroTalkedAboutBusinessWithZed == true) Output::writeDialogue("\t- 'Hey, what's up? Are you sclerotic or something? We already talked about this, haha!'\n");
            else {
                heroTalkedAboutBusinessWithZed = true;
                Output::writeDialogue("\t- 'What kind of question is that anyway? Business is doing great! Everyone stops by\n\tevery now and then to rearm. It's the natural order of things.'\n");
            }

            continue;
        }
        else if (heroChoice == 3)
        {
            Console::clearScreen();

            if (bobRecommendsZed && !zedKnowsAboutBobAndZed)
            {
                zedKnowsAboutBobAndZed = true;
                Menu::showHeroAction("'You're Zed? I come from Bob.'");
                Output::writeDialogue("\n\t- 'Yes, that is correct. I'm Zed, and this is my little shop.");
                Sleep(1000);
                Output::writeDialogue(" Since you know Bob,\n\tyou can get a small discount here.'");
                Npc::npcs["Zed"].setAttitude(Friendly);
                continue;
            }
            else {
                Menu::showHeroAction("'I have to go...'");
                Output::writeDialogue("\n\t- 'No problem. See you later!'\n");
                Console::clearScreen();

                if (!Npc::npcs["Caden"].knowsHero() && !Npc::npcs["CadenPartner"].knowsHero()) meetingWithPolicemans();
                else Game::game[0].setCurrentLocation(&Location::locations["Street"]);

                break;
            }
        }
        else if (heroChoice == 4 && bobRecommendsZed && !zedKnowsAboutBobAndZed)
        {
            Console::clearScreen();
            Menu::showHeroAction("'I have to go...'");
            Output::writeDialogue("\n\t- 'No problem. See you later!'\n");
            Console::clearScreen();

            if (!Npc::npcs["Caden"].knowsHero() && !Npc::npcs["CadenPartner"].knowsHero()) meetingWithPolicemans();
            else Game::game[0].setCurrentLocation(&Location::locations["Street"]);

            break;
        }
        else Logger::error("Entered invalid value of <b>heroChoice</b>", "Event::dialogueWithZed"); continue;
    }
}

void Event::zedTrade()
{
    Logger::out("Function starts", "Event::zedTrade");
    bool ZedTellsAboutWeapons = false;

    if (!Hero::heroes[0].hasItem(&Item::items["Pistol"]))
    {
        if (!ZedTellsAboutWeapons)
        {
            ZedTellsAboutWeapons = true;
            Output::writeDialogue("\t- 'Better ask what I don't have!");
            Sleep(1000);
            Output::writeDialogue(" Look - ");
            Sleep(1000);
            Output::writeDialogue("rifles, pistols, machine guns, shotguns. I\n\thave a melee weapons as well. Knives, hammers, long blades like katanas...");
            Sleep(1500);
            Output::writeDialogue(" Anything\n\tyou want, my friend!");
            Sleep(1500);
            Output::writeDialogue(" Tell me, what do you like?'\n\n");
            //--------------------------------
            Menu menu9;
            menu9.clearOptions();
            menu9.addOption("Buy: pistol (250 $).");
            menu9.addOption("'I have made up my mind.'");
            menu9.showOptions();
            //--------------------------------
            while (true)
            {
                heroChoice = menu9.getChoice();

                if (heroChoice == 1)
                {
                    Console::clearScreen();
                    Menu::showHeroAction("Buy: pistol (250 $).");
                    buyPistol();
                    break;
                }
                else if (heroChoice == 2)
                {
                    Console::clearScreen();
                    Menu::showHeroAction("'I have made up my mind.'");
                    Output::writeNarration("\n\tZed looks at you pityingly and shrugs his shoulders.");
                    Output::writeDialogue("\n\t- 'No problem. It can happen to anyone.'\n");
                    dialogueWithZed();
                    break;
                }
                else Logger::error("Entered invalid value of <b>heroChoice</b>", "Event::zedTrade"); continue;
            }
        }
        else
        {
            std::cout << std::endl;
            //--------------------------------
            Menu menu10;
            menu10.clearOptions();
            menu10.addOption("Buy: pistol (250 $).");
            menu10.addOption("'I have made up my mind.'");
            menu10.showOptions();
            //--------------------------------
            while (true)
            {
                heroChoice = menu10.getChoice();

                if (heroChoice == 1)
                {
                    Console::clearScreen();
                    Menu::showHeroAction("Buy: pistol (250 $).");
                    buyPistol();
                    break;
                }
                else if (heroChoice == 2)
                {
                    Console::clearScreen();
                    Menu::showHeroAction("'I have made up my mind.'");
                    Output::writeNarration("\n\tZed looks at you pityingly and shrugs his shoulders.");
                    Output::writeDialogue("\n\t- 'No problem. It can happen to anyone.'\n");
                    dialogueWithZed();
                    break;
                }
                else Logger::error("Entered invalid value of <b>heroChoice</b>", "Event::zedTrade"); continue;
            }
        }
    }
    else
    {
        Console::resetConsoleColor();
        Output::write("\tYou have everything you need. There's no point in bothering Zed.\n");
        dialogueWithZed();
    }
}

void Event::buyPistol()
{
    Logger::out("Function starts", "Event::buyPistol");

    if (Hero::heroes[0].getMoney() != 250.0)
    {
        Output::writeDialogue("\n\t- 'I see you're low on cash.");
        Sleep(1000);
        Output::writeDialogue(" But don't worry, we'll sort it out somehow.");
        Sleep(1500);

        if (zedKnowsAboutBobAndZed)
        {
            Output::writeDialogue(" Hmm, you know Old Bob, that already means something.");
            Sleep(1000);
            Output::writeDialogue(" Let's just say I'll loan you this gun on a friendly basis.");

            Hero::heroes[0].addItem(&Item::items["Pistol"]);
            Console::setConsoleColor(CC_Item);
            Output::write("\n\t" + Item::items["Pistol"].getName());
            Console::resetConsoleColor();
            Output::write(" gained.\n");
        }
        else
        {
            Quest::quests["ZedAccelerator"].start();
            Output::writeDialogue(" It so happens that I have been looking for a good accelerator for some time.");
            Sleep(1000);
            Output::writeDialogue(" I don't mean the crap produced by corporations these days.");
            Sleep(1000);
            Output::writeDialogue(" I mean the good old accelerator!");
            Sleep(1500);
            Output::writeDialogue(" Find me such a device and you will get that gun. Okay?");
        }
    }
    else
    {
        Output::writeDialogue("\n\t- 'A pistol is a good start. Here, it's yours.'");

        Hero::heroes[0].addItem(&Item::items["Pistol"]);
        Console::setConsoleColor(CC_Item);
        Output::write("\n\t" + Item::items["Pistol"].getName());
        Console::resetConsoleColor();
        Output::write(" was bought.\n");
    }
}

void Event::gunShopCrossroads()
{
    Logger::out("Function starts", "Event::gunShopCrossroads");
    enterGunShop();
}

// KLUB NOCNY
void Event::enterClub()
{
    Logger::out("Function starts", "Event::enterClub");
    Output::writeNarration("\n\tAfter passing through the entrance your eardrums are slowly bursting from the loud music in\n\tthe club.");
    Sleep(1000);
    Output::writeNarration(" You walk through a short lobby and so arrive at a crowded room full of dancing\n\tpeople.");
    Sleep(1000);
    Output::writeNarration(" Disco balls hung from the ceiling net everything around with streaks of multi-colored\n\tlight.");
    Sleep(1000);
    Output::writeNarration(" Next to the dance floor is a bar, and behind it are several mechanically streamlined\n\tbartenders.\n\n");
    //--------------------------------
    Menu menu11;
    menu11.clearOptions();
    menu11.addOption("Go to the dance floor.");
    menu11.addOption("Go to the bar.");
    menu11.addOption("Back on the street.");
    menu11.showOptions();
    //--------------------------------
    while (true)
    {
        heroChoice = menu11.getChoice();

        if (heroChoice == 1)
        {
            Console::clearScreen();
            Menu::showHeroAction("\nGo on the dance floor.");
            clubDanceFloor();
            break;
        }
        else if (heroChoice == 2)
        {
            Console::clearScreen();
            Menu::showHeroAction("\nGo to the bar.");
            clubBar();
            break;
        }
        else if (heroChoice == 3)
        {
            Console::clearScreen();
            Menu::showHeroAction("\nBack on the street.");
            Game::game[0].setCurrentLocation(&Location::locations["Street"]);
            break;
        }
        else Logger::error("Entered invalid value of <b>heroChoice</b>", "Event::enterClub"); continue;
    }
}

void Event::clubDanceFloor()
{
    Logger::out("Function starts", "Event::clubDanceFloor");

    if (!Npc::npcs["Nyx"].knowsHero())
    {
        Output::writeNarration("\n\tYou get on the dance floor.");
        Sleep(1000);
        Output::writeNarration(" A crowd of dancing people stretches out around you, rubbing\n\tagainst each other to the rhythm of the music.");
        Sleep(1500);
        Output::writeNarration(" Half-naked beauties are dancing in places\n\tthat look like pillars supporting the ceiling. You are not sure if they are real. There\n\tis a definite possibility that they are women, but somewhere in the back of your mind you\n\tthink they are just androids.");
        Sleep(1500);
        Output::writeNarration("\n\tYou start dancing yourself.");
        Sleep(1000);
        Output::writeNarration(" You are doing quite well when an attractive girl appears in\n\tfront of you. She's wearing a see-through, brightly coloured dress.");
        Sleep(1500);
        Output::writeNarration(" Is it a coincidence\n\tthat she has just appeared and is dancing so close to you?\n\n");
        //--------------------------------
        Menu menu12;
        menu12.clearOptions();
        menu12.addOption("'What do you want?'");
        menu12.addOption("'Hey, baby.'");
        menu12.addOption("Keep dancing with no words.");
        menu12.showOptions();
        //--------------------------------
        while (true)
        {
            heroChoice = menu12.getChoice();

            if (heroChoice == 1)
            {
                Console::clearScreen();
                Menu::showHeroAction("'What do you want?'");
                Output::writeNarration("\n\tThe girl turns towards you and smiles with her snow-white teeth.");
                Output::writeDialogue("\n\t- 'Nothing will escape your attention. I am Nyx. I think you can help me.'");
                break;
            }
            else if (heroChoice == 2)
            {
                Console::clearScreen();
                Menu::showHeroAction("'Hey, baby.'");
                Output::writeNarration("\n\tThe girl turns towards you and smiles with her snow-white teeth.");
                Output::writeDialogue("\n\t- 'Hi, stud. I've been watching you since you came in. I am Nyx.'");
                Output::writeNarration("\n\tWith the last word she comes closer to you turns her back on you and starts dancing very\n\tclose to you.");
                Output::writeDialogue("\n\t- 'I am looking for someone like you. I think you can help me.'");
                break;
            }
            else if (heroChoice == 3)
            {
                Console::clearScreen();
                Menu::showHeroAction("Keep dancing with no words.");
                Output::writeNarration("\n\tThe girl turns towards you and smiles with her snow-white teeth.");
                Output::writeDialogue("\n\t- 'Hi, I am Nyx. Vinc, the owner, is my boyfriend. I think you can help me.'");
                break;
            }
            else Logger::error("Entered invalid value of <b>heroChoice</b>", "Event::clubDanceFloor"); continue;
        }

        miaMeeting();
    }
    else
    {
        Output::writeNarration("\n\tYou get on the dance floor.");
        Sleep(1000);
        Output::writeNarration(" It's quite crowded, but at least you can enjoy the beautiful views. You try to keep up with\n\tthe rest of the people dancing there. However, you quickly get tired and head for the exit.");
        Sleep(1500);
        Console::clearScreen();
        nightclubCrossroads();
    }
}

void Event::clubBar()
{
    Logger::out("Function starts", "Event::clubBar");
    heroIsAtBar = true;
    Output::writeNarration("\tWith a slow step, you approach the counter, settle comfortably on a stool, and lift your gaze to the barman in front of you.");
    Output::writeDialogue("\n\t- 'What's for you?'\n\n");

    while (true)
    {
        //--------------------------------
        Menu menu13;
        menu13.clearOptions();
        menu13.addOption("'Give me anything.'");
        menu13.addOption("'Who's in charge?'");
        menu13.addOption("'Bye.'");
        menu13.showOptions();
        //--------------------------------
        heroChoice = menu13.getChoice();

        if (heroChoice == 1)
        {
            Output::writeDialogue("\n\t- 'Okay.");
            Sleep(1000);
            Output::writeDialogue(" Let's see...'");
            Sleep(1500);
            Output::writeNarration("\n\tThe barman turns his back on you and looks through the bottles of alcohol. Finally, he selects one of them and pours its contents into a glass before placing it on the counter in front of you.");
            Sleep(1500);
            Output::writeNarration("\n\tYou reach for the vessel and empty it.");
            Sleep(1000);
            Output::writeNarration(" You feel a pleasant warmth spreading up your throat and further down your gullet.");
            continue;
        }
        else if (heroChoice == 2)
        {
            Output::writeNarration("\n\tThe bartender squints, hearing your question.");
            Output::writeDialogue("\n\t- 'You're not from around here, are you?");
            Sleep(1500);
            Output::writeDialogue(" My boss is Vincent Ramsey.");
            Sleep(1000);
            Output::writeDialogue(" He's a tough guy, so you'd better not make trouble, or it could end badly for you.'");
            continue;
        }
        else if (heroChoice == 3)
        {
            Output::writeNarration("\n\tThe bartender reaches for a glass from under the counter and starts wiping it down.");
            Output::writeDialogue("\n\t- 'Yeah, have fun.'");
            break;
        }
        else Logger::error("Entered invalid value of <b>heroChoice</b>", "Event::clubBar"); continue;
    }
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::miaMeeting()
{
    Logger::out("Function starts", "Event::miaMeeting");
    std::cout << std::endl << std::endl;
    //--------------------------------
    Menu menu14;
    menu14.clearOptions();
    menu14.addOption("'What is it about?'");
    menu14.addOption("Be silent and let her speak.");
    menu14.showOptions();
    //--------------------------------
    while (true)
    {
        heroChoice = menu14.getChoice();

        if (heroChoice == 1)
        {
            Console::clearScreen();
            Menu::showHeroAction("'What is it about?'\n");
            break;
        }
        else if (heroChoice == 2)
        {
            Console::clearScreen();
            Menu::showHeroAction("Be silent and let her speak.\n");
            break;
        }
        else Logger::error("Entered invalid value of <b>heroChoice</b>", "Event::miaMeeting"); continue;
    }

    Output::writeDialogue("\n\t- 'Vinc, the owner, is my boyfriend.");
    Sleep(1000);
    Output::writeDialogue(" I want him dead.'");
    Quest::quests["KillVincent"].start();
    Sleep(1500);
    Output::writeNarration("\n\tNyx takes your hand and leads you towards the toilet.");
    Output::writeDialogue("\n\t- 'Do you have a gun?'");

    if (Hero::heroes[0].hasItem(&Item::items["Pistol"]))
    {
        Output::writeDialogue("\n\t- 'Good.");
        Sleep(1000);
        Output::writeDialogue(" So you already know what and how.'");
    }
    else
    {
        Output::writeDialogue("\n\t- 'You know how to use it, don't you?");
        Sleep(1000);
        Output::writeDialogue(" Get it for yourself, you'll need it. Here's 200 bucks.'");
        Hero::heroes[0].addMoney(200);
        Console::setConsoleColor(CC_Green);
        Output::write("\n\t200$");
        Console::resetConsoleColor();
        Output::write(" has been received.");
        Output::writeDialogue("\n\t- 'There is a gun shop nearby.");
        Output::writeDialogue(" It is run by a guy named Zed. Visit him before you head upstairs.'");
    }
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::clubUpstairs()
{
    Logger::out("Function starts", "Event::clubUpstairs");
    Output::writeNarration("\n\tYou go up a winding staircase. At the end of a short banister you will see a closed door\n\tguarded by another bulky individual.\n\n");
    //--------------------------------
    Menu menu15;
    menu15.clearOptions();
    menu15.addOption("Come closer.");
    menu15.addOption("Go back downstairs.");
    menu15.showOptions();
    //--------------------------------
    while (true)
    {
        heroChoice = menu15.getChoice();

        if (heroChoice == 1)
        {
            Console::clearScreen();
            Menu::showHeroAction("Come closer.");
            Output::writeNarration("\n\tAre you brave or foolish enough to face the hammer man. You are stopped from taking another\n\tstep by his firm voice.");
            Output::writeDialogue("\n\t- 'What here?'");
            Npc::npcs["Jet"].setToKnowHero();
            dialogueWithJet();
            break;
        }
        else if (heroChoice == 2)
        {
            Console::clearScreen();
            Menu::showHeroAction("Go back downstairs.");
            Output::writeNarration("\n\tYou don't dare to come closer, so like the last coward you turn back and return to the kingdom\n\tof loud music and dancing people.\n");
            nightclub();
            break;
        }
        else Logger::error("Entered invalid value of <b>heroChoice</b>", "Event::clubUpstairs"); continue;
    }
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::dialogueWithJet()
{
    Logger::out("Function starts", "Event::dialogueWithJet");
    int jetPoints = 0;
    std::cout << std::endl << std::endl;
    //--------------------------------
    Menu menu16;
    menu16.clearOptions();
    menu16.addOption("'I want to pass.'");
    menu16.addOption("'What is behind that door?'");

    if (Hero::heroes[0].hasItem(&Item::items["Pistol"]))
    {
        menu16.addOption("Kill him with a pistol.");
        menu16.addOption("Stun him with a pistol.");
    }

    menu16.addOption("It's time for me to go.");
    menu16.showOptions();
    //--------------------------------
    while (true)
    {
        heroChoice = menu16.getChoice();

        if (heroChoice == 1)
        {
            Console::clearScreen();
            Menu::showHeroAction("'I want to pass.'\n");
            jetPoints += 1;
            break;
        }
        else if (heroChoice == 2)
        {
            Console::clearScreen();
            Menu::showHeroAction("'What is behind that door?'\n");
            jetPoints += 1;
            break;
        }
        else if (heroChoice == 3 && !Hero::heroes[0].hasItem(&Item::items["Pistol"]))
        {
            Console::clearScreen();
            Menu::showHeroAction("'It's time for me to go.'\n");
            Console::clearScreen();
            nightclub();
            break;
        }
        else if (heroChoice == 3 && Hero::heroes[0].hasItem(&Item::items["Pistol"]))
        {
            Console::clearScreen();
            Menu::showHeroAction("Kill him with a pistol.\n");
            break;
        }
        else if (heroChoice == 4 && Hero::heroes[0].hasItem(&Item::items["Pistol"]))
        {
            Console::clearScreen();
            Menu::showHeroAction("Stun him with a pistol.\n");
            break;
        }
        else if (heroChoice == 5 && Hero::heroes[0].hasItem(&Item::items["Pistol"]))
        {
            Console::clearScreen();
            Menu::showHeroAction("'It's time for me to go.'\n");
            Console::clearScreen();
            nightclub();
            break;
        }
        else Logger::error("Entered invalid value of <b>heroChoice</b>", "Event::dialogueWithJet"); continue;
    }
}

void Event::vincentAssassination()
{
    Logger::out("Function starts", "Event::vincentAssassination");
    vincentOffice();
}

void Event::vincentOffice()
{
    Logger::out("Function starts", "Event::vincentOffice");
    Output::writeNarration("\tYou enter the manager's office immersed in twilight. In the middle of the room stands a sizable desk, and on it are stacks of documents and computer. To the left of the entrance is a window to the street below. On the right you will notice a door to another room.\n\n");
    //--------------------------------
    Menu menu17;
    menu17.clearOptions();
    menu17.addOption("Open the door and go into the other room.");
    menu17.addOption("Stay and search the office.");
    menu17.showOptions();
    //--------------------------------
    while (true)
    {
        heroChoice = menu17.getChoice();

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
        else Logger::error("Entered invalid value of <b>heroChoice</b>", "Event::vincentOffice"); continue;
    }
}

void Event::checkVincentDesk()
{
    Logger::out("Function starts", "Event::checkVincentDesk");
    heroKnowsVincentCode = true;
    Menu::showHeroAction("Stay and search the office.");
    Output::writeNarration("\n\tYou walk up to the desk. You start flipping through the e-papers one by one and finally your gaze falls on the flickering blue monitor.");
    Output::write("\n\t");

    vincentHideoutCode();
}

void Event::vincentHideoutCode()
{
    Logger::out("Function starts", "Event::vincentHideoutCode");
    Output::writeNarration("\n\tYou walk closer and spot the terminal. It looks like you'll need to use a code to get through.");
    Sleep(1500);

    if (!heroKnowsVincentCode)
    {
        Output::writeNarration(" You have to look around the office though, whether you want to or not.");
    }
    else {
        std::cout << std::endl << std::endl;
        //--------------------------------
        Menu menu18;
        menu18.clearOptions();
        menu18.addOption("Use code '2021'.");
        menu18.addOption("Search the office.");
        menu18.showOptions();
        //--------------------------------
    }
}

void Event::vincentHideout()
{
    Logger::out("Function starts", "Event::vincentHideout");
    Npc::npcs["Vincent"].setStatus(Unconscious);
    Output::writeNarration("\n\tThe door closes behind you, hissing quietly.");
    Sleep(2000);
    Output::writeNarration(" The room you're in is full of smaller and larger\n\tcables that merge into a single monitor that hangs above the sim-chair. On it lies a big guy\n\tin a tailored suit and a stimulation helmet on his head that obscures his face.");
    Sleep(1500);
    Output::writeNarration(" You guess it's\n\tVincent, the club owner.");
    Sleep(2000);
    Output::writeNarration("\n\tCreeping up, you come closer. Your goal is within reach. The question is what will you do?\n\n");
    //--------------------------------
    Menu menu19;
    menu19.clearOptions();
    menu19.addOption("Disconnect his consciousness from the neuronet. (Kill him)");
    menu19.addOption("Wait for his consciousness to leave the neuronet.");
    menu19.showOptions();
    //--------------------------------
    while (true)
    {
        heroChoice = menu19.getChoice();

        if (heroChoice == 1)
        {
            Console::clearScreen();
            Menu::showHeroAction("Disconnect his consciousness from the neuronet. (Kill him)");
            Output::writeNarration("\n\tYou lean over Vincent and, in a fluid motion without hesitation, pull the stimulation helmet\n\toff his head. You witness the nightclub owner being shaken by a wave of convulsions. Foam\n\tbegins to come out of his mouth and after a moment the man freezes.");
            Sleep(1500);
            Npc::npcs["Vincent"].setStatus(Dead);
            Output::writeNarration(" He's probably dead, just like\n\tNyx wanted.");
            break;
        }
        else if (heroChoice == 2)
        {
            Console::clearScreen();
            Menu::showHeroAction("Wait for his consciousness to leave the neuronet.");
            Output::writeNarration("\n\tYou are not a coward.");
            Sleep(1000);
            Output::writeNarration(" You don't stab people in the back. That's not your style. You prefer an\n\topen fight.");
            Sleep(1500);
            Npc::npcs["Vincent"].setStatus(Normal);
            Output::writeNarration(" After a while, you notice Vincent moving slightly in his seat. He opens his eyes -\n\tthey are shining with the excitement of his online adventure.");
            Sleep(1000);
            Output::writeNarration(" It is only a matter of time before\n\tVincent notices your presence. There is no turning back now.");
            Output::writeDialogue("\n\t- 'What the fuck are you doing here, dickhead?'\n");
            dialogueWithVincent();
            break;
        }
        else Logger::error("Entered invalid value of <b>heroChoice</b>", "Event::vincentHideout"); continue;
    }
}

void Event::dialogueWithVincent()
{
    Logger::out("Function starts", "Event::dialogueWithVincent");
    std::cout << std::endl << std::endl;
    //--------------------------------
    Menu menu20;
    menu20.clearOptions();
    menu20.addOption("'Die!'");
    menu20.addOption("'I don't want to fight with you.'");
    menu20.addOption("'Nyx wants you dead.'");
    menu20.showOptions();
    //--------------------------------
    while (true)
    {
        heroChoice = menu20.getChoice();

        if (heroChoice == 1)
        {
            Console::clearScreen();
            Menu::showHeroAction("'Die!'");
            Output::writeNarration("\n\tWith a shout, you bring out your gun and aim it at Vincent's chest.");
            Output::writeDialogue("\n\t- 'Are you such a hero?");
            Sleep(1000);
            Output::writeDialogue(" Would you kill an unarmed man?");
            Sleep(1000);
            Output::writeDialogue(" All right, can I at least find out who\n\tsent you? I know you're not working alone. I'm seeing you for the first time in my life.'");
            break;
        }
        else if (heroChoice == 2)
        {
            Console::clearScreen();
            Menu::showHeroAction("'I don't want to fight with you.'");
            Output::writeNarration("\n\tYou are not a coward.");
            Sleep(1000);
            Output::writeNarration(" You don't stab people in the back. That's not your style. You prefer an\n\topen fight.");
            break;
        }
        else if (heroChoice == 3)
        {
            Console::clearScreen();
            Menu::showHeroAction("'Nyx wants you dead.'");
            Output::writeNarration("\n\tYou are not a coward. You don't stab people in the back. That's not your style. You prefer an open fight.");
            break;
        }
        else Logger::error("Entered invalid value of <b>heroChoice</b>", "Event::dialogueWithVincent"); continue;
    }

    std::cout << std::endl << std::endl;
    //--------------------------------
    Menu menu21;
    menu21.clearOptions();
    menu21.addOption("'It doesn't matter.'");
    menu21.addOption("'Your girlfriend, Nyx.'");
    menu21.showOptions();
    //--------------------------------
    while (true)
    {
        heroChoice = menu21.getChoice();

        if (heroChoice == 1)
        {
            Console::clearScreen();
            Menu::showHeroAction("'It doesn't matter.'");
            Output::writeDialogue("\n\t- 'Ugh, you little prick. I'll get you from beyond the grave. There will be no peace. I won't let that happen!'");
            Sleep(1500);
            Output::writeNarration("\n\tThe last word spoken synchronizes with the bang of a gunshot as a bullet of energy pierces the club owner's chest.");
            Sleep(1000);
            Output::writeNarration(" The recoil knocks him from his seat. The lifeless body clatters against the floor.");
            Sleep(1500);
            Output::writeNarration(" He's dead, just like Nyx wanted.");
            Npc::npcs["Vincent"].setStatus(Dead);
            Output::writeNarration("\n\tOut of curiosity, you walk closer and spot the corpse holding a small pistol.");
            Sleep(1000);
            Output::writeNarration(" That bastard was playing for time after all!");
            break;
        }
        else if (heroChoice == 2)
        {
            Console::clearScreen();
            Menu::showHeroAction("'Your girlfriend, Nyx.'");
            Output::writeDialogue("\n\t- 'Traitorous bitch! She'll get her due someday.");
            Output::writeDialogue(" All right, shithead, let's get this over with.'");
            Output::writeNarration("\n\tThe last word spoken synchronizes with the bang of a gunshot as a bullet of energy pierces the club owner's chest.");
            Sleep(1000);
            Output::writeNarration(" The recoil knocks him from his seat. The lifeless body clatters against the floor.");
            Sleep(1500);
            Output::writeNarration(" He's dead, just like Nyx wanted.");
            Npc::npcs["Vincent"].setStatus(Dead);
            Output::writeNarration("\n\tOut of curiosity, you walk closer and spot the corpse holding a small pistol.");
            Sleep(1000);
            Output::writeNarration(" That bastard was playing for time after all!");
            break;
        }
        else Logger::error("Entered invalid value of <b>heroChoice</b>", "Event::dialogueWithVincent"); continue;
    }

    Output::writeNarration("\n\tThe passage behind your back is opened.");
    Sleep(1000);
    Output::writeNarration(" You turn around, in front of you is Nyx.");
    Output::writeDialogue("\n\t- 'Did you do what I asked you to do...'");
    Sleep(1500);
    Output::writeNarration("\n\tThe girl's gaze wanders from you to the body of her ex-boyfriend behind you.");
    Sleep(1000);
    Output::writeDialogue("\n\t- 'You did it... You really did it... Is he - is he dead?'");
    Sleep(1000);
    Output::writeNarration("\n\tNyx walks past you and kneels by the dead man. She starts searching his pockets for something.\n\n");
    //--------------------------------
    Menu menu22;
    menu22.clearOptions();
    menu22.addOption("Do nothing.");
    menu22.addOption("'What is this all about?'");
    menu22.showOptions();
    //--------------------------------
    while (true)
    {
        heroChoice = menu22.getChoice();

        if (heroChoice == 1)
        {
            Output::writeNarration("\n\tYou let the girl quietly plunder the corpse. This gives you more time to look at her shapes more closely.");
            Output::writeDialogue("\n\t- 'Spare me, if you please.'");
            break;
        }
        else if (heroChoice == 2)
        {
            Output::writeDialogue("\n\t- 'Well, now I think I owe you an explanation.'");
            Output::writeNarration("\n\tA girl talks to you without even looking at you.\n");
            break;
        }
        else Logger::error("Entered invalid value of <b>heroChoice</b>", "Event::dialogueWithVincent"); continue;
    }

    vincentResurrection();
}

void Event::vincentResurrection()
{
    Logger::out("Function starts", "Event::vincentResurrection");
    Output::writeNarration("\n\tSuddenly, the maze of cables begins to vibrate and move in a strange dance.");
    Sleep(1000);
    Output::writeNarration(" Hisses reach you and Nyx, forming a gibberish that is difficult to understand.");
    Console::setConsoleColor(CC_Robot);
    Output::write("\n\t<You scum! You thought you got rid of me.");
    Sleep(1000);
    Output::write(" But you didn't.");
    Sleep(1000);
    Output::write(" I'm immortal now!>");
    Output::writeNarration("\n\tYou exchange a look with Nyx. You both can't believe what's happening.");
    Output::writeDialogue("\n\t- 'What the fuck?!'");
    Console::setConsoleColor(CC_Robot);
    Output::write("\n\t<Before your new lover killed me, sweatheart, I managed to pour some of my consciousness into the net. I don't need my body anymore, nothing limits me anymore.");
    Sleep(1500);
    Console::setConsoleColor(CC_Robot);
    Output::write(" Now you will get what you deserve. The time for payment has come!");
    Sleep(1000);
    Output::write(" DIE!>");
    Console::waitForUserInput();
}
void Event::nightclubCrossroads()
{
    Logger::out("Function starts", "Event::nightclubCrossroads");

    Menu::showHeroAction("Visit: " + Location::locations["Nightclub"].getName() + ".\n");
    Output::writeNarration("\n\tYou enter from a fairly well-lit street into a slightly darkened nightclub, trembling with colour.\n\n");
    //--------------------------------
    Menu menu23;
    menu23.clearOptions();
    menu23.addOption("Go to the dance floor.");
    menu23.addOption("Go to the bar.");
    menu23.addOption("Go upstairs.");
    menu23.addOption("Visit: " + Location::locations["Street"].getName() + ".");
    menu23.showOptions();
    //--------------------------------
    while (true)
    {
        heroChoice = menu23.getChoice();

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
        else if (heroChoice == 3)
        {
            std::cout << std::endl;
            clubUpstairs();
            break;
        }
        else if (heroChoice == 4)
        {
            std::cout << std::endl;
            Game::game[0].setCurrentLocation(&Location::locations["Street"]);
            break;
        }
        else Logger::error("Entered invalid value of <b>heroChoice</b>", "Event::nightclubCrossroads"); continue;
    }
}

// KRYJÓWKA ŒNI¥CYCH
void Event::actOne()
{
    Logger::out("Function starts", "Event::actOne");

    if (Game::game[0].getLang() == EN) Output::write("\n\tAct One");
    else Output::write("\n\tAkt pierwszy");

    Sleep(2000);

    if (Game::game[0].getLang() == EN) Output::write("\n\n\tPROSELYTISM");
    else Output::write("\n\n\tNAWRÓCENIE");

    Sleep(5000);
    Console::clearScreen();
    storyIntroduction();
}

// INNE
void Event::loadingFiles()
{
    Logger::out("Function starts", "Event::loadingFiles");
    Console::setConsoleColor(CC_Dialogue);
    Output::write("\t||", 100);
    Sleep(1000);
    Output::write("=", 100);
    Sleep(1000);
    Output::write("=", 100);
    Sleep(1000);
    Output::write("=", 100);
    Sleep(1000);
    Output::write("=", 100);
    Sleep(1000);
    Output::write("=", 100);
    Sleep(1000);
    Output::write("=", 100);
    Sleep(1000);
    Output::write("=", 100);
    Sleep(1000);
    Output::write("=", 100);
    Sleep(1000);
    Output::write("=", 100);
    Sleep(1000);
    Output::write("=", 100);
    Sleep(1000);
    Output::write("=", 100);
    Sleep(1000);
    Output::write("=", 100);
    Sleep(1000);
    Output::write("=", 100);
    Sleep(1000);
    Output::write("=", 100);
    Sleep(1000);
    Output::write("=", 100);
    Sleep(1000);
    Output::write("=", 100);
    Sleep(1000);
    Output::write("=", 100);
    Sleep(1000);
    Output::write("=", 100);
    Sleep(1000);
    Output::write("=", 100);
    Sleep(1000);
    Output::write("=", 100);
    Output::write("||", 100);
    Sleep(1000);
    Output::write("\n\tDownload completed.");
    Console::resetConsoleColor();
}

void Event::namingHero()
{
    Logger::out("Function starts", "Event::namingHero");
    std::string heroName;
    Console::resetConsoleColor();
    std::cout << std::endl;
    heroName = Input::getString();
    Hero::heroes[0].setName(heroName);
    Logger::out("Set <b>" + Hero::heroes[0].getName() + "</b> to hero's name", "Event::namingHero");
}