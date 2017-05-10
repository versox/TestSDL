/* 
 * File:   Object.cpp
 * Author: cassc6073
 * 
 * Created on May 10, 2017, 10:11 AM
 */

#include "Object.h"
#include "Sprite.h"

Object::Object(Sprite* s, int x, int y) {
    sprite = s;
    this->x = x;
    this->y = y;
    visible = true;
}

Object::~Object() {
}

void Object::update() {
    
}

void Object::draw() {
    if(visible) {
        //sprite->render(x, y, NULL);
    }
}

