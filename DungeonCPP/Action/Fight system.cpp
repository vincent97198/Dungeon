#include "Dungeon.h"

void Dungeon::build_Monster_Map(vector<Monster *> &MAP) {
    for (auto &iter: player.getCurrentRoom()->getObjects()) {
        if (check_type::isMonsterType(iter) != nullptr)
            MAP.emplace_back(check_type::isMonsterType(iter));
    }
}

void Dungeon::Fight(Player *player) {
    cout << Screen::Shining << Color::Yellow << "Fighting!!!" << endl << Color::Default << Screen::Closed;

    vector<Monster *> monster_set;
    build_Monster_Map(monster_set);

    for (auto &monster:monster_set){
        monster->triggerEvent(dynamic_cast<GameCharacter *>(player));
        if(player->checkIsDead())   break;
        else player->getCurrentRoom()->popObject(monster);
    }

    cout << Color::Yellow << "Fight END!!!\n" << Color::Default;
    cout << Screen::Clear;
}