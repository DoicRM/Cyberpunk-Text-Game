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
    Display::write((std::string)jWriter["JournalInfos"]["JournalEntry"] + this->getName() + "\n");
}

void Quest::end()
{
    this->isRunning = false;
    this->isCompleted = true;
    this->status = Completed;
}

std::string Quest::printStatus()
{
    if (this->status == Ongoing)
    {
        return jWriter["QuestStatus"]["Ongoing"];
    }
    else if (this->status == Completed)
    {
        return jWriter["QuestStatus"]["Completed"];
    }

    return jWriter["QuestStatus"]["NotStarted"];
}

void Quest::initQuests()
{
    Logger::startFuncLog(__FUNCTION__);

    Quest KillVincent(jWriter["Quests"]["KillVincent"]["Name"], jWriter["Quests"]["KillVincent"]["Description"]);
    Quest ZedAccelerator(jWriter["Quests"]["ZedAccelerator"]["Name"], jWriter["Quests"]["ZedAccelerator"]["Description"]);

    quests["KillVincent"] = KillVincent;
    quests["ZedAccelerator"] = ZedAccelerator;
}