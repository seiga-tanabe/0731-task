#pragma once

#include "Character.h"



class Mage : public Character
{

public:

    Mage();


    CharacterType GetType() const override;

};