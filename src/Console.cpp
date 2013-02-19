#include "Console.h"
#include <string>
#include <iostream>
#include <stringutils.hpp>
#include <termios.h>
#include <sys/ioctl.h>

using namespace std;

unsigned int Console::charsWritten = 0;

Console::Console()
{
    //ctor
}

void Console::write(string stringToWrite)
{
    winsize wsz;
    ioctl(0, TIOCGWINSZ, &wsz);
    unsigned short cols = wsz.ws_col;
    auto words = util::string::split(stringToWrite);
    for(string &s : words)
    {
        if((charsWritten + s.length()) >= cols) //68 is char length of console for codeblocks
        {
            cout << endl;
            charsWritten = 0;
        }
        cout << s + " ";
        charsWritten += s.length() + 1;
    }
}

Console::~Console()
{
    //dtor
}
