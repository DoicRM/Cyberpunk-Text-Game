#include "./AmbientNpc.hpp"

AmbientNpc::AmbientNpc()
{
    init();
}

AmbientNpc::~AmbientNpc()
{
}

void AmbientNpc::init()
{
    randomSex(Utilities::randInt(0, 1));
    randomName(Utilities::randInt(0, 9));
    randomFraction(Utilities::randInt(0, 5));
}

void AmbientNpc::randomSex(int randNr)
{
    setSex(sex[randNr]);
}

void AmbientNpc::randomName(int randNr)
{
    if (getSex() == Sex::Female)
    {
        return setName(femaleNames[randNr]);
    }

    setName(maleNames[randNr]);
}

void AmbientNpc::randomFraction(int randNr)
{
    setFraction(AmbientNpc::fractions[randNr]);
}
