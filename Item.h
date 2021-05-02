#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "Object.h"
#include "Others/consoleColor.h"

using namespace std;

class Item : public Object {
private:
public:

    Item();

    Item(string, string);

    ~Item() = default;

    void saveFile(ofstream &);

    void loadFile(ifstream &);

    bool operator<(const Item &) const;

    friend ostream &operator<<(ostream &os, const Item *item);
};

#endif // ITEM_H_INCLUDED
