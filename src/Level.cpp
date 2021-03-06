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
#include "BounceEnemy.h"
#include "SpikesUp.h"
#include "Door.h"

Level::Level(){

}

Level::Level(Scene* context){
  player = NULL;
  player = new Hero(context,1,5);
  if (player == NULL) {
    std::cout << "new failed" << '\n';
  }
  isDone = false;
}

Level::~Level(){
  //delete[]tileArray;
}


void Level::DrawMap(Scene* context){
  amountEnemies = 0;
  amountObjects = 0;
  mapTexture = context->CreateTexture(mapWidth*32,mapHeight*32);
  levelTexture = context->CreateTexture(mapWidth*32,mapHeight*32);
  for (int i = 0; i < (mapWidth*mapHeight); i++) {
    if (tileArray[i]>2) {
      amountObjects++;
    }
    if (tileArray[i]==1) {
      amountEnemies++;
    }
    if (tileArray[i]==2) {
      amountEnemies++;
    }
  }
  colidables = NULL;
  enemies = NULL;
  colidables = new Colidable*[amountObjects+amountEnemies];
  if (colidables == NULL) {
    std::cout << "new failed" << '\n';
  }
  enemies = new Sprite*[amountEnemies];
  if (enemies == NULL) {
    std::cout << "new failed" << '\n';
  }
  Drawable** d = NULL;
  d = new Drawable*[amountObjects];
  if (d == NULL) {
    std::cout << "new failed" << '\n';
  }
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
          Enemy* badGuy = NULL;
          badGuy = new Enemy(context,j,i);
          if (badGuy == NULL) {
            std::cout << "new failed" << '\n';
          }
          colidables[objectStep+enemieStep] = badGuy;
          enemies[enemieStep] = badGuy;
          enemieStep++;
          break;
        }
        case 2:{
          BounceEnemy* bouncer = NULL;
          bouncer = new BounceEnemy(context,j,i);
          if (bouncer == NULL) {
            std::cout << "new failed" << '\n';
          }
          colidables[objectStep+enemieStep] = bouncer;
          enemies[enemieStep] = bouncer;
          enemieStep++;
          break;
        }
        case 3:{
          //make a brick
          Brick* b = NULL;
          b = new Brick(blockSheet,j,i);
          if (b == NULL) {
            std::cout << "new failed" << '\n';
          }
          colidables[objectStep+enemieStep] = b;
          d[objectStep] = b;
          objectStep++;
          break;
        }
        case 4:{
          SpikesUp* s = NULL;
          s = new SpikesUp(blockSheet,j,i);
          if (s == NULL) {
            std::cout << "new failed" << '\n';
          }
          colidables[objectStep+enemieStep] = s;
          d[objectStep] = s;
          objectStep++;
          break;
        }
        case 5:{
          Door* door = NULL;
          door = new Door(blockSheet,j,i);
          if (door == NULL) {
            std::cout << "new failed" << '\n';
          }
          colidables[objectStep+enemieStep] = door;
          d[objectStep] = door;
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
  SDL_RenderClear(r);
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
  if (!player->IsAlive()) {
    player->SetPos(1, 5);
    player->SetAlive();
  }
  if (player->Done()) {
    isDone = true;
  }
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
  SDL_Rect miniMapRect;
  miniMapRect.h =(mapHeight*32)/8;
  miniMapRect.w =(mapWidth*32)/8;
  miniMapRect.x = 0;
  miniMapRect.y = 0;
  SDL_RenderCopy(renderer, levelTexture, &viewport, NULL);
  SDL_RenderCopy(renderer, levelTexture, NULL, &miniMapRect);
}
