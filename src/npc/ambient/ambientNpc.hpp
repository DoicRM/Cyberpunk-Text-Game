#pragma once
#include "../npc.hpp"

class AmbientNpc : public Npc
{
private:
    std::array<int, 2> sex = { Sex::Male, Sex::Female };
    std::array<std::string, 10> maleNames = { "Astro", "Cypher", "Fade", "Hack", "Hex", "Miles", "Neo", "Ryker", "Smith", "Zayne" };
    std::array<std::string, 10> femaleNames = { "Apoch", "Aurora", "Bellatrix", "Cassia", "Dot", "Eve", "Harley", "Jabbit", "Jinx", "Moxie" };
    std::array<Fraction, 6> fractions = { Fraction::fractions["None"], Fraction::fractions["Beggars"], Fraction::fractions["Police"], Fraction::fractions["Hamers"], Fraction::fractions["Sleepers"], Fraction::fractions["Shitheads"] };
public:
    AmbientNpc();
    virtual ~AmbientNpc();

    void init();
    void randomName(int randNr);
    void randomSex(int randNr);
    void randomFraction(int randNr);
};