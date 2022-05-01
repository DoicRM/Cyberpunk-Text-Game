#pragma once
#include "../quest/quest.hpp"
#include "../utilities/languageHandler/languageHandler.hpp"
#include <vector>

class Journal
{
public:
    Journal();
    virtual ~Journal();

    void addQuest(Quest* quest);
    void endQuest(Quest* quest);
    void updateJournalFile();
    void clearJournal();

private:
    std::vector<Quest*>questsList;
};