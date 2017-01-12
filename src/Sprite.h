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
#ifndef _Sprite
#define _Sprite 1
#include "Drawable.h"
#include "Scene.h"
#include "Gvector.h"


class Sprite:Drawable {
protected:
	SDL_Texture* spriteSheet;

	SDL_Rect* leftArray;
	SDL_Rect* rightArray;
	SDL_Rect* backArray;
	SDL_Rect* frontArray;
	SDL_Rect* srcRect;
	SDL_Rect* posRect;
	Gvector speedVector;


public:
	Sprite(std::string, Scene*);
	~Sprite();
	virtual void Update(unsigned int)=0;
};



#endif
