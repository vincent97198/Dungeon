#ifndef NEW_ASK_H
#define NEW_ASK_H

#include <string>
#include <map>
#include <algorithm>
#include "Object.h"
#include "Others/programming_Tools.h"
#include "consoleColor.h"

namespace Ask {
    char Ask_oneAlphabet(string output, map<char, string> &MAP);

    char Ask_oneAlphabet_Object(string output, map<char, Object *> &MAP);

    void Ask_multi_int(string output, map<int, Object *> &MAP, vector<int> &outputType);
};


#endif //NEW_ASK_H
