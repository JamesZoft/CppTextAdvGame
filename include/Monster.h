#ifndef MONSTER_H
#define MONSTER_H
#include <vector>
#include <string>

class Item;
class Player;

class Monster
{
    public:
        Monster();
        inline std::vector<Item*> getLoot() {return loot;}
        inline std::string getName() {return name;}
        void setName(const std::string &_name);
        void setHp(const int &_hp);
        void setAttack(const int &_attack);
        void setAlive(bool _alive);
        void damageSelf(int damage);
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
