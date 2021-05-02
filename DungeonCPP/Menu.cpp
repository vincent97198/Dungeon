#include "DungeonCPP/Menu.h"

namespace Menu {
    void build_Menu_Map(map<char, string> &Menu_Map) {
        char Menu_index = 'A';

        ifstream test("Record.txt");
        Menu_Map[Menu_index++] = "Start Game";
        if(test)
            Menu_Map[Menu_index++] = "Load";
        Menu_Map[Menu_index++] = "Quit";
    }


    void choose(Dungeon &dungeon) {
        map<char, string> Action;
        build_Menu_Map(Action);

        char type = Ask::Ask_oneAlphabet("=======Menu=======", Action);

        for (auto iter = Action.begin(); iter != Action.end(); ++iter) {
            if (type == iter->first) {
                if (iter->second == "Start Game") dungeon.runDungeon(false);
                else if (iter->second == "Load") dungeon.runDungeon(true);
                else if (iter->second == "Quit") {
                    cout << Color::Yellow << "=======Closed=======" << Color::Default
                         << '\n';
                    exit(0);
                }
            }
        }
    }
}