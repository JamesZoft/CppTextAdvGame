#include "Player.h"
#include <string>
#include <boost/regex.hpp>
#include "Game.h"
#include "Console.h"
#include <sstream>
#include "ItemModifier.h"
#include "Item.h"
#include "Monster.h"
#include "PlayerStats.h"
#include "CommandAnalyser.h"
#include "../../useful_cpp_libs/cpp-utils/stringutils.hpp"

using namespace std;

Player::Player(Room *startingRoom)
{
    stats.damage = 5;
    currentRoom = startingRoom;
    equippedItems.insert(std::make_pair("head", nullptr));
    equippedItems.insert(std::make_pair("neck", nullptr));
    equippedItems.insert(std::make_pair("shoulders", nullptr));
    equippedItems.insert(std::make_pair("back", nullptr));
    equippedItems.insert(std::make_pair("chest", nullptr));
    equippedItems.insert(std::make_pair("hands", nullptr));
    equippedItems.insert(std::make_pair("wrists", nullptr));
    equippedItems.insert(std::make_pair("legs", nullptr));
    equippedItems.insert(std::make_pair("feet", nullptr));
    equippedItems.insert(std::make_pair("weapon", nullptr));
    equippedItems.insert(std::make_pair("offhand", nullptr));
}

void Player::applyModifiers()
{
    list<ItemModifier*> modifiers;
    for(auto item : inventory)
    {
        for(auto mod : item->getModifiers())
        {
            mod->modify(stats);
        }
    }
}

void Player::pickupItem()
{
    Console::write("The items available to pick up are: ");
    for(unsigned i = 0; i < currentRoom->getItems().size(); i++)
    {
        std::stringstream output;
        output << i << ": " << currentRoom->getItems()[i]->getName() << ",\n";
        Console::write(output.str());
    }
    Console::write("Which item do you want to pick up?");
    unsigned itemNumber;
    cin >> itemNumber;
    if(itemNumber < currentRoom->getItems().size() || itemNumber >= 0)
    {
        Item* item = currentRoom->getItems()[itemNumber];
        if(currentRoom->removeItem(item))
        {
            bool isEquippable = true;
            for(ItemModifier* m : item->getModifiers())
            {
                if(m->isEquippable())
                {
                    Console::write("You picked up a " + item->getName() + "! Would you like to equip it? [y/n]");
                    inventory.push_back(item);
                    string answer;
                    cin >> answer;
                    if(CommandAnalyser::regexSearch(answer, boost::regex("[yY](es)?")))
                    {
                        equipItem(item->getName());
                    }
                }
            }

        }
    }
}

void Player::equipItem(string itemName)
{
    auto found = std::find_if(std::begin(inventory), std::end(inventory), [&](const Item *_item) {
        return (_item->getName() == itemName);
    });
    if(found == inventory.end())
        Console::write("You do not have any item by that name in your inventory.");
    else
    {
        Item *item = *found;
        auto slotContent = equippedItems[item->getEquipSlot()];
        if(slotContent == nullptr)
            equippedItems[item->getEquipSlot()] = item;
        else
        {
            Item *currEquippedItem = slotContent;
            Console::write("You currently have " + currEquippedItem->getName() + " equipped. Do you want to swap it out for the " + item->getName() + "?");
            string response;
            cin >> response;
            if(CommandAnalyser::regexSearch(response, boost::regex("[yY](es)?")))
            {
                equippedItems[item->getEquipSlot()] = item;
                Console::write("You have equipped the " + item->getName() + ".");
            }
            else
                Console::write("You do nothing.");
        }
    }
}

bool Player::analyseAttackCommand()
{
    Console::write("The monsters available to attack are: ");
    for(unsigned i = 0; i < currentRoom->getMonsters().size(); i++)
    {
        std::stringstream output;
        output << i << ": " << currentRoom->getMonsters()[i].getName() << ",\n";
        Console::write(output.str());
    }
    Console::write("Which monster do you want to attack?");
    unsigned monsterNumber;
    cin >> monsterNumber;
    if(monsterNumber < currentRoom->getMonsters().size() || monsterNumber >= 0)
    {
        Monster m = currentRoom->getMonsters()[monsterNumber];
        applyModifiers();
        while(m.isAlive())
        {
            cout << "monster isalive: " << m.isAlive() << endl;
            Console::write("You have damaged the " + m.getName() + " for " + util::string::from(stats.damage) + " damage!\n");
            m.damageSelf(stats.damage);
        }
    }
    else
    {
        Console::write("Please enter a valid room number.");
        analyseMoveCommand();
    }

}

Room* Player::getCurrentRoom()
{
    return currentRoom;
}
/*
static bool regexSearch(std::string command, boost::regex regexString)
{
    boost::smatch results; return boost::regex_search(command, results, regexString);
}*/

void Player::setName(std::string const& m_name)
{
    name = m_name;
}

void Player::damageSelf(int damage)
{
    stats.health = damage;
}

PlayerStats Player::getStats()
{
    return stats;
}

bool Player::analyseMoveCommand()
{
    Console::write("The rooms connecting to this room are: ");
    string rooms;
    for(unsigned i = 0; i < currentRoom->getConnectingRooms().size(); i++)
    {
        rooms += currentRoom->getConnectingRooms()[i] + " ";
        std::stringstream output;
        output << i << ": " << currentRoom->getConnectingRooms()[i] << ",\n";
        Console::write(output.str());
    }
    string newRoomName;
    cin >> newRoomName;
    if(CommandAnalyser::regexSearch(newRoomName, boost::regex("[qQ](uit)?")))
        return false;
    unsigned newRoomNumber;
    std::stringstream stream(newRoomName); stream >> newRoomNumber;
    if(stream.bad())
         throw std::runtime_error("Failed to convert in Player.cpp:analyseMoveCommand");
    if(newRoomNumber < currentRoom->getConnectingRooms().size() || newRoomNumber >= 0)
    {
        currentRoom = Game::getRoom(currentRoom->getConnectingRooms()[newRoomNumber]);
        Console::write("You have entered the " + currentRoom->getName() +  ".");
    }
    else
    {
        Console::write("Please enter a valid room number.");
        analyseMoveCommand();
    }
}

Player::~Player()
{
    //dtor
}
