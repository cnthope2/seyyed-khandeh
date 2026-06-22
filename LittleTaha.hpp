#ifndef LITTLETAHA_HPP
#define LITTLETAHA_HPP

#include "healers.hpp"

class LittleTaha : public Healer
{
public:
    LittleTaha();

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