#include "ItemModifierDefense.h"
#include "PlayerStats.h"

ItemModifierDefense::ItemModifierDefense(int _modifier)
{
    modifier = _modifier;
}

bool ItemModifierDefense::isEquippable()
{
    return true;
}

void ItemModifierDefense::modify(PlayerStats &stats)
{
    stats.defense += modifier;
}

ItemModifierDefense::~ItemModifierDefense()
{
    //dtor
}
