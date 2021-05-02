#ifndef DUNGEON_H_INCLUDED
#define DUNGEON_H_INCLUDED

#include <string>
#include <vector>
#include <exception>
#include <map>
#include "GameCharacter/Player.h"
#include "GameCharacter/Monster.h"
#include "GameCharacter/NPC.h"
#include "Room.h"
#include "Record.h"
#include "Others/check_type.h"
#include "Others/programming_Tools.h"
#include "Others/Ask.h"

using namespace std;

class Dungeon {
private:
    Player player;
    vector<Room> rooms;

    void Show_Status(Player);

    void Pick_item(Player);

    void Fight(Player *);

    void Talk_to_NPC(Player *player);

    string AskName();

    void build_Movement_Map(map<char, string> &);

    void build_Action_Map(map<char, string> &);

    void build_pick_item_Map(map<int, Object*> &);

    void build_Monster_Map(vector<Monster *> &);

    void build_NPC_Map(map<char, Object*> &MAP);

    /*Dungeon();*/
    /* Create a new player, and give him/her basic status */
    void createPlayer();

    /* Create a map, which include several different rooms */
    void createMap(int);

    /* Deal with player's moveing action */
    void handleMovement();

    /* Deal with all game initial setting       */
    /* Including create player, create map etc  */
    void startGame(bool);

    /* Deal with the player's action     */
    /* including showing the action list */
    /* that player can do at that room   */
    /* and dealing with player's input   */
    void chooseAction();       // 還沒寫完，只寫了 MOVE 跟 CHECK STATUS

    /* Check whether the game should end or not */
    /* Including player victory, or he/she dead */
    bool checkGameLogic();

public:

    /* Deal with the whole game process */
    void runDungeon(bool);
};


#endif // DUNGEON_H_INCLUDED
