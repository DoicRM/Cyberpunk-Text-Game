#pragma once
#include "game.h"

using namespace std;

class Quest
{
    string name;
    string description;
    string status;
    bool isRunning;
    bool isComplete;

public:
    Quest(string = "none", string = "none", string = "unknown", bool = no, bool = no);
    virtual ~Quest();

    inline const string& getName() const { return this->name; };
    inline const string& getDescription() const { return this->description; };
    inline const string& getStatus() const { return this->status; };

    void addQuest();
    void endQuest();
    bool isQuestRunning();
    bool isQuestCompleted();

    enum yesAndNo
    {
        no = 0,
        yes
    };
};
