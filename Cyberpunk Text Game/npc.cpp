#include "npc.h"

std::map <std::string, Npc> Npc::npcs;

Npc::Npc()
{
    this->name = "None";
    this->sex = undefined;
    this->fraction = Fraction();
    this->attitude = neutral;
    this->status = normal;
    this->knowingHero = false;
}

Npc::Npc(std::string name, int sex, Fraction fraction)
{
    this->name = name;
    this->sex = sex;
    this->fraction = fraction;
    this->attitude = neutral;
    this->status = normal;
    this->knowingHero = false;
}


Npc::Npc(std::string name, int sex, Fraction fraction, int attitude, int status, bool knowingHero)
{
    this->name = name;
    this->sex = sex;
    this->fraction = fraction;
    this->attitude = attitude;
    this->status = status;
    this->knowingHero = knowingHero;
}

Npc::~Npc()
{
}

void Npc::setAttitude(int attitude)
{
    this->attitude = attitude;
    printAttitude();
}

void Npc::printAttitude()
{
    std::string attitude;

    if (this->attitude == angry)
    {
        attitude = "angry";
        Function::changeConsoleColor(yellow);
    }
    else if (this->attitude == hostile)
    {
        attitude = "hostile";
        Function::changeConsoleColor(red);
    }
    else if (this->attitude == friendly)
    {
        attitude = "friendly";
        Function::changeConsoleColor(green);
    }
    else
    {
        attitude = "neutral";
        Function::changeConsoleColor();
    }

    std::string str = "\t" + this->name + " is " + attitude + " now.";
    Function::write(str);
    std::cout << std::endl;
    Function::changeConsoleColor();
}

bool Npc::isDead()
{
    if (status != dead) return false;
    return true;
}

void Npc::initNpcs()
{
    Logger::out("Function start", "Npc::initNpcs");

    Npc Bob("Bob", male, Fraction::fractions["Beggars"]);
    Npc Caden("Caden", male, Fraction::fractions["Police"]);
    Npc CadensPartner("Policeman", male, Fraction::fractions["Police"]);
    Npc Zed("Zed", male, Fraction::fractions["None"]);
    Npc Nyx("Nyx", female, Fraction::fractions["Sleepers"]);
    Npc Jet("Jet", male, Fraction::fractions["Hammers"]);
    Npc Vincent("Vincent", male, Fraction::fractions["Hammers"]);
    Npc Enigma("Enigma", male, Fraction::fractions["None"]);
    Npc Morpheus("Morpheus", male, Fraction::fractions["Sleepers"]);

    npcs["Bob"] = Bob;
    npcs["Caden"] = Caden;
    npcs["CadensPartner"] = CadensPartner;
    npcs["Zed"] = Zed;
    npcs["Nyx"] = Nyx;
    npcs["Jet"] = Jet;
    npcs["Vincent"] = Vincent;
    npcs["Enigma"] = Enigma;
    npcs["Morpheus"] = Morpheus;
}