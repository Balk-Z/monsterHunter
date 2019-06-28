#include "player.h"
#include <iostream>
#include "unistd.h"

void Player::setNextLvl(unsigned int xpValue)
{
    nextLvl = xpValue;
}

unsigned int Player::getNextLvl()
{
    return nextLvl;
}
void Player::levelUpCheck(){
    srand(time(0));
    if(this->getExp()>=this->getNextLvl()){
    int currentXpNeeded = this->getNextLvl();
    int currentLvl = this->getLevel();
    this->setLevel(currentLvl + 1);
    this->setNextLvl(currentXpNeeded + (currentXpNeeded * 1.35));
    std::cout<< "----------------------------------------You level up!----------------------------------------"<<std::endl;
    this->setHealth(this->getHealth()*(((double)rand()/RAND_MAX)+1));
    this->setMaxHealth(this->getHealth());
    this->setAttack(this->getAttack()*(((double)rand()/RAND_MAX)+1));
    this->setDefense(this->getDefense()*(((double)rand()/RAND_MAX)+1));
    }
}
void Player::showStats(){
    std::cout<<std::endl<<"Level:"<<this->getLevel()<<std::endl<<"Name:" + this->getName()<<std::endl<<"Health:"<<this->getHealth()<<std::endl<<"Attack:" << this->getAttack()<<std::endl<<"Defense:" << this->getDefense()<<std::endl<<"XP:"<<this->getExp()<<"/"<<this->getNextLvl()<<std::endl<<"Gold:"<<this->getGold()<<std::endl;
}

unsigned int Player::getMaxHealth()
{
    return maxHealth;
}

void Player::setMaxHealth(double maxHP)
{
    maxHealth = maxHP;
}

Player::Player()
{

}
void Player::setStats(int gameDif){
    this->setLevel(1);
    this->setGold(0);
    this->setAttack(50*(gameDif*0.9));
    this->setDefense(30*(gameDif*0.9));
    this->setHealth(100*(gameDif*0.9));
    this->setExp(0);
    this->setNextLvl(100*gameDif);
    this->setMaxHealth(this->getHealth());
}
