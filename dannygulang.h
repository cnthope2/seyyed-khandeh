#ifndef DANNYGULANG_H
#define DANNYGULANG_H

#include "defender.h"

class dannygulang : public defender
{
private:

    Hero* lasttarget;
    int ghofliDamage;
    

public:
    dannygulang();
    void resetRound();

    void useNormalSkill1() override;
    void useNormalSkill2() override;
    void useSpecialSkill() override;
    int getSkill1Cost() const override;
    int getSkill2Cost() const override;
    int getSpecialCost() const override;
    TargetType getSkill1TargetType() const override;
    TargetType getSkill2TargetType() const override;
    TargetType getSpecialTargetType() const override;
};

#endif