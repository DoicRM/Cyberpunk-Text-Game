// CREATED BY Rachel Wil Sha Singh 2020 (https://gitlab.com/RachelWilShaSingh/simple-cpp-text-adventure)
// EDITED BY Radosław "Doic" Michalak 2022
#include "logger.hpp"

std::ofstream Logger::m_file;
time_t Logger::m_startTime;
time_t Logger::m_lastTimestamp;
int Logger::m_logLevel;
std::string Logger::m_categoryFilter;
int Logger::m_rowCount;
bool Logger::m_isLoud;

void Logger::setup(bool isLoud)
{
    m_rowCount = 0;
    m_logLevel = 0;
    m_file.open("log.html");
    m_startTime = (time_t)getTimestamp();
    m_lastTimestamp = m_startTime;
    m_isLoud = isLoud;

    m_file << "<html><head><title>LOG – " << __DATE__ << "</title><meta http-equiv='refresh' content='2'><link href='https://cdn.jsdelivr.net/npm/bootstrap@5.2.0-beta1/dist/css/bootstrap.min.css' rel='stylesheet' integrity='sha384-0evHe/X+R7YkIZDRvuzKMRqM+OrBnVFBL6DOitfPri4tjfHxaWutUpFmBp4vmVor' crossorigin='anonymous'><script src='https://kit.fontawesome.com/d9390232e7.js' crossorigin='anonymous'></script></head><body>" << std::endl;
    m_file << "<table class='table table-responsive table-sm table-hover table-striped'><thead class='table-light'>" << std::endl;
    m_file << "<tr>"
        << "<th scope='col'>LOCATION</td>"
        << "<th scope='col'>MESSAGE</td>"
        << "<th scope='col'>TIME</td>"
        << "</tr></thead><tbody>" << std::endl;
    out("Logging begins", __FUNCTION__);
}

void Logger::setup(int logLevel, const std::string& filter)
{
    setup();
    setLogLevel(logLevel);
    setFilterWord(filter);
}

void Logger::setLogLevel(int val)
{
    m_logLevel = val;
}

void Logger::setFilterWord(const std::string& filter)
{
    out("Setting filter to only display messages of category \"" + filter + "\"");
    m_categoryFilter = filter;
}

void Logger::cleanup()
{
    out("Logging ends", "Logger::cleanup");
    m_file << "</tbody></table>" << std::endl;
    m_file << "</body></html>" << std::endl;
    m_file.close();
}

void Logger::out(const std::string& message, const std::string& location /* = "" */, const std::string& category /* = "" */, bool condition /* = true */, int level /* = 0 */)
{
    if (m_categoryFilter.size() > 0)
    {
        // Filter is active
        if (category.size() == 0 || m_categoryFilter.find(category) == std::string::npos) return;
    }

    if (level < m_logLevel) return;

    if (condition)
    {
        //if (m_isLoud)
        //{
        //    std::cout << getFormattedTimestamp();
        //    if (location != "") { std::cout << " @ " << location; }
        //    std::cout << std::endl << "  " << message << std::endl << std::endl;
        //}

        std::string loc = location;
        if (loc == "") loc = "-";

        //std::string rowClass = (m_rowCount % 2 == 0) ? "" : "odd";

        m_file << "<tr>"
            << "<td>" << loc << "</td>"
            << "<td>" << message << "</td>"
            << "<td>" << getFormattedTimestamp() << "</td>"
            << "</tr>" << std::endl;

        m_rowCount++;
    }
}

void Logger::startFuncLog(const std::string& location)
{
    Logger::out("Function starts", location);
}

void Logger::invalidHeroChoiceError(const std::string& location)
{
    Logger::error("Entered invalid value of <b>heroChoice</b>", location);
}

void Logger::error(const std::string& message, const std::string& location /* = "" */)
{
    //std::cerr << "** " << getTimestamp() << "\t" << message;
    //if (location != "") std::cerr << " @ " << location;
    //std::cerr << "\t LINE " << __LINE__ << " FILE " << __FILE__;
    //std::cerr << std::endl;

    std::string loc = location;
    if (loc == "") loc = "-";

    m_file << "<tr class='table-danger'>"
        << "<td>" << loc << "</td>"
        << "<td>" << message << "</td>"
        << "<td>" << getFormattedTimestamp() << "</td>"
        << "</tr>" << std::endl;
}

void Logger::success(const std::string& message, const std::string& location /* = "" */)
{
    std::string loc = location;
    if (loc == "") loc = "-";

    m_file << "<tr class='table-success'>"
        << "<td>" << loc << "</td>"
        << "<td>" << message << "</td>"
        << "<td>" << getFormattedTimestamp() << "</td>"
        << "</tr>" << std::endl;
}

std::string Logger::getFormattedTimestamp()
{
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
    time_t timestamp = (time_t)getTimestamp();
    struct tm timeinfo;
    char buffer[80];
    time(&timestamp);
    localtime_s(&timeinfo, &timestamp);
    strftime(buffer, 80, "%H:%M:%S", &timeinfo);
    std::string str(buffer);
    return str;
#else
    time_t timestamp = getTimestamp();
    struct tm* timeinfo;
    char buffer[80];
    time(&timestamp);
    timeinfo = localtime_r(&timestamp);
    strftime(buffer, 80, "%H:%M:%S", timeinfo);
    std::string str(buffer);
    return str;
#endif
}

double Logger::getTimestamp()
{
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
    return (double)std::chrono::system_clock::to_time_t(now);
}