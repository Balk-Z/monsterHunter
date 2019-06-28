#include "gamelogic.h"
#include "entity.h"
#include "map.h"
#include "monster.h"
#include "options.h"
#include "player.h"
#include "story.h"
#include "world.h"
#include <iostream>
#include <unistd.h>
int trans=-99;
bool isPlaying;
Map map;
Options setup;
Player player;
World world;
void gameLogic::start(){
    isPlaying=true;
    srand(time(NULL));
    setup.titleScreen();

    std::string pName = setup.getPlayerNameAndIntroGame();
    int worldGenDiff = setup.getDesiredDifficuty();
    world.setGameDifficulty(worldGenDiff);
    player.setStats(worldGenDiff);
    player.setName(pName);
    system("clear");
    map.printHallway();
    this->hallwayInput();
}
void gameLogic::giveTreasure(){
    srand(time(NULL));
    int amountOfGold = rand()%19 +1;
    player.setGold(player.getGold() + amountOfGold);
    map.printHallway();
    std::cout<<"The treasure contained "<<amountOfGold<<" gold.\n"<<"You now have: "<<player.getGold()<<std::endl;
}
void gameLogic::activateTrapcard(int gameDiff){
    srand(time(NULL));
    int damageFromTrap = (rand()%15 + 15);
    player.setHealth(player.getHealth() - damageFromTrap);
    if(player.isDead()){
        this->end();
    }
    map.printHallway();
    std::cout<<"After you get up you noticed that you have a scarpe on your knee, it hurts..\n"<<"You took "<<damageFromTrap<<" damage from the trap.\n";

}
void gameLogic::hallwayInput(){
    std::string playerInput = "";
    while (isPlaying) {
        std::cin>>playerInput;
        if(playerInput==("MOVE")||playerInput==("move")){
            trans=0;
        } else if(playerInput==("STAY")||playerInput==("stay")) {
            trans=1;
        } else if(playerInput==("QUIT")||playerInput==("quit")||playerInput==("EXIT")||playerInput==("exit")){
            this->end();
        } else if(playerInput==("STATUS")||playerInput==("status")) {
            trans=-99;
            player.showStats();
        } else {
            trans=-99;
            std::cout<<"Invalid input!\nOPTIONS: MOVE || STAY || STATUS || QUIT || EXIT\n";
        }
        switch (trans) {
        case 0:
            this->decide();
            break;
        case 1:
            int randomValue = rand()%100;
            double currentHp = player.getHealth();
            if(player.getMaxHealth()<=currentHp){
              std::cout<<"YOU TRYING TO OVERFLOW YOUR HP?!?!\n";
              player.setHealth(player.getMaxHealth());
            }
            if(randomValue>=0&&randomValue<=10){
                std::cout<<"While trying to heal a monster smells your blood and attacks!\n";
                sleep(1);
                this->startBattle();
            }else {
                int restoreAmount = player.getHealth() * 0.1;
                std::cout<<"You regenerated: "<<restoreAmount<<std::endl<<"Lucky your blood didn't attract a monster!\n";
                player.setHealth(player.getHealth()+restoreAmount);
            }
            break;
        }

    }
}
void gameLogic::decide(){
    srand(time(NULL));
    int n = rand()%100;
    int dice;
    if(n>=0&&n<=29){
        dice=0;
    }else if (n>=30&&n<=69) {
        dice=1;
    }else if (n>=70&&n<=84) {
        dice=2;
    }else if (n>=85&&n<=99) {
        dice=3;
    }
    std::cout<<"DICE FROM FUNCTION: decide()== "<<dice<<"+++"<<n<<std::endl;
    switch (dice) {
    case 0:
        system("clear");
        std::cout<<R"(


                                               You pass through the door. There is no light.
                                                   All of the sudden you can see again...
                                                      It's the same Hallway, or is it?


                                                                                                                     )"<<std::endl;

        map.printHallway();
        break;
        case 1:
            system("clear");
            std::cout<<R"(


                                               You pass through the door. It's quite dark.
                                                  There seems to be a monster ahead...
                                                     You engage with all your might!


                                                                                                                     )"<<std::endl;

        this->startBattle();
        //actual battle controls and function
        break;
            case 2:
                system("clear");
                std::cout<<R"(


                                               You pass through the door. It's quite dark.
                                                  There seems to be a treasure ahead...
                                                       You feel slightly aroused!


                                                                                                                     )"<<std::endl;
             map.printTreasure();
             this->giveTreasure();
            //Treasure with items
            //Implement items first genius
            break;
                case 3:
                    system("clear");
                    std::cout<<R"(


                                               You pass through the door. It's quite dark.
                                                     A giant Laser-Eye attacks you..
                                                   You trip and fall hurting yourself!


                                                                                                                     )"<<std::endl;
                 map.printTrap();
                 this->activateTrapcard(world.getGameDifficulty());
                    //implement Traps
                //player damage, maybe mini game to get out
                break;
