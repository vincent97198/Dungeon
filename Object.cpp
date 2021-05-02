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
    os << "Name: \n" << Object::name << '\n'
       << "Tag: \n" << Object::tag << '\n';
}