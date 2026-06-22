#include "WhiteDoctor.hpp"
#include <cstdlib>
#include <iostream>

using namespace std;

WhiteDoctor::WhiteDoctor() : Healer("WhiteDoctor", 550, 4)
{
}

void WhiteDoctor::useNormalSkill1()
{
    int alive[3];
    int count = 0;

    for (int i = 0; i < 3; i++)
    {
        if (team[i] && team[i]->getIsAlive())
        {
            alive[count++] = i;
        }
    }

    if (count > 0)
    {
        int randomPerson = alive[rand() % count];
        team[randomPerson]->heal(40);
    }

    if (enemy && enemy->getIsAlive())
    {
        enemy->takeDamage(40);
    }

    cout << "Aspirin activated!" << endl;
}

void WhiteDoctor::useNormalSkill2()
{
    if (!enemy)
    {
        return;
    }

    enemy->setDoping(3);

    cout << "Doping activated!" << endl;
}

void WhiteDoctor::useSpecialSkill()
{
    if (specialready())
    {
        for (int i = 0; i < 3; i++)
        {
            Hero *h = team[i];

            if (h && h != this && !h->getIsAlive())
            {
                h->revive(200);

                Hero::setReverseTurns(0);

                cout << "Revived!" << endl;

                resetcooldown();
                return;
            }
        }

        cout << "No dead teammate found!" << endl;
    }
}
int WhiteDoctor::getSkill1Cost() const
{
    return 3;
}

int WhiteDoctor::getSkill2Cost() const
{
    return 4;
}

int WhiteDoctor::getSpecialCost() const
{
    return 4;
}
TargetType WhiteDoctor::getSkill1TargetType() const
{
    return ENEMY;
}

TargetType WhiteDoctor::getSkill2TargetType() const
{
    return ALLY;
}

TargetType WhiteDoctor::getSpecialTargetType() const
{
    return NONE;
}