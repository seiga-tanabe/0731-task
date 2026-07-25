#include "Game.h"
#include "BattleManager.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Game::Game()
{
    // 乱数の初期化
    srand(static_cast<unsigned int>(time(nullptr)));
}

void Game::Start()
{
    int turn = 1;

    // どちらかの戦力が0になるまでループ
    while (playerTeam.GetPower() > 0 && enemyTeam.GetPower() > 0)
    {
        std::cout << "\n====================\n";
        std::cout << turn << "ターン目\n";
        std::cout << "====================\n";

        Turn();

        turn++;
    }

    ShowResult();
}

void Game::Turn()
{
    // 1. 各チームのステータス表示
    std::cout << "\n味方の状態\n";
    playerTeam.ShowStatus();

    std::cout << "\n敵の状態\n";
    enemyTeam.ShowStatus();

    // 2. プレイヤーのキャラクター選択
    int select;
    std::cout << "\n使用するキャラクター\n";
    std::cout << "1. 剣士\n";
    std::cout << "2. 魔法使い\n";
    std::cout << "3. 召喚士\n";
    std::cin >> select;

    while (select < 1 || select > 3)
    {
        std::cout << "入力し直してください：";
        std::cin >> select;
    }
    Character* playerChar = playerTeam.GetCharacter(select - 1);

    // 3. プレイヤーの行動選択
    int actionSelect;
    std::cout << "\n行動選択\n";
    std::cout << "1. 攻撃\n";
    std::cout << "2. 防御\n";
    std::cin >> actionSelect;

    while (actionSelect != 1 && actionSelect != 2)
    {
        std::cout << "入力し直してください：";
        std::cin >> actionSelect;
    }
    Action playerAction = (actionSelect == 1) ? Action::Attack : Action::Defense;

    // 4. 敵のキャラクターと行動を選択（ランダム）
    int enemyIndex = rand() % enemyTeam.GetMemberCount();
    Character* enemyChar = enemyTeam.GetCharacter(enemyIndex);
    Action enemyAction = (rand() % 2 == 0) ? Action::Attack : Action::Defense;

    // 5. バトルの実行（★詳細な判定やダメージ計算は BattleManager に一任！）
    BattleManager::Resolve(playerTeam, enemyTeam, playerChar, playerAction, enemyChar, enemyAction);
}

void Game::ShowResult()
{
    std::cout << "\n====================\n";

    if (playerTeam.GetPower() <= 0 && enemyTeam.GetPower() <= 0)
    {
        std::cout << "引き分けです！\n";
    }
    else if (playerTeam.GetPower() <= 0)
    {
        std::cout << "敗北しました...\n";
    }
    else
    {
        std::cout << "勝利しました！\n";
    }

    std::cout << "====================\n";
}
