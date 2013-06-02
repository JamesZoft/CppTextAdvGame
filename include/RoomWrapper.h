#ifndef ROOMWRAPPER_H
#define ROOMWRAPPER_H
#include <string>
#include <vector>

class Room;

class RoomWrapper
{
    public:
        RoomWrapper();
        virtual ~RoomWrapper();
        std::vector<std::string> getConnectingRooms();
    protected:
    private:
        Room *room;
        bool changeRoom(Room *newRoom);
};

#endif // ROOMWRAPPER_H
