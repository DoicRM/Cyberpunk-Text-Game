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
    Display::write(jWriter["JournalInfos"].value("NoQuestsInJournal", "") + this->getName() + "\n");
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

    if (this->status == Ongoing) status = jWriter["QuestStatus"].value("Ongoing","");
    else if (this->status == Completed) status = jWriter["QuestStatus"].value("Completed", "");
    else status = jWriter["QuestStatus"].value("NotStarted", "");

    return status;
}

void Quest::initQuests()
{
    Logger::out("Function starts", "Quest::initQuests");

    Quest KillVincent(jWriter["Quests"]["KillVincent"].value("Name", ""), jWriter["Quests"]["KillVincent"].value("Description", ""));
    Quest ZedAccelerator(jWriter["Quests"]["ZedAccelerator"].value("Name", ""), jWriter["Quests"]["ZedAccelerator"].value("Description", ""));

    quests["KillVincent"] = KillVincent;
    quests["ZedAccelerator"] = ZedAccelerator;
}