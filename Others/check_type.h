#ifndef NEW_CHECK_TYPE_H
#define NEW_CHECK_TYPE_H

#include "Object.h"
#include "Item.h"
#include "GameCharacter/Monster.h"
#include "GameCharacter/NPC.h"
#include "Equipment/Equipment.h"
#include "Equipment/Weapon.h"

class Item;

class Object;

class Monster;

class NPC;

namespace check_type {
    Item *isItemType(Object *);

    Monster *isMonsterType(Object *);

    NPC *isNPCType(Object *);

    Equipment *isEquipmentType(Item *);

    Weapon *isWeaponType(Object *);
}

#endif //NEW_CHECK_TYPE_H
