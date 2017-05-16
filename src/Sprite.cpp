/*
 * File:   Sprite.cpp
 * Author: mathp0455
 *
 * Created on May 10, 2017, 10:21 AM
 */

#include "Sprite.h"

Sprite::Sprite(std::string path) {
  this->path = path;
  texture = NULL;
}

Sprite::Sprite(const Sprite& orig) {
}

Sprite::~Sprite() {
  SDL_DestroyTexture(texture);
}

void Sprite::setup(GameWindow* window, SDL_Renderer* renderer) {
  this->window = window;
  this->renderer = renderer;

  SDL_Surface* surface = IMG_Load(path.c_str());
  if( surface == NULL )
  {
    printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
  }
  texture = SDL_CreateTextureFromSurface(renderer, surface);
  if( texture == NULL ) {
    printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
  }
  SDL_FreeSurface( surface );
}

void Sprite::render(int xPos, int yPos) {
  SDL_RenderCopy(renderer, texture, NULL, NULL);
}
