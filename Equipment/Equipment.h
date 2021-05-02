#ifndef NEW_EQUIPMENT_H
#define NEW_EQUIPMENT_H

#include <iostream>
#include <string>
#include "Item.h"

using namespace std;

class Equipment : public Item {
private:
    int Durability;
public:

    int getDurability() const;

    void setDurability(int);

    Equipment();

    Equipment(string, string);

    Equipment(string, int);

    ~Equipment() = default;
};

#endif //NEW_EQUIPMENT_H
