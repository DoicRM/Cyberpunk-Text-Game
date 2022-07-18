#include "Npc.hpp"

std::map <std::string, Npc> Npc::npcs;

Npc::Npc()
{
    this->name = "None";
    this->sex = Sex::Undefined;
    this->fraction = Fraction();
    this->attitude = Attitude::Neutral;
    this->status = CharacterStatus::Normal;
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

void Npc::setFraction(Fraction fraction)
{
    this->fraction = fraction;
}

void Npc::setAttitude(int attitude)
{
    if (this->attitude == attitude)
    {
        return;
    }

    this->attitude = attitude;
    printAttitude();
}

void Npc::printAttitude()
{
    std::string attitude;

    if (this->attitude == Attitude::Angry)
    {
        attitude = json["attitude"]["angry"];
        Console::setConsoleColor(ConsoleColor::CC_Yellow);
    }
    else if (this->attitude == Attitude::Hostile)
    {
        attitude = json["attitude"]["hostile"];
        Console::setConsoleColor(ConsoleColor::CC_Red);
    }
    else if (this->attitude == Attitude::Friendly)
    {
        attitude = json["attitude"]["friendly"];
        Console::setConsoleColor(ConsoleColor::CC_Green);
    }
    else
    {
        attitude = json["attitude"]["neutral"];
        Console::resetConsoleColor();
    }

    Display::write("\t" + this->name + (std::string)json["attitude"]["is"] + attitude + (std::string)json["attitude"]["now"]);
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
    // PROLOGUE
    Npc Bob("Bob", Sex::Male, Fraction::fractions["Beggars"]);
    Npc Caden("Caden", Sex::Male, Fraction::fractions["Police"]);
    Npc CadensPartner(json["npcs"]["policeman"]["name"], Sex::Male, Fraction::fractions["Police"]);
    Npc Zed("Zed", Sex::Male, Fraction::fractions["None"]);
    Npc Nyx("Nyx", Sex::Female, Fraction::fractions["Sleepers"]);
    Npc Jet(json["npcs"]["bouncer"]["name"], Sex::Male, Fraction::fractions["Hammers"]);
    Npc Vincent("Vincent", Sex::Male, Fraction::fractions["Hammers"]);
    Npc Enigma("Enigma", Sex::Male, Fraction::fractions["None"]);
    // ACT I
    Npc Morpheus(json["npcs"]["morpheus"]["name"], Sex::Male, Fraction::fractions["Sleepers"]);
    Npc MerQRy("Mer Q'Ry", Sex::Male, Fraction::fractions["None"]);
    Npc Karla("Karla", Sex::Female, Fraction::fractions["None"]);
    Npc ChipCaine("Chip Caine", Sex::Male, Fraction::fractions["None"]);
    Npc JaxRasac("Jax Rasac", Sex::Male, Fraction::fractions["Shitheads"]);

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
