#include "team.h"
#include <iostream>

using namespace std;

team::team(int Id)
{
    teamId = Id;
    energy = 0;
    roundplayed = 0;
}

int team::getroundenergy() const
{

    if (teamId == 1)
    {
        if (roundplayed == 1)
        {
            return 5;
        }
        if (roundplayed == 2)
        {
            return 8;
        }
        if (roundplayed == 3)
        {
            return 9;
        }

        return 10;
    }
    else
    {
        if (roundplayed == 1)
        {
            return 8;
        }
        if (roundplayed == 2)
        {
            return 9;
        }

        return 10;
    }
}
void team::startRound()
{
    roundplayed++;
    energy = getroundenergy();
}
bool team::CanAfford(int cost) const
{
    return energy >= cost;
}
bool team::consumeenergy(int cost)
{
    if (!CanAfford(cost))
    {
        return false;
    }
    energy -= cost;
    return true;
}

void team::addhero(Hero *hero)
{
    heroes.push_back(hero);
}
vector<Hero *> &team::getHeros()
{
    return heroes;
}
bool team::AllHerosDead() const
{
    for (auto hero : heroes)
    {
        if (hero->getIsAlive())
        {
            return false;
        }
    }
    return true;
}
Hero *team::gethero(int index)
{
    if (index < 0 || index >= heroes.size())
    {
        return nullptr;
    }
    return heroes[index];
}

int team::herocount() const
{
    return heroes.size();
}

int team::aliveheros() const
{
    int count = 0;
    for (Hero *hero : heroes)
    {
        if (hero->getIsAlive())
        {
            count++;
        }
    }

    return count;
}

void team::setenergy(int energy)
{
    this->energy = energy;
}

int team::getenergy() const
{
    return energy;
}

bool team::spendenergy(int amount)
{
    if (energy < amount)
    {
        return false;
    }

    energy -= amount;
    return true;
}

void team::showheros(bool hideHidden) const
{
    cout << "\n-------------------------\n";

    for (int i = 0; i < heroes.size(); i++)
    {
        if (hideHidden && heroes[i]->getIsAlive() &&  heroes[i]->getIsHidden())
        {
            continue;
        }

        cout << i + 1 << ". " << heroes[i]->getName() << " HP:" << heroes[i]->getHp();

        if (!heroes[i]->getIsAlive())
        {
            cout << " DEAD";
        }

        cout << endl;
    }

    cout << "Energy: " << energy << endl;
}