#ifndef ROOM_H
#define ROOM_H
#include <vector>
#include "Monster.h"
#include "Item.h"

class Room
{
    public:
        Room();
        inline std::vector<Room> getConnectingRooms() {return connectingRooms;}
        virtual ~Room();
    protected:
    private:
        std::vector<Monster> monsters;
        std::vector<Item> itemsInRoom;
        std::vector<Room> connectingRooms;
};

#endif // ROOM_H
