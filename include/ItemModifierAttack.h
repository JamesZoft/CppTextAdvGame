#ifndef ITEMMODIFIERATTACK_H
#define ITEMMODIFIERATTACK_H
#include "PlayerStats.h"
#include "ItemModifier.h"


class ItemModifierAttack : public ItemModifier
{
    public:
        ItemModifierAttack(int _modifier);
        virtual ~ItemModifierAttack();
        void modify(PlayerStats &stats) override {stats.damage += modifier; }
    protected:
    private:
        int modifier;
};

#endif // ITEMMODIFIERATTACK_H
