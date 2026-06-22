#ifndef TEAM_H
#define TEAM_H

#include <vector>
#include "hero.hpp"

using namespace std;

class team
{
private:
    vector<Hero *> heroes;
    int energy;
    int roundplayed;
    int teamId;
    int getroundenergy() const;

public:
    team(int Id = 1);

    void startRound();
    bool CanAfford(int cost) const;
    bool consumeenergy(int cost);
    vector<Hero *> &getHeros();
    void addhero(Hero *hero);
    Hero *gethero(int index);
    int herocount() const;
    int aliveheros() const;
    bool AllHerosDead() const;
    void setenergy(int energy);
    int getenergy() const;
    bool spendenergy(int amount);
    void showheros(bool hideHidden = false) const;
};

#endif