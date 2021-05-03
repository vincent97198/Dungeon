#include "Room.h"

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
