#include "Room/Room.h"

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
        else if (check_type::isArmorType(iter) != nullptr)
            os << "Armor\n";
        else if (check_type::isItemType(iter) != nullptr)
            os << "Item\n";
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
