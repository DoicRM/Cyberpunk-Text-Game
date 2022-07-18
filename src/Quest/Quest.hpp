#pragma once
#include "../Utilities/Logger/Logger.hpp"
#include "../Utilities/Utilities.hpp"
#include "../Utilities/JsonHandler/JsonHandler.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <map>

enum Log
{
    NotStarted = 1,
    Running,
    Success,
    Failed,
    Obsolete,
};

class Quest
{
private:
    std::string name;
    std::string description;
    int status;
    bool isRunning;
    bool isCompleted;

public:
    Quest();
    Quest(std::string name, std::string description);
    Quest(std::string name, std::string description, int status, bool isRunning, bool isCompleted);
    virtual ~Quest();

    void start();
    void end(int status);
    std::string printStatus();

    inline const std::string& getName() const { return this->name; };
    inline const std::string& getDescription() const { return this->description; };
    inline const int& getStatus() const { return this->status; };
    inline const bool& getIsRunning() const { return this->isRunning; };
    inline const bool& getIsCompleted() const { return this->isCompleted; };

    static std::map <std::string, Quest> quests;
    static void initQuests();
};
