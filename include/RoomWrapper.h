#ifndef ROOMWRAPPER_H
#define ROOMWRAPPER_H
#include "Room.h"

class RoomWrapper
{
    public:
        RoomWrapper();
        virtual ~RoomWrapper();
        std::vector<Room> getConnectingRooms();
    protected:
    private:
        Room *room;
        bool changeRoom(Room *newRoom);
};

#endif // ROOMWRAPPER_H
