#include "Player.h"

void Player::build_skill_Map(map<char, string> &MAP) {
    char index = 'A';
    if (Player::getcurMp() >= 10)
        MAP[index++] = "Angel's blessing (full you health, cost: 10MP)";
    if (Player::getcurMp() >= 5)
        MAP[index++] = "Smith Master (full you equipment durability, cost: 5MP)";
}

void Player::triggerEvent(GameCharacter *player) {
    map<char, string> skill_Map;
    build_skill_Map(skill_Map);

    cout << Screen::Clear_soon;
    char type = Ask::Ask_oneAlphabet("=======Skill=======", skill_Map);
    string skill = skill_Map[type];

    if (skill == "Angel's blessing (full you health)") {
        Player::setCurrentHealth(Player::getMaxHealth());
        Player::curMP -= 10;
    } else if (skill == "Smith Master (full you equipment durability)") {
        if (Player::weapon != nullptr)
            Player::weapon->setDurability(100);
        if (Player::armor != nullptr)
            Player::armor->setDurability(100);

        if (Player::armor == nullptr && Player::weapon == nullptr) {
            cout << endl;
            cout << Color::RED << "No equipment!!!" << Color::Default << endl;
        } else
            Player::curMP -= 5;
    }


    cout << Screen::Shining << Color::Yellow << "Magic~~~" << endl << Screen::Closed;
    cout << Color::Yellow << "Magic Spell: ";
    for (int i = 0; i < 15; ++i) {
        char ch = Tools::gainRandomNumber(33, 91);
        cout << ch;
    }
    cout << endl << Screen::Closed;
}