#ifndef PUYAKAJDOM_H
#define PUYAKAJDOM_H

#include "attacker.h"

class puyakajdom : public attacker
{
    private:
    bool specialActive;
    int specialTurns;

    public:
    puyakajdom();
    void useNormalSkill1() override;
    void useNormalSkill2() override;
    void useSpecialSkill1() override;

    void applyEffects() override;
};

#endif