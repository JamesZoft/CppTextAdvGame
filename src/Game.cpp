#include "Game.h"
#include <iostream>
#include <string>
#include "Console.h"
#include "CommandAnalyser.h"
#include "Room.h"
#include <fstream>
#include "cJSON.h"
#include "ItemFactory.h"
#include "Player.h"
#include "Monster.h"

using namespace std;

Game::Game()
{

}

 std::vector<Room> Game::rooms;

void Game::play()
{
    string name;
    cout << "Please enter your name!" << endl;
    cin >> name;
    Console::write("Welcome to Erazhar, the magical castle of the dreaded Lord Torhazar! You must find your way through the maze of rooms to the room where Torhazar resides,");
    Console::write("and kill him. He has many monsters guarding his maze, but there are also magical treasures, lost in the ages awaiting your discovery!\n");
    Console::write(std::string("Good luck, ") + name + std::string("!"));
   // cout << "a1" << endl;
    generateRooms();

    player = new Player(&Game::getRooms()[0]);
    string command;
    cin >> command;
    while(!CommandAnalyser::analyse(command, player))
    {
        cin >> command;
    }
}

std::vector<Room>& Game::getRooms()
{
    return rooms;
}

 std::string getcwd_PRIME() {
       char buff[PATH_MAX];
       getcwd( buff, PATH_MAX );
       std::string cwd( buff );
       return cwd;
}

Room* Game::getRoom(std::string roomName)
{
    for(Room &room : Game::getRooms())
    {
        if(room.getName() == roomName)
            return &room;
    }
}

void Game::generateRooms()
{
    ifstream myfile("res/rooms/rooms.json");
    if(!myfile)
        cout << "not found" << endl;
    std::string str((std::istreambuf_iterator<char>(myfile)),
                 std::istreambuf_iterator<char>());
    cJSON *root = cJSON_Parse(str.c_str());
    if(!root)
        cout << "Json is probably invalid" << endl;
    cJSON *startRoom = cJSON_GetObjectItem(root,"Cellar");
    cJSON *connectingRooms = cJSON_GetObjectItem(startRoom, "connectingRooms");
    cJSON *room = root->child;

    while(room)
    {
        Room newRoom;
        newRoom.setName(room->string);
        cJSON *property = room->child;
        while(property)
        {
            if(property->string == string("connectingRooms"))
            {
                for(int i = 0; cJSON *conRoom = cJSON_GetArrayItem(property, i); i++)
                {
                    newRoom.addConnectingRoom(conRoom->valuestring);
                }
            }
            else if(property->string == string("items"))
            {
                for(int i = 0; cJSON *item = cJSON_GetArrayItem(property, i); i++)
                {
                    newRoom.addItem(ItemFactory::createItem(item));
                }
            }
            else if(property->string == string("monsters"))
            {
                for(int i = 0; cJSON *monster = cJSON_GetArrayItem(property, i); i++)
                {
                    Monster newMonster;
                    cJSON *monsterProperty = monster->child;
                    while(monsterProperty)
                    {
                        if(monsterProperty->string == string("name"))
                            newMonster.setName(monsterProperty->valuestring);
                        else if(monsterProperty->string == string("hp"))
                            newMonster.setHp(monsterProperty->valueint);
                        else if(monsterProperty->string == string("attack"))
                            newMonster.setAttack(monsterProperty->valueint);

                        monsterProperty = monsterProperty->next;
                    }
                    newRoom.addMonster(newMonster);
                }
            }
            property = property->next;
        }
        Game::rooms.push_back(newRoom);
       //cout << "Printing the new room!" << endl;
       // cout << "first connecting room: " << newRoom.getConnectingRooms()[0] << endl;
        //cout << "first item: " << newRoom.getItems()[0].getName() << endl;
        room = room->next;
    }
}

Game::~Game()
{
    delete player;
}
