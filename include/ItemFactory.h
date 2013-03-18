#ifndef ITEMFACTORY_H
#define ITEMFACTORY_H
#include "Item.h"
#include "cJSON.h"


class ItemFactory
{
    public:
        ItemFactory();
        virtual ~ItemFactory();
        static Item& createItem(cJSON *item);
    protected:
    private:
};

#endif // ITEMFACTORY_H
