#include "NPC.h"

NPC::NPC() :
        GameCharacter("Steve", "NPC", INT32_MAX, 0, INT32_MAX),
        script("Hello, I'm Steve. I am NPC.") {
    NPC::commodity.clear();
}

NPC::NPC(string name, string script, set<Item *> commodity) :
        GameCharacter(name, "NPC", INT32_MAX, 0, INT32_MAX),
        script(script),
        commodity(std::move(commodity)) {}

void NPC::build_NPC_commodity_Map(map<int, Object *> &MAP) {
    int cnt = 0;
    for (auto &iter:NPC::commodity)
        MAP[cnt++] = iter;
}

void NPC::triggerEvent(GameCharacter *character) {
    cout << Color::Green << script << Color::Default << '\n';

    if (!NPC::commodity.empty()) {
        map<int, Object *> commodity_Map;
        build_NPC_commodity_Map(commodity_Map);

        /*cout << (commodity_Map.begin()->second->getName()) << '\n';*/
        vector<int> input;
        Ask::Ask_multi_int("What do you want to buy?", commodity_Map, input);

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
    GameCharacter *base = dynamic_cast<GameCharacter *>(this);
    base->saveFile(os);

    os << "NPC script: \n" << script << '\n'
    << "NPC commodity: \n" << commodity.size() << '\n';
    for(auto iter:commodity)
        iter->saveFile(os);
}
