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
Drawable::Drawable(SDL_Renderer* renderer, SDL_Texture* texture ,SDL_Rect* rect){
  file = texture;
  posRect = rect;
  destRect = new SDL_Rect;
  destRect->w = posRect->w;
  destRect->h = posRect->h;
  destRect->x = 0;
  destRect->y = 0;
}
//constructor 2
Drawable::Drawable(SDL_Renderer* renderer, SDL_Texture* texture ,int w ,int h ,int x ,int y){
  file = texture;
  posRect = new SDL_Rect;
  posRect->w = w;
  posRect->h = h;
  posRect->x = x;
  posRect->y = y;
  destRect = new SDL_Rect;
  destRect->w = posRect->w;
  destRect->h = posRect->h;
  destRect->x = 0;
  destRect->y = 0;
}


Drawable::~Drawable(){
  delete destRect;
  delete posRect;
  file = NULL;
}

void Drawable::Draw(SDL_Renderer* renderer) {
  SDL_RenderCopy(renderer, file, posRect, destRect);
}

void Drawable::SetPos(int x, int y){
  destRect->x = x;
  destRect->y = y;
}
