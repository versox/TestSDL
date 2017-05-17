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
    Sprite(std::string path, double scale = 1);
    Sprite(const Sprite& orig);
    virtual ~Sprite();
    void setup(GameWindow* window, SDL_Renderer* renderer);
    //deallocates space
    void freeSpace();
    //Renders textures at specific point
    void render(int xPos, int yPos, int size);
    //gets sheet dimensions
    double getWidth();
    double getHeight();
    int getActualWidth();
    int getActualHeight();
    void setScale(int scale);
private:
    std::string path;
    GameWindow* window;
    SDL_Renderer* renderer;
    SDL_Texture* texture;

    double width;
    double height;
    int actualWidth;
    int actualHeight;
    double scale;
};

#endif	/* SPRITE_H */
