#include "check_type.h"

namespace check_type {
    Item *isItemType(Object *object) {
        Item *item = dynamic_cast<Item *>(object);
        return item;
    }

    NPC *isNPCType(Object *object) {
        NPC *npc = dynamic_cast<NPC *>(object);
        return npc;
    }

    Monster *isMonsterType(Object *object) {
        Monster *monster = dynamic_cast<Monster *>(object);
        return monster;
    }

    Equipment *isEquipmentType(Item *item) {
        Equipment *equip = dynamic_cast<Equipment *>(item);
        return equip;
    }

    Weapon *isWeaponType(Object *object) {
        Weapon *weapon = dynamic_cast<Weapon *>(object);
        return weapon;
    }

    Armor *isArmorType(Object *object) {
        Armor *armor = dynamic_cast<Armor *>(object);
        return armor;
    }
}