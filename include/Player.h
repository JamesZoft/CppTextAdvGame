#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <vector>
#include <boost/regex.hpp>
#include <map>
#include "PlayerStats.h"

class Item;
class Room;

class Player
{
    public:
        Player(Room *startingRoom);
        virtual ~Player();
        inline std::string getName() {return name;}
        inline std::vector<Item*> getInventory() {return inventory;}
        void setName(std::string const& m_name);
        //static bool regexSearch(std::string command, boost::regex regexString);
        bool analyseMoveCommand();
        bool analyseAttackCommand();
        Room *getCurrentRoom();
        void applyModifiers();
        const std::map<std::string, Item*> &getEquippedItems() {return equippedItems;}
        void equipItem(std::string itemName);
        void pickupItem();
        PlayerStats getStats();
        void damageSelf(int damage);
    protected:
    private:
        PlayerStats stats;
        std::string name;
        std::vector<Item*> inventory;
        Room *currentRoom;
        std::map<std::string, Item*> equippedItems;
};

#endif // PLAYER_H
