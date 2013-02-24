#include "CommandAnalyser.h"
#include "Player.h"
#include <string>
#include <regex>
#include <iostream>
#include <boost/regex.hpp>

using namespace std;

CommandAnalyser::CommandAnalyser()
{
    //ctor
}

void CommandAnalyser::help()
{

}

bool CommandAnalyser::analyse(std::string command, Player *player)
{
    boost::smatch results;
    if(regexSearch(command, boost::regex("[qQ](uit)?")))
        return false;
    else if(regexSearch(command, boost::regex("[hH]elp")))
        help();
    else if(regexSearch(command, boost::regex("[mM]ove")))
    {
        cout << "Move where?" << endl;
        return player->analyseMoveCommand();
    }
    else
        cout << "That is not a valid command, type \"help\" if you don\'t know what to do." << endl;



}
/*
bool CommandAnalyser::analyseMoveCommand(Player player)
{
    string moveCmd;
    cin >> moveCmd;
    if(regexSearch(moveCmd, boost::regex("(north|east|south|west)")))
    {
        cout << "asdasd" << endl;
        return player.dealWithMove(moveCmd);
    }
    if(regexSearch(moveCmd, boost::regex("[qQ](uit)?")))
        return false;
    else
    {
        cout << "Please enter a valid direction. Valid directions are North, East, South or West." << endl;
        analyseMoveCommand(player);
    }


}*/

CommandAnalyser::~CommandAnalyser()
{
    //dtor
}
