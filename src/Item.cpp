#include "Item.h"
#include <string>
#include "ItemModifier.h"

using namespace std;

Item::Item(std::string _name)
{
    name = _name;
}

std::list<ItemModifier*> Item::getModifiers()
{
    return modifiers;
}

std::string Item::getEquipSlot()
{
    return equipSlot;
}

void Item::setEquipSlot(std::string _equipSlot)
{
    equipSlot = _equipSlot;
}

void Item::add_modifier(ItemModifier* mod)
{
    modifiers.push_back(mod);
}

std::string Item::getName() const
{
    return name;
}

Item::~Item()
{
    //dtor
}
