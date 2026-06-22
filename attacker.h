#ifndef ATTACKER_H
#define ATTACKER_H

#include "hero.hpp"

class attacker : public Hero
{
public:
    attacker(string n, int hp, int cd);
};

#endif