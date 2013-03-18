#ifndef ITEM_H
#define ITEM_H
#include <string>
#include "ItemModifier.h"
#include <vector>
#include <memory>
#include <list>

class Item
{
    public:
        Item(std::string _name);
        inline std::string getName() const {return name;}
        virtual ~Item();
        inline std::list<ItemModifier*> getModifiers() { return modifiers; }
        inline void add_modifier(ItemModifier* mod) { modifiers.push_back(mod); }
        bool hasModifierInCommonWith(Item *item);
        inline std::string getEquipSlot() {return equipSlot;}
        inline void setEquipSlot(std::string _equipSlot) {equipSlot = _equipSlot;}
    protected:
    private:
        std::string name;
        std::list<ItemModifier*> modifiers;
        std::string equipSlot;
};

#endif // ITEM_H
