#include "Armor.h"

Armor::Armor() :
        Equipment("UNKNOWN_armor", INT16_MAX),
        defense(INT16_MAX) {}

Armor::Armor(string name, int Durability, int defense) :
        Equipment(name, Durability),
        defense(defense) {}

int Armor::getDefense() const {
    return defense;
}

void Armor::saveFile(ofstream &os) {
    Equipment base = *this;
    base.saveFile(os);
    os << defense << '\n';
}

void Armor::loadFile(ifstream &os) {
    Equipment *base = new Equipment();
    base->loadFile(os);
    this->setName(base->getName());
    this->setTag(base->getTag());
    this->setDurability(base->getDurability());

    os >> defense
}