#ifndef TAHABOZORGEH_H
#define TAHABOZORGEH_H

#include "attacker.h"

class tahabozorgeh : public attacker
{
private:
    bool hidden;

public:
    tahabozorgeh();

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