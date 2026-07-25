#pragma once

#include "Character.h"



class Summoner : public Character
{

public:

    Summoner();


    CharacterType GetType() const override;

};