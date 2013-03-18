#include "Monster.h"
#include <string>
#include "Console.h"

Monster::Monster()
{
    //ctor
}

void Monster::damageSelf(unsigned damage)
{
    if((hp - damage) > 0)
    {
        hp = hp - damage;
    }
    else if((hp - damage) <= 0)
    {
        setAlive(false);
        Console::write("You have slain the " + getName() + "!");
    }
}

void Monster::attackPlayer()
{

}

Monster::~Monster()
{
    //dtor
}
