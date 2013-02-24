#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <vector>
#include "Item.h"
#include "Room.h"
#include <boost/regex.hpp>

class Player
{
    public:
        Player(Room *startingRoom);
        virtual ~Player();
        inline std::string getName() {return name;}
        inline std::vector<Item> getInventory() {return inventory;}
        inline void setName(std::string const& m_name) {name = m_name;}
        inline static bool regexSearch(std::string command, boost::regex regexString) { boost::smatch results; return boost::regex_search(command, results, regexString); }
        bool analyseMoveCommand();
    protected:
    private:
        std::string name;
        std::vector<Item> inventory;
        Room *currentRoom;
};

#endif // PLAYER_H
