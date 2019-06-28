#ifndef MONSTER_H
#define MONSTER_H
#include <entity.h>
#include <math.h>


class Monster : public Entity {
public:
    unsigned int attack;
    unsigned int defense;
    unsigned int exp;
    unsigned int gold;
    Monster();
    Monster(std::string name,unsigned int level,int painScale);
    void attackMonster(Monster* enemyMonster);
    void showDetails(Monster* enemyMonster);
    bool isDead();
    unsigned int getAttack() ;
    void setAttack(unsigned int att);
    unsigned int getDefense() ;
    void setDefense(unsigned int def);
    unsigned int getExp() ;
    void setExp(unsigned int xp);
    unsigned int getGold() ;
    void setGold(unsigned int money);
};

#endif // MONSTER_H
