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

 #ifndef _Background
 #define _Background 1
 #include "Colidable.h"
 #include "Drawable.h"
 #include "Scene.h"


 class Background:Drawable , Colidable {
 protected:
   SDL_Texture* blockSheet;
   SDL_Rect* srcRect;
   SDL_Rect* posRect;

 public:
   Background(Scene*,std::string);
   Background(SDL_Texture*);
   virtual void Draw(SDL_Renderer*)=0;
   virtual OverlapType OverlapDetect(const SDL_Rect& , const Gvector& ,int*,int*);
 };



 #endif
