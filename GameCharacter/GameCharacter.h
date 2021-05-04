#ifndef GAMECHARACTER_H_INCLUDED
#define GAMECHARACTER_H_INCLUDED

#include <iostream>
#include <string>
#include "Object.h"
#include "Others/consoleColor.h"

using namespace std;

class GameCharacter : public Object {
private:
    int maxHealth;
    int currentHealth;
    int attack;
    int defense;
    int speed;
public:

    int getSpeed() const;

    void setSpeed(int speed);

    int getMaxHealth() const;

    void setMaxHealth(int maxHealth);

    int getCurrentHealth() const;

    void setCurrentHealth(int currentHealth);

    int getAttack() const;

    void setAttack(int attack);

    int getDefense() const;

    void setDefense(int defense);

    GameCharacter();

    GameCharacter(string, string, int, int, int, int);

    ~GameCharacter() = default;

    bool checkIsDead();

    void saveFile(ofstream &);

    void loadFile(ifstream &);

    void Show_Status(ostream &) const;
};

#endif // GAMECHARACTER_H_INCLUDED
