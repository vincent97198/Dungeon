#include "Dungeon.h"

/*#define DEBUG*/

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
    int Long = sqrt(mapSize - 1);
    Dungeon::rooms.resize(mapSize);

    // assign room index
    for (int i = 0; i < mapSize; ++i)
        Dungeon::rooms[i].setIndex(i);

    vector<int> connect_MAP;
        for (int i = 0; i < Long; ++i) {
            for (int j = 0; j < Long; ++j)
                connect_MAP.emplace_back(i * Long + j);
        }

    for (int i = Long * Long - 1; i >= 0; --i) {
        int randNumber = Tools::gainRandomNumber(0, i + 1);
        swap(connect_MAP[i], connect_MAP[randNumber]);
    }


    for (int i = 0; i < Long; ++i) {
        for (int j = 0; j < Long; ++j) {
            int now = connect_MAP[i * Long + j];

            if (i > 0) {
                int Up = connect_MAP[(i - 1) * Long + j];
                rooms[now].setUpRoom(&rooms[Up]);
                rooms[Up].setDownRoom(&rooms[now]);
            }
            if (i < Long - 1) {
                int Down = connect_MAP[(i + 1) * Long + j];
                rooms[now].setDownRoom(&rooms[Down]);
                rooms[Down].setUpRoom(&rooms[now]);
            }
            if (j > 0) {
                int Left = connect_MAP[i * Long + j - 1];
                rooms[now].setLeftRoom(&rooms[Left]);
                rooms[Left].setRightRoom(&rooms[now]);
            }
            if (j < Long - 1) {
                int Right = connect_MAP[i * Long + j + 1];
                rooms[now].setRightRoom(&rooms[Right]);
                rooms[Right].setLeftRoom(&rooms[now]);
            }
        }
    }

    // isExit assign
    Dungeon::rooms[Tools::gainRandomNumber(1, Long * Long)].setExit(true);

    //assign Monster
    for (int i = 0; i < Difficult * Long; ++i) {
        Monster *monster = new Monster("DANGER_monster","RRrrrrrr",Tools::gainRandomNumber(11,50),Tools::gainRandomNumber(0,12),Tools::gainRandomNumber(0,5),Tools::gainRandomNumber(1,100));
        rooms[Tools::gainRandomNumber(1, Long * Long)].addObject(monster);
    }

    //assign NPC
    for (int i = 0; i < (4 - Difficult) * Long; ++i) {
        set<Item *> commodity;
        int numberOfItem = Tools::gainRandomNumber(0, 5 - Difficult);
        for (int j = 0; j < numberOfItem; ++j) {
            int randNum = Tools::gainRandomNumber(0, 5);
            Item *item;
            if (randNum == 0)
                item = new Item("diamond","item");
            else if (randNum == 1)
                item = new Weapon("Stone Sword",100,Tools::gainRandomNumber(10,100));
            else if (randNum == 2)
                item = new Armor("Iron Armor",100,Tools::gainRandomNumber(15,100));
            commodity.insert(item);
        }
        NPC *npc = new NPC("Merchant","Hello, I am NPC.",commodity);
        rooms[Tools::gainRandomNumber(1, Long * Long)].addObject(npc);
    }

    //assign item on floor
    for (int i = 0; i < (3 - Difficult) * Long; ++i){
        int numberOfItem = Tools::gainRandomNumber(0, 4 - Difficult);
        Item *item = new Item("crystal","item");
        rooms[Tools::gainRandomNumber(1, Long * Long)].addObject(item);
    }
}

#endif