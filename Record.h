#ifndef RECORD_H_INCLUDED
#define RECORD_H_INCLUDED

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "Item.h"
#include "Dungeon.h"
#include "GameCharacter/Monster.h"
#include "GameCharacter/NPC.h"
#include "GameCharacter/Player/Player.h"

using namespace std;

namespace Record {
    void saveToFile(Player *, vector<Room> &);

    void loadFromFile(Player *, vector<Room> &);
};

#endif // RECORD_H_INCLUDED
