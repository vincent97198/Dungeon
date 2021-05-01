#include "Monster.h"

Monster::Monster()
        : GameCharacter("UNKNOWN_Monster", "danger_monster", INT16_MAX, INT16_MAX, INT16_MAX) {
    this->SAY = "Hello, I'm Monster";
}

Monster::Monster(string name, string SAY, int health, int attack, int defense)
        : GameCharacter(name, "danger_monster", health, attack, defense),
          SAY(SAY) {}

void Monster::triggerEvent(GameCharacter *Enemy) {
    int MyDPs = max(0, Monster::getAttack() - Enemy->getDefense()),
            EnemyDps = max(0, Enemy->getAttack() - Monster::getDefense());

    if (Tools::gainRandomNumber(0, 2) == 0) {    // Monster 先攻
        bool cnt = true;
        while (!Monster::checkIsDead() && !Enemy->checkIsDead()) {
            if (cnt)
                Enemy->setCurrentHealth(Enemy->getCurrentHealth() - MyDPs);
            else
                Monster::setCurrentHealth(Monster::getCurrentHealth() - EnemyDps);
            cnt = !cnt;
        }
    } else {   // Enemy 先攻
        bool cnt = false;
        while (!Monster::checkIsDead() && !Enemy->checkIsDead()) {
            if (cnt)
                Enemy->setCurrentHealth(Enemy->getCurrentHealth() - MyDPs);
            else
                Monster::setCurrentHealth(Monster::getCurrentHealth() - EnemyDps);
            cnt = !cnt;
        }
    }

    if (Monster::checkIsDead())
        cout << Color::Blue << Monster::getName() << " is dead\n" << Color::Default;
    else
        cout << Color::Blue << Enemy->getName() << " is dead\n" << Color::Default;
}
