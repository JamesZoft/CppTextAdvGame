#ifndef ITEMMODIFIER_H
#define ITEMMODIFIER_H

class PlayerStats;

class ItemModifier
{
    public:
        ItemModifier();
        virtual ~ItemModifier();
        virtual void modify(PlayerStats &stats) = 0;
        virtual bool isEquippable() = 0;
    protected:
    private:

};

#endif // ITEMMODIFIER_H
