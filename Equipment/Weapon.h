#ifndef NEW_WEAPON_H
#define NEW_WEAPON_H

#include "Equipment/Equipment.h"

class Weapon : public Equipment {
private:
    int attack;
public:
    Weapon();

    Weapon(string name,int Durability,int attack);

    int getAttack() const;

    void saveFile(ofstream&);
};


#endif //NEW_WEAPON_H
