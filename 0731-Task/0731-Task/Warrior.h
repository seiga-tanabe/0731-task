#pragma once

#include "Character.h"



class Warrior : public Character
{

public:

    Warrior();


    CharacterType GetType() const override;

};