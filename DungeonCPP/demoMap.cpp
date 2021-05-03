#include "Dungeon.h"

// #define DEBUG

#ifdef DEBUG

void Dungeon::createMap(int mapSize,int Difficult) {
    Dungeon::rooms.resize(mapSize);

    Item *item = new Item();
    Weapon *equip = new Weapon();
    Armor *armor = new Armor();
    Item *item2 =new Item();
    set<Item*> demo_commodity;   demo_commodity.insert(item2);
    NPC *npc = new NPC("KING","DEMO",demo_commodity);
    Monster *monster2 = new Monster();
    Dungeon::rooms[0].addObject(item);
    Dungeon::rooms[0].addObject(equip);
    Dungeon::rooms[0].addObject(armor);
    Dungeon::rooms[0].addObject(npc);
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

#ifndef DEBUG

void Dungeon::createMap(int mapSize, int Difficult) {
    int Long = sqrt(mapSize);
    Dungeon::rooms.resize(mapSize);

    // assign room index
    for (int i = 0; i < mapSize; ++i)
        Dungeon::rooms[i].setIndex(i);

    vector<int> connect_MAP;
    for (int i = 0; i < Long; ++i) {
        for (int j = 0; j < Long; ++j)
            connect_MAP.emplace_back(i * Long + j);
    }

    for (int i = Long - 1; i >= 0; --i)
        swap(connect_MAP[i], connect_MAP[Tools::gainRandomNumber(0, i + 1)]);

    for (int i = 1; i < Long - 1; ++i) {
        for (int j = 1; j < Long - 1; ++j) {
            int now = connect_MAP[i * Long + j],
                    Up = connect_MAP[(i - 1) * Long + j],
                    Down = connect_MAP[(i + 1) * Long + j],
                    Left = connect_MAP[i * Long + j - 1],
                    Right = connect_MAP[i * Long + j + 1];
            rooms[now].setUpRoom(&rooms[Up]);
            rooms[Up].setDownRoom(&rooms[now]);

            rooms[now].setDownRoom(&rooms[Down]);
            rooms[Down].setUpRoom(&rooms[now]);

            rooms[now].setLeftRoom(&rooms[Left]);
            rooms[Left].setRightRoom(&rooms[now]);

            rooms[now].setRightRoom(&rooms[Right]);
            rooms[Right].setLeftRoom(&rooms[now]);
        }
    }

    // isExit assign
    Dungeon::rooms[Tools::gainRandomNumber(1, Long * Long)].setExit(true);

    //assign Monster
    for (int i = 0; i < Difficult * Long; ++i) {
        Monster *monster = new Monster();
        rooms[Tools::gainRandomNumber(1, Long * Long)].addObject(monster);
    }

    //assign NPC
    for (int i = 0; i < (4 - Difficult * Long); ++i) {
        set<Item *> commodity;
        int numberOfItem = Tools::gainRandomNumber(0, 4 - Difficult);
        for (int j = 0; j < numberOfItem; ++j) {
            Item *item = new Item();
            commodity.insert(item);
        }
        NPC *npc = new NPC();
        npc->setCommodity(commodity);
    }
}

#endif