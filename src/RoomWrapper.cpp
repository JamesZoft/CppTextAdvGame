#include "RoomWrapper.h"
#include "Room.h"

RoomWrapper::RoomWrapper()
{
    //ctor
}

std::vector<Room> RoomWrapper::getConnectingRooms()
{
    return room->getConnectingRooms();
}

bool RoomWrapper::changeRoom(Room *newRoom)
{
    room = newRoom;
}

RoomWrapper::~RoomWrapper()
{
    //dtor
}
