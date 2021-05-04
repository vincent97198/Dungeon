#ifndef OBJECT_H_INCLUDED
#define OBJECT_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "Others/overLoad Control.h"
#include "Others/consoleScreen.h"
#include "Others/consoleColor.h"

using namespace std;

class Object {
private:
    string name;
    string tag;
public:
    const string &getName() const;

    void setName(const string &name);

    const string &getTag() const;

    void setTag(const string &tag);

    Object();

    Object(string, string);

    bool operator<(const Object &) const;

    virtual ~Object() = default;

    virtual void saveFile(ofstream &os);

    virtual void loadFile(ifstream &);

    virtual void Show_Status(ostream &) const;

    friend ostream &operator<<(ostream &os, Object *item);
};

#endif // OBJECT_H_INCLUDED
