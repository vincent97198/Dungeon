#include "Player.h"

void Player::saveFile(ofstream &os) {
    GameCharacter base = *this;
    base.saveFile(os);

    os << currentRoom->getIndex() << '\n'
       << (previousRoom == nullptr ? -1 : previousRoom->getIndex()) << '\n';

    os << curMP << maxMP;

    if (weapon != nullptr) {
        os << "Weapon\n";
        weapon->saveFile(os);
    } else os << "noWeapon\n";

    if (armor != nullptr) {
        os << "Armor\n";
        armor->saveFile(os);
    } else os << "noArmor\n";

    os << inventory.size() << '\n';
    for (auto iter:inventory) {
        if (check_type::isWeaponType(iter) != nullptr)
            os << "Weapon\n";
        else if (check_type::isItemType(iter) != nullptr)
            os << "Item\n";
        else if (check_type::isArmorType(iter) != nullptr)
            os << "Armor\n";
        iter->saveFile(os);
    }
}

void Player::loadFile(ifstream &os) {
    GameCharacter *base = new GameCharacter();
    base->loadFile(os);
    this->setMaxHealth(base->getMaxHealth());
    this->setCurrentHealth(base->getCurrentHealth());
    this->setAttack(base->getAttack());
    this->setDefense(base->getDefense());
    this->setName(base->getName());
    this->setTag(base->getTag());

    os >> cur >> pre;

    os >> curMP >> maxMP;

    string type;
    os >> type;
    if (type == "Weapon") {
        weapon = new Weapon();
        weapon->loadFile(os);
    }
    os >> type;
    if (type == "Armor") {
        armor = new Armor();
        armor->loadFile(os);
    }

    int SZ;
    os >> SZ;
    for (int i = 0; i < SZ; ++i) {
        os >> type;
        Item *item;
        if (type == "Weapon")
            item = new Weapon();
        else if (type == "Item")
            item = new Item();
        else if (type == "Armor")
            item = new Armor();
        item->loadFile(os);
        inventory.emplace_back(item);
    }
}