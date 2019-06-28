#include "options.h"
#include <iostream>
#include "unistd.h"
#include <string>

Options::Options()
{

}
void Options::titleScreen(){
    std::cout<<R"(
               ___  ___                _            _   _             _              _____  _____
               |  \/  |               | |          | | | |           | |            / __  \|  _  |
               | .  . | ___  _ __  ___| |_ ___ _ __| |_| |_   _ _ __ | |_ ___ _ __  `' / /'| |/' |
               | |\/| |/ _ \| '_ \/ __| __/ _ \ '__|  _  | | | | '_ \| __/ _ \ '__|   / /  |  /| |
               | |  | | (_) | | | \__ \ ||  __/ |  | | | | |_| | | | | ||  __/ |    ./ /___\ |_/ /
               \_|  |_/\___/|_| |_|___/\__\___|_|  \_| |_/\__,_|_| |_|\__\___|_|    \_____(_)___/

                                                   WELCOME
                                             Press "RETURN" to start                                                            )"<<"\n"<<"\n"<<"\n"<<"\n"<<"\n";
    std::cin.get();

}
void trollPlayerforDumbness(){
    std::cout<<"Well then, it seems somebody can't follow instructions.."<<std::endl;
    sleep(3);
    std::cout<<"What to do with you hmm..."<<std::endl;
    sleep(5);
    std::cout<<"Hmm i know!"<<std::endl;
    sleep(5);
    std::cout<<"WAIT FOR IT!!!"<<std::endl;
    sleep(10);
    std::cout<<"You suck try following instructions!";
    exit(1);
}
int Options::getDesiredDifficuty(){
    int gDiff=-1;
    std::cout<<"Please enter your desired difficulty.\n";
    sleep(1);
    std::cout<<"0  = Easy\n1  = Medium\n3  = Hard\n5  = Hell-ish\n10 = Not Fun\n\n"<<"Anything between 0-10. Choose wisely."<<std::endl;
    std::cin>>gDiff;
    if(gDiff==0){
        gDiff=1;
        std::cout<<"Don't be a pu**y\n";
    } else if (gDiff>=10) {
        gDiff=10;
        std::cout<<"You seem to be insane, well have fun.\n";
    } else if (gDiff<0) {
        trollPlayerforDumbness();
}
        std::cout<<"\nYour difficulty was set to "<<gDiff<<std::endl;
        return gDiff;
}
std::string Options::getPlayerNameAndIntroGame(){
    sleep(1);
    system("clear");
    std::string playerName="";
    std::cout<<"                                                    Hello young adventurer!"<<std::endl;
    std::cout<<"                     This is a small game, created due to a competition between two - more or less - skilled students."<<std::endl;
    std::cout<<"                                                Please try and enjoy yourself."<<std::endl;
    sleep(7);
    system("clear");
    std::cout<<"WHAT IS THIS GAME?"<<std::endl;
    sleep(1);
    std::cout<<"-Turn-Based-RPG (at least at some point hopefully)\n"<<std::endl;
    sleep(2);
    std::cout<<"WHAT DO I DO?"<<std::endl;
    sleep(1);
    std::cout<<"-You kill creatures that are smaller than you.\n"<<std::endl;
    sleep(2);
    std::cout<<"CAN I DIE?"<<std::endl;
    sleep(1);
    std::cout<<"-Don’t worry about dying for now.\n"<<std::endl;
    sleep(2);
    std::cout<<"WHAT IS MY GOAL?"<<std::endl;
    sleep(1);
    std::cout<<"-Be the very best, like no one ever was.\n"<<std::endl;
    sleep(2);
    std::cout<<"HOW DO I PLAY?"<<std::endl;
    sleep(1);
    std::cout<<"-Look at screen, press button to corresponding action, hit enter.\n"<<std::endl;
    sleep(2);
    std::cout<<"IS THERE ANYTHING ELSE?"<<std::endl;
    sleep(1);
    std::cout<<"Yes...something very important."<<std::endl;
    sleep(2);
    std::cout<<"........................"<<std::endl;
    sleep(2);
    std::cout<<".........................."<<std::endl;
    sleep(3);
    std::cout<<"............................"<<std::endl;
    sleep(3);
    std::cout<<"The game doesn't like the player, not one bit."<<std::endl;
    std::cout<<"\nShall we begin?\n(Hit 'y' or 'n' and press ENTER)\n";
    std::string introChoice ="";
    std::cin>>introChoice;
    if(introChoice == "n"||introChoice=="N"){
        std::cout<<std::endl<<std::endl<<"WELL THEN GOODBYE!\n";
         exit(1);
    } else if(introChoice =="y"||introChoice=="Y") {
//    std::cout<<"Great! First, what is your name?"<<std::endl;
//    std::string temp;
//    std::cin>>temp;
//    std::cin.ignore(temp.length(),'\n');
//    for (int i=0;i<=30;i++) {
//        std::cout<<"--------------------------------------- ERROR ERROR ERROR--------------------------------------"<<"\a\a\a"<<std::endl;
//    }
//    sleep(1);
//    system("clear");
//    std::cout<<"\n\n------------------------------MY NAME IS TERMI THE TERMINAL AND I AM YOUR HOST!-----------------------\n"<<"\a\a\a\a\a\a\a\a";
//    sleep(1);
//    std::cout<<"--------------------------------AS IF I WOULD CARE ABOUT YOUR NAME, FOOL-----------------------\n"<<"\a\a\a\a\a\a\a\a";
//    sleep(1);
//    std::cout<<"--------------------------------------I WILL MAKE YOU FEEL TERRIBLE!-----------------------\n"<<"\a\a\a\a\a\a\a\a\a\a\a";
//    sleep(1);
//    std::cout<<"-------------------------------------------YOU WILL WISH TO QUIT-----------------------\n"<<"\a\a\a\a\a\a\a\a\a\a\a\a";
//    sleep(1);
//    std::cout<<"------------------------------------------MUHAHAHAHAHAHAHAHAHAHAHAHAH-----------------------\n"<<"\a\a\a\a\a\a\a\a";
//    sleep(5);
//    std::cout<<R"(
//                _
//               | |
//               | |===( )   //////
//               |_|   |||  | o o|
//                      ||| ( c  )                  ____
//                       ||| \= /                  ||   \_
//                        ||||||                   ||     |
//                        ||||||                ...||__/|-"
//                        ||||||             __|________|__
//                          |||             |______________|
//                          |||             || ||      || ||
//                          |||             || ||      || ||
//  ------------------------|||-------------||-||------||-||-------
//                          |__>            || ||      || ||                  )"<<std::endl;
//    sleep(1);
    std::cout<<"Now that these bugs are gone, WELCOME!\n"<<"Please do tell me your Name. :)\n";
    std::cin>>playerName;
    return playerName;
    } else {
        trollPlayerforDumbness();
}
}

