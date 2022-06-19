#include "quest.hpp"

std::map <std::string, Quest> Quest::quests;

Quest::Quest()
{
    this->name = "None";
    this->description = "None";
    this->status = QuestStatus::NotStarted;
    this->isRunning = false;
    this->isCompleted = false;
}

Quest::Quest(std::string name, std::string description)
{
    this->name = name;
    this->description = description;
    this->status = QuestStatus::NotStarted;
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
    this->status = QuestStatus::Ongoing;

    Console::resetConsoleColor();
    Display::write((std::string)jWriter["journal"]["entry"] + this->getName() + "\n");
}

void Quest::end()
{
    this->isRunning = false;
    this->isCompleted = true;
    this->status = QuestStatus::Completed;
}

std::string Quest::printStatus()
{
    if (this->status == Ongoing)
    {
        return jWriter["questStatus"]["ongoing"];
    }
    else if (this->status == Completed)
    {
        return jWriter["questStatus"]["completed"];
    }

    return jWriter["questStatus"]["notStarted"];
}

void Quest::initQuests()
{
    Logger::startFuncLog(__FUNCTION__);

    Quest KillVincent(jWriter["quests"]["killVincent"]["name"], jWriter["quests"]["killVincent"]["description"]);
    Quest ZedAccelerator(jWriter["quests"]["zedAccelerator"]["name"], jWriter["quests"]["zedAccelerator"]["description"]);

    quests["KillVincent"] = KillVincent;
    quests["ZedAccelerator"] = ZedAccelerator;
}