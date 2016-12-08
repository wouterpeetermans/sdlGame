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
#include "UnMovable.h"


UnMovable::UnMovable(SDL_Renderer* renderer, SDL_Texture* texture ,SDL_Rect* rect):Drawable(renderer, texture, rect){
  
}

UnMovable::UnMovable(SDL_Renderer* renderer, SDL_Texture* texture ,int w ,int h ,int x ,int y):Drawable(renderer, texture , w , h , x , y){

}

UnMovable::~UnMovable(){

}