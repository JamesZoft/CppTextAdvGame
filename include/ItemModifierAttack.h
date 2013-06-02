#ifndef ITEMMODIFIERATTACK_H
#define ITEMMODIFIERATTACK_H

#include "ItemModifier.h"
#include "PlayerStats.h"

class PlayerStats;
class ItemModifier;

class ItemModifierAttack : public ItemModifier
{
    public:
        ItemModifierAttack(int _modifier);
        virtual ~ItemModifierAttack();
        void modify(PlayerStats &stats) override;
        bool isEquippable() override;
    protected:
    private:
        int modifier;
};

#endif // ITEMMODIFIERATTACK_H
