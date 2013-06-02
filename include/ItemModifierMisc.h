#ifndef ITEMMODIFIERMISC_H
#define ITEMMODIFIERMISC_H

#include "ItemModifier.h"

class ItemModifierMisc : public ItemModifier
{
    public:
        ItemModifierMisc();
        virtual ~ItemModifierMisc();
        bool isEquippable() override;
    protected:
    private:
};

#endif // ITEMMODIFIERMISC_H
