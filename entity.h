#ifndef ENTITY_H
#define ENTITY_H
#include "string"

class Entity
{

public:
    std::string name;
    double health;
    unsigned int level;
    int mood; //0=Passiv;1=Hostile;2=Neutral
    Entity();
    void setName(std::string name);
    std::string getName();
    unsigned int getLevel();
    void setLevel(unsigned int lvl);
    double getHealth();
    void setHealth(double hp);
    int getMood();
    void setMood(int mood);
};

#endif // ENTITY_H
