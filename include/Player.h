#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <vector>
#include "Item.h"
#include "Room.h"

class Player
{
    public:
        Player();
        virtual ~Player();
        inline std::string getName() {return name;}
        inline std::vector<Item> getInventory() {return inventory;}
        inline void setName(std::string const& m_name) {name = m_name;}
    protected:
    private:
        std::string name;
        std::vector<Item> inventory;
        Room currentRoom;
};

#endif // PLAYER_H
