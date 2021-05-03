#include "Player.h"


Equipment *Player::getEquip(string equip) const {
    if (equip == "Weapon")
        return dynamic_cast<Equipment *>(Player::weapon);
    else if (equip == "Armor")
        return dynamic_cast<Equipment *>(Player::armor);
    else exit(1);
}


void Player::Equip(Equipment *Equip) {
    try {
        string Warning;
        Weapon *Debug_test = dynamic_cast<Weapon *>(Equip);
        Armor *Debug_test2 = dynamic_cast<Armor *>(Equip);
        if (Debug_test == nullptr && Debug_test2 == nullptr)
            throw (Warning = "BUG!!! Ambiguous Data Type. Weapon or Armor");
    }
    catch (string Warning) {
        cout << Color::RED << Warning << Color::Default << '\n';
    }

    Weapon *new_weapon = dynamic_cast<Weapon *>(Equip);
    Armor *new_armor = dynamic_cast<Armor *>(Equip);

    if (new_weapon != nullptr) {
        if (weapon == nullptr) {
            Player::setAttack(Player::getAttack() + new_weapon->getAttack());
            weapon = new_weapon;
        } else if (changeEquip(weapon->getName()))
            Player::setAttack(Player::getAttack() + new_weapon->getAttack() - Player::weapon->getAttack());
        weapon = new_weapon;
    }

    if (new_armor != nullptr) {
        if (armor == nullptr) {
            Player::setDefense(Player::getDefense() + new_armor->getDefense());
            armor = new_armor;
        } else if (changeEquip(armor->getName()))
            Player::setDefense(Player::getDefense() + new_armor->getDefense() - Player::armor->getDefense());
        armor = new_armor;
    }
}

bool Player::changeEquip(string str) {
    cout << Color::Yellow
         << "You have already equipped " << str << '\n'
         << Color::Default;
    map<char, string> true_false_Map;
    true_false_Map['Y'] = "YES";
    true_false_Map['N'] = "NO";
    char type = Ask::Ask_oneAlphabet("Do you want to change your equipment?[Y/n]", true_false_Map);
    if (type == 'Y')
        return true;
    else return false;
}
