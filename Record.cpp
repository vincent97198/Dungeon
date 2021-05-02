#include "Record.h"

namespace Record {
    void saveToFile(Player *player, vector<Room> &MAP) {
        ofstream record("Record.txt");

        try{
            string Warning;
            if(!record) throw (Warning="Open File Fail!");
        }catch(string Warning){
            cout << Color::RED << Warning << Color::Default << '\n';
        }

        player->saveFile(record);
        record << MAP.size() << '\n';
        for (Room room:MAP)
            room.saveFile(record);
    }

    void loadFromFile(Player *player,vector<Room> &MAP){
        ifstream record("Record.txt");

        try{
            string Warning;
            if(!record) throw (Warning="Open File Fail!");
        }catch(string Warning){
            cout << Color::RED << Warning << Color::Default << '\n';
        }

        player->loadFile(record);

        int SZ;
        record >> SZ;
        for(int i=0;i<SZ;++i){
            Room room;  room.loadFile(record);
            MAP.emplace_back(room);
        }

        player->setCurrentRoom(&MAP[player->getCur()]);
        player->setPreviousRoom(&MAP[player->getPre()]);

        for(int i=0;i<SZ;++i){
            if(MAP[i].getUp()!=-1)
                MAP[i].setUpRoom(&MAP[MAP[i].getUp()]);
            if(MAP[i].getDown()!=-1)
                MAP[i].setDownRoom(&MAP[MAP[i].getDown()]);
            if(MAP[i].getLeft()!=-1)
                MAP[i].setLeftRoom(&MAP[MAP[i].getLeft()]);
            if(MAP[i].getRight()!=-1)
                MAP[i].setRightRoom(&MAP[MAP[i].getRight()]);
        }
    }
}