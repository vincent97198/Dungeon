#include "Object.h"

const string &Object::getName() const {
    return name;
}

void Object::setName(const string &name) {
    Object::name = name;
}

const string &Object::getTag() const {
    return tag;
}

void Object::setTag(const string &tag) {
    Object::tag = tag;
}

Object::Object() {
    name = "";
    tag = "";
}

Object::Object(string name, string tag) {
    Object::name = name;
    Object::tag = tag;
}

bool Object::operator<(const Object &object) const {
    return this->getName() < object.getName();
}

void Object::saveFile(ofstream &os) {
    os << Object::name << '\n'
       << Object::tag << '\n';
}

void Object::loadFile(ifstream &os) {
    os >> name
       >> tag;
}

void Object::Show_Status(ostream &os) const {
    os << endl;
    os << Color::Blue << "=======Object=======" << Color::Default << '\n'
       << "Name: " << Color::Yellow << Object::getName() << '\n' << Color::Default
       << Color::Blue << "====================" << Color::Default << '\n'
       << endl;
}

ostream &operator<<(ostream &os, Object *item) {
    if (item == nullptr)
        os << Color::Cyan << "Empty" << Color::Default;
    else
        item->Show_Status(os);
    return os;
}