#ifndef NEW_PROGRAMMING_TOOLS_H
#define NEW_PROGRAMMING_TOOLS_H

#include <string>
#include <iostream>
#include <map>
#include <random>
#include <time.h>
#include <sstream>
#include <set>
#include "consoleColor.h"
#include "Item.h"

using namespace std;

namespace Tools {

    extern mt19937_64 RANDOM;

    void stringToUpper(string &str);

    int stringToint(string &str);

    bool check_input_logic_oneAlphabet(string &input, map<char, string> &Map);

    bool check_input_logic_multi_int(string &input, map<int, Object *> &Map);

    bool check_input_logic_oneAlphabet_Object(string &input,map<char,Object*> &MAP);

    int gainRandomNumber(int RangeL, int RangeR);

    int CeilDiv(int A, int B);
}

#endif //NEW_PROGRAMMING_TOOLS_H
