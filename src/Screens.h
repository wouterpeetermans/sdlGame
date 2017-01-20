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

 #ifndef Screens
 #define Screens 1
 #include "Level.h"
 class Screen: public Level{
 public:
   Screen(Scene*,std::string);
   void Update(unsigned int);
   void Draw(SDL_Renderer*);
   void GetKeys(SDL_Event*);
   void CreateMap();
   bool Done();
 };
 #endif
