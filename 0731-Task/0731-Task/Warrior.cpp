#include "Warrior.h"



Warrior::Warrior()

    :Character("Œ•Žm", 40)

{

}



CharacterType Warrior::GetType() const

{

    return CharacterType::Warrior;

}