#include "Mage.h"



Mage::Mage()

    :Character("–‚–@Žg‚¢", 35)

{

}



CharacterType Mage::GetType() const

{

    return CharacterType::Mage;

}