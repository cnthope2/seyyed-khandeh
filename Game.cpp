#include "Game.hpp"
#include "Aminsafety.hpp"
#include "LittleTaha.hpp"
#include "WhiteDoctor.hpp"
#include "dannygulang.h"
#include "shahriar.h"
#include "tahabozorgeh.h"
#include "hero.hpp"
#include <iostream>
using namespace std;

Game::Game() : team1(1), team2(2)
{
    currentRound = 1;
}

void Game::setupGame()
{
    bool chosen[6] = {false};

    cout << "Player 1 please choose your heroes:" << endl;
    cout << endl;

    for (int i = 0; i < 3; i++)
    {
        int choice;

        while (true)
        {
            cout << "Hero " << i + 1 << ":\n";
            cout << "1. Aminimany\n";
            cout << "2. Tahakochikeh\n";
            cout << "3. doctorsefid\n";
            cout << "4. DannyGulang\n";
            cout << "5. AghaShahriar\n";
            cout << "6. TahaBozorgeh\n";
            cout << endl;

            cin >> choice;

            if (!cin)
            {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Please enter a number!" << endl;
                continue;
            }

            cin.ignore(10000, '\n');

            if (choice < 1 || choice > 6)
            {
                cout << "Invalid choice!" << endl;
                continue;
            }

            if (chosen[choice - 1])
            {
                cout << "This hero is already selected!" << endl;
                continue;
            }

            chosen[choice - 1] = true;
            break;
        }

        Hero *hero = nullptr;

        switch (choice)
        {
        case 1:
        {
            hero = new Aminsafety();
            break;
        }

        case 2:
        {
            hero = new LittleTaha();
            break;
        }

        case 3:
        {
            hero = new WhiteDoctor();
            break;
        }

        case 4:
        {
            hero = new dannygulang();
            break;
        }

        case 5:
        {
            hero = new shahriar();
            break;
        }

        case 6:
        {
            hero = new tahabozorgeh();
            break;
        }
        }

        team1.addhero(hero);
    }
    cout << endl;
    cout << "Player 1 team completed!\n";
    cout << endl;

    cout << "Player 2 please choose your heroes:\n";
    cout << endl;

    for (int i = 0; i < 3; i++)
    {
        int choice;

        while (true)
        {
            cout << "Hero " << i + 1 << ":\n";
            cout << "1. Aminimany\n";
            cout << "2. Tahakochikeh\n";
            cout << "3. doctorsefid\n";
            cout << "4. DannyGulang\n";
            cout << "5. AghaShahriar\n";
            cout << "6. TahaBozorgeh\n";
            cout << endl;

            cin >> choice;

            if (!cin)
            {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Please enter a number!" << endl;
                continue;
            }

            cin.ignore(10000, '\n');

            if (choice < 1 || choice > 6)
            {
                cout << "Invalid choice!" << endl;
                continue;
            }

            if (chosen[choice - 1])
            {
                cout << "This hero is already selected!" << endl;
                continue;
            }

            chosen[choice - 1] = true;
            break;
        }

        Hero *hero = nullptr;

        switch (choice)
        {
        case 1:
        {
            hero = new Aminsafety();
            break;
        }

        case 2:
        {
            hero = new LittleTaha();
            break;
        }

        case 3:
        {
            hero = new WhiteDoctor();
            break;
        }

        case 4:
        {
            hero = new dannygulang();
            break;
        }

        case 5:
        {
            hero = new shahriar();
            break;
        }

        case 6:
        {
            hero = new tahabozorgeh();
            break;
        }
        }

        team2.addhero(hero);
    }
    cout << endl;
    cout << "Player 2 team completed!\n";
    cout << endl;

    for (int i = 0; i < 3; i++)
    {
        team1Heroes[i] = team1.gethero(i);
        team2Heroes[i] = team2.gethero(i);
    }
    for (int i = 0; i < 3; i++)
    {
        team1Heroes[i]->setTeam(team1Heroes);
        team1Heroes[i]->setEnemyTeam(team2Heroes);

        team2Heroes[i]->setTeam(team2Heroes);
        team2Heroes[i]->setEnemyTeam(team1Heroes);
    }
}

