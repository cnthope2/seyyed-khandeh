#include "tahabozorgeh.h"
#include "team.h"
#include <iostream>
#include <cstdlib>

using namespace std;

tahabozorgeh::tahabozorgeh()
    : attacker("Taha Bozorgeh", 500, 4)
{
}

void tahabozorgeh::useNormalSkill1()
{
    for (int i = 0; i < 3; i++)
    {
        if (enemyteam[i] && enemyteam[i]->getIsAlive())
        {
            enemyteam[i]->takeDamage(getDamageWithDoping(30));
        }
    }

    cout << "Ragbar -> 30 damage to all enemies" << endl;
}

void tahabozorgeh::useNormalSkill2()
{
    if (enemy)
    {
        enemy->takeDamage(getDamageWithDoping(90));

        setHidden(true);
        setHiddenTurns(1);

        cout << "X-Ray -> 90 damage" << endl;
    }
}

void tahabozorgeh::useSpecialSkill()
{
    if (specialready())
    {
        cout << "in yeki baraye dadash kuchikam bud..." << endl;

        if (enemy)
        {
            if (enemy->getHp() < 360)
            {
                enemy->takeDamage(getDamageWithDoping(360));
            }
            else
            {
                enemy->takeDamage(getDamageWithDoping(200));
            }
        }

        resetcooldown();
    }
}

int tahabozorgeh::getSkill1Cost() const
{
    return 3;
}

int tahabozorgeh::getSkill2Cost() const
{
    return 4;
}

int tahabozorgeh::getSpecialCost() const
{
    return 3;
}

TargetType tahabozorgeh::getSkill1TargetType() const
{
    return NONE;
}

TargetType tahabozorgeh::getSkill2TargetType() const
{
    return ENEMY;
}

TargetType tahabozorgeh::getSpecialTargetType() const
{
    return ENEMY;
}