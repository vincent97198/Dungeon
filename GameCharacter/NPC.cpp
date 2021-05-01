#include "NPC.h"

NPC::NPC() :
        GameCharacter("Steve", "NPC", INT32_MAX, 0, INT32_MAX),
        script("Hello, I'm Steve. I am NPC.") {
    NPC::commodity.clear();
}

NPC::NPC(string name, string script, vector<Item> commodity) :
        GameCharacter(name, "NPC", INT32_MAX, 0, INT32_MAX),
        script(script),
        commodity(commodity) {}
