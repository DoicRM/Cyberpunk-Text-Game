#include "npc.hpp"

std::map <std::string, Npc> Npc::npcs;

Npc::Npc()
{
    this->name = "None";
    this->sex = Undefined;
    this->fraction = Fraction();
    this->attitude = Attitude::Neutral;
    this->status = Normal;
    this->knowingHero = false;
}

Npc::Npc(std::string name, int sex, Fraction fraction)
{
    this->name = name;
    this->sex = sex;
    this->fraction = fraction;
    this->attitude = Attitude::Neutral;
    this->status = CharacterStatus::Normal;
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

void Npc::setName(std::string name)
{
    this->name = name;
}

void Npc::setSex(int sex)
{
    this->sex = sex;
}

void Npc::setFraction(Fraction fraction)
{
    this->fraction = fraction;
}

void Npc::setAttitude(int attitude)
{
    this->attitude = attitude;
    printAttitude();
}

void Npc::printAttitude()
{
    std::string attitude;

    if (this->attitude == Attitude::Angry)
    {
        attitude = jWriter["attitude"]["angry"];
        Console::setConsoleColor(ConsoleColor::CC_Yellow);
    }
    else if (this->attitude == Attitude::Hostile)
    {
        attitude = jWriter["attitude"]["hostile"];
        Console::setConsoleColor(ConsoleColor::CC_Red);
    }
    else if (this->attitude == Attitude::Friendly)
    {
        attitude = jWriter["attitude"]["friendly"];
        Console::setConsoleColor(ConsoleColor::CC_Green);
    }
    else
    {
        attitude = jWriter["attitude"]["neutral"];
        Console::resetConsoleColor();
    }

    Display::write("\t" + this->name + (std::string)jWriter["attitude"]["is"] + attitude + (std::string)jWriter["attitude"]["now"]);
    Console::resetConsoleColor();
}

bool Npc::isDead()
{
    if (status != CharacterStatus::Dead)
    {
        return false;
    }

    return true;
}

void Npc::initNpcs()
{
    Logger::startFuncLog(__FUNCTION__);
    // PROLOG
    Npc Bob("Bob", Sex::Male, Fraction::fractions["Beggars"]);
    Npc Caden("Caden", Sex::Male, Fraction::fractions["Police"]);
    Npc CadensPartner(jWriter["npcs"]["policeman"]["name"], Sex::Male, Fraction::fractions["Police"]);
    Npc Zed("Zed", Sex::Male, Fraction::fractions["None"]);
    Npc Nyx("Nyx", Sex::Female, Fraction::fractions["Sleepers"]);
    Npc Jet(jWriter["npcs"]["bouncer"]["name"], Sex::Male, Fraction::fractions["Hammers"]);
    Npc Vincent("Vincent", Sex::Male, Fraction::fractions["Hammers"]);
    Npc Enigma("Enigma", Sex::Male, Fraction::fractions["None"]);
    // AKT I
    Npc Morpheus(jWriter["npcs"]["morpheus"]["name"], Sex::Male, Fraction::fractions["Sleepers"]);
    Npc MerQRy("Mer Q'Ry", Sex::Male, Fraction::fractions["None"]);
    Npc Karla("Karla", Sex::Female, Fraction::fractions["None"]);
    Npc ChipCaine("Chip Caine", Sex::Male, Fraction::fractions["None"]);
    Npc JaxRasac("Jax Rasac", Sex::Male, Fraction::fractions["SowersOfConfusion"]);

    npcs["Bob"] = Bob;
    npcs["Caden"] = Caden;
    npcs["CadensPartner"] = CadensPartner;
    npcs["Zed"] = Zed;
    npcs["Nyx"] = Nyx;
    npcs["Jet"] = Jet;
    npcs["Vincent"] = Vincent;
    npcs["Enigma"] = Enigma;
    npcs["Morpheus"] = Morpheus;
    npcs["MerQRy"] = MerQRy;
    npcs["Karla"] = Karla;
    npcs["ChipCaine"] = ChipCaine;
    npcs["JaxRasac"] = JaxRasac;
}