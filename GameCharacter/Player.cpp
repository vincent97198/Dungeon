#include "Player.h"

Room *Player::getCurrentRoom() const {
    return currentRoom;
}

void Player::setCurrentRoom(Room *currentRoom) {
    Player::currentRoom = currentRoom;
}

Room *Player::getPreviousRoom() const {
    return previousRoom;
}

void Player::setPreviousRoom(Room *previousRoom) {
    Player::previousRoom = previousRoom;
}

const vector<Item *> &Player::getInventory() const {
    return inventory;
}

void Player::setInventory(const vector<Item *> &inventory) {
    Player::inventory = inventory;
}

Player::Player() : GameCharacter() {
    Player::currentRoom = nullptr;
    Player::previousRoom = nullptr;
    Player::weapon = nullptr;
    Player::inventory.clear();
}

Player::Player(string name, int maxHealth, int attack, int defense, Room *currentRoom) : GameCharacter(name, "Player",
                                                                                                       maxHealth,
                                                                                                       attack,
                                                                                                       defense) {
    Player::currentRoom = currentRoom;
    Player::previousRoom = nullptr;
    Player::inventory.clear();
    Player::weapon = nullptr;
}

void Player::addItem(Item *item) {
    if (check_type::isEquipmentType(item) != nullptr)
        Player::Equip(check_type::isEquipmentType(item));
    else
        inventory.emplace_back(item);
}

void Player::increaseStates(int maxHealth, int attack, int defense) {
    GameCharacter::setMaxHealth(GameCharacter::getMaxHealth() + maxHealth);
    GameCharacter::setAttack(GameCharacter::getAttack() + attack);
    GameCharacter::setDefense(GameCharacter::getDefense() + defense);
}

void Player::changeRoom(Room *nextRoom) {
    Player::previousRoom = Player::currentRoom;
    Player::currentRoom = nextRoom;
}

Player::~Player() {
    inventory.clear();
    currentRoom = nullptr;
    previousRoom = nullptr;
    weapon = nullptr;
}

void Player::Equip(Equipment *Equip) {
    try {
        string Warning;
        Weapon *Debug_test = dynamic_cast<Weapon *>(Equip);
        if (Debug_test == nullptr) throw (Warning = "BUG!!! Ambiguous Data Type. Weapon or Armor");
    }
    catch (string Warning) {
        cout << Color::RED << Warning << Color::Default << '\n';
    }
    Player::weapon = dynamic_cast<Weapon *>(Equip);
    Player::setAttack(Player::getAttack() + Player::weapon->getAttack());
}

Item *Player::getEquip() const {
    return dynamic_cast<Item *>(Player::weapon);
}

void Player::saveFile(ofstream &os) {
    GameCharacter base = *this;
    base.saveFile(os);

    os << currentRoom->getIndex() << '\n'
       << (previousRoom == nullptr ? -1 : previousRoom->getIndex()) << '\n';
    if (weapon != nullptr) {
        os << "Weapon\n";
        weapon->saveFile(os);
    } else os << "noWeapon\n";

    os << inventory.size() << '\n';
    for (auto iter:inventory) {
        if (check_type::isWeaponType(iter) != nullptr)
            os << "Weapon\n";
        else if (check_type::isItemType(iter) != nullptr)
            os << "Item\n";
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

    string type;
    os >> type;
    if (type == "Weapon") {
        weapon = new Weapon();
        weapon->loadFile(os);
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
        item->loadFile(os);
        inventory.emplace_back(item);
    }
}

int Player::getCur() const {
    return cur;
}

int Player::getPre() const {
    return pre;
}
