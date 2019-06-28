#include <QCoreApplication>
#include "monster.h"
#include "world.h"
#include "entity.h"
#include "gamelogic.h"
#include <iostream>
int main()
{
    srand(time(0));

    gameLogic game;
    game.start();
//    srand(time(NULL));
//    std::string playerInput = "";

//    Map console;
//    Options setup = Options();
//    setup.titleScreen();
//    std::string pName = setup.getPlayerNameAndIntroGame();
//    int worldGenDiff = setup.getDesiredDifficuty();

//    World world(worldGenDiff);
//    Player player(pName);
//    player.showStats();
//    while (true) {
//        console.printHallway();
//        console.printRoomChoices();
//        getline(std::cin,playerInput);
//        if(playerInput.compare("MOVE")||playerInput.compare("move")){
//            trans=0;
//        } else if (playerInput.compare("STAY")||playerInput.compare("stay")) {
//            trans=1;
//        }
//        switch (trans) {
//        case 0: player.

//        }

//    }




    //    int c;
    //    std::cout<<"end game is 2";
    //    while(true){
    //        std::cin>>c;
    //        switch (c) {
    //        case 0: std::cout<<"m"; break;
    //            case 1: std::cout<<"d"; break;
    //                case 2: return 0;
    //            default: std::cout<<"what are you doing";
    //        }
    //    }


    //    Monster timmer("Timmer",99,1.00,1,world.getGameDifficulty());
    //    std::cout<<world.getGameDifficulty();
    //    kim.showDetails();
    //    timmer.showDetails();
    //    kim.attackMonster(&timmer);
    //    kim.showDetails();
    //    timmer.showDetails();




}
