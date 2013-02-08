#include "../include/Game.h"
#include <iostream>
#include <string>
#include "Console.h"

using namespace std;

Game::Game()
{
    //ctor
}

void Game::play()
{
    string name;
    cout << "Please enter your name!" << endl;
    cin >> name;
    player.setName(name);
    Console::write("Welcome to Erazhar, the magical castle of the dreaded Lord Torhazar! You must find your way through the maze of rooms to the room where Torhazar resides,");
    Console::write("and kill him. He has many monsters guarding his maze, but there are also magical treasures, lost in the ages awaiting your discovery!\n");
    Console::write(std::string("Good luck, ") + player.getName() + std::string("!"));

}

Game::~Game()
{
    //dtor
}
