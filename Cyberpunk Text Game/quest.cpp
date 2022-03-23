#include "quest.h"

std::map <std::string, Quest> Quest::quests;

Quest::Quest()
{
    this->name = "None";
    this->description = "None";
    this->status = "unknown";
    this->running = false;
    this->completed = false;
}

Quest::Quest(std::string name, std::string description)
{
    this->name = name;
    this->description = description;
    this->status = "unknown";
    this->running = false;
    this->completed = false;
}

Quest::Quest(std::string name, std::string description, std::string status, bool running, bool completed)
{
    this->name = name;
    this->description = description;
    this->status = status;
    this->running = running;
    this->completed = completed;
}

Quest::~Quest()
{
}

void Quest::start()
{
    this->running = true;
    this->status = "ongoing";

    std::fstream q;
    q.open("quests.txt", std::ios::out | std::ios::app);

    if (q.good())
    {
        Logger::out("Access to txt file", "Quest::start");
        q << "  Name: " << this->getName() << std::endl;
        q << "  Description: " << this->getDescription() << std::endl;
        q << "  Status: " << this->getStatus() << std::endl;
        q << "..........................................................................." << std::endl;
        q.close();
    }
    else Logger::error("No file access", "Quest::start");
}

void Quest::end()
{
    this->running = false;
    this->completed = true;
    this->status = "completed";

    std::string quests[2];
    std::string header, breakLine, questName[1], questDesc[1], questStatus[1], questsLine;
    int questNr = 0;
    int lineNr = 1;

    std::fstream q;
    q.open("quests.txt", std::ios::in | std::ios::out | std::ios::app);

    if (q.good())
    {
        Logger::out("Access to txt file", "Quest::end");

        while (getline(q, questsLine))
        {
            switch (lineNr)
            {
            case 1: header = questsLine; break;
            case 2: breakLine = questsLine;  break;
            case 3: questName[questNr] = questsLine; break;
            case 4: questDesc[questNr] = questsLine; break;
            case 5: questStatus[questNr] = questsLine; break;
            }

            if (lineNr == 5)
            {
                getline(q, questsLine);
                std::cout << "  Status: " << this->status;
                lineNr = 3;
                questNr++;
            }

            lineNr++;
        }

        q.close();
    }
    else Logger::error("No file access", "Quest::end");
}

void Quest::initQuests()
{
    Logger::out("Function start", "Quest::initQuests");

    Quest KillVincent("Beauty and the Beast", "Kill 'Amnesia' nightclub owner Vincent Ramsey at the request of his girlfriend, Mia.");
    Quest ZedAccelerator("Shades of the Past", "Bring Zed an old model of an accelerator. In return you will receive a gun from him.");

    quests["KillVincent"] = KillVincent;
    quests["ZedAccelerator"] = ZedAccelerator;
}

