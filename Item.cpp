#include "Item.h"

Item::Item() : Object("UNKNOWN", "Item") {}

Item::Item(string name, string tag) : Object(name, tag) {}

bool Item::operator<(const Item &item) const {
    return this->getName() < item.getName();
}

ostream &operator<<(ostream &os, const Item *item) {
    if (item == nullptr)
        os << "Empty";
    else
        os << item->getName();
    return os;
}