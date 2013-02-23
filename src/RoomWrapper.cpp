#include "RoomWrapper.h"
#include "Room.h"
#include <string>

RoomWrapper::RoomWrapper()
{
    //ctor
}

std::vector<std::string> RoomWrapper::getConnectingRooms()
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
