#ifndef PLAYER_H
#define PLAYER_H
#include <monster.h>
#include <string>
class Player : public Monster
{
public:
    unsigned int nextLvl;
    double maxHealth;
    Player();
    void setNextLvl(unsigned int xpValue);
    void levelUpCheck();
    unsigned int getNextLvl();
    void showStats();
    void setStats(int gameDiff);
    unsigned int getMaxHealth();
    void setMaxHealth(double maxHp);
};

#endif // PLAYER_H
