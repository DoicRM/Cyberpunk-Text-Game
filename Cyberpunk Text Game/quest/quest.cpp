#include "quest.hpp"

std::map <std::string, Quest> Quest::quests;

Quest::Quest()
{
    this->name = "None";
    this->description = "None";
    this->status = NotStarted;
    this->isRunning = false;
    this->isCompleted = false;
}

Quest::Quest(std::string name, std::string description)
{
    this->name = name;
    this->description = description;
    this->status = NotStarted;
    this->isRunning = false;
    this->isCompleted = false;
}

Quest::Quest(std::string name, std::string description, int status, bool isRunning, bool isCompleted)
{
    this->name = name;
    this->description = description;
    this->status = status;
    this->isRunning = isRunning;
    this->isCompleted = isCompleted;
}

Quest::~Quest()
{
}

void Quest::start()
{
    this->isCompleted = false;
    this->isRunning = true;
    this->status = Ongoing;

    Console::resetConsoleColor();
    Display::write("\n\tNew quest added to the journal: " + this->getName() + "\n");
}

void Quest::end()
{
    this->isRunning = false;
    this->isCompleted = true;
    this->status = Completed;
}

std::string Quest::printStatus()
{
    std::string status;

    if (this->status == Ongoing) status = "ongoing";
    else if (this->status == Completed) status = "completed";
    else status = "not started";

    return status;
}

void Quest::initQuests_EN()
{
    Logger::out("Function starts", "Quest::initQuests_EN");

    Quest KillVincent("Beauty and the Beast", "Kill 'Amnesia' nightclub owner Vincent Ramsey at the request of his girlfriend, Nyx.");
    Quest ZedAccelerator("Shades of the Past", "Bring Zed an old model of an accelerator. In return you will receive a gun from him.");

    quests["KillVincent"] = KillVincent;
    quests["ZedAccelerator"] = ZedAccelerator;
}

void Quest::initQuests_PL()
{
    Logger::out("Function starts", "Quest::initQuests_PL");

    Quest KillVincent("Piêkna i bestia", "Zabij w³aœciciela klubu nocnego 'Amnezja', Vincenta Ramseya, na proœbê jego dziewczyny, Nyx.");
    Quest ZedAccelerator("Cienie przesz³oœci", "Przynieœ Zedowi stary model akumulatora. W zamian otrzymasz od niego pistolet.");

    quests["KillVincent"] = KillVincent;
    quests["ZedAccelerator"] = ZedAccelerator;
}