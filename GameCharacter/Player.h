#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "GameCharacter.h"
#include "Room.h"
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

    bool changeEquip(string);

    void build_skill_Map(map<char, string> &);

public:

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

    Player(string, int, int, int, int, Room *);

    ~Player();

    void addItem(Item *);

    void increaseStates(int, int, int);

    void changeRoom(Room *);

    void saveFile(ofstream &);

    void loadFile(ifstream &);

    void triggerEvent(GameCharacter *);
};

#endif // PLAYER_H_INCLUDED
