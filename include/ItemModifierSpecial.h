#ifndef ITEMMODIFIERSPECIAL_H
#define ITEMMODIFIERSPECIAL_H

#include "ItemModifier.h"

class ItemModifierSpecial : public ItemModifier
{
    public:
        ItemModifierSpecial();
        virtual ~ItemModifierSpecial();
        bool isEquippable() override;
    protected:
    private:
};

#endif // ITEMMODIFIERSPECIAL_H
