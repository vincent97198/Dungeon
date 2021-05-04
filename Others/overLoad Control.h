#ifndef NEW_OVERLOAD_CONTROL_H
#define NEW_OVERLOAD_CONTROL_H

#include <fstream>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

ifstream &operator>>(ifstream &os, int &ret);

ifstream &operator>>(ifstream &os, bool &ret);

ifstream &operator>>(ifstream &os, string &ret);

#endif //NEW_OVERLOAD_CONTROL_H
