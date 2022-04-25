#include "quest.hpp"

std::map <std::string, Quest> Quest::quests;

Quest::Quest()
{
    this->name = "None";
    this->description = "None";
    this->status = NotStarted;
    this->isRunning = false;
    this->isCompleted = false;
}

Quest::Quest(std::string name, std::string description)
{
    this->name = name;
    this->description = description;
    this->status = NotStarted;
    this->isRunning = false;
    this->isCompleted = false;
}

Quest::Quest(std::string name, std::string description, int status, bool isRunning, bool isCompleted)
{
    this->name = name;
    this->description = description;
    this->status = status;
    this->isRunning = isRunning;
    this->isCompleted = isCompleted;
}

Quest::~Quest()
{
}

void Quest::start()
{
    this->isRunning = true;
    this->status = Ongoing;

    std::ofstream q;
    q.open("quests.txt", std::ios::app);

    if (q.good())
    {
        Logger::out("Access to txt file", "Quest::start");
        q << "  Name: " << this->getName() << std::endl;
        q << "  Description: " << this->getDescription() << std::endl;
        q << "  Status: " << this->printStatus() << std::endl;
        q << "..........................................................................." << std::endl;
        q.close();
    }
    else Logger::error("No file access", "Quest::start");
}

void Quest::end()
{
    this->isRunning = false;
    this->isCompleted = true;
    this->status = Completed;

    /*
    std::string quests[2];
    std::string header, breakLine, questName[1], questDesc[1], questStatus[1], questsLine;
    int questNr = 0;
    int lineNr = 1;

    std::fstream q;
    q.open("quests.txt", std::ios::in | std::ios::out | std::ios::app);

    if (q.good())
    {
        Logger::out("Access to txt file", "Quest::end");

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
                std::cout << "  Status: " << this->status;
                lineNr = 3;
                questNr++;
            }

            lineNr++;
        }

        q.close();
    }
    else Logger::error("No file access", "Quest::end");
    */
}

std::string Quest::printStatus()
{
    std::string status;

    if (this->status == Ongoing) status = "ongoing";
    else if (this->status == Completed) status = "completed";
    else status = "not started";

    return status;
}

void Quest::initQuests_EN()
{
    Logger::out("Function starts", "Quest::initQuests_EN");

    Quest KillVincent("Beauty and the Beast", "Kill 'Amnesia' nightclub owner Vincent Ramsey at the request of his girlfriend, Nyx.");
    Quest ZedAccelerator("Shades of the Past", "Bring Zed an old model of an accelerator. In return you will receive a gun from him.");

    quests["KillVincent"] = KillVincent;
    quests["ZedAccelerator"] = ZedAccelerator;
}

void Quest::initQuests_PL()
{
    Logger::out("Function starts", "Quest::initQuests_PL");

    Quest KillVincent("Piêkna i bestia", "Zabij w³aœciciela klubu nocnego 'Amnezja', Vincenta Ramseya, na proœbê jego dziewczyny, Nyx.");
    Quest ZedAccelerator("Cienie przesz³oœci", "Przynieœ Zedowi stary model akumulatora. W zamian otrzymasz od niego pistolet.");

    quests["KillVincent"] = KillVincent;
    quests["ZedAccelerator"] = ZedAccelerator;
}