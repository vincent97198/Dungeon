#include "Dungeon.h"
#include "DungeonCPP/Menu.h"

using namespace std;

bool Dungeon::DELAY = true;
bool Dungeon::CLEAR = true;

int main() {
    ifstream file("setting.txt");
    file >> Dungeon::DELAY
         >> Dungeon::CLEAR;
    Dungeon dungeon;
    while (1) Menu::choose(dungeon);

    return 0;
}
