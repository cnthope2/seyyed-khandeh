#ifndef HERO_HPP
#define HERO_HPP

#include <string>
using namespace std;

enum TargetType
{
    ENEMY,
    ALLY,
    NONE
   
};

class Hero
{

protected:
    string name;
    string role;
    int maxHp;
    int hp;
    bool isAlive;
    int damage;
    int specialSkillCooldown;
    int currentSpecialSkillTimer;
    int dopingTurns;
    int scorpionCount;
    int shield;
    int shieldTurns;
    bool isHidden;
    int hiddenTurns;
    static int reverseTurns;
    int serumTurns;
    Hero *enemy;
    Hero **team;
    Hero **enemyteam;

public:
    Hero(string name, string role, int hp, int specialPower);
    virtual ~Hero() {}
    virtual void useNormalSkill1() = 0;
    virtual void useNormalSkill2() = 0;
    virtual void useSpecialSkill() = 0;
    virtual int getSkill1Cost() const = 0;
    virtual int getSkill2Cost() const = 0;
    virtual int getSpecialCost() const = 0;
    virtual TargetType getSkill1TargetType() const = 0;
    virtual TargetType getSkill2TargetType() const = 0;
    virtual TargetType getSpecialTargetType() const = 0;
    string getName() const;
    string getRole() const;
    void setHidden(bool value);
    void setHiddenTurns(int turns);
    void setShield(int value);
    int getShield() const;
    void setShieldTurns(int turns);
    int getShieldTurns() const;
    int getHp() const;
    bool getIsAlive() const;
    void takeDamage(int amount);
    void setSerumTurns(int turns);
    int getSerumTurns() const;
    void applyEffects();
    int getDamageWithDoping(int damage);
    void heal(int amount);
    void setEnemy(Hero *e);
    void setTeam(Hero **t);
    Hero** getTeam() const;
    void setEnemyTeam(Hero **enemies);
    void revive(int healthAmount);
    static void setReverseTurns(int turns);
    static int getReverseTurns();
    bool getIsHidden() const;
    void setDoping(int turns);
    int getDoping() const;
    void reduccooldown();
    bool specialready() const;
    void resetcooldown();
};

#endif