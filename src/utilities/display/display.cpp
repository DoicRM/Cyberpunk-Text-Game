#include "display.hpp"

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
