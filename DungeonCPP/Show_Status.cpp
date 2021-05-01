#include "Dungeon.h"

template<class T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    if (v.empty()) {
        os << "It's empty";
        return os;
    }

    int cnt = 0;
    for (int i = 0; i < v.size(); ++i) {
        auto &iter = v[i];
        os << "No." << ++cnt << " " << iter << "\n"[i+1==v.size()];
    }
    return os;
}


void Dungeon::Show_Status(Player player) {
    cout << "====Detail====" << '\n'
         << "Name: " << Color::Cyan << player.getName() << '\n' << Color::Default
         << "Health: " << player.getCurrentHealth() << '/' << player.getMaxHealth() << '\n'
         << "Attack: " << player.getAttack() << '\n'
         << "Defense: " << player.getDefense() << '\n'
         << "Position(Room index): " << player.getCurrentRoom()->getIndex() << '\n'
         << "Inventory: " << player.getInventory() << '\n'
         << "Weapon: " << player.getEquip() << '\n';
}
