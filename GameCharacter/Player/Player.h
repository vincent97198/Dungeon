#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "GameCharacter/GameCharacter.h"
#include "Room/Room.h"
#include "Item.h"
#include "Others/consoleColor.h"
#include "Equipment/Weapon.h"
#include "Others/check_type.h"

using namespace std;

class Item;

class Equipment;

class Room;

class Weapon;

class Player : public GameCharacter {
private:
    Room *currentRoom;
    Room *previousRoom;
    int cur, pre;

    int curMP, maxMP;

    Weapon *weapon;
    Armor *armor;

    vector<Item *> inventory;

    bool changeEquip(string, Equipment *);

    void build_skill_Map(map<char, string> &);

public:

    void setWeapon(Weapon *weapon);

    void setArmor(Armor *armor);

    int getMaxMp() const;

    void setMaxMp(int maxMp);

    int getcurMp() const;

    void setcurMp(int mp);

    int getCur() const;

    int getPre() const;

    Room *getCurrentRoom() const;

    void setCurrentRoom(Room *currentRoom);

    Room *getPreviousRoom() const;

    void setPreviousRoom(Room *previousRoom);

    const vector<Item *> &getInventory() const;

    void setInventory(const vector<Item *> &inventory);

    Equipment *getEquip(string) const;

    void Equip(Equipment *equip);

    Player();

    Player(string, int, int, int, int, int, Room *);

    ~Player();

    void addItem(Item *);

    void changeRoom(Room *);

    void saveFile(ofstream &);

    void loadFile(ifstream &);

    void triggerEvent(GameCharacter *);

    void Show_Status(ostream &) const;
};

#endif // PLAYER_H_INCLUDED
