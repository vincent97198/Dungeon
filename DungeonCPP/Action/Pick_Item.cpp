#include "Dungeon.h"

void Dungeon::build_pick_item_Map(map<int, Object *> &Pick_Item_Map) {
    int Pick_Item_Index = 0;

    for (const auto &iter:Dungeon::player.getCurrentRoom()->getObjects())
        if (check_type::isItemType(iter) != nullptr)
            Pick_Item_Map[Pick_Item_Index++] = iter;
}

void Dungeon::Pick_item(Player player) {
    map<int, Object *> Pick_Item_Map;
    build_pick_item_Map(Pick_Item_Map);

    vector<int> type;
    Ask::Ask_multi_int("Which item do you want to pick?", Pick_Item_Map, type);

    int cnt_item = 0, cnt_type = 0;
    for (const auto &iter:Dungeon::player.getCurrentRoom()->getObjects()) {
        if (check_type::isItemType(iter) != nullptr) {
            if (cnt_type < type.size() && type[cnt_type] == cnt_item) {
                ++cnt_type;
                Dungeon::player.getCurrentRoom()->popObject(iter);
                Dungeon::player.addItem(check_type::isItemType(iter));
            }
            ++cnt_item;
        }
    }
}