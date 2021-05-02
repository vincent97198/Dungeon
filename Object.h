#ifndef OBJECT_H_INCLUDED
#define OBJECT_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

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

    void saveFile(ofstream& os);

};

#endif // OBJECT_H_INCLUDED
