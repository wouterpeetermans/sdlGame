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
#include "Screens.h"

Screen::Screen(Scene* context,std::string file){
  levelTexture = context->LoadTexture(file);
  isDone = false;
}

void Screen::GetKeys(SDL_Event * e){
  if(e->type == SDL_KEYDOWN) {//keys pressed
    switch (e->key.keysym.sym) {
      case SDLK_RETURN:
        isDone = true;
      break;
      default:
      //do nothing
      break;
    }
  }
}

void Screen::CreateMap(){
  tileArray = new int[2];
}

void Screen::Draw(SDL_Renderer* r){
  SDL_RenderCopy(r, levelTexture, NULL, NULL);
}

void Screen::Update(unsigned int time){

}

bool Screen::Done(){
  if (isDone) {
    isDone = false;
    return true;
  } else {
    return false;
  }
}
