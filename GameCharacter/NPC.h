#ifndef NPC_H_INCLUDED
#define NPC_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "GameCharacter/GameCharacter.h"
#include "GameCharacter/Player.h"
#include "Item.h"

using namespace std;

class Item;

class NPC : public GameCharacter {
private:
    string script;
    vector<Item> commodity;
public:
    NPC();

    NPC(string, string, vector<Item>);

    ~NPC() = default; // 亂寫

    void listCommodity(); /*print all the Item in this NPC*/

    /* Virtual function that you need to complete   */
    /* In NPC, this function should deal with the   */
    /* transaction in easy implementation           */
    void triggerEvent(GameCharacter *);

    /* Set & Get function*/
    void setScript(string);

    void setCommodity(vector<Item>);

    string getScript();

    vector<Item> getCommodity();
};


#endif // NPC_H_INCLUDED
