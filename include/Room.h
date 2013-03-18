#ifndef ROOM_H
#define ROOM_H
#include <vector>
#include "Monster.h"
#include "Item.h"
#include <string>
#include <iostream>
#include <algorithm>

class Room
{
    public:
        Room();
        inline std::vector<std::string> getConnectingRooms() {return connectingRooms;}
        inline std::vector<Monster> getMonsters() {return monsters;}
        inline std::vector<Item*> getItems() {return itemsInRoom;}
        inline void addMonster(const Monster &m) {monsters.push_back(m);}
        inline void addItem(Item &i) {itemsInRoom.push_back(&i); std::cout << "added item: " << i.getName() << std::endl;}
        inline void addConnectingRoom(const std::string &r) {connectingRooms.push_back(r);}
        inline std::string getName() {return name;}
        inline void setName(const std::string &_name) {name = _name;}
        bool removeItem(Item *item);
        virtual ~Room();
    protected:
    private:
        std::vector<Monster> monsters;
        std::vector<Item*> itemsInRoom;
        std::vector<std::string> connectingRooms;
        std::string name;
};

#endif // ROOM_H
