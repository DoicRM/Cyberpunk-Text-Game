#pragma once
// CREATED BY Rachel Wil Sha Singh 2020 (https://gitlab.com/RachelWilShaSingh/simple-cpp-text-adventure)
#include <chrono>
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

class Logger
{
public:
    static void setup(bool loud = false);
    static void setup(int logLevel, const std::string& filter);
    static void cleanup();
    static void setLogLevel(int val);
    static void setFilterWord(const std::string& filter);

    static void out(const std::string& message, const std::string& location = "", const std::string& category = "", bool condition = true, int level = 0);
    static void startFuncLog(const std::string& location);
    static void error(const std::string& message, const std::string& location = "");

    static double getTimestamp();
    static std::string getFormattedTimestamp();

private:
    static std::ofstream m_file;
    static time_t m_startTime;
    static time_t m_lastTimestamp;
    static int m_logLevel;
    static std::string m_categoryFilter;
    static int m_rowCount;
    static bool m_isLoud;
};

// Shortcut expressions for logger
#define LOG( msg ) dal::Logger::Out( msg );
#define LOGLOC( msg, loc ) dal::Logger::Out( msg, loc );
#define ERR( msg, loc ) dal::Logger::Error( msg, loc );
