#include "Dungeon.h"

template<class T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    if (v.empty()) {
        os << Color::Cyan << "Empty" << Color::Default;
        return os;
    }

    int cnt = 0;
    for (int i = 0; i < v.size(); ++i) {
        auto &iter = v[i];
        os << "No." << ++cnt << " " << iter << "\n"[i + 1 == v.size()];
    }
    return os;
}


void Dungeon::Show_Status(Player &player) {
    cout << endl;
    cout << Color::Blue << "=======Detail=======" << Color::Default << '\n'
         << "Name: " << Color::Yellow << player.getName() << '\n' << Color::Default
         << "Position: #" << player.getCurrentRoom()->getIndex() << '\n'
         << "Health: " << player.getCurrentHealth() << '/' << player.getMaxHealth() << '\n'
         << "MP: " << player.getcurMp() << '/' << player.getMaxMp() << '\n'
         << "Attack: " << player.getAttack() << '\n'
         << "Defense: " << player.getDefense() << '\n'
         << "Inventory: " << player.getInventory() << '\n'
         << "Weapon: " << player.getEquip("Weapon") << '\n';
    if (player.getEquip("Weapon") != nullptr)
        cout << "Weapon Durability: " << player.getEquip("Weapon")->getDurability() << '\n';
    cout << "Armor: " << player.getEquip("Armor") << '\n';
    if (player.getEquip("Armor") != nullptr)
        cout << "Armor Durability: " << player.getEquip("Armor")->getDurability() << '\n';
    cout << endl;
}
