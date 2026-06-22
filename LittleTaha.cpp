#include "LittleTaha.hpp"
#include "team.h"
#include "hero.hpp"
#include <cstdlib>
#include <iostream>

using namespace std;

LittleTaha::LittleTaha() : Healer("LittleTaha", 500, 3)
{
}

void LittleTaha::useNormalSkill1()
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
        weakest->heal(20);
    }

    if (enemy && enemy->getIsAlive())
    {
        enemy->takeDamage(getDamageWithDoping(30));
    }

    cout << "Tighe Tiz activated" << endl;
}
void LittleTaha::useNormalSkill2()
{
    if (!enemy)
    {
        return;
    }

    enemy->heal(40);
    enemy->setSerumTurns(2);

    cout << "Serum Khoon Activated!" << endl;
}
void LittleTaha::useSpecialSkill()
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
            weakest->heal(200);
        }

        cout << "Emergency Treatment -> 200 heal" << endl;
    }

    resetcooldown();
}
int LittleTaha::getSkill1Cost() const
{
    return 2;
}

int LittleTaha::getSkill2Cost() const
{
    return 4;
}

int LittleTaha::getSpecialCost() const
{
    return 4;
}
TargetType LittleTaha::getSkill1TargetType() const
{
    return ENEMY;
}

TargetType LittleTaha::getSkill2TargetType() const
{
    return ALLY;
}

TargetType LittleTaha::getSpecialTargetType() const
{
    return NONE;
}