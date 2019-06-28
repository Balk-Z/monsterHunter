#ifndef WORLD_H
#define WORLD_H
#include "monster.h"

class World
{
public:
    World();
    int getGameDifficulty() const;
    void setGameDifficulty(int value);
protected:
    int gameDifficulty;//0=easy,1=medium,2=hard,3=hell-ish,10=don't
};

#endif // WORLD_H
