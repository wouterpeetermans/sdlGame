/*
    a simple platformer game written for a shool project
    Copyright (C) 2016  Wouter Peetermans

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include "Drawable.h"

//constructor 1
Drawable::Drawable(SDL_Renderer* renderer, SDL_Surface* file ,SDL_Rect* posRect){
  SDL_Surface* dest;
  SDL_BlitSurface(file,posRect,dest,NULL);
  object = SDL_CreateTextureFromSurface(renderer,dest);
  SDL_FreeSurface(dest);
  destRect.w = posRect->w;
  destRect.h = posRect->h;
  destRect.x = 0;
  destRect.y = 0;
}
//constructor 2
Drawable::Drawable(SDL_Renderer* renderer, SDL_Surface* file ,int w ,int h ,int x ,int y){
  SDL_Rect posRect;
  posRect.w = w;
  posRect.h = h;
  posRect.x = x;
  posRect.y = y;
  SDL_Surface* dest;
  SDL_BlitSurface(file,&posRect,dest,NULL);
  object = SDL_CreateTextureFromSurface(renderer,dest);
  SDL_FreeSurface(dest);
  destRect.w = w;
  destRect.h = h;
  destRect.x = 0;
  destRect.y = 0;
}
// constructor 3
Drawable::Drawable(SDL_Renderer* renderer, SDL_Surface* file){
  SDL_Surface* dest;
  SDL_BlitSurface(file,NULL,dest,NULL);
  object = SDL_CreateTextureFromSurface(renderer,dest);
  SDL_FreeSurface(dest);
  destRect.w = dest->w;
  destRect.h = dest->h;
  destRect.x = 0;
  destRect.y = 0;
}

Drawable::~Drawable(){
  SDL_DestroyTexture(object);
}

void Drawable::Draw(SDL_Renderer* renderer) {
  SDL_RenderCopy(renderer, object, NULL, &destRect);
}
