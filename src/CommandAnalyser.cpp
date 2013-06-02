#include "CommandAnalyser.h"
#include "Player.h"
#include <string>
#include <regex>
#include <iostream>
#include <boost/regex.hpp>
#include "Item.h"
#include "Console.h"
#include "Monster.h"
#include "Room.h"
#include <vector>

using namespace std;

CommandAnalyser::CommandAnalyser()
{
    //ctor
}

void CommandAnalyser::help()
{
    Console::write("The commands available are: q(uit), h(help), m(ove), a(ttack) and l(ook).");
}

bool CommandAnalyser::regexSearch(std::string command, boost::regex regexString)
{
    boost::smatch results; return boost::regex_search(command, results, regexString);
}

bool CommandAnalyser::analyse(std::string command, Player *player)
{
    boost::smatch results;
    if(regexSearch(command, boost::regex("[qQ](uit)?")))
        return false;
    else if(regexSearch(command, boost::regex("[hH](elp)?")))
        help();
    else if(regexSearch(command, boost::regex("[mM](ove)?")))
    {
        Console::write("Move where?");
        return player->analyseMoveCommand();
    }
    else if(regexSearch(command, boost::regex("[lL](ook)?")))
    {

        Console::write("You are in the " + player->getCurrentRoom()->getName()
                        + ". As you look around the room, you see" + getItemsAsString(player)
        + " and there" +  getMonstersAsString(player) + "\n");

    }
    else if(regexSearch(command, boost::regex("[aA](ttack)?")))
    {
        vector<Monster> monsters = player->getCurrentRoom()->getMonsters();
        if(monsters.size() == 0)
            Console::write("There are no monsters to attack!");
        else
        {
            Console::write("Attack what?");
            return player->analyseAttackCommand();
        }
    }
    else if(regexSearch(command, boost::regex("[pP](ickup)?")))
    {
        vector<Item*> items = player->getCurrentRoom()->getItems();
        if(items.size() == 0)
            Console::write("There are no items to pickup.");
        else
        {
            Console::write("Pickup what?");
            player->pickupItem();
        }
    }
    else
        Console::write("That is not a valid command, type \"help\" if you don\'t know what to do.");
}

string CommandAnalyser::getMonstersAsString(Player *player)
{
     string monstersAsString;
     vector<Monster> monsters = player->getCurrentRoom()->getMonsters();
        if(monsters.size() == 0)
            monstersAsString = " are no monsters in this room.";
        else
            monstersAsString = " is a";
        for(unsigned i = 0; i < monsters.size(); i++)
        {
            monstersAsString += " " + monsters[i].getName();
            if(monsters.size() != 1)
            {
                if(i == monsters.size() - 2) //Penultimate item
                {
                    monstersAsString += " and a";
                }
                else if(i == monsters.size() - 1) //ultimate item
                {
                    monstersAsString += ".";
                }
                else
                {
                    monstersAsString += ",";
                }
            }
            else
               monstersAsString += ".";
        }
        return monstersAsString;
}

string CommandAnalyser::getItemsAsString(Player *player)
{
     string itemsAsString;
        if(player->getCurrentRoom()->getItems().size() == 0)
            itemsAsString = " no items of importance in this room.";
        else
            itemsAsString = " a";
        for(unsigned i = 0; i < player->getCurrentRoom()->getItems().size(); i++)
        {
            itemsAsString += " " + player->getCurrentRoom()->getItems()[i]->getName();
            if(player->getCurrentRoom()->getItems().size() != 1)
            {
                if(i == player->getCurrentRoom()->getItems().size() - 2) //Penultimate item
                {
                    itemsAsString += " and a";
                }
                else if(i == player->getCurrentRoom()->getItems().size() - 1) //ultimate item
                {
                    itemsAsString += "";
                }
                else
                {
                    itemsAsString += ",";
                }
            }
            else
               itemsAsString += ".";
        }
        return itemsAsString;
}

CommandAnalyser::~CommandAnalyser()
{
    //dtor
}
