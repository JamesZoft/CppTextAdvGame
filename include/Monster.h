#ifndef MONSTER_H
#define MONSTER_H
#include "Item.h"
#include <vector>
#include <string>
#include "Player.h"

class Monster
{
    public:
        Monster();
        inline std::vector<Item*> getLoot() {return loot;}
        inline std::string getName() {return name;}
        inline void setName(const std::string &_name) {name = _name;}
        inline void setHp(const int &_hp) {hp = _hp;}
        inline void setAttack(const int &_attack) {attack = _attack;}
        inline void setAlive(bool _alive) { alive = _alive;}
        void damageSelf(unsigned damage);
        void attackPlayer(Player *player);
        inline bool isAlive() {return alive;}
        virtual ~Monster();
    protected:
    private:
        std::vector<Item*> loot;
        std::string name;
        int hp;
        int attack;
        bool alive;
};

#endif // MONSTER_H
