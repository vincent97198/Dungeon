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

using namespace std;

class Dungeon {
private:
    Player player;
    vector<Room> rooms;

    void Show_Status(Player);

    void Pick_item(Player);

    void Fight(Player *);

    string AskName();

    void build_Movement_Map(map<char, string> &);

    void build_Action_Map(map<char, string> &);

    void build_pick_item_Map(map<int, string> &);

    void build_Monster_Map(vector<Monster *> &);

    char Ask_oneAlphabet(string, map<char, string> &);

    void Ask_multi_int(string, map<int, string> &, vector<int> &);


    /*Dungeon();*/
    /* Create a new player, and give him/her basic status */
    void createPlayer();

    /* Create a map, which include several different rooms */
    void createMap(int);

    /* Deal with player's moveing action */
    void handleMovement();

    /* Deal with all game initial setting       */
    /* Including create player, create map etc  */
    void startGame();

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
    void runDungeon();
};


#endif // DUNGEON_H_INCLUDED
