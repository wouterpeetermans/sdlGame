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

#ifndef _Level
#define _Level 1
#include "Hero.h"

class Level {
protected:
  SDL_Texture* mapTexture;
  Colidable** colidables;
  Sprite** enemies;
  Hero* player;
  int amountObjects;
  int amountEnemies;
  int* tileArray;
  int mapWidth;
  int mapHeight;
  virtual void CreateMap()=0;
  virtual void DrawMap(Scene*);
public:
  Level(Scene*);
  ~Level();
  virtual void Update(unsigned int);
  virtual void Draw(SDL_Renderer*);
  virtual void GetKeys(SDL_Event*);
  virtual Colidable** GetColidables(){return colidables;};
  virtual int GetAmountColidables(){return amountObjects+amountEnemies;}
};








#endif
