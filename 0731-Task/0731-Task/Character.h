#pragma once

#include <string>


// キャラクター種類
enum class CharacterType
{
    Warrior,
    Mage,
    Summoner
};



class Character
{

protected:

    std::string name;

    int attack;


public:

    Character(
        std::string n,
        int atk
    );


    virtual ~Character();



    std::string GetName() const;


    int GetAttack() const;



    // 仮想関数
    virtual CharacterType GetType() const = 0;

};