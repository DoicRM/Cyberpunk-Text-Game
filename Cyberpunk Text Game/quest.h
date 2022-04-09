#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include "logger.h"

class Quest
{
private:
    std::string name;
    std::string description;
    std::string status;
    bool isRunning;
    bool isCompleted;

public:
    Quest();
    Quest(std::string name, std::string description);
    Quest(std::string name, std::string description, std::string status, bool isRunning, bool isCompleted);
    virtual ~Quest();

    void start();
    void end();

    inline const std::string& getName() const { return this->name; };
    inline const std::string& getDescription() const { return this->description; };
    inline const std::string& getStatus() const { return this->status; };
    inline const bool& getIsRunning() const { return this->isRunning; };
    inline const bool& getIsCompleted() const { return this->isCompleted; };

    static std::map <std::string, Quest> quests;
    static void initQuests_EN();
    static void initQuests_PL();
};
