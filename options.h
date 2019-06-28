#ifndef OPTIONS_H
#define OPTIONS_H
#include <string>

class Options
{
public:
    Options();
    void titleScreen();
    int getDesiredDifficuty();
    std::string getPlayerNameAndIntroGame();
};

#endif // OPTIONS_H
