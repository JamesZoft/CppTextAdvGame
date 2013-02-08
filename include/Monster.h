#ifndef MONSTER_H
#define MONSTER_H
#include "Item.h"
#include <vector>
#include <string>

class Monster
{
    public:
        Monster();
        inline std::vector<Item> getLoot() {return loot;}
        inline std::string getName() {return name;}
        virtual ~Monster();
    protected:
    private:
        std::vector<Item> loot;
        std::string name;
};

#endif // MONSTER_H
