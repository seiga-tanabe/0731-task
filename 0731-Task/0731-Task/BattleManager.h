#pragma once

#include "Team.h"
#include "Character.h"

// s“®‚Ìí—Ş
enum class Action
{
    Attack,
    Defense
};

class BattleManager
{
public:
    static void Resolve(
        Team& playerTeam,
        Team& enemyTeam,
        Character* playerChar,
        Action playerAction,
        Character* enemyChar,
        Action enemyAction
    );

private:
    static void AttackVsAttack(Team& playerTeam, Team& enemyTeam, Character* player, Character* enemy);
    static void AttackVsDefense(Team& attackerTeam, Team& defenderTeam, Character* attacker, Character* defender);
};
