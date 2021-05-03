# include "Room/Room.h"

int Room::getUp() const {
    return up;
}

int Room::getDown() const {
    return down;
}

int Room::getLeft() const {
    return left;
}

int Room::getRight() const {
    return right;
}

void Room::setExit(int Exit) {
    Room::Exit = Exit;
}

bool Room::isNPC() const {
    return npc > 0;
}

bool Room::isMonster() const {
    return monster > 0;
}


bool Room::isItemOnFloor() const {
    return item_on_floor > 0;
}

int Room::getNpc() const {
    return npc;
}

int Room::getMonster() const {
    return monster;
}

int Room::getItemOnFloor() const {
    return item_on_floor;
}

set<Object *> Room::getObjects() {
    return Room::objects;
}

Room *Room::getUpRoom() const {
    return upRoom;
}

void Room::setUpRoom(Room *upRoom) {
    Room::upRoom = upRoom;
}

Room *Room::getDownRoom() const {
    return downRoom;
}

void Room::setDownRoom(Room *downRoom) {
    Room::downRoom = downRoom;
}

Room *Room::getLeftRoom() const {
    return leftRoom;
}

void Room::setLeftRoom(Room *leftRoom) {
    Room::leftRoom = leftRoom;
}

Room *Room::getRightRoom() const {
    return rightRoom;
}

void Room::setRightRoom(Room *rightRoom) {
    Room::rightRoom = rightRoom;
}

int Room::getIndex() const {
    return index;
}

void Room::setIndex(int index) {
    Room::index = index;
}

bool Room::isExit() const {
    return Exit;
}
