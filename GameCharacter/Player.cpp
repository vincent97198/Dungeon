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
    GameCharacter *base = static_cast<GameCharacter *>(this);
    base->saveFile(os);

    os << "Current Room: \n" << currentRoom->getIndex() << '\n'
       << "Previous Room: \n" << (previousRoom == nullptr ? -1 : previousRoom->getIndex()) << '\n'
       << "Weapon: \n";
    if(weapon!=nullptr)
        weapon->saveFile(os);

    os << "Inventory: \n" << inventory.size() << '\n';
    for (auto iter:inventory)
        iter->saveFile(os);
}
