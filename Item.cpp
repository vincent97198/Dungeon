#include "Item.h"

Item::Item() : Object("UNKNOWN", "Item") {}

Item::Item(string name, string tag) : Object(name, tag) {}

bool Item::operator<(const Item &item) const {
    return this->getName() < item.getName();
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

void Item::Show_Status(ostream &os) const {
    os << Color::Blue << "=======Item=======" << Color::Default << '\n'
       << "Name: " << Color::Yellow << Item::getName() << '\n' << Color::Default
       << Color::Blue << "==================" << Color::Default << '\n'
       << endl;
}