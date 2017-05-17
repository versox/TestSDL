/*
 * File:   Paddle.cpp
 * Author: mathp0455
 *
 * Created on May 16, 2017, 10:10 AM
 */

#include "Paddle.h"
#include "EventHandler.h"

Paddle::Paddle(GameWindow* window, Sprite* sprite, int x, int y) : Object(window, sprite,  x, y, 1) {

}


Paddle::~Paddle() {
}

void Paddle::moveDown(){
  /*  yPos-=15;
    if(yPos<0){
        yPos=0;
    } */
    y+=15;
}

void Paddle::moveUp(){
  y-=15;
  /*  yPos+=15;
    if(yPos>500){
        yPos=500;
    } */

}
