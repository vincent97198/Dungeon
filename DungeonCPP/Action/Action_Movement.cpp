#include "Dungeon.h"

void Dungeon::build_Movement_Map(map<char, string> &Movement_Map) {
    Room *nowRoom = Dungeon::player.getCurrentRoom();
    Movement_Map['N'] = "Stay here";
    if (nowRoom->getUpRoom())
        Movement_Map['W'] = "Up";
    if (nowRoom->getLeftRoom())
        Movement_Map['A'] = "Left";
    if (nowRoom->getRightRoom())
        Movement_Map['D'] = "Right";
    if (nowRoom->getDownRoom())
        Movement_Map['S'] = "Down";
}

void Dungeon::handleMovement() {
    map<char, string> Movement;
    build_Movement_Map(Movement);

    char type = Ask::Ask_oneAlphabet("Where do you want to go?", Movement);

    switch (type) {
        case 'W':
            Dungeon::player.changeRoom(Dungeon::player.getCurrentRoom()->getUpRoom());
            break;
        case 'S':
            Dungeon::player.changeRoom(Dungeon::player.getCurrentRoom()->getDownRoom());
            break;
        case 'D':
            Dungeon::player.changeRoom(Dungeon::player.getCurrentRoom()->getRightRoom());
            break;
        case 'A':
            Dungeon::player.changeRoom(Dungeon::player.getCurrentRoom()->getLeftRoom());
            break;
        case 'N':
            break;
    }
}