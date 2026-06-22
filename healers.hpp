#ifndef HEALERS_HPP
#define HEALERS_HPP
#include "hero.hpp"

class Healer : public Hero
{
public:
    Healer(string name, int hp, int specialPower);
};

#endif