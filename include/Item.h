#ifndef SOMECLASS_H
#define SOMECLASS_H
#include <string>

class Item
{
    public:
        Item();
        virtual ~Item();
    protected:
    private:
        std::string name;
};

#endif // SOMECLASS_H
