#include "hero.hpp"
#include "healers.hpp"
#include <iostream>

using namespace std;

Healer::Healer(string name, int hp, int specialPower):Hero(name,"Healer",hp,specialPower)
{
}