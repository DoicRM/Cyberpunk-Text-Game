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
    randomSex(Randomize::randIntBetween(0, 1));
    randomName(Randomize::randIntBetween(0,9));
    randomFraction(Randomize::randIntBetween(0, 4));
}

void AmbientNpc::randomSex(int randNr)
{
    setSex(sex[randNr]);
}

void AmbientNpc::randomName(int randNr)
{
    if (getSex() == Male) setName(namesMale[randNr]);
    else setName(namesFemale[randNr]);
}

void AmbientNpc::randomFraction(int randNr)
{
    setFraction(AmbientNpc::fractions[randNr]);
}