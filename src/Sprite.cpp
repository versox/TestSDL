/* 
 * File:   Sprite.cpp
 * Author: mathp0455
 * 
 * Created on May 10, 2017, 10:21 AM
 */

#include "Sprite.h"

Sprite::Sprite() {
}

Sprite::Sprite(const Sprite& orig) {
}

Sprite::~Sprite() {
    free();
}

void Sprite::render(int xPos, int yPos, SDL_Rect* sprite = NULL){
    SDL_Rect renderSpace = {xPos, yPos, mWidth, mHeight};
    
    if(sprite!=NULL){
        renderSpace.w=sprite->w;
        renderSpace.h=sprite->h;
        
        SDL_RenderCopy(renderer, mTexture, sprite, &renderSpace);
    }
}

bool Sprite::getFromFile(std::string path){
    free();
    SDL_Texture* newTex=NULL;
    SDL_Surface* loadSurface = IMG_Load(path.c_str());
}