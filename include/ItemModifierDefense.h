#ifndef ITEMMODIFIERDEFENSE_H
#define ITEMMODIFIERDEFENSE_H
#include "ItemModifier.h"


class ItemModifierDefense : public ItemModifier
{
    public:
        ItemModifierDefense(int _modifier);
        virtual ~ItemModifierDefense();
        void modify(PlayerStats &stats) override {stats.defense += modifier; }
    protected:
    private:
        int modifier;
};

#endif // ITEMMODIFIERDEFENSE_H
