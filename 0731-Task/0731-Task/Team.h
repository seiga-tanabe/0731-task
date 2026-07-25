#pragma once

#include <vector>
#include <memory>

#include "Character.h"
#include "Warrior.h"
#include "Mage.h"
#include "Summoner.h"

class Team
{
private:

    // 陣営の戦力
    int power;

    // キャラクター3人
    std::vector<std::unique_ptr<Character>> members;

public:

    // コンストラクタ
    Team();

    // デストラクタ
    ~Team();

    // 戦力取得
    int GetPower() const;

    // ダメージ
    void Damage(int damage);

    // 戦力回復（今後の拡張用）
    void Heal(int value);

    // キャラクター取得
    Character* GetCharacter(int index);

    // 人数取得
    int GetMemberCount() const;

    // 戦力表示
    void ShowStatus() const;
};