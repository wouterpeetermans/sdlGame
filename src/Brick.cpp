/*
    a simple platformer game written for a shool project
    Copyright (C) 2016  Wouter Peetermans

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "Brick.h"


Brick::Brick(Scene* context,int xpos ,int ypos):Background(context,"game/castle.png"){
  init(xpos,ypos);
}
Brick::Brick(SDL_Texture* texture,int xpos,int ypos):Background(texture){
  init(xpos,ypos);
}

void Brick::init(int x , int y){
  srcRect.h = 64;
  srcRect.w = 64;
  srcRect.x = 0;
  srcRect.y = 192;
  posRect.h = 32;
  posRect.w = 32;
  posRect.x = x*32;
  posRect.y = y*32;
  colRect = &posRect;
}
void Brick::Draw(SDL_Renderer* renderer){
  SDL_RenderCopy(renderer, blockSheet, &srcRect, &posRect);
}
OverlapType Brick::OverlapDetect(SDL_Rect* rect,SDL_Rect* resultRect){
  if(SDL_IntersectRect(rect,colRect,resultRect)) {
    return OL_COLLISION;
  } else {
    return OL_NO_COLLISION;
  }
}
