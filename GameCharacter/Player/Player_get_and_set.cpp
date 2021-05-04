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

int Player::getCur() const {
    return cur;
}

int Player::getPre() const {
    return pre;
}


int Player::getcurMp() const {
    return curMP;
}

void Player::setcurMp(int mp) {
    curMP = mp;
}

int Player::getMaxMp() const {
    return maxMP;
}

void Player::setMaxMp(int maxMp) {
    maxMP = maxMp;
}

void Player::setWeapon(Weapon *weapon) {
    Player::weapon = weapon;
}

void Player::setArmor(Armor *armor) {
    Player::armor = armor;
}
