//
// Created by vincent97198 on 2021/5/1.
//

#include "Weapon.h"

Weapon::Weapon() :
        Equipment("UNKNOWN_weapon", INT16_MAX),
        attack(INT16_MAX) {}

Weapon::Weapon(string name, int Durability, int attack) :
        Equipment(name, Durability),
        attack(attack) {}

int Weapon::getAttack() const {
    return attack;
}

void Weapon::saveFile(ofstream &os) {
    Equipment base = *this;
    base.saveFile(os);
    os << attack << '\n';
}

void Weapon::loadFile(ifstream &os) {
    Equipment *base = new Equipment();
    base->loadFile(os);
    this->setName(base->getName());
    this->setTag(base->getTag());
    this->setDurability(base->getDurability());

    os >> attack;
}

void Weapon::Show_Status(ostream &os) const {
    os << Color::Blue << "=======Weapon=======" << Color::Default << '\n'
       << "Weapon Name: " << Weapon::getName() << '\n'
       << "Weapon Durability: " << Weapon::getDurability() << '\n'
       << "Weapon Defense: " << Weapon::getAttack() << '\n'
       << Color::Blue << "====================" << Color::Default << '\n';
}