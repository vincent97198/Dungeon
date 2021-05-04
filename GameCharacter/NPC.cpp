#include "NPC.h"

NPC::NPC() :
        GameCharacter("Steve", "NPC", INT32_MAX, 0, INT32_MAX, INT32_MAX),
        script("Hello, I'm Steve. I am NPC.") {
    NPC::commodity.clear();
}

NPC::NPC(string name, string script, set<Item *> commodity) :
        GameCharacter(name, "NPC", INT32_MAX, 0, INT32_MAX, INT32_MAX),
        script(script),
        commodity(std::move(commodity)) {}

void NPC::build_NPC_commodity_Map(map<int, Object *> &MAP) {
    int cnt = 0;
    for (auto &iter:NPC::commodity)
        MAP[cnt++] = iter;
}

void NPC::triggerEvent(GameCharacter *character) {
    cout << Color::Green << NPC::getName() << " says: " << script << Color::Default << '\n' << endl;

    if (!NPC::commodity.empty()) {
        map<int, Object *> commodity_Map;
        build_NPC_commodity_Map(commodity_Map);

        vector<int> input;
        Ask::Ask_multi_int("I can give you some gifts. What do you want?", commodity_Map, input);

        for (int POP:input) {
            Item *item = dynamic_cast<Item *>(commodity_Map[POP]);
            NPC::commodity.erase(item);

            Player *player;
            try {
                string Warning;
                player = dynamic_cast<Player *>(character);
                if (player == nullptr) throw (Warning = "BUG!!! NPC triggerEvent");
            }
            catch (string Warning) {
                cout << Color::RED << Warning << Color::Default << '\n';
            }

            player->addItem(item);
        }
    }
}

void NPC::saveFile(ofstream &os) {
    GameCharacter base = *this;
    base.saveFile(os);

    os << script << '\n'
       << commodity.size() << '\n';
    for (auto iter:commodity) {
        if (check_type::isWeaponType(iter) != nullptr)
            os << "Weapon\n";
        else if (check_type::isItemType(iter) != nullptr)
            os << "Item\n";
        else if (check_type::isArmorType(iter) != nullptr)
            os << "Armor\n";
        iter->saveFile(os);
    }
}

void NPC::loadFile(ifstream &os) {
    GameCharacter *base = new GameCharacter();
    base->loadFile(os);
    this->setMaxHealth(base->getMaxHealth());
    this->setCurrentHealth(base->getCurrentHealth());
    this->setAttack(base->getAttack());
    this->setDefense(base->getDefense());
    this->setName(base->getName());
    this->setTag(base->getTag());

    int SZ;
    os >> script >> SZ;
    string type;
    for (int i = 0; i < SZ; ++i) {
        os >> type;
        Item *item;
        if (type == "Weapon")
            item = new Weapon();
        else if (type == "Item")
            item = new Item();
        else if (type == "Armor")
            item = new Armor();
        commodity.insert(item);
    }
}

void NPC::setCommodity(const set<Item *> &commodity) {
    NPC::commodity = commodity;
}

NPC::~NPC() {
    for (auto iter:NPC::commodity) {
        delete iter;
        iter = nullptr;
    }
    NPC::commodity.clear();
    NPC::script.clear();
}
