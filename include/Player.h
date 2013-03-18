#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <vector>
#include "Item.h"
#include "Room.h"
#include <boost/regex.hpp>
#include <map>

class Player
{
    public:
        Player(Room *startingRoom);
        virtual ~Player();
        inline std::string getName() {return name;}
        inline std::vector<Item*> getInventory() {return inventory;}
        inline void setName(std::string const& m_name) {name = m_name;}
        inline static bool regexSearch(std::string command, boost::regex regexString) { boost::smatch results; return boost::regex_search(command, results, regexString); }
        bool analyseMoveCommand();
        bool analyseAttackCommand();
        inline Room *getCurrentRoom() {return currentRoom;}
        void applyModifiers();
        const std::map<std::string, Item*> &getEquippedItems() {return equippedItems;}
        void equipItem(std::string itemName);
        void pickupItem();
        PlayerStats* getStats() {return stats;}
        inline void damageSelf(int damage) {stats->health = damage;}
    protected:
    private:
        PlayerStats *stats;
        std::string name;
        std::vector<Item*> inventory;
        Room *currentRoom;
        std::map<std::string, Item*> equippedItems;
};

#endif // PLAYER_H
