#ifndef GAME_HPP
#define GAME_HPP

#include "team.h"

class Game
{
private:
    team team1;
    team team2;
    int currentRound;

    Hero *team1Heroes[3];
    Hero *team2Heroes[3];

public:
    Game();

    void setupGame();
    void playGame();
    void playTurn(team &currentTeam, team &enemyTeam);

    void applyRoundEffects();

    bool checkGameEnd();
};

#endif