#include "GameCharacter.h"
#include <climits>

int GameCharacter::getMaxHealth() const {
    return maxHealth;
}

void GameCharacter::setMaxHealth(int maxHealth) {
    GameCharacter::maxHealth = maxHealth;
}

int GameCharacter::getCurrentHealth() const {
    return currentHealth;
}

void GameCharacter::setCurrentHealth(int currentHealth) {
    GameCharacter::currentHealth = currentHealth;
}

int GameCharacter::getAttack() const {
    return attack;
}

void GameCharacter::setAttack(int attack) {
    GameCharacter::attack = attack;
}

int GameCharacter::getDefense() const {
    return defense;
}

void GameCharacter::setDefense(int defense) {
    GameCharacter::defense = defense;
}

bool GameCharacter::checkIsDead() {
    return GameCharacter::currentHealth <= 0;
}

GameCharacter::GameCharacter() : Object("UNKNOWN", "GameCharacter") {
    const int INF = INT_MAX;

    GameCharacter::maxHealth = INF;
    GameCharacter::currentHealth = INF;
    GameCharacter::attack = INF;
    GameCharacter::defense = INF;
}

GameCharacter::GameCharacter(string name, string tag, int maxHealth, int attack, int defense, int speed) : Object(name,
                                                                                                                  tag) {
    GameCharacter::maxHealth = maxHealth;
    GameCharacter::currentHealth = GameCharacter::maxHealth;
    GameCharacter::attack = attack;
    GameCharacter::defense = defense;
    GameCharacter::speed = speed;
}

void GameCharacter::saveFile(ofstream &os) {
    Object base = *this;
    base.saveFile(os);

    os << currentHealth << '\n'
       << maxHealth << '\n'
       << attack << '\n'
       << defense << '\n'
       << speed << '\n';
}

void GameCharacter::loadFile(ifstream &os) {
    Object *base = new Object();
    base->loadFile(os);
    this->setName(base->getName());
    this->setTag(base->getTag());

    os >> currentHealth
       >> maxHealth
       >> attack
       >> defense
       >> speed;
}

int GameCharacter::getSpeed() const {
    return speed;
}

void GameCharacter::setSpeed(int speed) {
    GameCharacter::speed = speed;
}

void GameCharacter::Show_status() {
    cout << endl;
    cout << Color::Blue << "=======Detail=======" << Color::Default << '\n'
         << "Name: " << Color::Yellow << GameCharacter::getName() << '\n' << Color::Default
         << endl;
}