//                    case 4:
//                        system("clear");
//                        std::cout<<R"(


//                                               You pass through the door. It's quite dark.
//                                                  You scream in fear, as you see this!!!



//                                                                                                                     )"<<std::endl;

//                          //implement easterEgg
//                          //yes this is sorted by prio, past balky
//                        break;

    }
}
void gameLogic::end(){
    isPlaying=false;
    std::string quit="";
    if(player.isDead()){
    std::cout<<"You died, this game might be unforgiving but I am not.\nDo you wish to play again?\n(y/n)";

    while(!isPlaying){
     std::cin>>quit;
     if(quit==("y")||quit==("Y")){
         isPlaying=true;
         this->start();
     }else if (quit==("n")||quit==("N")) {
    std::cout<<R"(
                     _________          _______  _        _        _______
                     \__   __/|\     /|(  ___  )( (    /|| \    /\(  ____ \
                        ) (   | )   ( || (   ) ||  \  ( ||  \  / /| (    \/
                        | |   | (___) || (___) ||   \ | ||  (_/ / | (_____
                        | |   |  ___  ||  ___  || (\ \) ||   _ (  (_____  )
                        | |   | (   ) || (   ) || | \   ||  ( \ \       ) |
                        | |   | )   ( || )   ( || )  \  ||  /  \ \/\____) |
                        )_(   |/     \||/     \||/    )_)|_/    \/\_______)

                                     _______  _______  _______
                                   (  ____ \(  ___  )(  ____ )
                                    | (    \/| (   ) || (    )|
                                    | (__    | |   | || (____)|
                                    |  __)   | |   | ||     __)
                                    | (      | |   | || (\ (
                                    | )      | (___) || ) \ \__
                                    |/       (_______)|/   \__/

                  _______  _        _______          _________ _        _______ _
                (  ____ )( \      (  ___  )|\     /|\__   __/( (    /|(  ____ \( )
                | (    )|| (      | (   ) |( \   / )   ) (   |  \  ( || (    \/| |
                | (____)|| |      | (___) | \ (_) /    | |   |   \ | || |      | |
                |  _____)| |      |  ___  |  \   /     | |   | (\ \) || | ____ | |
                | (      | |      | (   ) |   ) (      | |   | | \   || | \_  )(_)
                | )      | (____/\| )   ( |   | |   ___) (___| )  \  || (___) | _
                |/       (_______/|/     \|   \_/   \_______/|/    )_)(_______)(_)            )"<<std::endl<<std::endl<<std::endl;
    exit(1);
     }
    }
    } else if (!player.isDead()) {
        std::cout<<"Are you sure you want to quit the game?\nThere is no coming back..\n(y/n)";
        while(!isPlaying){
            std::cin>>quit;
            if(quit==("n")||quit==("N")){
                isPlaying=true;
                system("clear");
                map.printHallway();
                this->hallwayInput();
            }else if (quit==("y")||quit==("Y")) {
         std::cout<<R"(
                          _________          _______  _        _        _______
                          \__   __/|\     /|(  ___  )( (    /|| \    /\(  ____ \
                             ) (   | )   ( || (   ) ||  \  ( ||  \  / /| (    \/
                             | |   | (___) || (___) ||   \ | ||  (_/ / | (_____
                             | |   |  ___  ||  ___  || (\ \) ||   _ (  (_____  )
                             | |   | (   ) || (   ) || | \   ||  ( \ \       ) |
                             | |   | )   ( || )   ( || )  \  ||  /  \ \/\____) |
                             )_(   |/     \||/     \||/    )_)|_/    \/\_______)

                                          _______  _______  _______
                                        (  ____ \(  ___  )(  ____ )
                                         | (    \/| (   ) || (    )|
                                         | (__    | |   | || (____)|
                                         |  __)   | |   | ||     __)
                                         | (      | |   | || (\ (
                                         | )      | (___) || ) \ \__
                                         |/       (_______)|/   \__/

                       _______  _        _______          _________ _        _______ _
                     (  ____ )( \      (  ___  )|\     /|\__   __/( (    /|(  ____ \( )
                     | (    )|| (      | (   ) |( \   / )   ) (   |  \  ( || (    \/| |
                     | (____)|| |      | (___) | \ (_) /    | |   |   \ | || |      | |
                     |  _____)| |      |  ___  |  \   /     | |   | (\ \) || | ____ | |
                     | (      | |      | (   ) |   ) (      | |   | | \   || | \_  )(_)
                     | )      | (____/\| )   ( |   | |   ___) (___| )  \  || (___) | _
                     |/       (_______/|/     \|   \_/   \_______/|/    )_)(_______)(_)            )"<<std::endl<<std::endl<<std::endl;
         exit(1);
          }else {
              std::cout<<"Go ahead and try that one again..";
          }
         }
    }
}

void gameLogic::endBattle(){
    system("clear");
    map.printHallway();
    this->hallwayInput();
}
void gameLogic::startBattle(){
    map.printBattleScreen();
    srand(time(NULL));
    //NAMENS-Array, FORMEL für Level gen
    std::string playerInput;
    Monster enemy("SLITHER",player.getLevel() + 1,world.getGameDifficulty());
    while (!enemy.isDead()&&!player.isDead()) {
    std::cin>>playerInput;
    if(playerInput=="ATT"||playerInput=="att"){
        trans=10;
    } else if(playerInput==("ITEM")||playerInput==("item")) {
        trans=11;
    } else if (playerInput==("FLEE")||playerInput==("flee")) {
        trans=12;
    } else if(playerInput==("QUIT")||playerInput==("quit")||playerInput==("EXIT")||playerInput==("exit")){
        this->end();
    } else {
        trans=-99;
    std::cout<<"Invalid input!\nOPTIONS: ATT || ITEM || FLEE || QUIT || EXIT\n";
    }
    switch (trans) {
    case 10:
        player.attackMonster(&enemy);
        enemy.attackMonster(&player);
        map.printBattleScreen();
        player.showDetails(&enemy);
        break;
    case 11:

        //add items and logic
        std::cout<<"Sorry items are not implemented yet..\n"<<"Though i should maybe add health potions for PoC..\n";
        enemy.attackMonster(&player);
        map.printBattleScreen();
        break;
    case 12:
        std::cout<<"YOU COWARD!\n";
        int escapeChance = rand()% 100 + 1;
        if(escapeChance>=50){
            std::cout<<"You managed to escape!\n";
            sleep(2);
            this->endBattle();
        } else {
            system("clear");
            std::cout<<"The monster managed to prevent your cowardly escape\n";
            enemy.attackMonster(&player);
            map.printBattleScreen();
            break;
        }
        }
    }
    map.printHallway();
    if(enemy.isDead()){
    int xpGain = enemy.getExp();
    std::cout<<"This battle rewarded you with "<<xpGain<<" experience.\n";
    player.setExp(player.getExp() + xpGain);
    player.levelUpCheck();
    } else if (player.isDead()) {
        this->end();

}
}
gameLogic::gameLogic()
{
}
