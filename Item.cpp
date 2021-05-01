#include "Item.h"

Item::Item() : Object("UNKNOWN", "Item") {}

Item::Item(string name, string tag) : Object(name, tag) {}

ostream &operator<<(ostream &os, const Item *item) {
    if(item==nullptr)
        os << "Empty";
    else
        os << item->getName();
    return os;
}