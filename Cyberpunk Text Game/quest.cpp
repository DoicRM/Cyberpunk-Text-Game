#include "quest.h"

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
    q << "  Name: " << this->name << std::endl;
    q << "  Description: " << this->description << std::endl;
    q << "  Status: " << this->status << std::endl;
    q << "..........................................................................." << std::endl;
    q.close();
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

