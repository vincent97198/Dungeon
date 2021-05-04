#include "Menu.h"

namespace Menu {
    void build_Menu_Map(map<char, string> &Menu_Map) {
        char Menu_index = 'A';

        ifstream load("Record.txt");
        Menu_Map[Menu_index++] = "Start Game";
        if (load)
            Menu_Map[Menu_index++] = "Load";
        Menu_Map[Menu_index++] = "Options";
        Menu_Map[Menu_index++] = "Quit";
    }


    void choose(Dungeon &dungeon) {
        map<char, string> Action;
        build_Menu_Map(Action);
        if (Dungeon::CLEAR)
            cout << Screen::Clear;
        char type = Ask::Ask_oneAlphabet("=======Menu=======", Action);

        for (auto iter = Action.begin(); iter != Action.end(); ++iter) {
            if (type == iter->first) {
                if (iter->second == "Start Game") dungeon.runDungeon(false);
                else if (iter->second == "Load") dungeon.runDungeon(true);
                else if (iter->second == "Options") Options::Setting();
                else if (iter->second == "Quit") {
                    cout << Color::Yellow << "=======Closed=======" << Color::Default
                         << '\n';
                    exit(0);
                }
            }
        }
    }
}