#include "Journal.hpp"

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

void Journal::endQuest(Quest* quest, int status)
{
    if (!quest->getIsCompleted())
    {
        quest->end(status);
        updateJournalFile();
    }

    Logger::out("<b>" + quest->getName() + "</b> ended", __FUNCTION__);
}

void Journal::updateJournalFile()
{
    std::ofstream quests;
    quests.open("journal.txt");

    if (!quests.is_open())
    {
        return Logger::error("Unable to open file", __FUNCTION__);
    }

    if (questsList.empty())
    {
        quests << (std::string)json["journal"]["noQuests"] << std::endl;
        quests.close();
        return;
    }

    for (auto i : questsList)
    {
        quests << (std::string)json["quest"]["name"] << i->getName() << std::endl;
        quests << (std::string)json["quest"]["description"] << i->getDescription() << std::endl;
        quests << (std::string)json["quest"]["status"] << i->printStatus() << std::endl;
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