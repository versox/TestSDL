/* 
 * File:   Object.h
 * Author: cassc6073
 *
 * Created on May 10, 2017, 10:11 AM
 */

#ifndef OBJECT_H
#define	OBJECT_H

#include "Sprite.h"

class Object {
public:
    Object(Sprite* s, int x, int y);
    virtual ~Object();
    void update();
    void draw();
private:
    Sprite* sprite;
    int x;
    int y;
    int width;
    int height;
    bool visible;

};

#endif	/* OBJECT_H */

