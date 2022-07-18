#pragma once
#include "../Quest/Quest.hpp"
#include "../Utilities/JsonHandler/JsonHandler.hpp"
#include <vector>

class Journal
{
public:
    Journal();
    virtual ~Journal();

    void addQuest(Quest* quest);
    void endQuest(Quest* quest, int status);
    void updateJournalFile();
    void clearJournal();

private:
    std::vector<Quest*>questsList;
};