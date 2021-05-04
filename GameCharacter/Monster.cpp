#include "Monster.h"

Monster::Monster()
        : GameCharacter("UNKNOWN_Monster", "danger_monster", INT16_MAX, INT16_MAX, INT16_MAX, 10) {
    this->SAY = "Hello, I'm Monster";
}

Monster::Monster(string name, string SAY, int health, int attack, int defense, int speed)
        : GameCharacter(name, "danger_monster", health, attack, defense, speed),
          SAY(SAY) {}

void Monster::triggerEvent(GameCharacter *Enemy) {
    cout << Color::Green << Monster::SAY << Color::Default << '\n';

    int MyDPs = max(0, Monster::getAttack() - Enemy->getDefense()),
            EnemyDps = max(0, Enemy->getAttack() - Monster::getDefense());

    if (Tools::gainRandomNumber(0, Monster::getSpeed() + Enemy->getSpeed()) < Monster::getSpeed()) {    // Monster 先攻
        bool cnt = true;
        while (!Monster::checkIsDead() && !Enemy->checkIsDead()) {
            if (cnt)
                Enemy->setCurrentHealth(Enemy->getCurrentHealth() - MyDPs * Tools::gainRandomNumber(8, 12) / 10);
            else
                Monster::setCurrentHealth(
                        Monster::getCurrentHealth() - EnemyDps * Tools::gainRandomNumber(8, 12) / 10);
            cnt = !cnt;
        }
    } else {   // Enemy 先攻
        bool cnt = false;
        while (!Monster::checkIsDead() && !Enemy->checkIsDead()) {
            if (cnt)
                Enemy->setCurrentHealth(Enemy->getCurrentHealth() - MyDPs * Tools::gainRandomNumber(8, 12) / 10);
            else
                Monster::setCurrentHealth(
                        Monster::getCurrentHealth() - EnemyDps * Tools::gainRandomNumber(8, 12) / 10);
            cnt = !cnt;
        }
    }

    if (Monster::checkIsDead())
        cout << Color::Blue << Monster::getName() << " is dead\n" << Color::Default;
    else
        cout << Color::Blue << Enemy->getName() << " is dead\n" << Color::Default;
}

void Monster::saveFile(ofstream &os) {
    GameCharacter base = *this;
    base.saveFile(os);

    os << SAY << '\n';
}

void Monster::loadFile(ifstream &os) {
    GameCharacter *base = new GameCharacter();
    base->loadFile(os);
    this->setMaxHealth(base->getMaxHealth());
    this->setCurrentHealth(base->getCurrentHealth());
    this->setAttack(base->getAttack());
    this->setDefense(base->getDefense());
    this->setName(base->getName());
    this->setTag(base->getTag());

    os >> SAY;
}

void Monster::Show_Status(ostream &os) const {
    os << endl;
    os << Color::Blue << "=======Monster=======" << Color::Default << '\n'
       << "Name: " << Color::Yellow << Monster::getName() << '\n' << Color::Default
       << "Health: " << Monster::getCurrentHealth() << '/' << Monster::getMaxHealth() << '\n'
       << "Attack: " << Monster::getAttack() << '\n'
       << "Defense: " << Monster::getDefense() << '\n'
       << "Speed: " << Monster::getSpeed() << '\n'
       << Color::Blue << "====================" << Color::Default << '\n'
       << endl;
}