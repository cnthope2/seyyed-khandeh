#ifndef DEFENDER_H
#define DEFENDER_H

#include "hero.hpp"

class defender : public Hero
{

public:
    defender(string n, int hp, int cd);
    void addshield(int amount);
};

#endif