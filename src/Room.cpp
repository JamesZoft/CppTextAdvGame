#include "Room.h"

Room::Room()
{
    //ctor
}

bool Room::removeItem(Item *item)
{
    auto i = std::find(itemsInRoom.begin(),itemsInRoom.end(),item);
    if(i != itemsInRoom.end())
    {
        itemsInRoom.erase(i);
        return true;
    }
    else
        return false;

}

Room::~Room()
{
    //dtor
}
