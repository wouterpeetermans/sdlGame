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

#include "Level.h"
#include "Brick.h"
#include "Enemy.h"

Level::Level(Scene* context){
  player = new Hero(context,1,5);
}

Level::~Level(){
  delete[]tileArray;

}


void Level::DrawMap(Scene* context){
  amountEnemies = 0;
  amountObjects = 0;
  mapTexture = context->CreateTexture(mapWidth*32,mapHeight*32);
  levelTexture = context->CreateTexture(mapWidth*32,mapHeight*32);
  for (int i = 0; i < (mapWidth*mapHeight); i++) {
    if (tileArray[i]>1) {
      amountObjects++;
    }
    if (tileArray[i]==1) {
      amountEnemies++;
    }
  }
  colidables = new Colidable*[amountObjects+amountEnemies];
  enemies = new Sprite*[amountEnemies];
  Drawable** d = new Drawable*[amountObjects];
  SDL_Texture* blockSheet = context->LoadTexture("game/castle.png");
  int objectStep = 0;
  int enemieStep = 0;
  for (int i = 0; i < mapHeight; i++) {
    for (int j = 0; j < mapWidth; j++) {
      switch (tileArray[(i*mapWidth)+j]) {
        case 0:
          //do nothing
          break;
        case 1:{
          Enemy* badGuy = new Enemy(context,j,i);
          colidables[objectStep+enemieStep] = badGuy;
          enemies[enemieStep] = badGuy;
          enemieStep++;
          break;
        }
        case 2:{
          //make a brick
          Brick* b = new Brick(blockSheet,j,i);
          colidables[objectStep+enemieStep] = b;
          d[objectStep] = b;
          objectStep++;
          break;
        }
        default:
          break;
      }
    }
  }


  SDL_Renderer* r = context->GetRenderer();
  SDL_SetRenderTarget(r, mapTexture);
  for (int i = 0; i < amountObjects; i++) {
    d[i]->Draw(r);
  }
  SDL_SetRenderTarget(r, NULL);
  delete[] d;
}

void Level::GetKeys(SDL_Event *e){
  player->GetKeys(e);
}

void Level::Update(unsigned int timePast){
  for (int i = 0; i < amountEnemies; i++) {
    enemies[i]->Update(timePast, colidables, (amountObjects+amountEnemies));
  }
  player->Update(timePast, colidables, (amountObjects+amountEnemies));
}

void Level::Draw(SDL_Renderer * renderer){
  SDL_SetRenderTarget(renderer, levelTexture);
  SDL_Rect src, dest;
  dest.h = src.h = mapHeight*32;
  dest.w = src.w = mapWidth*32;
  dest.x = src.x = dest.y = src.y = 0;
  SDL_RenderCopy(renderer, mapTexture,&src,&dest);
  for (int i = 0; i < amountEnemies; i++) {
    enemies[i]->Draw(renderer);
  }
  player->Draw(renderer);
  SDL_SetRenderTarget(renderer,NULL);
  SDL_Rect viewport;
  viewport.h = window_Height;
  viewport.w = window_Width;
  viewport.y = 0;
  int playerPos = player->GetPos();
  if (playerPos>(window_Width/2)) {
    if (playerPos>(mapWidth*32)-(window_Width/2)) {
      viewport.x = (mapWidth*32)-window_Width;
    } else {
      viewport.x = playerPos-(window_Width/2);
    }
  } else {
    viewport.x = 0;
  }
  SDL_RenderCopy(renderer, levelTexture, &viewport, NULL);
}