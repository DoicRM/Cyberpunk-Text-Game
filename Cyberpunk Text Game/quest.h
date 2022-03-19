#pragma once
#include <iostream>
#include <string>
#include <fstream>

class Quest
{
private:
    std::string name;
    std::string description;
    std::string status;
    bool running;
    bool completed;

public:
    Quest();
    Quest(std::string name, std::string description);
    Quest(std::string name, std::string description, std::string status, bool running, bool completed);
    virtual ~Quest();

    void start();
    void end();

    inline const std::string& getName() const { return this->name; };
    inline const std::string& getDescription() const { return this->description; };
    inline const std::string& getStatus() const { return this->status; };
    inline const bool& isRunning() const { return this->running; };
    inline const bool& isCompleted() const { return this->completed; };
};
