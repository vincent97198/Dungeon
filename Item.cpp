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

void Item::saveFile(ofstream &os) {
    Object base = *this;
    base.saveFile(os);
}

void Item::loadFile(ifstream &os) {
    Object *base = new Object();
    base->loadFile(os);
    this->setName(base->getName());
    this->setTag(base->getTag());
}