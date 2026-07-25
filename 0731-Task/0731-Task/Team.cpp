#include "Team.h"

#include <iostream>

Team::Team()
{
    // 初期戦力
    power = 300;

    // キャラクター生成(new)
    members.push_back(std::unique_ptr<Character>(new Warrior()));
    members.push_back(std::unique_ptr<Character>(new Mage()));
    members.push_back(std::unique_ptr<Character>(new Summoner()));
}

Team::~Team()
{
    // unique_ptrが自動でdeleteするので何もしない
}

int Team::GetPower() const
{
    return power;
}

void Team::Damage(int damage)
{
    power -= damage;

    if (power < 0)
    {
        power = 0;
    }
}

void Team::Heal(int value)
{
    power += value;
}

Character* Team::GetCharacter(int index)
{
    if (index < 0 || index >= members.size())
    {
        return nullptr;
    }

    return members[index].get();
}

int Team::GetMemberCount() const
{
    return static_cast<int>(members.size());
}

void Team::ShowStatus() const
{
    std::cout << "======================" << std::endl;
    std::cout << "戦力 : " << power << std::endl;
    std::cout << "======================" << std::endl;

    for (int i = 0; i < members.size(); i++)
    {
        std::cout
            << i + 1
            << ". "
            << members[i]->GetName()
            << "  攻撃力:"
            << members[i]->GetAttack()
            << std::endl;
    }

    std::cout << std::endl;
}