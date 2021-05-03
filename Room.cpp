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
    } else if (check_type::isNPCType(newObject) != nullptr) {
        if (op)
            ++npc;
        else
            --npc;
    }
}

set<Object *> Room::getObjects() {
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

int Room::getNpc() const {
    return npc;
}

int Room::getMonster() const {
    return monster;
}

int Room::getItemOnFloor() const {
    return item_on_floor;
}

void Room::saveFile(ofstream &os) {
    os << index << '\n'
       << (upRoom == nullptr ? -1 : upRoom->getIndex()) << '\n'
       << (downRoom == nullptr ? -1 : downRoom->getIndex()) << '\n'
       << (leftRoom == nullptr ? -1 : leftRoom->getIndex()) << '\n'
       << (rightRoom == nullptr ? -1 : rightRoom->getIndex()) << '\n'
       << Exit << '\n'
       << npc << '\n'
       << monster << '\n'
       << item_on_floor << '\n'
       << objects.size() << '\n';

    for (auto iter:objects) {
        if (check_type::isNPCType(iter) != nullptr)
            os << "NPC\n";
        else if (check_type::isMonsterType(iter) != nullptr)
            os << "Monster\n";
        else if (check_type::isWeaponType(iter) != nullptr)
            os << "Weapon\n";
        else if (check_type::isItemType(iter) != nullptr)
            os << "Item\n";
        else if (check_type::isArmorType(iter) != nullptr)
            os << "Armor\n";
        iter->saveFile(os);
    }
}

void Room::loadFile(ifstream &os) {
    int SZ;
    os >> index
       >> up
       >> down
       >> left
       >> right
       >> Exit
       >> npc
       >> monster
       >> item_on_floor
       >> SZ;
    for (int i = 0; i < SZ; ++i) {
        string type;
        os >> type;
        Object *object;
        if (type == "Item")
            object = new Item();
        else if (type == "Monster")
            object = new Monster();
        else if (type == "NPC")
            object = new NPC();
        else if (type == "Weapon")
            object = new Weapon();
        else if (type == "Armor")
            object = new Armor();
        object->loadFile(os);
        objects.insert(object);
    }
}

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
