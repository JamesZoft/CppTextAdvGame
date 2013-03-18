#ifndef GAME_H
#define GAME_H
#include "Player.h"
#include "Room.h"
#include <vector>

class Game
{
    public:
        Game();
        void play();
        virtual ~Game();
        static inline std::vector<Room> &getRooms() {return Game::rooms;}
        static inline Room *getRoom(std::string roomName) {for(Room &room : Game::getRooms()) {if(room.getName() == roomName){return &room;} }}
    protected:
    private:
        void generateRooms();
        static std::vector<Room> rooms;
        Player *player;
};

#endif // GAME_H
