#ifndef SOMECLASS_H
#define SOMECLASS_H
#include <string>

class Item
{
    public:
        Item(std::string _name);
        inline std::string getName() const {return name;}
        virtual ~Item();
    protected:
    private:
        std::string name;
};

#endif // SOMECLASS_H
