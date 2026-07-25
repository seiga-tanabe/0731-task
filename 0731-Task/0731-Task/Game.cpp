#include "Game.h"

#include <iostream>
#include <cstdlib>
#include <ctime>


Game::Game()
{
    srand((unsigned int)time(nullptr));
}



void Game::Start()
{

    int turn = 1;


    while (playerTeam.GetPower() > 0 &&
        enemyTeam.GetPower() > 0)
    {

        std::cout << "\n====================\n";
        std::cout << turn << "ƒ^[ƒ“–Ú\n";
        std::cout << "====================\n";


        Turn();


        turn++;

    }


    ShowResult();

}



void Game::Turn()
{

    playerTeam.ShowStatus();


    std::cout << "\n“G‚Ìó‘Ô\n";

    enemyTeam.ShowStatus();



    int select;


    std::cout << "\nŽg—p‚·‚éƒLƒƒƒ‰ƒNƒ^[\n";
    std::cout << "1.Œ•Žm\n";
    std::cout << "2.–‚–@Žg‚¢\n";
    std::cout << "3.¢Š«Žm\n";


    std::cin >> select;



    while (select < 1 || select > 3)
    {
        std::cout << "“ü—Í‚µ’¼‚µ‚Ä‚­‚¾‚³‚¢\n";
        std::cin >> select;
    }



    Character* player =
        playerTeam.GetCharacter(select - 1);




    int action;


    std::cout << "\ns“®‘I‘ð\n";
    std::cout << "1.UŒ‚\n";
    std::cout << "2.–hŒä\n";


    std::cin >> action;



    Action playerAction;


    if (action == 1)
    {
        playerAction = Action::Attack;
    }
    else
    {
        playerAction = Action::Defense;
    }




    // “G‘I‘ð

    int enemyNumber =
        rand() % 3;


    Character* enemy =
        enemyTeam.GetCharacter(enemyNumber);



    Action enemyAction;


    if (rand() % 2 == 0)
    {
        enemyAction = Action::Attack;

        std::cout
            << "“G‚Ì"
            << enemy->GetName()
            << "‚ÍUŒ‚‚ð‘I‘ð\n";
    }
    else
    {
        enemyAction = Action::Defense;

        std::cout
            << "“G‚Ì"
            << enemy->GetName()
            << "‚Í–hŒä‚ð‘I‘ð\n";
    }



    Battle
    (
        player,
        enemy,
        playerAction,
        enemyAction
    );

}






void Game::Battle
(
    Character* player,
    Character* enemy,
    Action playerAction,
    Action enemyAction
)
{


    std::cout << "\n";
    std::cout
        << player->GetName()
        << " VS "
        << enemy->GetName()
        << "\n";



    // —¼•ûUŒ‚

    if (playerAction == Action::Attack &&
        enemyAction == Action::Attack)
    {

        AttackVsAttack(player, enemy);

    }



    // –¡•ûUŒ‚ “G–hŒä

    else if (playerAction == Action::Attack &&
        enemyAction == Action::Defense)
    {

        AttackVsDefense(player, enemy);

    }



    // –¡•û–hŒä “GUŒ‚

    else if (playerAction == Action::Defense &&
        enemyAction == Action::Attack)
    {

        AttackVsDefense(enemy, player);

    }



    else
    {

        std::cout
            << "‚¨ŒÝ‚¢–hŒä‚µ‚½\n";

        std::cout
            << "‰½‚à‹N‚±‚ç‚È‚©‚Á‚½\n";

    }

}







// UŒ‚ VS UŒ‚

void Game::AttackVsAttack
(
    Character* player,
    Character* enemy
)
{


    int playerPower =
        player->GetAttack();


    int enemyPower =
        enemy->GetAttack();




    if (playerPower > enemyPower)
    {

        std::cout
            << "–¡•û‚ÌUŒ‚¬Œ÷\n";


        enemyTeam.Damage(playerPower);


    }


    else if (enemyPower > playerPower)
    {

        std::cout
            << "“G‚ÌUŒ‚¬Œ÷\n";


        playerTeam.Damage(enemyPower);

    }


    else
    {

        std::cout
            << "UŒ‚—Í‚ª“¯‚¶Iƒhƒ[\n";

    }


}








// UŒ‚ VS –hŒä

void Game::AttackVsDefense
(
    Character* attacker,
    Character* defender
)
{

    CharacterType attackType =
        attacker->GetType();


    CharacterType defenseType =
        defender->GetType();




    // “¯‚¶ƒLƒƒƒ‰

    if (attackType == defenseType)
    {

        std::cout
            << "–hŒä¬Œ÷\n";

        return;

    }





    // ƒNƒŠƒeƒBƒJƒ‹”»’è

    bool critical = false;



    if (
        (attackType == CharacterType::Warrior &&
            defenseType == CharacterType::Summoner)

        ||

        (attackType == CharacterType::Mage &&
            defenseType == CharacterType::Warrior)

        ||

        (attackType == CharacterType::Summoner &&
            defenseType == CharacterType::Mage)
        )
    {

        critical = true;

    }





    if (critical)
    {

        std::cout
            << "ƒNƒŠƒeƒBƒJƒ‹UŒ‚”­¶!\n";

        std::cout
            << defender->GetName()
            << "‘¤‚Ìí—Í‚ª"
            << attacker->GetAttack() * 2
            << "Œ¸­\n";


        if (defender == enemyTeam.GetCharacter(0) ||
            defender == enemyTeam.GetCharacter(1) ||
            defender == enemyTeam.GetCharacter(2))
        {

            enemyTeam.Damage(
                attacker->GetAttack() * 2);

        }
        else
        {

            playerTeam.Damage(
                attacker->GetAttack() * 2);

        }


    }


    else
    {

        std::cout
            << "ƒJƒEƒ“ƒ^[”­¶!\n";


        std::cout
            << "UŒ‚‘¤‚Ìí—Í‚ª"
            << attacker->GetAttack() * 2
            << "Œ¸­\n";



        if (attacker == enemyTeam.GetCharacter(0) ||
            attacker == enemyTeam.GetCharacter(1) ||
            attacker == enemyTeam.GetCharacter(2))
        {

            enemyTeam.Damage(
                attacker->GetAttack() * 2);

        }
        else
        {

            playerTeam.Damage(
                attacker->GetAttack() * 2);

        }

    }

}






void Game::ShowResult()
{



    if (playerTeam.GetPower() <= 0)
    {

        std::cout
            << "“Gw‰c‚ÌŸ—˜\n";

    }
    else
    {

        std::cout
            << "–¡•ûw‰c‚ÌŸ—˜\n";

    }



}