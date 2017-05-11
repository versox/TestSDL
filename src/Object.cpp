/*
 * File:   Object.cpp
 * Author: cassc6073
 *
 * Created on May 10, 2017, 10:11 AM
 */

#include "Object.h"

std::vector<Object*> Object::objects;

Object::Object(Sprite* s, int x, int y) {
    sprite = s;
    this->x = x;
    this->y = y;
    visible = true;

    objectID = objects.size();
    objects.push_back(this);
}

Object::~Object() {
    objects.erase(objects.begin() + 5);
}

Object* Object::getObject(int objectID) {
  return objects.at(objectID);
}

void Object::update() {

}

void Object::draw() {
    if(visible) {
        this->sprite->render(this->x, this->y, NULL);
    }
}

void Object::test() {
    std::cout << "YAY!" << std::endl;
}
