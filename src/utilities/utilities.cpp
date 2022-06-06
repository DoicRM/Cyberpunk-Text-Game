#include "utilities.hpp"

// DISPLAY
void Display::write(const std::string& text, int speed)
{
    using namespace std::chrono_literals;

    for (auto letter : text)
    {
        std::cout << letter;
        std::cout.flush();
        std::this_thread::sleep_for(std::chrono::milliseconds(speed));
    }
}

void Display::writeNarration(std::string text, int speed)
{
    Console::setConsoleColor(CC_Narration);
    Display::write(text, speed);
    Console::resetConsoleColor();
}

void Display::writeDialogue(std::string text, int speed)
{
    Console::setConsoleColor(CC_Dialogue);
    Display::write(text, speed);
    Console::resetConsoleColor();
}

// INPUT
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

int RandUtil::randBetween(int min, int max)
{
    return rand() % ((max - min) + 1) + min;
}
