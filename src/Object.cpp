#include "Object.h"

std::vector<Object*> Object::objects;

std::vector<Object*> Object::getObjects() {
  return objects;
}

Object::Object(GameWindow* window, Sprite* sprite, int x, int y) {
    this->window = window;
    this->sprite = sprite;
    sprite->setup(window, window->getRenderer());
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

void Object::render() {
    if(visible) {
        this->sprite->render(this->x, this->y);
    }
}

void Object::test() {
    std::cout << "YAY!" << std::endl;
}
