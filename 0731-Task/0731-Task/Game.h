#pragma once

#include "Team.h"

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
    void ShowResult();
};
