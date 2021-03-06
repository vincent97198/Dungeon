#ifndef ROOM_H_INCLUDED
#define ROOM_H_INCLUDED

#include <iostream>
#include <string>
#include <set>
#include "Others/overLoad Control.h"
#include "Object.h"
#include "GameCharacter/Player/Player.h"
#include "GameCharacter/Monster.h"
#include "GameCharacter/NPC.h"
#include "Others/check_type.h"
#include "Item.h"


using namespace std;

class Room {
private:
    Room *upRoom;
    Room *downRoom;
    Room *leftRoom;
    Room *rightRoom;
    int up,down,left,right;
    bool Exit;
    int npc;
    int monster;
    int item_on_floor;

    int index;
    set<Object*> objects; /*contain 1 or multiple objects, including monster, npc, etc*/

    void setBoolean(Object *, bool);
public:
    Room();

    void addObject(Object *);

    bool popObject(Object *); /*pop out the specific object, used when the interaction is done*/

    /* Set & Get function*/

    set<Object*> getObjects();

    Room *getUpRoom() const;

    void setUpRoom(Room *upRoom);

    Room *getDownRoom() const;

    void setDownRoom(Room *downRoom);

    Room *getLeftRoom() const;

    void setLeftRoom(Room *leftRoom);

    Room *getRightRoom() const;

    void setRightRoom(Room *rightRoom);

    int getIndex() const;

    void setIndex(int index);

    bool isExit() const;

    void setExit(int);

    bool isNPC() const;


    bool isMonster() const;


    bool isItemOnFloor() const;

    int getNpc() const;

    int getMonster() const;

    int getItemOnFloor() const;

    int getUp() const;

    int getDown() const;

    int getLeft() const;

    int getRight() const;

    void saveFile(ofstream&);
    void loadFile(ifstream&);
};

#endif // ROOM_H_INCLUDED
