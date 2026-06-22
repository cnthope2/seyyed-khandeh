#include "dannygulang.h"
#include "team.h"
#include <iostream>

using namespace std;

dannygulang::dannygulang() : defender("danny gulang", 600, 4)
{
    lasttarget = nullptr;
    ghofliDamage = 20;
}

void dannygulang::resetRound()
{
    ghofliDamage = 20;
    lasttarget = nullptr;
}

void dannygulang::useNormalSkill1()
{
    if (enemy == lasttarget)
    {
        ghofliDamage = (int)(ghofliDamage * 1.6);
    }
    else
    {
        ghofliDamage = 20;
    }

    enemy->takeDamage(getDamageWithDoping(ghofliDamage));

    lasttarget = enemy;

    cout << "Ghofli -> " << ghofliDamage << " damage" << endl;
}

void dannygulang::useNormalSkill2()
{
    Hero *strongest = nullptr;

    for (int i = 0; i < 3; i++)
    {
        if (enemyteam[i] && enemyteam[i]->getIsAlive())
        {
            if (!strongest || enemyteam[i]->getHp() > strongest->getHp())
            {
                strongest = enemyteam[i];
            }
        }
    }

    enemy->takeDamage(getDamageWithDoping(50));

    if (strongest)
    {
        strongest->takeDamage(getDamageWithDoping(50));
    }

    cout << "Filkesh activated!" << endl;
}

void dannygulang::useSpecialSkill()
{
    if (specialready())
    {

        Hero *weakest = nullptr;

        for (int i = 0; i < 3; i++)
        {
            if (team[i] && team[i]->getIsAlive())
            {
                if (!weakest || team[i]->getHp() < weakest->getHp())
                {
                    weakest = team[i];
                }
            }
        }

        if (weakest)
        {
            weakest->setShield(250);
            weakest->setShieldTurns(2);
        }

        cout << "Hichkas az in khat rad nemishe!" << endl;
    }

    resetcooldown();
}

int dannygulang::getSkill1Cost() const
{
    return 2;
}

int dannygulang::getSkill2Cost() const
{
    return 4;
}

int dannygulang::getSpecialCost() const
{
    return 4;
}

TargetType dannygulang::getSkill1TargetType() const
{
    return ENEMY;
}

TargetType dannygulang::getSkill2TargetType() const
{
    return ENEMY;
}

TargetType dannygulang::getSpecialTargetType() const
{
    return NONE;
}