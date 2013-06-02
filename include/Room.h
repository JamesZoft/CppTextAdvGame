#ifndef ROOM_H
#define ROOM_H
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

class Item;
class Monster;

class Room
{
    public:
        Room();
        std::vector<std::string> getConnectingRooms();
        std::vector<Monster> getMonsters();
        std::vector<Item*> getItems();
        void addMonster(const Monster &m);
        void addItem(Item &i);
        void addConnectingRoom(const std::string &r);
        std::string getName() {return name;}
        void setName(const std::string &_name);
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
