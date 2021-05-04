#include "Dungeon.h"
#include "DungeonCPP/Menu.h"
#include "Others/console.h"

using namespace std;

bool Dungeon::DELAY = true;
bool Dungeon::CLEAR = true;

int main() {
    ifstream file2("setting.txt");
    if(file2){
        file2 >> Dungeon::DELAY
              >> Dungeon::CLEAR;
        file2.close();
    }
#ifdef WINDOW
    Dungeon::CLEAR = false;
#endif

    Dungeon dungeon;
    while (1) Menu::choose(dungeon);

    return 0;
}
