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
#ifndef _unmovable
#define _unmovable 1
#include "Drawable.h"

class UnMovable: public Drawable {
protected:
  SDL_Rect* colideRect = NULL;

public:
  UnMovable(SDL_Renderer*, SDL_Texture*, SDL_Rect*);
  UnMovable(SDL_Renderer*, SDL_Texture*, int, int, int, int);
  ~UnMovable();
  void SetColidable(SDL_Rect*);
  OverlapType OverlapDetect(SDL_Rect*);
};






#endif
