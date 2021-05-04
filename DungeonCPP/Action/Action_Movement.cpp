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

    char type = Ask::Ask_oneAlphabet("=======Movement=======", Movement);

    switch (type) {
        case 'W':
            Dungeon::player.changeRoom(Dungeon::player.getCurrentRoom()->getUpRoom());
            if (Dungeon::DELAY)
                cout << Screen::Shining << Color::Yellow << "Walking" << endl << Screen::Closed;
            break;
        case 'S':
            Dungeon::player.changeRoom(Dungeon::player.getCurrentRoom()->getDownRoom());
            if (Dungeon::DELAY)
                cout << Screen::Shining << Color::Yellow << "Walking" << endl << Screen::Closed;
            break;
        case 'D':
            Dungeon::player.changeRoom(Dungeon::player.getCurrentRoom()->getRightRoom());
            if (Dungeon::DELAY)
                cout << Screen::Shining << Color::Yellow << "Walking" << endl << Screen::Closed;
            break;
        case 'A':
            Dungeon::player.changeRoom(Dungeon::player.getCurrentRoom()->getLeftRoom());
            if (Dungeon::DELAY)
                cout << Screen::Shining << Color::Yellow << "Walking" << endl << Screen::Closed;
            break;
        case 'N':
            if (Dungeon::DELAY)
                cout << Screen::Shining << Color::Yellow << "Looking around~" << endl << Screen::Closed;
            break;
    }
    if (Dungeon::CLEAR)
        cout << Screen::Clear;
    else if (Dungeon::DELAY)
        cout << Screen::Sleep1Sec;
}