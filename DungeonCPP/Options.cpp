#include "Options.h"

namespace Options {
    void build_Options_Map(map<char, string> &Options_Map) {
        char Options_index = 'A';

        if (!Dungeon::DELAY)
            Options_Map[Options_index++] = "Open Delay";
        else
            Options_Map[Options_index++] = "Close Delay";
#ifndef WINDOW
        if (!Dungeon::CLEAR)
            Options_Map[Options_index++] = "Open clear screen";
        else
            Options_Map[Options_index++] = "Close clear screen";
#endif
        Options_Map[Options_index++] = "Quit";
    }

    void Setting() {
        map<char, string> Action;
        build_Options_Map(Action);

        char type = Ask::Ask_oneAlphabet("=======Options=======", Action);

        for (auto iter = Action.begin(); iter != Action.end(); ++iter) {
            if (type == iter->first) {
                if (iter->second == "Open Delay") Dungeon::DELAY = true;
                else if (iter->second == "Close Delay") Dungeon::DELAY = false;
                else if (iter->second == "Open clear screen") Dungeon::CLEAR = true;
                else if (iter->second == "Close clear screen") Dungeon::CLEAR = false;
                else if (iter->second == "Quit") break;
            }
        }

        ofstream file("setting.txt");
        file << Dungeon::DELAY << '\n'
             << Dungeon::CLEAR << '\n';
        file.close();
    }
}