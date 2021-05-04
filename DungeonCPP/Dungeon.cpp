#include "Dungeon.h"


ifstream &operator>>(ifstream &os, int &ret) {
    string str;
    getline(os, str);
    stringstream ss;
    ss << str;
    ss >> ret;
    return os;
}

ifstream &operator>>(ifstream &os, bool &ret) {
    string str;
    int tmp;
    getline(os, str);
    stringstream ss;
    ss << str;
    ss >> tmp;
    ret = tmp;
    return os;
}

ifstream &operator>>(ifstream &os, string &ret) {
    getline(os, ret);
    return os;
}


void Dungeon::startGame(bool record) {
    if (Dungeon::CLEAR)
        cout << Screen::Clear;
    if (record)
        Record::loadFromFile(&player, Dungeon::rooms);
    else {
        createMap(20, 1);
        createPlayer();
    }
}

void Dungeon::runDungeon(bool record) {
    startGame(record);
    do {
        chooseAction();
        player.setcurMp(min(player.getcurMp() + 1, player.getMaxMp()));
        if (!checkGameLogic())
            exit(0);
    } while (checkGameLogic());
}