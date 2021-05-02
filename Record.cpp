#include "Record.h"

namespace Record {
    void saveToFile(Player *player, vector<Room> &MAP) {
        ofstream output("test.txt");

        try{
            string Warning;
            if(!output) throw (Warning="Open File Fail!");
        }catch(string Warning){
            cout << Color::RED << Warning << Color::Default << '\n';
        }

        player->saveFile(output);
        for (Room room:MAP)
            room.saveFile(output);
    }
}