void Game::playGame()
{
    setupGame();

    currentRound = 1;

    while (!checkGameEnd() && currentRound <= 15)
    {
        cout << ">>>>>>>>>>> Round " << currentRound << " >>>>>>>>>>>\n";

        team1.startRound();
        playTurn(team1, team2);

        if (checkGameEnd())
        {
            return;
        }

        team2.startRound();
        playTurn(team2, team1);

        if (checkGameEnd())
        {
            return;
        }

        applyRoundEffects();

        currentRound++;
    }

    int alive1 = team1.aliveheros();
    int alive2 = team2.aliveheros();

    cout << "************* GAME OVER *************" << endl;
    cout << "Player 1 Alive Heroes: " << alive1 << endl;
    cout << "Player 2 Alive Heroes: " << alive2 << endl;

    if (alive1 > alive2)
    {
        cout << "Player 1 Wins!" << endl;
    }
    else if (alive2 > alive1)
    {
        cout << "Player 2 Wins!" << endl;
    }
    else
    {
        cout << "Draw!" << endl;
    }
}
void Game::playTurn(team &currentTeam, team &enemyTeam)
{
    while (currentTeam.getenergy() > 0)
    {
        bool canPlay = false;

        for (int i = 0; i < currentTeam.herocount(); i++)
        {
            Hero *hero = currentTeam.gethero(i);

            if (!hero->getIsAlive())
            {
                continue;
            }

            if (currentTeam.getenergy() >= hero->getSkill1Cost())
                canPlay = true;

            if (currentTeam.getenergy() >= hero->getSkill2Cost())
                canPlay = true;

            if (hero->specialready() &&
                currentTeam.getenergy() >= hero->getSpecialCost())
                canPlay = true;
        }

        if (!canPlay)
        {
            cout << "No skills can be used. Turn ended!" << endl;
            break;
        }
        cout << "Current Energy: " << currentTeam.getenergy() << endl;

        currentTeam.showheros();

        cout << "0. End Turn\n";
        cout << "Choose Hero: ";

        int heroChoice;
        cin >> heroChoice;

        if (heroChoice == 0)
        {
            cout << "Turn Ended!\n"
                 << endl;
            break;
        }

        Hero *hero = currentTeam.gethero(heroChoice - 1);

        if (hero == nullptr)
        {
            cout << "Invalid Hero!\n"
                 << endl;
            continue;
        }

        if (!hero->getIsAlive())
        {
            cout << "This hero is dead!\n"
                 << endl;
            continue;
        }

        cout << "Choose Skill:\n";
        cout << "1. Normal Skill 1 (Cost: " << hero->getSkill1Cost() << ")\n";

        cout << "2. Normal Skill 2 (Cost: " << hero->getSkill2Cost() << ")\n";

        cout << "3. Special Skill (Cost: " << hero->getSpecialCost() << ")\n";

        int skillChoice;
        cin >> skillChoice;

        int cost = 0;
        TargetType targetType;

        switch (skillChoice)
        {
        case 1:

            cost = hero->getSkill1Cost();
            targetType = hero->getSkill1TargetType();
            break;

        case 2:

            cost = hero->getSkill2Cost();
            targetType = hero->getSkill2TargetType();
            break;

        case 3:

            if (!hero->specialready())
            {
                cout << "Special not ready!\n";
                cout << endl;
                continue;
            }

            cost = hero->getSpecialCost();
            targetType = hero->getSpecialTargetType();
            break;

        default:

            cout << "Invalid Skill!\n";
            continue;
        }
        if (currentTeam.getenergy() < cost)
        {
            cout << "Not enough energy!\n";
            continue;
        }

        Hero *target = nullptr;

        if (targetType == ENEMY)
        {
            cout << "Choose Enemy:\n";

            enemyTeam.showheros(true);

            int targetChoice;
            cin >> targetChoice;

            target = enemyTeam.gethero(targetChoice - 1);

            if (target == nullptr)
            {
                cout << "Invalid target!\n"
                     << endl;
                continue;
            }

            if (!target->getIsAlive())
            {
                cout << "Target is dead!\n"
                     << endl;
                continue;
            }
        }
        else if (targetType == ALLY)
        {
            cout << "Choose Ally:\n";

            currentTeam.showheros(true);

            int targetChoice;
            cin >> targetChoice;

            target = currentTeam.gethero(targetChoice - 1);

            if (target == nullptr)
            {
                cout << "Invalid target!\n";
                continue;
            }

            if (!target->getIsAlive())
            {
                cout << "Target is dead!\n";
                continue;
            }
        }

        if (target != nullptr)
        {
            hero->setEnemy(target);
        }

        currentTeam.consumeenergy(cost);

        switch (skillChoice)
        {
        case 1:
        {
            hero->useNormalSkill1();
            break;
        }

        case 2:
        {
            hero->useNormalSkill2();
            break;
        }

        case 3:
        {
            hero->useSpecialSkill();
            break;
        }
        }

        if (enemyTeam.AllHerosDead())
        {
            return;
        }
    }
}

void Game::applyRoundEffects()
{
    for (int i = 0; i < team1.herocount(); i++)
    {
        Hero *h = team1.gethero(i);

        if (h)
        {
            h->applyEffects();
            h->reduccooldown();
        }
    }

    for (int i = 0; i < team2.herocount(); i++)
    {
        Hero *h = team2.gethero(i);

        if (h)
        {
            h->applyEffects();
            h->reduccooldown();
        }
    }
}

bool Game::checkGameEnd()
{
    if (team1.AllHerosDead())
    {
        cout << "Player 2 Wins!\n";
        return true;
    }

    if (team2.AllHerosDead())
    {
        cout << "Player 1 Wins!\n";
        return true;
    }

    return false;
}
