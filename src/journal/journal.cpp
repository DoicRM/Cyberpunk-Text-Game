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
        {
            Logger::out("<b>" + quest->getName() + "</b> added to journal", __FUNCTION__);
        }
    }

    quest->start();
    updateJournalFile();
}

void Journal::endQuest(Quest* quest)
{
    if (!quest->getIsCompleted())
    {
        quest->end();
        updateJournalFile();
    }

    Logger::out("<b>" + quest->getName() + "</b> ended", __FUNCTION__);
}

void Journal::updateJournalFile()
{
    std::ofstream quests;
    quests.open("journal.txt");

    if (!quests.good())
    {
        return Logger::error("No file access", __FUNCTION__);
    }

    Logger::success("Access to txt file", __FUNCTION__);

    if (questsList.empty())
    {
        quests << (std::string)jWriter["JournalInfos"]["NoQuestsInJournal"] << std::endl;
        quests.close();
        return;
    }

    for (auto i : questsList)
    {
        quests << (std::string)jWriter["QuestsInfos"]["Name"] << i->getName() << std::endl;
        quests << (std::string)jWriter["QuestsInfos"]["Description"] << i->getDescription() << std::endl;
        quests << (std::string)jWriter["QuestsInfos"]["Status"] << i->printStatus() << std::endl;
        quests << "..........................................................................." << std::endl;
    }

    quests.close();
}

void Journal::clearJournal()
{
    if (!questsList.empty())
    {
        questsList.clear();
        updateJournalFile();
    }

    Logger::out("Journal is empty", __FUNCTION__);
}