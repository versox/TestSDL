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
#include "GameWindow.h"

//class GameWindow;

class Object {
//Static
public:
    static Object* getObject(int objectID);
    static std::vector<Object*> getObjects();
    static void updateObjects();
private:
    static std::vector<Object*> objects;
//Object
public:
    Object(GameWindow* window, Sprite* sprite, int x, int y, int size = 1);
    virtual ~Object();
    int getObjectID();
    virtual void setup();
    virtual void update();
    virtual void render();
    Sprite* getSprite();
    int x;
    int y;
private:
    int objectID;
    Sprite* sprite;
    int size;
    int width;
    int height;
    bool visible;

protected:
    GameWindow* window;
};

#endif	/* OBJECT_H */
