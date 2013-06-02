#include "Room.h"
#include "Monster.h"
#include "Item.h"

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

std::vector<Monster> Room::getMonsters()
{
    return monsters;
}

std::vector<std::string> Room::getConnectingRooms()
{
    return connectingRooms;
}

void Room::setName(const std::string& _name)
{
     name = _name;
}

void Room::addConnectingRoom(const std::string& r)
{
    connectingRooms.push_back(r);
}

void Room::addMonster(const Monster& m)
{
    monsters.push_back(m);
}

void Room::addItem(Item& i)
{
    itemsInRoom.push_back(&i);
    std::cout << "added item: " << i.getName() << std::endl;
}

std::vector<Item*> Room::getItems()
{
    return itemsInRoom;
}

Room::~Room()
{
    //dtor
}
