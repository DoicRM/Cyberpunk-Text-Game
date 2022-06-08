#include "input.hpp"

int Input::getChoice()
{
    int choice;
    Display::write("\t> ", 25);
    std::cin >> choice;
    std::cin.clear();
    std::cin.ignore();
    Logger::out("Entered <b>" + std::to_string(choice) + "</b>", __FUNCTION__);
    return choice;
}

std::string Input::getString()
{
    std::string text;
    Display::write("\t> ", 25);
    std::cin >> text;
    std::cin.clear();
    std::cin.ignore();
    Logger::out("Entered <b>" + text + "</b>", __FUNCTION__);
    return text;
}