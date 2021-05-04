#include "Dungeon.h"

void Dungeon::startGame(bool record) {
    if (Dungeon::CLEAR)
        cout << Screen::Clear;
    if (record)
        Record::loadFromFile(&player, Dungeon::rooms);
    else {
        createMap(30, 1);
        createPlayer();
    }
}

void Dungeon::runDungeon(bool record) {
    startGame(record);
    do {
        chooseAction();
        player.setcurMp(min(player.getcurMp() + 1, player.getMaxMp()));
    } while (checkGameLogic());
    exit(0);
}