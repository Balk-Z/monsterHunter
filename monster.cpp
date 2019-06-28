#include "monster.h"
#include <iostream>
#include <cmath>

unsigned int Monster::getAttack()
{
    return attack;
}

void Monster::setAttack(unsigned int att)
{
    attack = att;
}

unsigned int Monster::getDefense()
{
    return defense;
}

void Monster::setDefense(unsigned int def)
{
    defense = def;
}

unsigned int Monster::getExp()
{
    return exp;
}

void Monster::setExp(unsigned int xp)
{
    exp = xp;
}

unsigned int Monster::getGold()
{
    return gold;
}

void Monster::setGold(unsigned int money)
{
    gold = money;
}
Monster::Monster(){

}


Monster::Monster(std::string name,unsigned int level, int painScale)
{
    srand(time(NULL));
    setName(name);
    setLevel(level);
    setHealth((20.5*pow(2*level,2)*painScale)/4);
    setAttack(rand()% (((level*100)/8)*painScale) +20);
    setDefense(rand()% (((level*100)/10)*painScale) + 20);
    setGold(rand()%(10*painScale)+ 1);
    setExp((((round((this->health)+this->attack+this->defense)/2)/3))*painScale);

//    setMood(mood);
}
void Monster::attackMonster(Monster* enemyMonster){
    std::cout<<"\n"<<this->getName()<<" prepares an attack and charges!"<<std::endl;

    unsigned int myAtt=this->getAttack();
    double myHp = this->getHealth();
    double enemyHp = enemyMonster->getHealth();
    unsigned int enemyDef = enemyMonster->getDefense();
    std::cout<<"\n"<<this->getName()<<" is attacking: "<<enemyMonster->getName()<<std::endl;
    if(myAtt<enemyDef){
        std::cout<<this->name<<" is to weak!\n"<<this->getName()<<" took: "<<(enemyDef-myAtt)<<" damage."<<std::endl;
        this->setHealth(myHp-(enemyDef-myAtt));
    } else if(enemyDef<myAtt){
        std::cout<<enemyMonster->getName()<<" took: "<<(myAtt-enemyDef)<<" damage."<<std::endl;
        enemyMonster->setHealth(enemyHp-(myAtt-enemyDef));
    }
    if(enemyMonster->isDead()){
        enemyMonster->setHealth(0);
        std::cout<<"The enemy died!"<<std::endl;
    } else if (this->isDead()) {
        this->setHealth(0);
        std::cout<<"You died..."<<std::endl;
        std::cout<<"\a";
    }
}
bool Monster::isDead(){
    if(this->getHealth()<=0){
        return true;
    }else {
        return false;
    }
}
void Monster::showDetails(Monster* monster){
    if(!(this->health==0)){
        std::cout<<"Name: " + this->getName()<<"\t\t\t"<<"Name: " + monster->getName()<<std::endl<<"Health: "<<this->getHealth()<<"\t\t\t"<<"Health: "<<monster->getHealth()<<std::endl<<"Attack: " << this->getAttack()<<"\t\t\t"<<"Attack: " << monster->getAttack()<<std::endl<<"Defense: " << this->getDefense()<<"\t\t\t"<<"Defense: " << monster->getDefense()<<std::endl;
    }
}




