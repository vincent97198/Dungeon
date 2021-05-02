#include "Record.h"

void Record::savePlayer(Player *player, ofstream &saveFile) {
    cout << "====Detail====" << '\n'
         << "Name: \n" << player->getName() << '\n'
         << "Tag: \n" << player->getTag() << '\n'
         << "currentHealth: \n" << player->getCurrentHealth() << '\n'
         << "MaxHealth: \n" << player->getMaxHealth() << '\n'
         << "Attack: \n" << player->getAttack() << '\n'
         << "Defense: \n" << player->getDefense() << '\n'
         << "Position(Room index): \n" << player->getCurrentRoom()->getIndex() << '\n'
         << "Inventory: \n" << player->getInventory().size();
    for (auto inventory:player->getInventory())
        cout << inventory << '\n';

    Weapon *playerWeapon=dynamic_cast<Weapon*>(player->getEquip());
    cout << "Weapon name: \n" << playerWeapon->getName() << '\n'
         << "Weapon tag: \n" << playerWeapon->getTag() << '\n'
         << "Weapon attack: \n" << playerWeapon->getAttack() << '\n'
         << "Weapon Durability: \n" << playerWeapon->getDurability() << '\n';

    cout << "Current Room: \n" << player->getCurrentRoom()->getIndex() << '\n'
    << "Previous Room: \n" << player->getPreviousRoom()->getIndex() << '\n';
}
