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

    for (auto &monster:monster_set) {
        Show_Status(monster);
        monster->triggerEvent(dynamic_cast<GameCharacter *>(player));
        if (player->checkIsDead()) break;
        else player->getCurrentRoom()->popObject(monster);
    }

    if (player->getEquip("Weapon") != nullptr)
        player->getEquip("Weapon")->setDurability(
                player->getEquip("Weapon")->getDurability() - Tools::gainRandomNumber(0, 30));
    if (player->getEquip("Armor") != nullptr)
        player->getEquip("Armor")->setDurability(
                player->getEquip("Armor")->getDurability() - Tools::gainRandomNumber(0, 30));

    cout << Color::Yellow << "Fight END!!!\n" << Color::Default;
    if (Dungeon::DELAY)
        cout << Screen::Sleep5sec;
    if (Dungeon::CLEAR)
        cout << Screen::Clear;
    else if(Dungeon::DELAY)
        cout << Screen::Sleep1Sec;

}