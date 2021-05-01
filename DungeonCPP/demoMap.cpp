#include "Dungeon.h"

#define DEMO

#ifdef DEMO

void Dungeon::createMap(int mapSize) {
    Dungeon::rooms.resize(mapSize);

    Item *item = new Item();
    Weapon *equip = new Weapon();
    Monster *monster = new Monster();
    Monster *monster2 = new Monster();
    Dungeon::rooms[0].addObject(item);
    Dungeon::rooms[0].addObject(equip);
    /*Dungeon::rooms[0].addObject(monster);*/
    Dungeon::rooms[1].addObject(monster2);
    Dungeon::rooms[3].setExit(true);

    Dungeon::rooms[0].setUpRoom(&Dungeon::rooms[1]);
    Dungeon::rooms[1].setDownRoom(&Dungeon::rooms[0]);
    Dungeon::rooms[1].setUpRoom(&Dungeon::rooms[2]);
    Dungeon::rooms[2].setDownRoom(&Dungeon::rooms[1]);
    Dungeon::rooms[2].setUpRoom(&Dungeon::rooms[3]);
    Dungeon::rooms[3].setDownRoom(&Dungeon::rooms[2]);

    for (int i = 0; i < mapSize; ++i) Dungeon::rooms[i].setIndex(i);
}

#endif

#ifndef DEMO
void Dungeon::createMap(int mapSize) {
    Dungeon::rooms.resize(mapSize);

    // connect rooms
    for (int i = 0; i < mapSize; ++i) {
        Dungeon::rooms[i].setUpRoom(&rooms[Tools::gainRandomNumber(0, mapSize)]);
        Dungeon::rooms[i].setDownRoom(&rooms[Tools::gainRandomNumber(0, mapSize)]);
        Dungeon::rooms[i].setLeftRoom(&rooms[Tools::gainRandomNumber(0, mapSize)]);
        Dungeon::rooms[i].setRightRoom(&rooms[Tools::gainRandomNumber(0, mapSize)]);
    }

    // assign room index
    for (int i = 0; i < mapSize; ++i)
        Dungeon::rooms[i].setIndex(i);

    // isExit assign
    Dungeon::rooms.back().setExit(true);
}
#endif

