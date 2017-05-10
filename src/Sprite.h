/* 
 * File:   Sprite.h
 * Author: mathp0455
 *
 * Created on May 10, 2017, 10:21 AM
 */

#ifndef SPRITE_H
#define	SPRITE_H
#include "SDL.h"
#include <cstdlib>
#include <string>
class Sprite {
public:
    Sprite();
    Sprite(const Sprite& orig);
    virtual ~Sprite();
    
    bool getFromFile(std::string path);
    //deallocates space
    void freeSpace();
    //Renders textures at specific point
    void render(int xPos, int yPos, SDL_Rect* sprite=NULL);
    //gets sheet dimensions
    int getWidth();
    int getHeight();
private:
    SDL_Texture* mTexture;
    
    int mHeight;
    int mWidth;
};

#endif	/* SPRITE_H */

