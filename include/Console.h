#ifndef CONSOLE_H
#define CONSOLE_H
#include <string>

class Console
{
    public:
        Console();
        static void write(std::string stringToWrite);
        virtual ~Console();
    protected:
    private:
        static unsigned int charsWritten;
};

#endif // CONSOLE_H
