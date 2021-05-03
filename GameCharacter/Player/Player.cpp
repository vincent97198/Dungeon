#include "Player.h"

Player::Player() : GameCharacter() {
    Player::currentRoom = nullptr;
    Player::previousRoom = nullptr;
    Player::weapon = nullptr;
    Player::armor = nullptr;
    Player::inventory.clear();
    Player::maxMP = 10;
    Player::curMP = 10;
}


Player::Player(string name, int maxMP, int maxHealth, int attack, int defense, Room *currentRoom) : GameCharacter(name,
                                                                                                                  "Player",
                                                                                                                  maxHealth,
                                                                                                                  attack,
                                                                                                                  defense) {
    Player::currentRoom = currentRoom;
    Player::previousRoom = nullptr;
    Player::inventory.clear();
    Player::weapon = nullptr;
    Player::armor = nullptr;
    Player::maxMP = maxMP;
    Player::curMP = maxMP;
}

void Player::addItem(Item *item) {
    if (check_type::isEquipmentType(item) != nullptr)
        Player::Equip(check_type::isEquipmentType(item));
    else
        inventory.emplace_back(item);
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
    armor = nullptr;
}
