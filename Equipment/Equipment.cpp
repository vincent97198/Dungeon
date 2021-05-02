#include "Equipment.h"

Equipment::Equipment() : Item("UNKNOWN_Equipment", "Equipment") {
    const int INF = INT16_MAX;
    Equipment::Durability = INF;
}

Equipment::Equipment(string name, string tag) : Item(name, tag) {
    const int INF = INT16_MAX;
    Equipment::Durability = INF;
}

Equipment::Equipment(string name, int Durability) : Item(name, "Equipment") {
    Equipment::Durability = Durability;
}

void Equipment::setDurability(int durability) {
    Durability = durability;
}

int Equipment::getDurability() const {
    return Durability;
}

void Equipment::saveFile(ofstream &os) {
    Item base = *this;
    base.saveFile(os);

    os << Durability << '\n';
}

void Equipment::loadFile(ifstream &os) {
    Item *base = new Item();
    base->loadFile(os);
    this->setName(base->getName());
    this->setTag(base->getTag());

    os >> Durability;
}