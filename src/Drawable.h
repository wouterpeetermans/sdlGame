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
#ifndef _Drawable
#define _Drawable 1
#include <SDL2/SDL.h>  //import the main SDL library
#include <SDL2/SDL_image.h>  // import the image convorting part of SDL
#include <iostream> //give me some c++ powers like string support and cout

class Drawable {
private:
  SDL_Texture* object;//the actual texture this class is all about
public:
  Drawable(SDL_Renderer*, SDL_Surface*, SDL_Rect*);
  Drawable(SDL_Renderer*, SDL_Surface*, int, int, int, int);
  Drawable(SDL_Renderer*, SDL_Surface*);
  ~Drawable();
};


#endif
