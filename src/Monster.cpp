#include "Monster.h"
#include <string>
#include "Console.h"
#include <sstream>
#include <iostream>

using namespace std;

Monster::Monster()
{
    setAlive(true);
}

void Monster::damageSelf(int damage)
{
    if((hp - damage) > 0)
    {
        hp = hp - damage;
    }
    else if((hp - damage) <= 0)
    {
        setAlive(false);
        Console::write("You have slain the " + getName() + "!\n");
    }
    cout << "Damage: " << damage << " hp: " << hp << endl;
}

void Monster::setName(const std::string &_name)
{
    name = _name;
}
void Monster::setHp(const int &_hp)
{
    hp = _hp;
}
void Monster::setAttack(const int &_attack)
{
    attack = _attack;
}
void Monster::setAlive(bool _alive)
{
    alive = _alive;
}
/*
void Monster::attackPlayer()
{

}*/

Monster::~Monster()
{
    //dtor
}
