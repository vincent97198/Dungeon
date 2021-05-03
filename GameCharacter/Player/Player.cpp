#include "Player.h"

Player::Player() : GameCharacter() {
    Player::currentRoom = nullptr;
    Player::previousRoom = nullptr;
    Player::weapon = nullptr;
    Player::armor = nullptr;
    Player::inventory.clear();
    Player::maxMP = 10;
    Player::curMP = 10;
    Player::setSpeed(10);
    Player::setMaxHealth(100);
    Player::setAttack(10);
    Player::setDefense(1);
}


Player::Player(string name,int speed ,int maxMP, int maxHealth, int attack, int defense, Room *currentRoom) : GameCharacter(name,
                                                                                                                  "Player",
                                                                                                                  maxHealth,
                                                                                                                  attack,
                                                                                                                  defense,
                                                                                                                  speed) {
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
