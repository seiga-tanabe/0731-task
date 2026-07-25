#include "BattleManager.h"
#include <iostream>

void BattleManager::Resolve(Team& playerTeam, Team& enemyTeam, Character* player, Action playerAction, Character* enemy, Action enemyAction)
{
    std::cout << "\n" << player->GetName() << " VS " << enemy->GetName() << "\n";

    if (playerAction == Action::Attack && enemyAction == Action::Attack) {
        AttackVsAttack(playerTeam, enemyTeam, player, enemy);
    }
    else if (playerAction == Action::Attack && enemyAction == Action::Defense) {
        AttackVsDefense(playerTeam, enemyTeam, player, enemy);
    }
    else if (playerAction == Action::Defense && enemyAction == Action::Attack) {
        AttackVsDefense(enemyTeam, playerTeam, enemy, player);
    }
    else {
        std::cout << "‚¨ŒÝ‚¢–hŒä‚µ‚½\n‰½‚à‹N‚±‚ç‚È‚©‚Á‚½\n";
    }
}
