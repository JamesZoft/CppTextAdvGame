#ifndef ITEMMODIFIER_H
#define ITEMMODIFIER_H
#include "PlayerStats.h"


class ItemModifier
{
    public:
        ItemModifier();
        virtual ~ItemModifier();
        virtual void modify(PlayerStats &stats) = 0;
    protected:
    private:

};

#endif // ITEMMODIFIER_H
