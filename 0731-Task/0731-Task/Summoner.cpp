#include "Summoner.h"



Summoner::Summoner()

    :Character("¢Š«m", 25)

{

}



CharacterType Summoner::GetType() const

{

    return CharacterType::Summoner;

}