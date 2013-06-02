#ifndef ITEM_H
#define ITEM_H
#include <string>
#include <vector>
#include <memory>
#include <list>

class ItemModifier;

class Item
{
    public:
        Item(std::string _name);
        std::string getName() const;
        virtual ~Item();
        std::list<ItemModifier*> getModifiers();
        void add_modifier(ItemModifier* mod);
        bool hasModifierInCommonWith(Item *item);
        std::string getEquipSlot();
        void setEquipSlot(std::string _equipSlot);
    protected:
    private:
        std::string name;
        std::list<ItemModifier*> modifiers;
        std::string equipSlot;
};

#endif // ITEM_H
