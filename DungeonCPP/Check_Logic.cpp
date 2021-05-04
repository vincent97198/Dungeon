#include "Dungeon.h"

bool Dungeon::checkGameLogic() {    // End game if return false
    if (player.getEquip("Weapon") != nullptr && player.getEquip("Weapon")->getDurability() <= 0){
        delete player.getEquip("Weapon");
        player.setWeapon(nullptr);
        cout << Color::RED << "Your weapon is broken\n" << Color::Default << '\n';
    }
    if (player.getEquip("Armor") != nullptr && player.getEquip("Armor")->getDurability() <= 0){
        delete player.getEquip("Armor");
        player.setArmor(nullptr);
        cout << Color::RED << "Your armor is broken\n" << Color::Default << '\n';
    }




    if (player.checkIsDead()) {
        if (Dungeon::CLEAR)
            cout << Screen::Clear;
        cout << Color::RED << "You're dead\n" << Color::Default << '\n';
        return false;
    } else if (player.getCurrentRoom()->isExit()) {
        if (Dungeon::CLEAR)
            cout << Screen::Clear;
        cout << Color::Purple << "You escape from the Dungeon\n" << Color::Default << '\n';
        return false;
    }
    return true;
}
