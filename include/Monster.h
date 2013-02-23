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
        inline void setName(const std::string &_name) {name = _name;}
        inline void setHp(const int &_hp) {hp = _hp;}
        inline void setAttack(const int &_attack) {attack = _attack;}
        virtual ~Monster();
    protected:
    private:
        std::vector<Item> loot;
        std::string name;
        int hp;
        int attack;
};

#endif // MONSTER_H
