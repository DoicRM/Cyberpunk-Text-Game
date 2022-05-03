#include "journal.hpp"

Journal::Journal()
{
}

Journal::~Journal()
{
}

void Journal::addQuest(Quest* quest)
{
    questsList.push_back(quest);

    for (auto i : questsList)
    {
        if (i == quest)
            Logger::out("<b>" + quest->getName() + "</b> added to journal", "Journal::addQuest");
    }

    quest->start();
    updateJournalFile();
}

void Journal::endQuest(Quest* quest)
{
    quest->end();

    if (quest->getIsCompleted())
        Logger::out("<b>" + quest->getName() + "</b> ended", "Journal::addQuest");

    updateJournalFile();
}

void Journal::updateJournalFile()
{
    std::ofstream q;
    q.open("journal.txt");

    if (q.good())
    {
        Logger::out("Access to txt file", "Journal::updateJournalFile");

        if (questsList.empty())
        {
            q << j["JournalInfos"].value("NoQuestsInJournal","") << std::endl;
        }
        else
        {
            for (auto i : questsList)
            {
                q << j["QuestsInfos"].value("Name", "") << i->getName() << std::endl;
                q << j["QuestsInfos"].value("Description", "") << i->getDescription() << std::endl;
                q << j["QuestsInfos"].value("Status", "") << i->printStatus() << std::endl;
                q << "..........................................................................." << std::endl;
            }
        }

        q.close();
    }
    else Logger::error("No file access", "Journal::updateJournalFile");
}

void Journal::clearJournal()
{
    questsList.clear();

    if (questsList.empty())
        Logger::out("Journal is empty", "Journal::clearJournal");
    
    updateJournalFile();
}