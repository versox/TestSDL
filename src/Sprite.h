/*
 * File:   Sprite.h
 * Author: mathp0455
 *
 * Created on May 10, 2017, 10:21 AM
 */

#ifndef SPRITE_H
#define	SPRITE_H

#include <cstdio>
#include <string>
#include "SDL.h"
#include "SDL_image.h"

class GameWindow;

class Sprite {
public:
    Sprite(std::string path);
    Sprite(const Sprite& orig);
    virtual ~Sprite();
    void setup(GameWindow* window, SDL_Renderer* renderer);
    //deallocates space
    void freeSpace();
    //Renders textures at specific point
    void render(int xPos, int yPos);
    //gets sheet dimensions
    int getWidth();
    int getHeight();
private:
    std::string path;
    GameWindow* window;
    SDL_Renderer* renderer;
    SDL_Texture* texture;

    int width;
    int height;
};

#endif	/* SPRITE_H */
