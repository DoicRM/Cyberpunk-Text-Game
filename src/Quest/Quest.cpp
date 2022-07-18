#include "Quest.hpp"

std::map <std::string, Quest> Quest::quests;

Quest::Quest()
{
    this->name = "None";
    this->description = "None";
    this->status = Log::NotStarted;
    this->isRunning = false;
    this->isCompleted = false;
}

Quest::Quest(std::string name, std::string description)
{
    this->name = name;
    this->description = description;
    this->status = Log::NotStarted;
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
    this->status = Log::Running;

    Console::resetConsoleColor();
    Display::write((std::string)json["journal"]["entry"] + this->getName() + "\n");
}

void Quest::end(int status)
{
    this->isRunning = false;
    this->isCompleted = true;
    this->status = status;
}

std::string Quest::printStatus()
{
    if (this->status == Log::Running)
    {
        return json["log"]["running"];
    }
    else if (this->status == Log::Success)
    {
        return json["log"]["success"];
    }
    else if (this->status == Log::Failed)
    {
        return json["log"]["failed"];
    }
    else if (this->status == Log::Obsolete)
    {
        return json["log"]["obsolete"];
    }

    return json["questStatus"]["notStarted"];
}

void Quest::initQuests()
{
    Logger::startFuncLog(__FUNCTION__);

    Quest KillVincent(json["quests"]["killVincent"]["name"], json["quests"]["killVincent"]["description"]);
    Quest ZedAccelerator(json["quests"]["zedAccelerator"]["name"], json["quests"]["zedAccelerator"]["description"]);

    quests["KillVincent"] = KillVincent;
    quests["ZedAccelerator"] = ZedAccelerator;
}