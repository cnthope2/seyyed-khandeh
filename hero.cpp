#include "hero.hpp"
#include <iostream>

using namespace std;

Hero::Hero(string name, string role, int heroHp, int specialPower)
{
    this->name = name;
    this->role = role;
    maxHp = heroHp;
    hp = heroHp;
    isAlive = true;
    specialSkillCooldown = specialPower;
    currentSpecialSkillTimer = specialPower - 1;
    shield = 0;
    shieldTurns = 0;
    dopingTurns = 0;
    scorpionCount = 0;
    isHidden = false;
    hiddenTurns = 0;
    serumTurns = 0;
    enemy = nullptr;
    team = nullptr;
    enemyteam = nullptr;
}
int Hero::reverseTurns = 0;

void Hero::takeDamage(int amount)
{
    if (!isAlive)
    {
        return;
    }

    if (isHidden)
    {
        cout << name << " is hidden" << endl;
        return;
    }

    if (reverseTurns > 0)
    {
        hp += amount;

        if (hp > maxHp)
        {
            hp = maxHp;
        }

        return;
    }

    if (shield > 0)
    {
        if (amount <= shield)
        {
            shield -= amount;

            if (shield <= 0)
            {
                shield = 0;
                shieldTurns = 0;
            }

            return;
        }

        amount -= shield;
        shield = 0;
        shieldTurns = 0;
    }

    hp -= amount;

    if (hp <= 0)
    {
        hp = 0;
        isAlive = false;
    }
}

void Hero::applyEffects()
{
    if (!isAlive)
    {
        return;
    }

    if (serumTurns > 0)
    {
        
        heal(40);
        serumTurns--;
    }

    if (dopingTurns > 0)
    {
        dopingTurns--;
    }

    if (shieldTurns > 0)
    {
        shieldTurns--;

        if (shieldTurns == 0)
        {
            shield = 0;
        }
    }

    if (hiddenTurns > 0)
    {
        hiddenTurns--;

        if (hiddenTurns == 0)
        {
            isHidden = false;
        }
    }

    if (reverseTurns > 0)
    {
        reverseTurns--;
    }
}
void Hero::setSerumTurns(int turns)
{
    serumTurns = turns;
}

int Hero::getSerumTurns() const
{
    return serumTurns;
}
void Hero::setEnemyTeam(Hero **enemies)
{
    enemyteam = enemies;
}
void Hero::heal(int amount)
{
    if (!isAlive)
    {
        return;
    }

    if (reverseTurns > 0)
    {
        hp -= amount;

        if (hp <= 0)
        {
            hp = 0;
            isAlive = false;
        }

        return;
    }

    hp += amount;

    if (hp > maxHp)
    {
        hp = maxHp;
    }
    
}
void Hero::setReverseTurns(int turns)
{
    reverseTurns = turns;
}

int Hero::getReverseTurns()
{
    return reverseTurns;
}
void Hero::revive(int healthAmount)
{
    if (!isAlive)
    {
        isAlive = true;
        hp = healthAmount;

        if (hp > maxHp)
        {
            hp = maxHp;
        }

        scorpionCount = 0;
    }
}
void Hero::setShieldTurns(int turns)
{
    shieldTurns = turns;
}

int Hero::getShieldTurns() const
{
    return shieldTurns;
}
void Hero::setEnemy(Hero *e)
{
    enemy = e;
}

void Hero::setTeam(Hero **t)
{
    team = t;
}
Hero **Hero::getTeam() const
{
    return team;
}
void Hero::setHidden(bool value)
{
    isHidden = value;
}

void Hero::setHiddenTurns(int turns)
{
    hiddenTurns = turns;
}
bool Hero::getIsHidden() const
{
    return isHidden;
}
void Hero::setShield(int value)
{
    shield = value;
}
int Hero::getShield() const
{
    return shield;
}
int Hero::getDoping() const
{
    return dopingTurns;
}
int Hero::getDamageWithDoping(int damage)
{
    if (dopingTurns > 0)
    {
        damage = damage * 120 / 100;
    }

    return damage;
}
void Hero::setDoping(int turns)
{
    dopingTurns = turns;
}

string Hero::getName() const
{
    return name;
}

string Hero::getRole() const
{
    return role;
}

int Hero::getHp() const
{
    return hp;
}

bool Hero::getIsAlive() const
{
    return isAlive;
}


void Hero::reduccooldown()
{
    if (currentSpecialSkillTimer > 0)
    {
        currentSpecialSkillTimer--;
    }
}

bool Hero::specialready() const
{
    return currentSpecialSkillTimer == 0;
}

void Hero::resetcooldown()
{
    currentSpecialSkillTimer = specialSkillCooldown ;
} 
