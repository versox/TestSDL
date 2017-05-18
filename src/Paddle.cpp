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
   
    if(y+3 <(window->getHeight())){
        y+=3;
    }
    
   std::cout<<y<<std::endl;
}

void Paddle::moveUp(){
  
    if(y-3>0){
        y-=3;
    }
  std::cout<<y<<std::endl;
}
