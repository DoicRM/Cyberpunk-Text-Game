#include "quest.h"

Quest::Quest(string n, string d, string s, bool ir, bool ic)
{
    name = n;
    description = d;
    status = s;
    isRunning = ir;
    isComplete = ic;
}

Quest::~Quest()
{

}

void Quest::addQuest()
{
    isRunning = true;
    status = "ongoing";

    fstream q;
    q.open("quests.txt", ios::out | ios::app);
    q << "  Name: " << name << endl;
    q << "  Description: " << description << endl;
    q << "  Status: " << status << endl;
    q << "..........................................................................." << endl;
    q.close();
}

void Quest::endQuest()
{
    isRunning = false;
    isComplete = true;
    status = "completed";

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
            cout << "  Status: " << status;
            lineNr = 3;
            questNr++;
        }

        lineNr++;
    }

    q.close();
}

bool Quest::isQuestRunning()
{
    if (!isComplete) return true;
    else return false;
}

bool Quest::isQuestCompleted()
{
    if (!isRunning) return true;
    else return false;
}

