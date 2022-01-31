#include "quest.h"

Quest::Quest()
{
    this->name = "None";
    this->description = "None";
    this->status = "unknown";
    this->running = false;
    this->completed = false;
}

Quest::Quest(string name, string description)
{
    this->name = name;
    this->description = description;
    this->status = "unknown";
    this->running = false;
    this->completed = false;
}

Quest::Quest(string name, string description, string status, bool running, bool completed)
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

    fstream q;
    q.open("quests.txt", ios::out | ios::app);
    q << "  Name: " << this->name << endl;
    q << "  Description: " << this->description << endl;
    q << "  Status: " << this->status << endl;
    q << "..........................................................................." << endl;
    q.close();
}

void Quest::end()
{
    this->running = false;
    this->completed = true;
    this->status = "completed";

    string quests[2];
    string header, breakLine, questName[1], questDesc[1], questStatus[1], questsLine;
    int questNr = 0;
    int lineNr = 1;

    fstream q;
    q.open("quests.txt", ios::in | ios::out | ios::app);

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
            cout << "  Status: " << this->status;
            lineNr = 3;
            questNr++;
        }

        lineNr++;
    }

    q.close();
}

