#include "Player.h"

Player::Player() : GameCharacter() {
    Player::currentRoom = nullptr;
    Player::previousRoom = nullptr;
    Player::weapon = nullptr;
    Player::armor = nullptr;
    Player::inventory.clear();
    Player::maxMP = 10;
    Player::curMP = 10;
    Player::setSpeed(10);
    Player::setMaxHealth(100);
    Player::setAttack(10);
    Player::setDefense(1);
}


Player::Player(string name,int speed ,int maxMP, int maxHealth, int attack, int defense, Room *currentRoom) : GameCharacter(name,
                                                                                                                  "Player",
                                                                                                                  maxHealth,
                                                                                                                  attack,
                                                                                                                  defense,
                                                                                                                  speed) {
    Player::currentRoom = currentRoom;
    Player::previousRoom = nullptr;
    Player::inventory.clear();
    Player::weapon = nullptr;
    Player::armor = nullptr;
    Player::maxMP = maxMP;
    Player::curMP = maxMP;
}

void Player::addItem(Item *item) {
    if (check_type::isEquipmentType(item) != nullptr)
        Player::Equip(check_type::isEquipmentType(item));
    else
        inventory.emplace_back(item);
}

void Player::changeRoom(Room *nextRoom) {
    Player::previousRoom = Player::currentRoom;
    Player::currentRoom = nextRoom;
}

Player::~Player() {
    inventory.clear();
    currentRoom = nullptr;
    previousRoom = nullptr;
    weapon = nullptr;
    armor = nullptr;
}

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


void Player::Show_status() {
    cout << endl;
    cout << Color::Blue << "=======Player=======" << Color::Default << '\n'
         << "Name: " << Color::Yellow << Player::getName() << '\n' << Color::Default
         << "Position: #" << Player::getCurrentRoom()->getIndex() << '\n'
         << "Health: " << Player::getCurrentHealth() << '/' << Player::getMaxHealth() << '\n'
         << "MP: " << Player::getcurMp() << '/' << Player::getMaxMp() << '\n'
         << "Attack: " << Player::getAttack() << '\n'
         << "Defense: " << Player::getDefense() << '\n'
         << "Speed: " << Player::getSpeed() << '\n'
         << "Inventory: " << Player::getInventory() << '\n'
         << "Weapon: " << Player::getEquip("Weapon") << '\n';
    if (Player::getEquip("Weapon") != nullptr)
        cout << "Weapon Durability: " << Player::getEquip("Weapon")->getDurability() << '\n';
    cout << "Armor: " << Player::getEquip("Armor") << '\n';
    if (Player::getEquip("Armor") != nullptr)
        cout << "Armor Durability: " << Player::getEquip("Armor")->getDurability() << '\n';
    cout << endl;
}
