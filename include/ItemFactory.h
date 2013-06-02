#ifndef ITEMFACTORY_H
#define ITEMFACTORY_H

class Item;
class cJSON;

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
