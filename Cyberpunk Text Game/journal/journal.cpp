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
            q << "..." << std::endl;
        }
        else
        {
            for (int i = 0; i < questsList.size(); i++)
            {
                q << "Name: " << questsList[i]->getName() << std::endl;
                q << "Description: " << questsList[i]->getDescription() << std::endl;
                q << "Status: " << questsList[i]->printStatus() << std::endl;
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