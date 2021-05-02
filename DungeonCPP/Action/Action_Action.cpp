#include "Dungeon.h"

void Dungeon::build_Action_Map(map<char, string> &Action_Map) {

    char Action_index = 'A';

    if (Dungeon::player.getCurrentRoom()->isMonster()) {
        Action_Map[Action_index++] = "Fight!!!";
        Action_Map[Action_index++] = "Retreat~~~";
    } else {
        Action_Map[Action_index++] = "Move";
        Action_Map[Action_index++] = "Check Status";
        if (Dungeon::player.getCurrentRoom()->isNPC())
            Action_Map[Action_index++] = "Talk to NPC";
        if (Dungeon::player.getCurrentRoom()->isItemOnFloor())
            Action_Map[Action_index++] = "Gain the item in the chest";
    }
    Action_Map[Action_index++] = "Save to file";
}

void Dungeon::chooseAction() {
    map<char, string> Action;
    build_Action_Map(Action);

    char type = Ask::Ask_oneAlphabet("What do you want to do?", Action);

    for (auto iter = Action.begin(); iter != Action.end(); ++iter) {
        if (type == iter->first) {
            if (iter->second == "Move") handleMovement();
            else if (iter->second == "Check Status") Show_Status(Dungeon::player);
            else if (iter->second == "Gain the item in the chest") Pick_item(Dungeon::player);
            else if (iter->second == "Fight!!!") Fight(&player);
            else if (iter->second == "Retreat~~~") Dungeon::player.changeRoom(Dungeon::player.getPreviousRoom());
            else if(iter->second == "Talk to NPC") Talk_to_NPC(&player);
        }
    }

    if (!checkGameLogic())
        exit(0);
}