#include "Dungeon.h"

string Dungeon::AskName() {
    cout << endl;
    cout << Color::Blue << "What's your name?\n" << Color::Default;
    string name;
    getline(cin, name);
    return name;
}

void Dungeon::createPlayer() {
    const int Player_attack = 100000,
            Player_maxHealth = 150000000,
            Player_defense = 1;

    Dungeon::player = Player(AskName(), Player_maxHealth, Player_attack, Player_defense, &Dungeon::rooms[0]);
    Show_Status(player);
}