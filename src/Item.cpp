#include "Item.h"
#include <string>
#include "ItemModifier.h"

using namespace std;

Item::Item(std::string _name)
{
    name = _name;
}

Item::~Item()
{
    //dtor
}
