#include "Dungeon.h"

void Dungeon::Show_Status(GameCharacter *character) {
    if (Dungeon::CLEAR)
        cout << Screen::Clear;
    else if (Dungeon::DELAY)
        cout << Screen::Sleep1Sec;
    cout << character;
}
