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

#include "SpikesUp.h"


SpikesUp::SpikesUp(SDL_Texture* texture,int xpos,int ypos):Background(texture){
  int corSize = 10;
  int corSizeX = 20;
  srcRect.h = 32 - corSize;
  srcRect.w = 64 -corSizeX;
  srcRect.x = 192 +(corSizeX/2);
  srcRect.y = 160 + corSize;
  posRect.h = 32;
  posRect.w = 32;
  posRect.x = xpos*32;
  posRect.y = ypos*32;
}
SpikesUp::~SpikesUp(){
}


void SpikesUp::Draw(SDL_Renderer* renderer){
  SDL_RenderCopy(renderer, blockSheet, &srcRect, &posRect);
}
OverlapType SpikesUp::OverlapDetect(SDL_Rect* rect,SDL_Rect* resultRect){
  if(SDL_IntersectRect(rect,&posRect,resultRect)) {
    return OL_DEADLY;
  } else {
    return OL_NO_COLLISION;
  }
}
