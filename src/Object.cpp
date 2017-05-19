#include "Object.h"

std::vector<Object*> Object::objects;

std::vector<Object*> Object::getObjects() {
  return objects;
}

void Object::updateObjects() {
  for(unsigned int i = 0; i < objects.size(); i++) {
    objects[i]->update();
  }
}

Object::Object(GameWindow* window, Sprite* sprite, int x, int y, int size) {
    this->window = window;
    this->sprite = sprite;
    sprite->setup(window, window->getRenderer());
    this->x = x;
    this->y = y;
    this->size = size;
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

int Object::getObjectID() {
  return objectID;
}

void Object::update() {

}

void Object::render() {
    if(visible) {
        this->sprite->render(this->x, this->y, size);
    }
}
