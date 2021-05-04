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
    if (Dungeon::player.getcurMp() > 0)
        Action_Map[Action_index++] = "Use skill!";
    Action_Map[Action_index++] = "Save to file";
    Action_Map[Action_index++] = "Quit";
}

void Dungeon::chooseAction() {
    map<char, string> Action;
    build_Action_Map(Action);

    char type = Ask::Ask_oneAlphabet("=======Action=======", Action);

    string action_str = Action[type];
    if (action_str == "Move") handleMovement();
    else if (action_str == "Check Status") Show_Status(&player);
    else if (action_str == "Gain the item in the chest") Pick_item(Dungeon::player);
    else if (action_str == "Use skill!") {
        if (Dungeon::CLEAR)
            cout << Screen::Clear_soon;
        Dungeon::player.triggerEvent(&player);
    } else if (action_str == "Fight!!!") Fight(&player);
    else if (action_str == "Retreat~~~") Dungeon::player.changeRoom(Dungeon::player.getPreviousRoom());
    else if (action_str == "Talk to NPC") Talk_to_NPC(&player);
    else if (action_str == "Save to file") Record::saveToFile(&player, rooms);
    else if (action_str == "Quit") {
        cout << Color::Yellow << "=======Closed=======" << Color::Default
             << '\n';
        exit(0);
    }
}