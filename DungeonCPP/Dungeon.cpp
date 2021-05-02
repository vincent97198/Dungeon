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


void Dungeon::startGame() {
    cout << Color::Magenta << "Use record?[y/n]" << Color::Default;
    string str;
    getline(cin,str);
    if (str[0] == 'y')
        Record::loadFromFile(&player, Dungeon::rooms);
    else {
        createMap(10);
        createPlayer();
    }
}

void Dungeon::runDungeon() {
    startGame();
    do {
        chooseAction();
    } while (checkGameLogic());
}