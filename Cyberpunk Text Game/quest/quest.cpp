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
    Display::write(jWriter.at("JournalInfos").value("JournalEntry", JSON_VALUE_ERROR) + this->getName() + "\n");
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

    if (this->status == Ongoing) status = jWriter.at("QuestStatus").value("Ongoing", JSON_VALUE_ERROR);
    else if (this->status == Completed) status = jWriter.at("QuestStatus").value("Completed", JSON_VALUE_ERROR);
    else status = jWriter.at("QuestStatus").value("NotStarted", JSON_VALUE_ERROR);

    return status;
}

void Quest::initQuests()
{
    Logger::startFuncLog(__FUNCTION__);

    Quest KillVincent(jWriter.at("Quests").at("KillVincent").value("Name", JSON_VALUE_ERROR), jWriter.at("Quests").at("KillVincent").value("Description", JSON_VALUE_ERROR));
    Quest ZedAccelerator(jWriter.at("Quests").at("ZedAccelerator").value("Name", JSON_VALUE_ERROR), jWriter.at("Quests").at("ZedAccelerator").value("Description", JSON_VALUE_ERROR));

    quests["KillVincent"] = KillVincent;
    quests["ZedAccelerator"] = ZedAccelerator;
}