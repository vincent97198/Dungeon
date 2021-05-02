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

void Weapon::saveFile(ofstream &os){
    Equipment* base=dynamic_cast<Equipment*>(this);
    base->saveFile(os);
    os << "Weapon Attack: \n" << attack << '\n';
}