/* 
 * File:   Paddle.cpp
 * Author: mathp0455
 * 
 * Created on May 16, 2017, 10:10 AM
 */

#include "Paddle.h"
#include "EventHandler.h"

Paddle::Paddle(GameWindow* window, Sprite* sprite, int x, int y) : Object(window, sprite,  x, y) {
    xPos = x;
    yPos = y;
    
}


Paddle::~Paddle() {
}

void Paddle::moveDown(){
    yPos-=5;
    if(yPos<0){
        yPos=0;
    }
    
}

void Paddle::moveUp(){
    yPos+=5;
    if(yPos>500){
        yPos=500;
    }
    
}