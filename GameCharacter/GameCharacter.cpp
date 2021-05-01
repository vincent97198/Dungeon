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

GameCharacter::GameCharacter(string name, string tag, int maxHealth, int attack, int defense) : Object(name, tag) {
    GameCharacter::maxHealth = maxHealth;
    GameCharacter::currentHealth = GameCharacter::maxHealth;
    GameCharacter::attack = attack;
    GameCharacter::defense = defense;
}

void GameCharacter::triggleEvent(GameCharacter * tmp) {}