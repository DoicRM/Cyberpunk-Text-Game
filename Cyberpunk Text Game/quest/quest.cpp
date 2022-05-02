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
    Display::write(JSON::getValue("JournalEntry") + this->getName() + "\n");
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

void Quest::initQuests()
{
    Logger::out("Function starts", "Quest::initQuests");

    Quest KillVincent(JSON::getValue("Quest_KillVincent_Name"), JSON::getValue("Quest_KillVincent_Desc"));
    Quest ZedAccelerator(JSON::getValue("Quest_ZedAccelerator_Name"), JSON::getValue("Quest_ZedAccelerator_Desc"));

    quests["KillVincent"] = KillVincent;
    quests["ZedAccelerator"] = ZedAccelerator;
}