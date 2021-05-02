#include "Record.h"

void Record::savePlayer(Player *player, ofstream &saveFile) {
    saveFile << "====Detail====" << '\n'
             << "Name: \n" << player->getName() << '\n'
             << "Tag: \n" << player->getTag() << '\n'
             << "currentHealth: \n" << player->getCurrentHealth() << '\n'
             << "MaxHealth: \n" << player->getMaxHealth() << '\n'
             << "Attack: \n" << player->getAttack() << '\n'
             << "Defense: \n" << player->getDefense() << '\n'
             << "Inventory: \n" << player->getInventory().size();
    for (auto inventory:player->getInventory())
        saveFile << inventory << '\n';

    Weapon *playerWeapon = dynamic_cast<Weapon *>(player->getEquip());
    saveFile << "Weapon name: \n" << playerWeapon->getName() << '\n'
             << "Weapon tag: \n" << playerWeapon->getTag() << '\n'
             << "Weapon attack: \n" << playerWeapon->getAttack() << '\n'
             << "Weapon Durability: \n" << playerWeapon->getDurability() << '\n';

    saveFile << "Current Room: \n" << player->getCurrentRoom()->getIndex() << '\n'
             << "Previous Room: \n" << player->getPreviousRoom()->getIndex() << '\n';
}

void saveRooms(vector<Room> &MAP, ofstream &saveFile) {
    for (Room room:MAP) {
        saveFile << "Room index: \n" << room.getIndex() << '\n'
                 << "Room upRoom: \n" << (room.getUpRoom() == nullptr ? -1 : room.getUpRoom()->getIndex()) << '\n'
                 << "Room downRoom: \n" << (room.getDownRoom() == nullptr ? -1 : room.getDownRoom()->getIndex()) << '\n'
                 << "Room leftRoom: \n" << (room.getLeftRoom() == nullptr ? -1 : room.getLeftRoom()->getIndex()) << '\n'
                 << "Room rightRoom: \n" << (room.getRightRoom() == nullptr ? -1 : room.getRightRoom()->getIndex()) << '\n'
                 << "Room isExit: \n" << room.isExit() << '\n'
                 << "Room number of npc: \n" << room.getNpc() << '\n'
                 << "Room number of monster: \n" << room.getMonster() << '\n'
                 << "Room the number of item in the chest: \n" << room.getItemOnFloor() << '\n'
                 << "Object in Room: \n";

    }
}