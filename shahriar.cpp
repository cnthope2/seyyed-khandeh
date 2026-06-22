#include "shahriar.h"
#include <iostream>
#include <cstdlib>

using namespace std;

shahriar::shahriar() : joker("Agha shahriar", 500, 4)
{
}

void shahriar::useNormalSkill1()
{
    int chance = rand() % 100;

    if (chance < 20)
    {
        cout << "missed!" << endl;
        return;
    }

    enemy->takeDamage(getDamageWithDoping(60));

    cout << "Maskhareh -> 60 damage" << endl;
}

void shahriar::useNormalSkill2()
{
    if (enemy != nullptr)
    {
        enemy->takeDamage(getDamageWithDoping(100));

        cout << "Lajbaz -> 100 damage to main enemy ("
             << enemy->getName() << ")" << endl;
    }

    if (enemy != nullptr && enemy->getTeam() != nullptr)
    {
        Hero** enemyTeam = enemy->getTeam();

        Hero* validTargets[2];
        int targetCount = 0;

        for (int i = 0; i < 3; i++)
        {
            if (enemyTeam[i] != nullptr &&
                enemyTeam[i] != enemy &&
                enemyTeam[i]->getIsAlive())
            {
                validTargets[targetCount++] = enemyTeam[i];
            }
        }

        if (targetCount > 0)
        {
            int randomIndex = rand() % targetCount;
            Hero* randomEnemy = validTargets[randomIndex];

            randomEnemy->takeDamage(getDamageWithDoping(100));

            cout << "Lajbaz -> AND 100 additional damage to "
                 << randomEnemy->getName()
                 << " (Random Enemy)" << endl;
        }
        else
        {
            cout << "No other alive enemies for the random effect!" << endl;
        }
    }
}

void shahriar::useSpecialSkill()
{
    if (specialready())
    {
        Hero::setReverseTurns(2);

        cout << "khub misheh bad... bad misheh khub" << endl;
    }

    resetcooldown();
}

int shahriar::getSkill1Cost() const
{
    return 2;
}

int shahriar::getSkill2Cost() const
{
    return 4;
}

int shahriar::getSpecialCost() const
{
    return 8;
}

TargetType shahriar::getSkill1TargetType() const
{
    return ENEMY;
}

TargetType shahriar::getSkill2TargetType() const
{
    return ENEMY;
}

TargetType shahriar::getSpecialTargetType() const
{
    return NONE;
}