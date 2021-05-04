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

    void Show_Status(ostream&)const;

    bool operator<(const Item &) const;
};

#endif // ITEM_H_INCLUDED
