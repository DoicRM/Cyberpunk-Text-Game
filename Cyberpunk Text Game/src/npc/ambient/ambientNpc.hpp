#pragma once
#include "../npc.hpp"

class AmbientNpc : public Npc
{
private:
    int sex[2] = { Male, Female };
    std::string namesMale[10] = { "Astro", "Cypher", "Fade", "Hack", "Hex", "Miles", "Neo", "Ryker", "Smith", "Zayne" };
    std::string namesFemale[10] = { "Apoch", "Aurora", "Bellatrix", "Cassia", "Dot", "Eve", "Harley", "Jabbit", "Jinx", "Moxie" };
    Fraction fractions[5] = { Fraction::fractions["None"], Fraction::fractions["Beggars"], Fraction::fractions["Police"], Fraction::fractions["Hamers"], Fraction::fractions["Sleepers"] };
public:
    AmbientNpc();
    virtual ~AmbientNpc();

    void init();
    void randomName(int randNr);
    void randomSex(int randNr);
    void randomFraction(int randNr);
};