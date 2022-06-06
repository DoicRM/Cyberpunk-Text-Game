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
            Logger::out("<b>" + quest->getName() + "</b> added to journal", __FUNCTION__);
    }

    quest->start();
    updateJournalFile();
}

void Journal::endQuest(Quest* quest)
{
    quest->end();

    if (quest->getIsCompleted())
        Logger::out("<b>" + quest->getName() + "</b> ended", __FUNCTION__);

    updateJournalFile();
}

void Journal::updateJournalFile()
{
    std::ofstream q;
    q.open("journal.txt");

    if (q.good())
    {
        Logger::out("Access to txt file", __FUNCTION__);

        if (questsList.empty())
        {
            q << jWriter.at("JournalInfos").value("NoQuestsInJournal", JSON_VALUE_ERROR) << std::endl;
        }
        else
        {
            for (auto i : questsList)
            {
                q << jWriter.at("QuestsInfos").value("Name", JSON_VALUE_ERROR) << i->getName() << std::endl;
                q << jWriter.at("QuestsInfos").value("Description", JSON_VALUE_ERROR) << i->getDescription() << std::endl;
                q << jWriter.at("QuestsInfos").value("Status", JSON_VALUE_ERROR) << i->printStatus() << std::endl;
                q << "..........................................................................." << std::endl;
            }
        }

        q.close();
    }
    else Logger::error("No file access", __FUNCTION__);
}

void Journal::clearJournal()
{
    questsList.clear();

    if (questsList.empty())
        Logger::out("Journal is empty", __FUNCTION__);
    
    updateJournalFile();
}