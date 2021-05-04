#include "Dungeon.h"

void Dungeon::build_NPC_Map(map<char, Object *> &MAP) {
    char NPC_index = 'A';
    for (auto &iter:Dungeon::player.getCurrentRoom()->getObjects())
        if (check_type::isNPCType(iter) != nullptr)
            MAP[NPC_index++] = iter;
}

void Dungeon::Talk_to_NPC(Player *player) {
    map<char, Object *> NPC_Map;
    build_NPC_Map(NPC_Map);

    char NPC_index = Ask::Ask_oneAlphabet_Object("Which NPC do you want to talk to?", NPC_Map);

    NPC *npc = dynamic_cast<NPC *>(NPC_Map[NPC_index]);
    npc->triggerEvent(player);
    if (Dungeon::CLEAR)
        cout << Screen::Clear;
    else if(Dungeon::DELAY)
        cout << Screen::Sleep1Sec;
}
