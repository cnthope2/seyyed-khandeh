#ifndef JOKER_H
#define JOKER_H

#include "hero.hpp"

class joker : public Hero
{
public:
    joker(string n, int hp, int cd);
};

#endif