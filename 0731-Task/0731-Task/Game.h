#pragma once

#include "Team.h"

// s“®‚Ì—ñ‹“Œ^i1. UŒ‚, 2. –hŒäj
enum class Action
{
    Attack,
    Defense
};

class Game
{
private:
    Team playerTeam;
    Team enemyTeam;

public:
    Game();
    void Start();

private:
    void Turn();

    // Game.cpp ‚Ì“à—e‚ÆŠ®‘S‚É‡‚í‚¹‚½ŠÖ”‚ÌéŒ¾
    void Battle(Character* player, Character* enemy, Action playerAction, Action enemyAction);
    void AttackVsAttack(Character* player, Character* enemy);
    void AttackVsDefense(Character* attacker, Character* defender);
    void ShowResult();
};
