#include "../include/Player.h"
#include <string>
#include <boost/regex.hpp>
#include "Game.h"


using namespace std;

Player::Player(Room *startingRoom)
{
    currentRoom = startingRoom;
}

bool Player::analyseMoveCommand()
{
    cout << "The rooms connecting to this room are: " << endl;
    string rooms;
    cout << "test0" << endl;
    for(int i = 0; i < (currentRoom->getConnectingRooms().size() - 1); i++)
    {
        cout << "test1" << endl;
        rooms += currentRoom->getConnectingRooms()[i] + " ";
        cout << "test2" << endl;
        cout << i << ": " << currentRoom->getConnectingRooms()[i] << ", ";
        cout << "test3" << endl;
        cout << endl;
    }
    string newRoomName;
    cin >> newRoomName;
    currentRoom = Game::getRoom(newRoomName);
    if(regexSearch(newRoomName, boost::regex("[qQ](uit)?")))
        return false;
    else
    {
        cout << "Please enter a valid room number." << endl;
        analyseMoveCommand();
    }
}

Player::~Player()
{
    //dtor
}
