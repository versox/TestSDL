/*
 * File:   Object.h
 * Author: cassc6073
 *
 * Created on May 10, 2017, 10:11 AM
 */

#ifndef OBJECT_H
#define	OBJECT_H

#include <iostream>
#include <vector>
#include "SDL.h"
#include "Sprite.h"

class Object {
public:
    static Object* getObject(int objectID);

    Object(Sprite* s, int x, int y);
    virtual ~Object();
    int getObjectID();
    virtual void update();
    void draw();
    void test();
private:
    static std::vector<Object*> objects;

    Sprite* sprite;
    int x;
    int y;
    int width;
    int height;
    bool visible;
    int objectID;
};

#endif	/* OBJECT_H */
