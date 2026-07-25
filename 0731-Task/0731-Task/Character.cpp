#include "Character.h"



Character::Character(
    std::string n,
    int atk
)
{
    name = n;
    attack = atk;
}



Character::~Character()
{

}



std::string Character::GetName() const
{
    return name;
}




int Character::GetAttack() const
{
    return attack;
}