#ifndef GAME_H
#define GAME_H
#include <vector>
#include "Room.h"

class Player;

class Game
{
    public:
        Game();
        void play();
        virtual ~Game();
        static std::vector<Room> &getRooms();
        static Room *getRoom(std::string roomName);
    protected:
    private:
        void generateRooms();
        static std::vector<Room> rooms;
        Player *player;
};

#endif // GAME_H
