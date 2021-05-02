#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "Others/consoleColor.h"
#include "Others/programming_Tools.h"
#include "GameCharacter.h"
#include "Player.h"

using namespace std;

class Monster : public GameCharacter {
private:
    string SAY;
public:
    Monster();

    Monster(string, string, int, int, int);

    ~Monster() = default; //亂寫

    void triggerEvent(GameCharacter *);

    void saveFile(ofstream& os);
};


#endif // ENEMY_H_INCLUDED
