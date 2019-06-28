#include "entity.h"
#include <iostream>

unsigned int Entity::getLevel()
{
    return level;
}

void Entity::setLevel(unsigned int lvl)
{
    level = lvl;
}

double Entity::getHealth()
{
    return health;
}

void Entity::setHealth(double hp)
{
    health = hp;
}

int Entity::getMood()
{
    return mood;
}

void Entity::setMood(int newMood)
{
    mood = newMood;
}

Entity::Entity()
{
    setName("");
    setLevel(0);
    setHealth(0);
    setMood(0);
}

void Entity::setName(std::string newName)
{
    name = newName;
}

std::string Entity::getName()
{
    return name;
}
