#ifndef OBJECT_H_INCLUDED
#define OBJECT_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>

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

    virtual ~Object() = default;

};

#endif // OBJECT_H_INCLUDED
