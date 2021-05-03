#ifndef NPC_H_INCLUDED
#define NPC_H_INCLUDED

#include <iostream>
#include <string>
#include <set>
#include "GameCharacter/GameCharacter.h"
#include "GameCharacter/Player.h"
#include "Item.h"
#include "Others/Ask.h"
#include "Equipment/Armor.h"

using namespace std;

class Object;

class NPC : public GameCharacter {
private:
    string script;
    set<Item*> commodity;

    void build_NPC_commodity_Map(map<int,Object*> &MAP);

    void popCommodity(Item*);

public:
    NPC();

    NPC(string, string, set<Item*>);

    ~NPC() = default; // 亂寫

    void triggerEvent(GameCharacter *);

    void saveFile(ofstream&);

    void loadFile(ifstream&);
};


#endif // NPC_H_INCLUDED
