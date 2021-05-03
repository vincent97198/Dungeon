#include "Player.h"

Room *Player::getCurrentRoom() const {
    return currentRoom;
}

void Player::setCurrentRoom(Room *currentRoom) {
    Player::currentRoom = currentRoom;
}

Room *Player::getPreviousRoom() const {
    return previousRoom;
}

void Player::setPreviousRoom(Room *previousRoom) {
    Player::previousRoom = previousRoom;
}

const vector<Item *> &Player::getInventory() const {
    return inventory;
}

void Player::setInventory(const vector<Item *> &inventory) {
    Player::inventory = inventory;
}

Player::Player() : GameCharacter() {
    Player::currentRoom = nullptr;
    Player::previousRoom = nullptr;
    Player::weapon = nullptr;
    Player::armor = nullptr;
    Player::inventory.clear();
    Player::maxMP = 10;
    Player::curMP = 10;
}

Player::Player(string name, int maxMP, int maxHealth, int attack, int defense, Room *currentRoom) : GameCharacter(name,
                                                                                                                  "Player",
                                                                                                                  maxHealth,
                                                                                                                  attack,
                                                                                                                  defense) {
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

void Player::Equip(Equipment *Equip) {
    try {
        string Warning;
        Weapon *Debug_test = dynamic_cast<Weapon *>(Equip);
        Armor *Debug_test2 = dynamic_cast<Armor *>(Equip);
        if (Debug_test == nullptr && Debug_test2 == nullptr)
            throw (Warning = "BUG!!! Ambiguous Data Type. Weapon or Armor");
    }
    catch (string Warning) {
        cout << Color::RED << Warning << Color::Default << '\n';
    }

    Weapon *new_weapon = dynamic_cast<Weapon *>(Equip);
    Armor *new_armor = dynamic_cast<Armor *>(Equip);

    if (new_weapon != nullptr) {
        if (weapon == nullptr) {
            Player::setAttack(Player::getAttack() + new_weapon->getAttack());
            weapon = new_weapon;
        } else if (changeEquip(weapon->getName()))
            Player::setAttack(Player::getAttack() + new_weapon->getAttack() - Player::weapon->getAttack());
        weapon = new_weapon;
    }

    if (new_armor != nullptr) {
        if (armor == nullptr) {
            Player::setDefense(Player::getDefense() + new_armor->getDefense());
            armor = new_armor;
        } else if (changeEquip(armor->getName()))
            Player::setDefense(Player::getDefense() + new_armor->getDefense() - Player::armor->getDefense());
        armor = new_armor;
    }
}

Equipment* Player::getEquip(string equip) const {
    if (equip == "Weapon")
        return dynamic_cast<Equipment *>(Player::weapon);
    else if (equip == "Armor")
        return dynamic_cast<Equipment *>(Player::armor);
    else exit(1);
}

void Player::saveFile(ofstream &os) {
    GameCharacter base = *this;
    base.saveFile(os);

    os << currentRoom->getIndex() << '\n'
       << (previousRoom == nullptr ? -1 : previousRoom->getIndex()) << '\n';

    os << curMP << maxMP;

    if (weapon != nullptr) {
        os << "Weapon\n";
        weapon->saveFile(os);
    } else os << "noWeapon\n";

    if (armor != nullptr) {
        os << "Armor\n";
        armor->saveFile(os);
    } else os << "noArmor\n";

    os << inventory.size() << '\n';
    for (auto iter:inventory) {
        if (check_type::isWeaponType(iter) != nullptr)
            os << "Weapon\n";
        else if (check_type::isItemType(iter) != nullptr)
            os << "Item\n";
        else if (check_type::isArmorType(iter) != nullptr)
            os << "Armor\n";
        iter->saveFile(os);
    }
}

void Player::loadFile(ifstream &os) {
    GameCharacter *base = new GameCharacter();
    base->loadFile(os);
    this->setMaxHealth(base->getMaxHealth());
    this->setCurrentHealth(base->getCurrentHealth());
    this->setAttack(base->getAttack());
    this->setDefense(base->getDefense());
    this->setName(base->getName());
    this->setTag(base->getTag());

    os >> cur >> pre;

    os >> curMP >> maxMP;

    string type;
    os >> type;
    if (type == "Weapon") {
        weapon = new Weapon();
        weapon->loadFile(os);
    }
    os >> type;
    if (type == "Armor") {
        armor = new Armor();
        armor->loadFile(os);
    }

    int SZ;
    os >> SZ;
    for (int i = 0; i < SZ; ++i) {
        os >> type;
        Item *item;
        if (type == "Weapon")
            item = new Weapon();
        else if (type == "Item")
            item = new Item();
        else if (type == "Armor")
            item = new Armor();
        item->loadFile(os);
        inventory.emplace_back(item);
    }
}

int Player::getCur() const {
    return cur;
}

int Player::getPre() const {
    return pre;
}

bool Player::changeEquip(string str) {
    cout << Color::Yellow
         << "You have already equipped " << str << '\n'
         << Color::Default;
    map<char, string> true_false_Map;
    true_false_Map['Y'] = "YES";
    true_false_Map['N'] = "NO";
    char type = Ask::Ask_oneAlphabet("Do you want to change your equipment?[Y/n]", true_false_Map);
    if (type == 'Y')
        return true;
    else return false;
}

int Player::getcurMp() const {
    return curMP;
}

void Player::setcurMp(int mp) {
    curMP = mp;
}

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
    cout << Color::Yellow  << "Magic Spell: ";
    for(int i=0;i<15;++i){
        char ch=Tools::gainRandomNumber(33,91);
        cout << ch;
    }
    cout << endl << Screen::Closed;
}

int Player::getMaxMp() const {
    return maxMP;
}

void Player::setMaxMp(int maxMp) {
    maxMP = maxMp;
}