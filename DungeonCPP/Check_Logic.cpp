#include "Dungeon.h"

bool Dungeon::checkGameLogic() {    // End game if return false
    if (player.checkIsDead()) {
        cout << Color::RED << "You're dead\n" << Color::Default << '\n';
        return false;
    } else if (player.getCurrentRoom()->isExit()) {
        cout << Color::Magenta << "You escape from the Dungeon\n" << Color::Default << '\n';
        return false;
    }
    return true;
}
