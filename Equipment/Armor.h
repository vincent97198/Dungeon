//
// Created by vincent97198 on 2021/5/3.
//

#ifndef NEW_ARMOR_H
#define NEW_ARMOR_H

#include "Equipment/Equipment.h"

class Armor : public Equipment {
private:
    int defense;
public:
    Armor();

    Armor(string name, int Durability, int attack);

    int getDefense() const;

    void saveFile(ofstream &);

    void loadFile(ifstream &);
};


#endif //NEW_ARMOR_H
