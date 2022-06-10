#include "./ambientNpc.hpp"

AmbientNpc::AmbientNpc()
{
    init();
}

AmbientNpc::~AmbientNpc()
{
}

void AmbientNpc::init()
{
    randomSex(Randomize::randInt(0, 1));
    randomName(Randomize::randInt(0,9));
    randomFraction(Randomize::randInt(0, 4));
}

void AmbientNpc::randomSex(int randNr)
{
    setSex(sex[randNr]);
}

void AmbientNpc::randomName(int randNr)
{
    if (getSex() == Female)
    {
        return setName(namesFemale[randNr]);
    }

    setName(namesMale[randNr]);
}

void AmbientNpc::randomFraction(int randNr)
{
    setFraction(AmbientNpc::fractions[randNr]);
}