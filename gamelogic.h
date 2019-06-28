#ifndef GAMELOGIC_H
#define GAMELOGIC_H


class gameLogic
{
public:
    gameLogic();
    void start();
    void end();
    void decide();
    void startBattle();
    void endBattle();
    void hallwayInput();
    void giveTreasure();
    void activateTrapcard(int gameDiff);
};

#endif // GAMELOGIC_H
