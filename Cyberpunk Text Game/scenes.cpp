#include "events.hpp"

int heroChoice = 0;
bool bobRecommendsZed = false, zedKnowsAboutBobAndZed = false, heroIsOnDanceFloor = false, heroIsAtBar = false, heroKnowsVincentCode = false;

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// MROCZNY ZAU£EK
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::prologue()
{
    Logger::out("Function starts", "Event::prologue");

    if (Game::game[0].getLang() == en) Function::write("\n\tPrologue");
    else Function::write("\n\tProlog");

    Sleep(2000);

    if (Game::game[0].getLang() == en) Function::write("\n\n\tREQUIEM FOR A DREAM");
    else Function::write("\n\n\tREQUIEM DLA MARZEÑ");

    Sleep(5000);
    Function::clearScreen();
    storyIntroduction();
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::storyIntroduction()
{
    Logger::out("Function starts", "Event::storyIntroduction");

    if (Game::game[0].getLang() == en)
    {
        Function::writeNarration("\n\tIt's 2050.");
        Sleep(1000);
        Function::writeNarration(" Megacity is a place overrun by poverty and feuding gangs, where powerful\n\tcorporations have the most influence. The violence in the streets is a clear sign of\n\tan impending war. Government operating from behind the secure walls of City Hall are\n\ttrying to combat this, but so far without success. There are rumors that they themselves\n\tare secretly supporting the chaos to create a New Order on the ruins of the city.\n\n", 20);
        Game::pause();
        Function::clearScreen();
        Sleep(2500);
        Function::writeDialogue("\n\tStanding at the edge of the tallest tower...", 75);
        Sleep(2500);
        Function::writeDialogue("\n\tHolding your hand and dive...", 75);
        Sleep(2500);
        Function::writeDialogue("\n\tFalling and falling for what feels like hours...", 75);
        Sleep(3000);
        Function::clearScreen();
        wakeUpInDarkAlley();
    }
    else {
        Function::writeNarration("\n\tJest rok 2050.");
        Sleep(1000);
        Function::writeNarration(" Megacity to miejsce opanowane przez biedê i zwaœnione gangi, gdzie najwiêksze\n\twp³ywy maj¹ potê¿ne korporacje. Przemoc na ulicach jest wyraŸnym znakiem zbli¿aj¹cej siê wojny.\n\tRz¹d dzia³aj¹cy zza bezpiecznych murów ratusza próbuje z tym walczyæ, ale jak na razie\n\tbezskutecznie. Kr¹¿¹ plotki, ¿e sam potajemnie wspiera chaos, by na gruzach miasta stworzyæ\n\tNowy Porz¹dek.\n\n", 20);
        Game::pause();
        Function::clearScreen();
        Sleep(2500);
        Function::writeDialogue("\n\tStoj¹c na krawêdzi najwy¿szej wie¿y...", 75);
        Sleep(2500);
        Function::writeDialogue("\n\tTrzymam ciê za rêkê i skaczê...", 75);
        Sleep(2500);
        Function::writeDialogue("\n\tSpadam i spadam jakby godzinami...", 75);
        Sleep(3000);
        Function::clearScreen();
        std::cout << std::endl;
        wakeUpInDarkAlley();
    }
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::wakeUpInDarkAlley()
{
    Logger::out("Function starts", "Event::wakeUpInDarkAlley");

    if (Game::game[0].getLang() == en)
    {
        Sleep(2000);
        Function::writeNarration("\n\tYou wake up dazed from a restless slumber.");
        Sleep(1000);
        Function::writeNarration(" It was the same dream again...");
        Sleep(1500);
        Function::writeNarration("\n\tYou are somewhere in a dark alley. Above your head, among the smoggy haze, as if torn from\n\ta dream, rise the monumental skyscrapers of large corporations.");
        Sleep(1000);
        Function::writeNarration(" Their divine majesty beats\n\tyou to the eyes.");
        Sleep(3000);
        Function::writeNarration("\n\tYour heart beats so hard that only the stinging touch of the wind protects you from a sudden\n\theart attack.");
        Sleep(500);
        Function::writeNarration(" Suddenly a wave of shivers comes over your body, you start shaking like an\n\taspen, and realize that you are lying on a lair made of some old newspapers.");
        Sleep(3000);
        Function::writeNarration("\n\tWhen you rise from the ground, you notice a sea of trash around you.");
        Sleep(1000);
        Function::writeNarration(" It's full of cardboard\n\tboxes, old mechanical parts, and god knows what else.");
        Sleep(2500);
        Function::writeNarration("\n\tMaybe you will find something interesting there...\n\n");
        //--------------------------------
        Function::clearChoices();
        Function::addChoice("Search the area for something valuable.");
        Function::addChoice("Find the exit from the alley.");
        Function::showChoices();
        //--------------------------------
    }
    else {
        Function::writeNarration("\n\tBudzisz siê oszo³omiony z niespokojnej drzemki.");
        Sleep(1000);
        Function::writeNarration(" To by³ znowu ten sam sen...");
        Sleep(1500);
        Function::writeNarration("\n\tZnajdujesz siê gdzieœ w ciemnym zau³ku. Nad twoj¹ g³ow¹, wœród smogowej mg³y, niczym wyrwane\n\tze snu, wznosz¹ siê monumentalne drapacze chmur wielkich korporacji.");
        Sleep(1000);
        Function::writeNarration(" Ich boski majestat bije\n\tciê po oczach.");
        Sleep(2500);
        Function::writeNarration("\n\tSerce bije ci tak mocno, ¿e tylko szczypi¹cy dotyk wiatru chroni ciê przed nag³ym atakiem\n\tserca.");
        Sleep(500);
        Function::writeNarration(" Nagle przez twoje cia³o przechodzi fala dreszczy, zaczynasz trz¹œæ siê jak osika i\n\tuœwiadamiasz sobie, ¿e le¿ysz na legowisku zrobionym ze starych gazet.");
        Sleep(2000);
        Function::writeNarration("\n\tKiedy podnosisz siê z ziemi, zauwa¿asz wokó³ siebie morze œmieci.");
        Sleep(1000);
        Function::writeNarration(" Jest pe³ne kartonów, starych\n\tczêœci mechanicznych i Bóg wie czego jeszcze.");
        Sleep(1500);
        Function::writeNarration("\n\tMo¿e znajdziesz tam coœ interesuj¹cego...\n\n");
        //--------------------------------
        Function::clearChoices();
        Function::addChoice("Rozejrzyj siê po okolicy w poszukiwaniu czegoœ cennego.");
        Function::addChoice("ZnajdŸ wyjœcie z zau³ka.");
        Function::showChoices();
        //--------------------------------
    }

    while (true)
    {
        heroChoice = Function::getChoice();

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
        else Logger::error("Entered invalid value of <b>heroChoice</b>", "Event::wakeUpInDarkAlley"); continue;
    }
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::acceleratorFinding()
{
    Logger::out("Function starts", "Event::acceleratorFinding");
    Function::writeNarration("\n\tYou start rummaging through the trash.");
    Sleep(1500);
    Function::writeNarration(" The search takes a long while, but eventually you\n\tmanage to find something.");
    Sleep(2000);

    Hero::heroes[0].addItem(&Item::items["AD13"]);
    Function::changeConsoleColor(item);
    Function::write("\n\n\t" + Item::items["AD13"].getName());
    Function::changeConsoleColor();
    Function::write(" was found.");

    if (Hero::heroes[0].hasItem(&Item::items["AD13"])) Logger::out(Item::items["AD13"].getName() + " added to EQ", "Event::acceleratorFinding");
    else Logger::error(Item::items["AD13"].getName() + " not added to EQ", "Event::accelelatorFinding");

    Function::write("\n\t[TIP: This item has been added to your inventory. You can view it in the text file in your\n\tgame folder.]", 15);
    Sleep(4000);
    Function::writeNarration("\n\n\tHmm, that might come in handy in the future.");
    Sleep(1000);
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::rubbishSearch()
{
    Logger::out("Function starts", "Event::rubbishSearch");
    Function::showHeroAction("Search the area for something valuable.");
    acceleratorFinding();
    outOfTheAlley();
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::outOfTheAlley()
{
    Logger::out("Function starts", "Event::outOfTheAlley");

    if (!Hero::heroes[0].hasItem(&Item::items["AD13"]))
    {
        Function::showHeroAction("Find the exit from the alley.");
        Function::writeNarration("\n\tYou're not going to rummage through the trash.");
        Sleep(1500);
        Function::writeNarration(" And that's okay, you probably wouldn't find\n\tanything there anyway.");
        Function::writeNarration(" Instead, you slowly toddle toward the neon color bombs at the end of\n\tthe alley.");
    }
    else Function::writeNarration("\n\tYou slowly toddle toward the neon color bombs at the end of the alley.");

    Sleep(3000);
    Function::writeNarration("\n\tYou are getting closer and closer to your goal when from the right, from behind a veil of\n\tshadows, a low, not very pleasant voice belonging to a man speaks up.");
    Function::writeDialogue("\n\t- 'Hey, kid. Wait for a second.'\n\n");
    //--------------------------------
    Function::clearChoices();
    Function::addChoice("Stop and find out what he wants.");
    Function::addChoice("Ignore him and keep walking.");
    Function::showChoices();
    //--------------------------------
    while (true)
    {
        heroChoice = Function::getChoice();

        if (heroChoice == 1)
        {
            Function::clearScreen();
            Function::showHeroAction("Stop and find out what he wants.");
            Function::writeNarration("\n\tYou stop and turn towards the owner of the voice.");
            Sleep(1500);
            Function::writeNarration(" His silhouette looms in the darkness. It's\n\tone of the homeless people who live here. What can he have for you?\n");
            Sleep(1000);
            dialogueWithBob();
            break;
        }
        else if (heroChoice == 2)
        {
            Function::clearScreen();
            Function::showHeroAction("Ignore him and keep walking.");
            Function::writeNarration("\n\tYou have a mysterious stranger for nothing. You speed up your step and leave him far behind you.");
            Function::writeDialogue("\n\t- 'Hey, you! Come back here!'");
            Function::writeNarration("\n\tWhatever he wanted from you is no longer important.");
            Sleep(1000);
            Game::game[0].setCurrentLocation(&Location::locations["Street"]);
            break;
        }
        else Logger::error("Entered invalid value of <b>heroChoice</b>", "Event::outOfTheAlley"); continue;
    }
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::dialogueWithBob()
{
    Logger::out("Function starts", "Event::dialogueWithBob");
    Function::writeDialogue("\t- 'What's your name, boy?'");

    if (!Npc::npcs["Bob"].knowsHero() && !Npc::npcs["Caden"].knowsHero() && !Npc::npcs["CadenPartner"].knowsHero()) namingHero();
    else std::cout << std::endl;

    Npc::npcs["Bob"].setToKnowHero();
    Function::writeDialogue("\t- 'So you're " + Hero::heroes[0].getName() + ", huh?");
    Sleep(1500);
    Function::writeDialogue(" All right. I'm " + Npc::npcs["Bob"].getName() + ".");
    Sleep(1500);
    Function::writeDialogue(" What are you doin' here?'");
    Function::writeNarration("\n\tThe shadows in front of you, begin to ripple when your caller stands up.\n\n");
    //--------------------------------
    Function::clearChoices();
    Function::addChoice("'I'm not looking for trouble.'");
    Function::addChoice("'I'm just looking around. Where are we actually?'");
    Function::addChoice("'It's not your business.'");
    Function::showChoices();
    //--------------------------------
    while (true)
    {
        heroChoice = Function::getChoice();

        if (heroChoice == 1)
        {
            Function::clearScreen();
            Function::showHeroAction("'I'm not looking for trouble.'");
            bobRecommendsZed = true; // Bob poleca bohaterowi sklep z broni¹ Zeda
            Function::writeDialogue("\n\t- 'Ha-ha, that's what I thought. To tell you the truth, you don't look very threatening.");
            Sleep(1000);
            Function::writeDialogue(" Well,\n\tyou could use some gat. I happen to know a guy who deals guns. His name is Zed, and his store is\n\tright around the corner.");
            Sleep(1000);
            Function::writeDialogue(" Tell him you're coming from old Bob and he'll find something for you.'\n");
            break;
        }
        else if (heroChoice == 2)
        {
            Function::clearScreen();
            Function::showHeroAction("'I'm just looking around. Where are we actually?'");
            Function::writeDialogue("\n\t- 'What's wrong with you?");
            Sleep(1000);
            Function::writeDialogue(" Anyway, it doesn't matter.");
            Sleep(1500);
            Function::writeDialogue(" Have you ever heard of Megacity?");
            Sleep(1500);
            Function::writeDialogue(" Well,\n\tit's right here. The neighborhood we are currently in is called Gunce Deep.");
            Sleep(1000);
            Function::writeDialogue(" Did I make your\n\thead clearer?'\n");
            break;
        }
        else if (heroChoice == 3)
        {
            Function::clearScreen();
            Function::showHeroAction("'It's not your business.'\n");
            Npc::npcs["Bob"].setAttitude(angry); // angry / hostile / friendly / neutral
            Function::writeDialogue("\t- 'You're wrong. It's absolutely my business, kid. Don't shut your mouth like that, or you might\n\tlose a few teeth. Got it?'\n");
            break;
        }
        else Logger::error("Entered invalid value of <b>heroChoice</b>", "Event::outOfTheAlley"); continue;
    }

    if (!streetWasVisited)
    {
        Function::writeNarration("\tFinally, an old, wrinkled face surrounded by gray fuzz emerges from the darkness. An artificial,\n\tcybernetic eye watches you vigilantly.");
        Sleep(1000);
        Function::writeNarration(" You start to feel strangely uncomfortable.");
        Sleep(2000);
        Function::writeNarration("\n\tIn an instant the alley is filled with the howling of a police siren.");
        Sleep(1000);
        Function::writeNarration(" On the wall in front of\n\tyou, red and blue begin to dance with each other.");
        Function::writeDialogue("\n\t- 'Shit");
        Sleep(500);
        Function::writeDialogue(", cops!");
        Sleep(500);
        Function::writeDialogue(" Well, that's super. I think it's time for me to go.'");
        Sleep(1500);
        Function::writeNarration("\n\tThe aging beggar dives into the embrace of darkness in a flash.");
        Sleep(1500);
        Function::writeNarration(" Does this mean you see him for\n\tthe last time?");
        Sleep(3500);
        Game::game[0].setCurrentLocation(&Location::locations["Street"]);
    }
    else {
        Function::writeDialogue("\t - 'All right, that is enough.");
        Sleep(1500);
        Function::writeDialogue("I saw the cops hanging around. It stopped\n\tbeing safe here, at least for me.");

        if (Npc::npcs["Bob"].getAttitude() == angry || Npc::npcs["Bob"].getAttitude() == hostile) Function::writeDialogue(" Be glad we don't have more of it left.'");
        else Function::writeDialogue(" Take care, kid.'");

        Sleep(1500);
        Function::writeNarration("\n\tThe aging beggar dives into the embrace of darkness in a flash.");
        Sleep(1500);
        Function::writeNarration(" Does this mean you see him for\n\tthe last time?\n\n");
        Game::pause();
        Game::game[0].setCurrentLocation(&Location::locations["Street"]);
    }
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::darkAlleyCrossroads()
{
    Logger::out("Function starts", "Event::darkAlleyCrossroads");
    Function::showHeroAction("Visit: " + Location::locations["DarkAlley"].getName() + ".\n");

    if (!Npc::npcs["Bob"].knowsHero())
    {
        Function::writeNarration("\tWhen you enter the alley, you hear a familiar voice.");
        Function::writeDialogue("\n\t- 'It's you again. Why don't you tell me something for one this time?'\n\n");
        //--------------------------------
        Function::clearChoices();
        Function::addChoice("Stop and finally find out what he wants.");
        Function::addChoice("Ignore him again.");
        Function::showChoices();
        //--------------------------------
        while (true)
        {
            heroChoice = Function::getChoice();

            if (heroChoice == 1)
            {
                Function::clearScreen();
                Function::showHeroAction("Stop and finally find out what he wants.");
                Function::writeNarration("\n\tYou stop and turn towards the owner of the voice.");
                Sleep(1500);
                Function::writeNarration(" His silhouette looms in the darkness. It's one of the homeless people who live here. What can he have for you?\n");
                dialogueWithBob();
                break;
            }
            else if (heroChoice == 2)
            {
                Function::clearScreen();
                Function::showHeroAction("Ignore him again.");
                Function::writeNarration("\n\tYou have a mysterious stranger for nothing. You speed up your step and leave him far behind\n\tyou. Whatever he wanted from you is no longer important.");
                Function::writeDialogue("\n\t- 'Don't show up here again if you don't want to get your teeth kicked in!'\n");
                Function::clearScreen();
                Game::game[0].setCurrentLocation(&Location::locations["Street"]);
                break;
            }
            else Logger::error("Entered invalid value of <b>heroChoice</b>", "Event::darkAlleyCrossroads"); continue;
        }
    }
    else
    {
        Function::writeNarration("\tWhen you enter an alley, you notice a sea of trash around you.");
        Sleep(1000);
        Function::writeNarration(" It's full of cardboard boxes,\n\told mechanical parts, and god knows what else.");

        if (!Hero::heroes[0].hasItem(&Item::items["AD13"]))
        {
            Sleep(1500);
            Function::writeNarration("\n\tMaybe you will find something interesting there...\n\n");
            //--------------------------------
            Function::clearChoices();
            Function::addChoice("Search the area for something valuable.");
            Function::addChoice("Go out of the alley.");
            Function::showChoices();
            //--------------------------------
            while (true)
            {
                heroChoice = Function::getChoice();

                if (heroChoice == 1)
                {
                    Sleep(1000);
                    acceleratorFinding();
                    Function::writeNarration("\n\tThere is nothing interesting here any more. Time to go back...\n");
                    Function::clearScreen();
                    Game::game[0].setCurrentLocation(&Location::locations["Street"]);
                    break;
                }
                else if (heroChoice == 2)
                {
                    std::cout << std::endl;
                    Function::clearScreen();
                    Game::game[0].setCurrentLocation(&Location::locations["Street"]);
                    break;
                }
                else Logger::error("Entered invalid value of <b>heroChoice</b>", "Event::darkAlleyCrossroads"); continue;
            }
        }
        else
        {
            Function::writeNarration("\n\tThere is nothing interesting here. Time to go back...\n\n");
            Game::pause();
            Function::clearScreen();
            Game::game[0].setCurrentLocation(&Location::locations["Street"]);
        }
    }
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ULICA
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::lookAtAmnesia()
{
    Logger::out("Function starts", "Event::lookAtAmnesia");

    if (!Npc::npcs["Bob"].knowsHero())
    {
        Function::writeNarration("\n\tYou walk out of the alley onto a street lit by neon lights on the opposite side. A large sign\n\tthat reads 'Amnesia' belongs to a nightclub.");
        Sleep(1000);
        Function::writeNarration(" A small crowd gathers outside the entrance to the\n\tbuilding. Some people are arguing with the bouncers.");
        Sleep(1500);
        Function::writeNarration(" Something smells here, it's probably trouble...\n\n");
    }
    else {
        Function::writeNarration("\n\tYou walk out of the alley onto a street lit by neon lights and the lamp of a police car on the\n\topposite side. A large sign that reads 'Amnesia' belongs to a nightclub.");
        Function::writeNarration(" Two cops interrogate\n\ta small crowd outside the entrance to the building.");
        Sleep(1500);
        Function::writeNarration(" Something smells here, it's probably trouble...\n\n");
    }
    //--------------------------------
    Function::clearChoices();
    Function::addChoice("Come closer and see what it's all about.");
    Function::addChoice("Take a look around the area.");
    Function::showChoices();
    //--------------------------------
    while (true)
    {
        heroChoice = Function::getChoice();

        if (heroChoice == 1)
        {
            Function::clearScreen();
            Function::showHeroAction("Come closer and see what it's all about.\n");

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
            Function::clearScreen();
            Function::showHeroAction("Take a look around the area.");
            Game::game[0].setCurrentLocation(&Location::locations["GunShop"]);
            break;
        }
        else Logger::error("Entered invalid value of <b>heroChoice</b>", "Event::lookAtAmnesia"); continue;
    }
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::encounterGunStore()
{
    Logger::out("Function starts", "Event::encounterGunStore");
    Function::writeNarration("\n\tYou go to the right side of the street. After walking several meters you come across a small\n\tbooth between blocks of flats.");

    if (bobRecommendsZed) Function::writeNarration(" Could it be that the famous gun store managed by Bob's friend?");

    std::cout << std::endl << std::endl;
    //--------------------------------
    Function::clearChoices();
    Function::addChoice("Go inside.");
    Function::addChoice("Turn back.");
    Function::showChoices();
    //--------------------------------
    while (true)
    {
        heroChoice = Function::getChoice();

        if (heroChoice == 1)
        {
            Function::clearScreen();
            Function::showHeroAction("Go inside.\n");
            enterGunShop();
            break;
        }
        else if (heroChoice == 2)
        {
            Function::clearScreen();
            Function::showHeroAction("Turn back.\n");

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
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::meetingWithSecurityGuards()
{
    Logger::out("Function starts", "Event::meetingWithSecurityGuards");
    Function::writeNarration("\tWhen you get closer, the faces turn toward you and start looking at you intently.");
    Sleep(1000);
    Function::writeNarration(" You pass\n\tthem in silenceand are confronted by a broad -\n\tshouldered security guard.");
    Function::writeDialogue("\n\t- 'What are you looking for here?");
    Sleep(1500);
    Function::writeDialogue(" Trouble, maybe?'");
    Function::writeNarration("\n\tThe man clenches his hands into fists and smiles unpleasantly.");
    Function::writeDialogue("\n\t- 'You asshole, better let us in! I want a drink and for fuck's sake. I'm losing my patience!");
    Function::writeNarration("\n\tOne of the men waiting in the queue rushes forward and threatens the bouncer with his fist.");
    Sleep(1500);
    Function::writeNarration("\n\tThe security guard's attention shifts from you to the furious guy next to you.");
    Function::writeDialogue("\n\t- 'I'll say it one last time: get the fuck out of here or you'll get fucked.'\n");
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::meetingWithPolicemans()
{
    Logger::out("Function starts", "Event::meetingWithPolicemans");

    if (Npc::npcs["Bob"].knowsHero()) Function::writeNarration("\tWhen you get closer, one of the police officers in a dark blue uniform turns toward you.");
    else {
        Function::writeNarration("\tIn an instant the street is filled with the howling of a police siren.");
        Sleep(1000);
        Function::writeNarration(" The reds and blues\n\tbegin to dance with each other on the sidewalk and the silhouettes of the people around you.");
        Sleep(2000);
        Function::writeNarration("\n\tTwo grim-looking guys in dark blue uniforms get out of a police car and walk towards you.\n\tOne of them points at you, taking out a tablet from behind his belt.");
    }

    Function::writeDialogue("\n\t- 'Who are you?");
    Sleep(1500);
    Function::writeDialogue(" And what are you doing here? Please show me your ID card.'");

    if (Hero::heroes[0].hasItem(&Item::items["AD13"])) Function::writeNarration("\n\tYou start searching through the pockets of your jacket and pants, but other than the accelerator\n\tyou found in the trash, there's nothing else there.");
    else Function::writeNarration("\n\tYou start searching through the pockets of your jacket and pants, but there's nothing there.");

    Function::writeDialogue("\n\t- 'I see that we have a problem.");
    Sleep(1500);
    Function::writeDialogue(" Okay, then what's your name, citizen?");

    if (!Npc::npcs["Bob"].knowsHero())
    {
        Function::writeDialogue("'\n");
        namingHero();
        Sleep(1500);
        Function::writeDialogue("\t- '" + Hero::heroes[0].getName() + "...");
        Sleep(1000);
        Function::writeDialogue(" Caden, check it out in the database.");
    }
    else {
        Function::writeDialogue(" " + Hero::heroes[0].getName() + "...");
        Sleep(1000);
        Function::writeDialogue(" Caden, check\n\tit out in the database.");
    }

    Npc::npcs["CadenPartner"].setToKnowHero();
    Npc::npcs["Caden"].setToKnowHero();
    Sleep(1500);
    Function::writeDialogue(" And you, stand where you are.'");
    Function::writeNarration("\n\tThe other police officer nods, gets back in the car, and it looks like he's connecting with\n\theadquarters.");
    Sleep(3000);
    Function::writeNarration("\n\tA minute later, the same policeman returns and whispers something in his partner's ear.");
    Sleep(1500);
    Function::writeNarration(" That\n\tone nods and turns to look at you.");
    Function::writeDialogue("\n\t- 'I have good news for you.");
    Sleep(1500);
    Function::writeDialogue(" You're free for now, just don't let it occur to you to do\n\tsomething here, or you'll end up in arrest at the police station.");
    Sleep(1000);
    Function::writeDialogue(" Caden, take care of the\n\trest of the attendees.'");
    Function::writeNarration("\n\tThe cop walks away to talk to the nearest person standing.");
    Function::writeDialogue("\n\t- 'If you're so pure, get in.'");
    Function::writeNarration("\n\tThe bouncer points to the door behind him.\n\n");
    //--------------------------------
    Function::clearChoices();
    Function::addChoice("Go inside.");
    Function::addChoice("Turn back.");
    Function::showChoices();
    //--------------------------------
    while (true)
    {
        heroChoice = Function::getChoice();

        if (heroChoice == 1)
        {
            Function::clearChoices();
            Function::clearScreen();
            Function::showHeroAction("Go inside.\n");
            Game::game[0].setCurrentLocation(&Location::locations["Nightclub"]);
            break;
        }
        else if (heroChoice == 2)
        {
            Function::clearChoices();
            Function::clearScreen();
            Function::showHeroAction("Turn back.\n");
            Game::game[0].setCurrentLocation(&Location::locations["GunShop"]);
            break;
        }
        else Logger::error("Entered invalid value of <b>heroChoice</b>", "Event::meetingWithPolicemans"); continue;
    }
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::streetCrossroads()
{
    Logger::out("Function starts", "Event::streetCrossroads");
    Function::showHeroAction("Visit: " + Location::locations["Street"].getName() + '.');
    Function::writeNarration("\n\tOnce again you are on a street bathed in nighttime darkness.\n\n");
    //--------------------------------
    Function::clearChoices();
    Function::addChoice("Visit: " + Location::locations["DarkAlley"].getName() + '.');
    Function::addChoice("Visit: " + Location::locations["Nightclub"].getName() + '.');
    Function::addChoice("Visit: " + Location::locations["GunShop"].getName() + '.');
    Function::showChoices();
    //--------------------------------
    while (true)
    {
        heroChoice = Function::getChoice();

        if (heroChoice == 1)
        {
            Function::clearScreen();
            Game::game[0].setCurrentLocation(&Location::locations["DarkAlley"]);
            break;
        }
        else if (heroChoice == 2)
        {
            Function::clearScreen();
            Game::game[0].setCurrentLocation(&Location::locations["Nightclub"]);
            break;
        }
        else if (heroChoice == 3)
        {
            Function::clearScreen();
            Game::game[0].setCurrentLocation(&Location::locations["GunShop"]);
            break;
        }
        else Logger::error("Entered invalid value of <b>heroChoice</b>", "Event::streetCrossroads"); continue;
    }
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// SKLEP Z BRONI¥
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::enterGunShop()
{
    Logger::out("Function starts", "Event::enterGunShop");
    Function::writeNarration("\tThe front door hisses open before you.");

    if (!Npc::npcs["Zed"].knowsHero())
    {
        Sleep(1000);
        Function::writeNarration(" You step over the threshold and enter a small room\n\twith a counter opposite the entrance. Behind it stands a tall, thin man with fatigue painted\n\ton his terribly oblong face.");
        Sleep(1500);
        Function::writeNarration(" He is dressed in an old corporate commando\n\tsuit. On the wall behind his back hangs a lot of weapons.");
        Function::writeDialogue("\n\t- 'How can I help you, my friend?'\n");
        Npc::npcs["Zed"].setToKnowHero();
        dialogueWithZed();
    }
    else {
        Sleep(1000);
        Function::writeNarration(" From behind the counter, Zed is already smiling at\n\tyou.");

        if (Hero::heroes[0].hasItem(&Item::items["Pistol"])) Function::writeDialogue("\n\t- 'What's up? How's the gun working out?'");

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
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::dialogueWithZed()
{
    Logger::out("Function starts", "Event::dialogueWithZed");
    bool heroTalkedAboutBusinessWithZed = false;

    while (true)
    {
        std::cout << std::endl;
        //--------------------------------
        Function::clearChoices();
        Function::addChoice("'What do you have?'");
        Function::addChoice("'How's business going?'");

        if (bobRecommendsZed && !zedKnowsAboutBobAndZed) Function::addChoice("'You're Zed? I come from Bob.'");

        Function::addChoice("'I have to go...'");
        Function::showChoices();
        //--------------------------------
        heroChoice = Function::getChoice();

        if (heroChoice == 1)
        {
            Function::clearScreen();
            Function::showHeroAction("'What do you have?'\n");
            zedTrade();
            continue;
        }
        else if (heroChoice == 2)
        {
            Function::clearScreen();
            Function::showHeroAction("'How's business going?'\n");

            if (heroTalkedAboutBusinessWithZed == true) Function::writeDialogue("\t- 'Hey, what's up? Are you sclerotic or something? We already talked about this, haha!'\n");
            else {
                heroTalkedAboutBusinessWithZed = true;
                Function::writeDialogue("\t- 'What kind of question is that anyway? Business is doing great! Everyone stops by\n\tevery now and then to rearm. It's the natural order of things.'\n");
            }

            continue;
        }
        else if (heroChoice == 3)
        {
            Function::clearScreen();

            if (bobRecommendsZed && !zedKnowsAboutBobAndZed)
            {
                zedKnowsAboutBobAndZed = true;
                Function::showHeroAction("'You're Zed? I come from Bob.'");
                Function::writeDialogue("\n\t- 'Yes, that is correct. I'm Zed, and this is my little shop.");
                Sleep(1000);
                Function::writeDialogue(" Since you know Bob,\n\tyou can get a small discount here.'");
                Npc::npcs["Zed"].setAttitude(friendly);
                continue;
            }
            else {
                Function::showHeroAction("'I have to go...'");
                Function::writeDialogue("\n\t- 'No problem. See you later!'\n");
                Function::clearScreen();

                if (!Npc::npcs["Caden"].knowsHero() && !Npc::npcs["CadenPartner"].knowsHero()) meetingWithPolicemans();
                else Game::game[0].setCurrentLocation(&Location::locations["Street"]);

                break;
            }
        }
        else if (heroChoice == 4 && bobRecommendsZed && !zedKnowsAboutBobAndZed)
        {
            Function::clearScreen();
            Function::showHeroAction("'I have to go...'");
            Function::writeDialogue("\n\t- 'No problem. See you later!'\n");
            Function::clearScreen();

            if (!Npc::npcs["Caden"].knowsHero() && !Npc::npcs["CadenPartner"].knowsHero()) meetingWithPolicemans();
            else Game::game[0].setCurrentLocation(&Location::locations["Street"]);

            break;
        }
        else Logger::error("Entered invalid value of <b>heroChoice</b>", "Event::dialogueWithZed"); continue;
    }
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::zedTrade()
{
    Logger::out("Function starts", "Event::zedTrade");
    bool ZedTellsAboutWeapons = false;

    if (!Hero::heroes[0].hasItem(&Item::items["Pistol"]))
    {
        if (!ZedTellsAboutWeapons)
        {
            ZedTellsAboutWeapons = true;
            Function::writeDialogue("\t- 'Better ask what I don't have!");
            Sleep(1000);
            Function::writeDialogue(" Look - ");
            Sleep(1000);
            Function::writeDialogue("rifles, pistols, machine guns, shotguns. I\n\thave a melee weapons as well. Knives, hammers, long blades like katanas...");
            Sleep(1500);
            Function::writeDialogue(" Anything\n\tyou want, my friend!");
            Sleep(1500);
            Function::writeDialogue(" Tell me, what do you like?'\n\n");
            //--------------------------------
            Function::clearChoices();
            Function::addChoice("Buy: pistol (250 $).");
            Function::addChoice("'I have made up my mind.'");
            Function::showChoices();
            //--------------------------------
            while (true)
            {
                heroChoice = Function::getChoice();

                if (heroChoice == 1)
                {
                    Function::clearScreen();
                    Function::showHeroAction("Buy: pistol (250 $).");
                    buyPistol();
                    break;
                }
                else if (heroChoice == 2)
                {
                    Function::clearScreen();
                    Function::showHeroAction("'I have made up my mind.'");
                    Function::writeNarration("\n\tZed looks at you pityingly and shrugs his shoulders.");
                    Function::writeDialogue("\n\t- 'No problem. It can happen to anyone.'\n");
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
            Function::clearChoices();
            Function::addChoice("Buy: pistol (250 $).");
            Function::addChoice("'I have made up my mind.'");
            Function::showChoices();
            //--------------------------------
            while (true)
            {
                heroChoice = Function::getChoice();

                if (heroChoice == 1)
                {
                    Function::clearScreen();
                    Function::showHeroAction("Buy: pistol (250 $).");
                    buyPistol();
                    break;
                }
                else if (heroChoice == 2)
                {
                    Function::clearScreen();
                    Function::showHeroAction("'I have made up my mind.'");
                    Function::writeNarration("\n\tZed looks at you pityingly and shrugs his shoulders.");
                    Function::writeDialogue("\n\t- 'No problem. It can happen to anyone.'\n");
                    dialogueWithZed();
                    break;
                }
                else Logger::error("Entered invalid value of <b>heroChoice</b>", "Event::zedTrade"); continue;
            }
        }
    }
    else
    {
        Function::changeConsoleColor();
        Function::write("\tYou have everything you need. There's no point in bothering Zed.\n");
        dialogueWithZed();
    }
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::buyPistol()
{
    Logger::out("Function starts", "Event::buyPistol");

    if (Hero::heroes[0].getMoney() != 250.0)
    {
        Function::writeDialogue("\n\t- 'I see you're low on cash.");
        Sleep(1000);
        Function::writeDialogue(" But don't worry, we'll sort it out somehow.");
        Sleep(1500);

        if (zedKnowsAboutBobAndZed)
        {
            Function::writeDialogue(" Hmm, you know Old Bob, that already means something.");
            Sleep(1000);
            Function::writeDialogue(" Let's just say I'll loan you this gun on a friendly basis.");

            Hero::heroes[0].addItem(&Item::items["Pistol"]);
            Function::changeConsoleColor(item);
            Function::write("\n\t" + Item::items["Pistol"].getName());
            Function::changeConsoleColor();
            Function::write(" gained.\n");
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
        Function::writeDialogue("\n\t- 'A pistol is a good start. Here, it's yours.'");

        Hero::heroes[0].addItem(&Item::items["Pistol"]);
        Function::changeConsoleColor(item);
        Function::write("\n\t" + Item::items["Pistol"].getName());
        Function::changeConsoleColor();
        Function::write(" was bought.\n");
    }
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::gunShopCrossroads()
{
    Logger::out("Function starts", "Event::gunShopCrossroads");
    enterGunShop();
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// KLUB NOCNY
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::enterClub()
{
    Logger::out("Function starts", "Event::enterClub");
    Function::writeNarration("\n\tAfter passing through the entrance your eardrums are slowly bursting from the loud music in\n\tthe club.");
    Sleep(1000);
    Function::writeNarration(" You walk through a short lobby and so arrive at a crowded room full of dancing\n\tpeople.");
    Sleep(1000);
    Function::writeNarration(" Disco balls hung from the ceiling net everything around with streaks of multi-colored\n\tlight.");
    Sleep(1000);
    Function::writeNarration(" Next to the dance floor is a bar, and behind it are several mechanically streamlined\n\tbartenders.\n\n");
    //--------------------------------
    Function::clearChoices();
    Function::addChoice("Go to the dance floor.");
    Function::addChoice("Go to the bar.");
    Function::addChoice("Back on the street.");
    Function::showChoices();
    //--------------------------------
    while (true)
    {
        heroChoice = Function::getChoice();

        if (heroChoice == 1)
        {
            Function::clearScreen();
            Function::showHeroAction("\nGo on the dance floor.");
            clubDanceFloor();
            break;
        }
        else if (heroChoice == 2)
        {
            Function::clearScreen();
            Function::showHeroAction("\nGo to the bar.");
            clubBar();
            break;
        }
        else if (heroChoice == 3)
        {
            Function::clearScreen();
            Function::showHeroAction("\nBack on the street.");
            Game::game[0].setCurrentLocation(&Location::locations["Street"]);
            break;
        }
        else Logger::error("Entered invalid value of <b>heroChoice</b>", "Event::enterClub"); continue;
    }
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::clubDanceFloor()
{
    Logger::out("Function starts", "Event::clubDanceFloor");

    if (!Npc::npcs["Nyx"].knowsHero())
    {
        Function::writeNarration("\n\tYou get on the dance floor.");
        Sleep(1000);
        Function::writeNarration(" A crowd of dancing people stretches out around you, rubbing\n\tagainst each other to the rhythm of the music.");
        Sleep(1500);
        Function::writeNarration(" Half-naked beauties are dancing in places\n\tthat look like pillars supporting the ceiling. You are not sure if they are real. There\n\tis a definite possibility that they are women, but somewhere in the back of your mind you\n\tthink they are just androids.");
        Sleep(1500);
        Function::writeNarration("\n\tYou start dancing yourself.");
        Sleep(1000);
        Function::writeNarration(" You are doing quite well when an attractive girl appears in\n\tfront of you. She's wearing a see-through, brightly coloured dress.");
        Sleep(1500);
        Function::writeNarration(" Is it a coincidence\n\tthat she has just appeared and is dancing so close to you?\n\n");
        //--------------------------------
        Function::clearChoices();
        Function::addChoice("'What do you want?'");
        Function::addChoice("'Hey, baby.'");
        Function::addChoice("Keep dancing with no words.");
        Function::showChoices();
        //--------------------------------
        while (true)
        {
            heroChoice = Function::getChoice();

            if (heroChoice == 1)
            {
                Function::clearScreen();
                Function::showHeroAction("'What do you want?'");
                Function::writeNarration("\n\tThe girl turns towards you and smiles with her snow-white teeth.");
                Function::writeDialogue("\n\t- 'Nothing will escape your attention. I am Nyx. I think you can help me.'");
                break;
            }
            else if (heroChoice == 2)
            {
                Function::clearScreen();
                Function::showHeroAction("'Hey, baby.'");
                Function::writeNarration("\n\tThe girl turns towards you and smiles with her snow-white teeth.");
                Function::writeDialogue("\n\t- 'Hi, stud. I've been watching you since you came in. I am Nyx.'");
                Function::writeNarration("\n\tWith the last word she comes closer to you turns her back on you and starts dancing very\n\tclose to you.");
                Function::writeDialogue("\n\t- 'I am looking for someone like you. I think you can help me.'");
                break;
            }
            else if (heroChoice == 3)
            {
                Function::clearScreen();
                Function::showHeroAction("Keep dancing with no words.");
                Function::writeNarration("\n\tThe girl turns towards you and smiles with her snow-white teeth.");
                Function::writeDialogue("\n\t- 'Hi, I am Nyx. Vinc, the owner, is my boyfriend. I think you can help me.'");
                break;
            }
            else Logger::error("Entered invalid value of <b>heroChoice</b>", "Event::clubDanceFloor"); continue;
        }

        miaMeeting();
    }
    else
    {
        Function::writeNarration("\n\tYou get on the dance floor.");
        Sleep(1000);
        Function::writeNarration(" It's quite crowded, but at least you can enjoy the beautiful views. You try to keep up with\n\tthe rest of the people dancing there. However, you quickly get tired and head for the exit.");
        Sleep(1500);
        Function::clearScreen();
        nightclubCrossroads();
    }
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::clubBar()
{
    Logger::out("Function starts", "Event::clubBar");
    heroIsAtBar = true;
    Function::writeNarration("\tWith a slow step, you approach the counter, settle comfortably on a stool, and lift your gaze to the barman in front of you.");
    Function::writeDialogue("\n\t- 'What's for you?'\n\n");

    while (true)
    {
        //--------------------------------
        Function::clearChoices();
        Function::addChoice("'Give me anything.'");
        Function::addChoice("'Who's in charge?'");
        Function::addChoice("'Bye.'");
        Function::showChoices();
        //--------------------------------
        heroChoice = Function::getChoice();

        if (heroChoice == 1)
        {
            Function::writeDialogue("\n\t- 'Okay.");
            Sleep(1000);
            Function::writeDialogue(" Let's see...'");
            Sleep(1500);
            Function::writeNarration("\n\tThe barman turns his back on you and looks through the bottles of alcohol. Finally, he selects one of them and pours its contents into a glass before placing it on the counter in front of you.");
            Sleep(1500);
            Function::writeNarration("\n\tYou reach for the vessel and empty it.");
            Sleep(1000);
            Function::writeNarration(" You feel a pleasant warmth spreading up your throat and further down your gullet.");
            continue;
        }
        else if (heroChoice == 2)
        {
            Function::writeNarration("\n\tThe bartender squints, hearing your question.");
            Function::writeDialogue("\n\t- 'You're not from around here, are you?");
            Sleep(1500);
            Function::writeDialogue(" My boss is Vincent Ramsey.");
            Sleep(1000);
            Function::writeDialogue(" He's a tough guy, so you'd better not make trouble, or it could end badly for you.'");
            continue;
        }
        else if (heroChoice == 3)
        {
            Function::writeNarration("\n\tThe bartender reaches for a glass from under the counter and starts wiping it down.");
            Function::writeDialogue("\n\t- 'Yeah, have fun.'");
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
    Function::clearChoices();
    Function::addChoice("'What is it about?'");
    Function::addChoice("Be silent and let her speak.");
    Function::showChoices();
    //--------------------------------
    while (true)
    {
        heroChoice = Function::getChoice();

        if (heroChoice == 1)
        {
            Function::clearScreen();
            Function::showHeroAction("'What is it about?'\n");
            break;
        }
        else if (heroChoice == 2)
        {
            Function::clearScreen();
            Function::showHeroAction("Be silent and let her speak.\n");
            break;
        }
        else Logger::error("Entered invalid value of <b>heroChoice</b>", "Event::miaMeeting"); continue;
    }

    Function::writeDialogue("\n\t- 'Vinc, the owner, is my boyfriend.");
    Sleep(1000);
    Function::writeDialogue(" I want him dead.'");
    Quest::quests["KillVincent"].start();
    Sleep(1500);
    Function::writeNarration("\n\tNyx takes your hand and leads you towards the toilet.");
    Function::writeDialogue("\n\t- 'Do you have a gun?'");

    if (Hero::heroes[0].hasItem(&Item::items["Pistol"]))
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
        Hero::heroes[0].addMoney(200);
        Function::changeConsoleColor(green);
        Function::write("\n\t200$");
        Function::changeConsoleColor();
        Function::write(" has been received.");
        Function::writeDialogue("\n\t- 'There is a gun shop nearby.");
        Function::writeDialogue(" It is run by a guy named Zed. Visit him before you head upstairs.'");
    }
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::clubUpstairs()
{
    Logger::out("Function starts", "Event::clubUpstairs");
    Function::writeNarration("\n\tYou go up a winding staircase. At the end of a short banister you will see a closed door\n\tguarded by another bulky individual.\n\n");
    //--------------------------------
    Function::clearChoices();
    Function::addChoice("Come closer.");
    Function::addChoice("Go back downstairs.");
    Function::showChoices();
    //--------------------------------
    while (true)
    {
        heroChoice = Function::getChoice();

        if (heroChoice == 1)
        {
            Function::clearScreen();
            Function::showHeroAction("Come closer.");
            Function::writeNarration("\n\tAre you brave or foolish enough to face the hammer man. You are stopped from taking another\n\tstep by his firm voice.");
            Function::writeDialogue("\n\t- 'What here?'");
            Npc::npcs["Jet"].setToKnowHero();
            dialogueWithJet();
            break;
        }
        else if (heroChoice == 2)
        {
            Function::clearScreen();
            Function::showHeroAction("Go back downstairs.");
            Function::writeNarration("\n\tYou don't dare to come closer, so like the last coward you turn back and return to the kingdom\n\tof loud music and dancing people.\n");
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
    Function::clearChoices();
    Function::addChoice("'I want to pass.'");
    Function::addChoice("'What is behind that door?'");

    if (Hero::heroes[0].hasItem(&Item::items["Pistol"]))
    {
        Function::addChoice("Kill him with a pistol.");
        Function::addChoice("Stun him with a pistol.");
    }

    Function::addChoice("It's time for me to go.");
    Function::showChoices();
    //--------------------------------
    while (true)
    {
        heroChoice = Function::getChoice();

        if (heroChoice == 1)
        {
            Function::clearScreen();
            Function::showHeroAction("'I want to pass.'\n");
            jetPoints += 1;
            break;
        }
        else if (heroChoice == 2)
        {
            Function::clearScreen();
            Function::showHeroAction("'What is behind that door?'\n");
            jetPoints += 1;
            break;
        }
        else if (heroChoice == 3 && !Hero::heroes[0].hasItem(&Item::items["Pistol"]))
        {
            Function::clearScreen();
            Function::showHeroAction("'It's time for me to go.'\n");
            Function::clearScreen();
            nightclub();
            break;
        }
        else if (heroChoice == 3 && Hero::heroes[0].hasItem(&Item::items["Pistol"]))
        {
            Function::clearScreen();
            Function::showHeroAction("Kill him with a pistol.\n");
            break;
        }
        else if (heroChoice == 4 && Hero::heroes[0].hasItem(&Item::items["Pistol"]))
        {
            Function::clearScreen();
            Function::showHeroAction("Stun him with a pistol.\n");
            break;
        }
        else if (heroChoice == 5 && Hero::heroes[0].hasItem(&Item::items["Pistol"]))
        {
            Function::clearScreen();
            Function::showHeroAction("'It's time for me to go.'\n");
            Function::clearScreen();
            nightclub();
            break;
        }
        else Logger::error("Entered invalid value of <b>heroChoice</b>", "Event::dialogueWithJet"); continue;
    }
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::vincentAssassination()
{
    Logger::out("Function starts", "Event::vincentAssassination");
    vincentOffice();
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::vincentOffice()
{
    Logger::out("Function starts", "Event::vincentOffice");
    Function::writeNarration("\tYou enter the manager's office immersed in twilight. In the middle of the room stands a sizable desk, and on it are stacks of documents and computer. To the left of the entrance is a window to the street below. On the right you will notice a door to another room.\n\n");
    //--------------------------------
    Function::clearChoices();
    Function::addChoice("Open the door and go into the other room.");
    Function::addChoice("Stay and search the office.");
    Function::showChoices();
    //--------------------------------
    while (true)
    {
        heroChoice = Function::getChoice();

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
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::checkVincentDesk()
{
    Logger::out("Function starts", "Event::checkVincentDesk");
    heroKnowsVincentCode = true;
    Function::showHeroAction("Stay and search the office.");
    Function::writeNarration("\n\tYou walk up to the desk. You start flipping through the e-papers one by one and finally your gaze falls on the flickering blue monitor.");
    Function::write("\n\t");

    vincentHideoutCode();
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::vincentHideoutCode()
{
    Logger::out("Function starts", "Event::vincentHideoutCode");
    Function::writeNarration("\n\tYou walk closer and spot the terminal. It looks like you'll need to use a code to get through.");
    Sleep(1500);

    if (!heroKnowsVincentCode)
    {
        Function::writeNarration(" You have to look around the office though, whether you want to or not.");
    }
    else {
        std::cout << std::endl << std::endl;
        //--------------------------------
        Function::clearChoices();
        Function::addChoice("Use code '2021'.");
        Function::addChoice("Search the office.");
        Function::showChoices();
        //--------------------------------
    }
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::vincentHideout()
{
    Logger::out("Function starts", "Event::vincentHideout");
    Npc::npcs["Vincent"].setStatus(unconscious);
    Function::writeNarration("\n\tThe door closes behind you, hissing quietly.");
    Sleep(2000);
    Function::writeNarration(" The room you're in is full of smaller and larger\n\tcables that merge into a single monitor that hangs above the sim-chair. On it lies a big guy\n\tin a tailored suit and a stimulation helmet on his head that obscures his face.");
    Sleep(1500);
    Function::writeNarration(" You guess it's\n\tVincent, the club owner.");
    Sleep(2000);
    Function::writeNarration("\n\tCreeping up, you come closer. Your goal is within reach. The question is what will you do?\n\n");
    //--------------------------------
    Function::clearChoices();
    Function::addChoice("Disconnect his consciousness from the neuronet. (Kill him)");
    Function::addChoice("Wait for his consciousness to leave the neuronet.");
    Function::showChoices();
    //--------------------------------
    while (true)
    {
        heroChoice = Function::getChoice();

        if (heroChoice == 1)
        {
            Function::clearScreen();
            Function::showHeroAction("Disconnect his consciousness from the neuronet. (Kill him)");
            Function::writeNarration("\n\tYou lean over Vincent and, in a fluid motion without hesitation, pull the stimulation helmet\n\toff his head. You witness the nightclub owner being shaken by a wave of convulsions. Foam\n\tbegins to come out of his mouth and after a moment the man freezes.");
            Sleep(1500);
            Npc::npcs["Vincent"].setStatus(dead);
            Function::writeNarration(" He's probably dead, just like\n\tNyx wanted.");
            break;
        }
        else if (heroChoice == 2)
        {
            Function::clearScreen();
            Function::showHeroAction("Wait for his consciousness to leave the neuronet.");
            Function::writeNarration("\n\tYou are not a coward.");
            Sleep(1000);
            Function::writeNarration(" You don't stab people in the back. That's not your style. You prefer an\n\topen fight.");
            Sleep(1500);
            Npc::npcs["Vincent"].setStatus(normal);
            Function::writeNarration(" After a while, you notice Vincent moving slightly in his seat. He opens his eyes -\n\tthey are shining with the excitement of his online adventure.");
            Sleep(1000);
            Function::writeNarration(" It is only a matter of time before\n\tVincent notices your presence. There is no turning back now.");
            Function::writeDialogue("\n\t- 'What the fuck are you doing here, dickhead?'\n");
            dialogueWithVincent();
            break;
        }
        else Logger::error("Entered invalid value of <b>heroChoice</b>", "Event::vincentHideout"); continue;
    }
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::dialogueWithVincent()
{
    Logger::out("Function starts", "Event::dialogueWithVincent");
    std::cout << std::endl << std::endl;
    //--------------------------------
    Function::clearChoices();
    Function::addChoice("'Die!'");
    Function::addChoice("'I don't want to fight with you.'");
    Function::addChoice("'Nyx wants you dead.'");
    Function::showChoices();
    //--------------------------------
    while (true)
    {
        heroChoice = Function::getChoice();

        if (heroChoice == 1)
        {
            Function::clearScreen();
            Function::showHeroAction("'Die!'");
            Function::writeNarration("\n\tWith a shout, you bring out your gun and aim it at Vincent's chest.");
            Function::writeDialogue("\n\t- 'Are you such a hero?");
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
            Function::writeNarration("\n\tYou are not a coward.");
            Sleep(1000);
            Function::writeNarration(" You don't stab people in the back. That's not your style. You prefer an\n\topen fight.");
            break;
        }
        else if (heroChoice == 3)
        {
            Function::clearScreen();
            Function::showHeroAction("'Nyx wants you dead.'");
            Function::writeNarration("\n\tYou are not a coward. You don't stab people in the back. That's not your style. You prefer an open fight.");
            break;
        }
        else Logger::error("Entered invalid value of <b>heroChoice</b>", "Event::dialogueWithVincent"); continue;
    }

    std::cout << std::endl << std::endl;
    //--------------------------------
    Function::clearChoices();
    Function::addChoice("'It doesn't matter.'");
    Function::addChoice("'Your girlfriend, Nyx.'");
    Function::showChoices();
    //--------------------------------
    while (true)
    {
        heroChoice = Function::getChoice();

        if (heroChoice == 1)
        {
            Function::clearScreen();
            Function::showHeroAction("'It doesn't matter.'");
            Function::writeDialogue("\n\t- 'Ugh, you little prick. I'll get you from beyond the grave. There will be no peace. I won't let that happen!'");
            Sleep(1500);
            Function::writeNarration("\n\tThe last word spoken synchronizes with the bang of a gunshot as a bullet of energy pierces the club owner's chest.");
            Sleep(1000);
            Function::writeNarration(" The recoil knocks him from his seat. The lifeless body clatters against the floor.");
            Sleep(1500);
            Function::writeNarration(" He's dead, just like Nyx wanted.");
            Npc::npcs["Vincent"].setStatus(dead);
            Function::writeNarration("\n\tOut of curiosity, you walk closer and spot the corpse holding a small pistol.");
            Sleep(1000);
            Function::writeNarration(" That bastard was playing for time after all!");
            break;
        }
        else if (heroChoice == 2)
        {
            Function::clearScreen();
            Function::showHeroAction("'Your girlfriend, Nyx.'");
            Function::writeDialogue("\n\t- 'Traitorous bitch! She'll get her due someday.");
            Function::writeDialogue(" All right, shithead, let's get this over with.'");
            Function::writeNarration("\n\tThe last word spoken synchronizes with the bang of a gunshot as a bullet of energy pierces the club owner's chest.");
            Sleep(1000);
            Function::writeNarration(" The recoil knocks him from his seat. The lifeless body clatters against the floor.");
            Sleep(1500);
            Function::writeNarration(" He's dead, just like Nyx wanted.");
            Npc::npcs["Vincent"].setStatus(dead);
            Function::writeNarration("\n\tOut of curiosity, you walk closer and spot the corpse holding a small pistol.");
            Sleep(1000);
            Function::writeNarration(" That bastard was playing for time after all!");
            break;
        }
        else Logger::error("Entered invalid value of <b>heroChoice</b>", "Event::dialogueWithVincent"); continue;
    }

    Function::writeNarration("\n\tThe passage behind your back is opened.");
    Sleep(1000);
    Function::writeNarration(" You turn around, in front of you is Nyx.");
    Function::writeDialogue("\n\t- 'Did you do what I asked you to do...'");
    Sleep(1500);
    Function::writeNarration("\n\tThe girl's gaze wanders from you to the body of her ex-boyfriend behind you.");
    Sleep(1000);
    Function::writeDialogue("\n\t- 'You did it... You really did it... Is he - is he dead?'");
    Sleep(1000);
    Function::writeNarration("\n\tNyx walks past you and kneels by the dead man. She starts searching his pockets for something.\n\n");
    //--------------------------------
    Function::clearChoices();
    Function::addChoice("Do nothing.");
    Function::addChoice("'What is this all about?'");
    Function::showChoices();
    //--------------------------------
    while (true)
    {
        heroChoice = Function::getChoice();

        if (heroChoice == 1)
        {
            Function::writeNarration("\n\tYou let the girl quietly plunder the corpse. This gives you more time to look at her shapes more closely.");
            Function::writeDialogue("\n\t- 'Spare me, if you please.'");
            break;
        }
        else if (heroChoice == 2)
        {
            Function::writeDialogue("\n\t- 'Well, now I think I owe you an explanation.'");
            Function::writeNarration("\n\tA girl talks to you without even looking at you.\n");
            break;
        }
        else Logger::error("Entered invalid value of <b>heroChoice</b>", "Event::dialogueWithVincent"); continue;
    }

    vincentResurrection();
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::vincentResurrection()
{
    Logger::out("Function starts", "Event::vincentResurrection");
    Function::writeNarration("\n\tSuddenly, the maze of cables begins to vibrate and move in a strange dance.");
    Sleep(1000);
    Function::writeNarration(" Hisses reach you and Nyx, forming a gibberish that is difficult to understand.");
    Function::changeConsoleColor(dia_robot);
    Function::write("\n\t<You scum! You thought you got rid of me.");
    Sleep(1000);
    Function::write(" But you didn't.");
    Sleep(1000);
    Function::write(" I'm immortal now!>");
    Function::writeNarration("\n\tYou exchange a look with Nyx. You both can't believe what's happening.");
    Function::writeDialogue("\n\t- 'What the fuck?!'");
    Function::changeConsoleColor(dia_robot);
    Function::write("\n\t<Before your new lover killed me, sweatheart, I managed to pour some of my consciousness into the net. I don't need my body anymore, nothing limits me anymore.");
    Sleep(1500);
    Function::changeConsoleColor(dia_robot);
    Function::write(" Now you will get what you deserve. The time for payment has come!");
    Sleep(1000);
    Function::write(" DIE!>");
    Function::waitForUserInput();
}
void Event::nightclubCrossroads()
{
    Logger::out("Function starts", "Event::nightclubCrossroads");

    Function::showHeroAction("Visit: " + Location::locations["Nightclub"].getName() + ".\n");
    Function::writeNarration("\n\tYou enter from a fairly well-lit street into a slightly darkened nightclub, trembling with colour.\n\n");
    //--------------------------------
    Function::clearChoices();
    Function::addChoice("Go to the dance floor.");
    Function::addChoice("Go to the bar.");
    Function::addChoice("Go upstairs.");
    Function::addChoice("Visit: " + Location::locations["Street"].getName() + ".");
    Function::showChoices();
    //--------------------------------
    while (true)
    {
        heroChoice = Function::getChoice();

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
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// KRYJÓWKA ŒNI¥CYCH
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::actOne()
{
    Logger::out("Function starts", "Event::actOne");

    if (Game::game[0].getLang() == en) Function::write("\n\tAct One");
    else Function::write("\n\tAkt pierwszy");

    Sleep(2000);

    if (Game::game[0].getLang() == en) Function::write("\n\n\tPROSELYTISM");
    else Function::write("\n\n\tNAWRÓCENIE");

    Sleep(5000);
    Function::clearScreen();
    storyIntroduction();
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// INNE
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::loadingFiles()
{
    Logger::out("Function starts", "Event::loadingFiles");
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
    Function::write("\n\tDownload completed.");
    Function::changeConsoleColor();
}

void Event::namingHero()
{
    Logger::out("Function starts", "Event::namingHero");
    std::string heroName;
    Function::changeConsoleColor();
    std::cout << std::endl;
    heroName = Function::getString();
    Hero::heroes[0].setName(heroName);
    Logger::out("Set <b>" + Hero::heroes[0].getName() + "</b> to hero's name", "Event::namingHero");
}