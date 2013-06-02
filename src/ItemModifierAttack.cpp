#include "ItemModifierAttack.h"
#include <sstream>
#include "Console.h"

ItemModifierAttack::ItemModifierAttack(int _modifier)
{
    modifier = _modifier;
}

bool ItemModifierAttack::isEquippable()
{
    return true;
}

void ItemModifierAttack::modify(PlayerStats &stats)
{
    stats.damage += modifier;
    std::stringstream output;
    output << stats.damage << "(" << modifier << ")" << "\n";
    Console::write("attack: " + output.str());
}

ItemModifierAttack::~ItemModifierAttack()
{
    //dtor
}
