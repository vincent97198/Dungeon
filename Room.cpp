#include "Room.h"
#include "Others/check_type.h"

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

void Room::setBoolean(Object *newObject, bool op) {
    if (check_type::isItemType(newObject) != nullptr) {
        if (op)
            ++item_on_floor;
        else
            --item_on_floor;
    } else if (check_type::isMonsterType(newObject) != nullptr) {
        if (op)
            ++monster;
        else
            --monster;
    } else if (check_type::isNPCType(newObject)!=nullptr){
        if(op)
            ++npc;
        else
            --npc;
    }
}

set<Object*> Room::getObjects() {
    return Room::objects;
}

bool Room::popObject(Object *REMOVE) {
    auto iter = Room::objects.find(REMOVE);
    if (iter == objects.end()) return false;
    else {
        Room::objects.erase(iter);
        setBoolean(REMOVE, false);
        return true;
    }
}

void Room::addObject(Object *ADD) {
    Room::objects.insert(ADD);
    setBoolean(ADD, true);
}


Room::Room() {
    Room::objects.clear();
    Room::rightRoom = nullptr;
    Room::leftRoom = nullptr;
    Room::upRoom = nullptr;
    Room::downRoom = nullptr;
    Room::index = 0;
    Room::Exit = false;
    Room::monster = false;
    Room::npc = false;
    Room::item_on_floor = false;
}

bool Room::isExit() const {
    return Exit;
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


