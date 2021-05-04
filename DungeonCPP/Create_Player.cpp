#include "Dungeon.h"

string Dungeon::AskName() {
    cout << endl;
    cout << Color::Blue << "What's your name?\n" << Color::Default;
    string name;
    getline(cin, name);
    return name;
}

void Dungeon::createPlayer() {
    const int Player_attack = 10,
            Player_maxHealth = 45,
            Player_defense = 0,
            Player_maxMP = 10,
            Player_speed = 20;

    Dungeon::player = Player(AskName(),Player_speed ,Player_maxMP, Player_maxHealth, Player_attack, Player_defense,
                             &Dungeon::rooms[0]);
    Show_Status(&player);
}