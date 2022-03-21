#include "functions.h"

void Function::nameGame(LPCSTR name)
{
    SetConsoleTitleA(name);
}

void Function::initSpecialChars(const char* lang)
{
    setlocale(LC_ALL, lang);
}

// Powolne wypisywanie kodu
void Function::write(const std::string& text, int speed)
{
    using namespace std::chrono_literals;

    for (auto letter : text)
    {
        std::cout << letter;
        std::cout.flush();
        std::this_thread::sleep_for(std::chrono::milliseconds(speed));
    }
}

// Powolne wypisywanie kodu (narracja)
void Function::writeNarration(std::string text, int speed)
{
    changeConsoleColor(narration);
    Function::write(text, speed);
    changeConsoleColor();
}

// Powolne wypisywanie kodu (dialog)
void Function::writeDialogue(std::string text, int speed)
{
    changeConsoleColor(dialogue);
    Function::write(text, speed);
    changeConsoleColor();
}


void Function::actionOption(int nr, std::string text)
{
    std::string str = "\t[" + std::to_string(nr) + "] " + text;
    Function::write(str, 25);
    std::cout << std::endl;
}

void Function::dialogueOption(int nr, std::string text)
{
    std::string str = "\t[" + std::to_string(nr) + "] '" + text + "'";
    Function::write(str, 25);
    std::cout << std::endl;
}

void Function::showHeroAction(std::string text)
{
    std::cout << std::endl;
    changeConsoleColor();
    std::string str = "\t> " + text;
    std::cout << str << std::endl;
}

// Zmiana koloru tekstu i t³a konsoli
void Function::changeConsoleColor(int color)
{
    HANDLE hOut;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hOut, color);
}

void Function::waitForUserInput()
{
#pragma warning(suppress : 6031)
    _getch();
}

// Inicjowanie ekwipunku gracza
void Function::initHeroEQ()
{
    Logger::out("Function start", "Function::initHeroEQ");
    std::fstream eq;

    if (eq.good())
    {
        Logger::out("Access to file", "Function::initHeroEQ");
        eq.open("eq.txt", std::ios::out);
        eq << "                                    ITEMS                                  " << std::endl;
        //eq << "                               PRZEDMIOTY                                  " << endl;
        eq << "..........................................................................." << std::endl;
        eq.close();
    }
    else Logger::error("No file access", "Function::initHeroEQ");
}

// Inicjowanie listy zadañ
void Function::initQuestsList()
{
    Logger::out("Function start", "Function::initQuestsList");
    std::fstream q;

    if (q.good())
    {
        Logger::out("Access to file", "Function::initQuestsList");
        q.open("quests.txt", std::ios::out);
        q << "                                    QUESTS                                 " << std::endl;
        //q << "                                   ZADANIA                                 " << endl;
        q << "..........................................................................." << std::endl;
        q.close();
    }
    else Logger::error("No file access", "Function::initQuestsList");
}

void Function::clearScreen()
{
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
    system("cls");
#else
    system("clear");
#endif
}

void Function::pauseGame()
{
    std::cout << "\tPress ANY KEY to continue...";
    //std::cout << "\tWciœnij DOWOLNY PRZYCISK, aby kontynuowaæ...";
    waitForUserInput();
}
