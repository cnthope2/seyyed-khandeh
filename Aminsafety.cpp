#include "Aminsafety.hpp"
#include <cstdlib>
#include <iostream>

using namespace std;

Aminsafety::Aminsafety() : attacker("Aminsafety", 500, 3)
{
    lastBulletDamage = 55;
}
void Aminsafety::useNormalSkill1()
{
    int damage = getDamageWithDoping(lastBulletDamage);

    enemy->takeDamage(damage);

    if (!enemy->getIsAlive())
    {
        lastBulletDamage *= 2;
    }

    cout << "Last bullet activated" << endl;
}

void Aminsafety::useNormalSkill2()
{
    int other[3];
    int count = 0;

    for (int i = 0; i < 3; i++)
    {
        if (team[i] && team[i] != this && team[i]->getIsAlive())
        {
            other[count++] = i;
        }
    }

    if (count == 0)
    {
        return;
    }

    int randomperson = other[rand() % count];

    team[randomperson]->takeDamage(25);

    heal(75);

    cout << "Zarbe Be Khodi activated" << endl;
}

void Aminsafety::useSpecialSkill()
{
    if (specialready())
    {
        int enemies[3];
        int enemyCount = 0;

        for (int i = 0; i < 3; i++)
        {
            if (enemyteam[i] && enemyteam[i]->getIsAlive())
            {
                enemies[enemyCount++] = i;
            }
        }

        if (enemyCount > 0)
        {
            int randomEnemy = enemies[rand() % enemyCount];

            int damage = getDamageWithDoping(250);

            enemyteam[randomEnemy]->takeDamage(damage);
        }

        for (int i = 0; i < 3; i++)
        {
            if (team[i] && team[i] != this && team[i]->getIsAlive())
            {
                team[i]->takeDamage(30);
            }
        }

        cout << "Yek... Do... Se...BOooOM che kasi mondeh mohem nist" << endl;

      
    }
      resetcooldown();
}
int Aminsafety::getSkill1Cost() const
{
    return 3;
}

int Aminsafety::getSkill2Cost() const
{
    return 3;
}

int Aminsafety::getSpecialCost() const
{
    return 4;
}
TargetType Aminsafety::getSkill1TargetType() const
{
    return ENEMY;
}

TargetType Aminsafety::getSkill2TargetType() const
{
    return ALLY;
}

TargetType Aminsafety::getSpecialTargetType() const
{
    return NONE;
}