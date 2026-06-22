#ifndef AMINSAFETY_HPP
#define AMINSAFETY_HPP

#include "attacker.h"

class Aminsafety : public attacker
{
private:
    int lastBulletDamage;

public:
    Aminsafety();

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