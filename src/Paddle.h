/* 
 * File:   Paddle.h
 * Author: mathp0455
 *
 * Created on May 16, 2017, 10:10 AM
 */

#ifndef PADDLE_H
#define	PADDLE_H
#include"Object.h"

class Paddle : public Object{
public:
    Paddle(GameWindow* window, Sprite* sprite, int x, int y);
    virtual ~Paddle();
    void moveDown();
    void moveUp();
private:
    int xPos, yPos;
};

#endif	/* PADDLE_H */

