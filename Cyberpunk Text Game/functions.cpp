#include "functions.h"

using namespace std;

// Powolne wypisywanie kodu
void Function::write(const string& sentence, int speed)
{
    using namespace chrono_literals;

    for (auto letter : sentence)
    {
        cout << letter;
        cout.flush();
        this_thread::sleep_for(chrono::milliseconds(speed));
    }
}

// Powolne wypisywanie kodu (narracja)
void Function::writeNarration(string st, int sp)
{
    changeConsoleColor(narration);
    Function::write(st, sp);
    changeConsoleColor();
}

// Powolne wypisywanie kodu (dialog)
void Function::writeDialogue(string st, int sp)
{
    changeConsoleColor(dialogue);
    Function::write(st, sp);
    changeConsoleColor();
}


void Function::actionOption(int nr, string text)
{
    string str = "\t[" + to_string(nr) + "] " + text;
    Function::write(str, 25);
    cout << endl;
}

void Function::dialogueOption(int nr, string text)
{
    string str = "\t[" + to_string(nr) + "] '" + text + "'";
    Function::write(str, 25);
    cout << endl;
}

void Function::showHeroAction(string text)
{
    cout << endl;
    changeConsoleColor();
    string str = "\t> " + text;
    cout << str << endl;
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
    fstream eq;
    eq.open("eq.txt", ios::out);
    eq << "                                    ITEMS                                  " << endl;
    //eq << "                               PRZEDMIOTY                                  " << endl;
    eq << "..........................................................................." << endl;
    eq.close();
}

// Inicjowanie listy zadañ
void Function::initQuestsList()
{
    fstream q;
    q.open("quests.txt", ios::out);
    q << "                                    QUESTS                                 " << endl;
    //q << "                                   ZADANIA                                 " << endl;
    q << "..........................................................................." << endl;
    q.close();
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
    cout << "\tPress ANY KEY to continue...";
    //cout << "\tWciœnij DOWOLNY PRZYCISK, aby kontynuowaæ...";
    waitForUserInput();
}
