#include "ItemFactory.h"
#include <string>
#include <memory>
#include "ItemModifier.h"
#include "ItemModifierAttack.h"
#include "Item.h"
#include "ItemModifierDefense.h"

using namespace std;

ItemFactory::ItemFactory()
{
    //ctor
}

Item& ItemFactory::createItem(cJSON *item)
{
    Item* newItem = new Item(cJSON_GetObjectItem(item, "name")->valuestring);
    string itemType = cJSON_GetObjectItem(item, "itemType")->valuestring;
    if(itemType == "weapon")
    {
        const int value = cJSON_GetObjectItem(item, "value")->valueint;
        newItem->add_modifier(new ItemModifierAttack(value));
    }
    if(itemType == "armour")
    {
        const int value = cJSON_GetObjectItem(item, "value")->valueint;
        newItem->add_modifier(new ItemModifierDefense(value));
    }
    cJSON *equipSlot = cJSON_GetObjectItem(item, "slot");
    if(equipSlot != nullptr)
        newItem->setEquipSlot(cJSON_GetObjectItem(item, "slot")->valuestring);
    return *newItem;
}

ItemFactory::~ItemFactory()
{
    //dtor
}
