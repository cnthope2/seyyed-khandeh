#include "puyakajdom.h"
#include <iostream>
#include <cstdlib>

using namespace std;

puyakajdom::puyakajdom() : attacker("puya kajdom", 550, 3)
{
    specialActive = false;
    specialTurns = 0;
}

void puyakajdom::useNormalSkill1()
{
    if (!enemy || !enemy->getIsAlive())
    {
        return;
    }

    enemy->takeDamage(40);
    int cnt = enemy->getScorpionCount();

    if (cnt > 0)
    {
        enemy->takeDamage(cnt * 60);
    }

    cout << "khanjar used" << endl;
}

void puyakajdom::useNormalSkill2()
{
    if (!enemy || !enemy->getIsAlive())
    {
        return;
    }

    enemy->addScorpion();

    cout << "scorpion added on " << enemy->getName() << endl;
}

void puyakajdom::useSpecialSkill1()
{
    if (!specialready())
    {
        cout << "special not ready" << endl;
        return;
    }

    cout << " nishamj ro didi? ma? khob..." << endl;

    specialActive = true;
    specialTurns = 3;

    setHidden(true);

    resetcooldown();
}