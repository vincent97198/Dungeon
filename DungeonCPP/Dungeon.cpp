#include "Dungeon.h"

void Dungeon::startGame() {
    createMap(10);
    createPlayer();
}

void Dungeon::runDungeon() {
    startGame();
    do {
        chooseAction();
    } while (checkGameLogic());
}