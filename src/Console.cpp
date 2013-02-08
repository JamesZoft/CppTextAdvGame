#include "Console.h"
#include <string>
#include <iostream>
#include <stringutils.hpp>

using namespace std;

unsigned int Console::charsWritten = 0;

Console::Console()
{
    //ctor
}

void Console::write(string stringToWrite)
{
    auto words = util::string::split(stringToWrite);
    for(string &s : words)
    {
        if((charsWritten + s.length()) >= 68)
        {
            cout << endl;
            charsWritten = 0;
        }
        cout << s + " ";
        charsWritten += s.length();
    }
}

Console::~Console()
{
    //dtor
}
