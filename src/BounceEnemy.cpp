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
 #include "BounceEnemy.h"

 BounceEnemy::BounceEnemy(Scene* context,int xPos ,int yPos):Sprite("game/enemy.png", context){
   int lenght = 1;
   leftArray = rightArray = backArray = frontArray = NULL;
   leftArray = new SDL_Rect[lenght];
   if (leftArray == NULL) {
     std::cout << "new fail" << '\n';
   }
   rightArray = new SDL_Rect[lenght];
   if (rightArray == NULL) {
     std::cout << "new fail" << '\n';
   }
   backArray = new SDL_Rect[lenght];
   if (backArray == NULL) {
     std::cout << "new fail" << '\n';
   }
   frontArray = new SDL_Rect[lenght];
   if (frontArray == NULL) {
     std::cout << "new fail" << '\n';
   }
   int sizeCor = 20;
   for (int i = 0; i < lenght; i++) {
     SDL_Rect rect;
     rect.h = 64 - sizeCor;
     rect.w = 32;
     rect.x = 96;
     rect.y = 0+sizeCor;
     frontArray[i] = rect;
     rect.y = 64+sizeCor;
     rightArray[i] = rect;
     rect.y = 128+sizeCor;
     leftArray[i] = rect;
     rect.y = 192+sizeCor;
     backArray[i] = rect;
   }

   srcRect = frontArray;
   posRect = new SDL_Rect;
   posRect->h = 64-sizeCor;
   posRect->w = 32;
   posRect->x = xPos*32;
   posRect->y = yPos*32;
   speedVector.yZero();
   speedVector.xZero();
   Gvector initVector(0,2);
   speedVector = initVector;
 }


 void BounceEnemy::Update(unsigned int timePast, Colidable** colidables, int amountColidables){
   int seq = 0;
   switch (speedVector.xDir()) {
    case -1:
      srcRect = leftArray+seq;
      break;
    case 0:
      srcRect = frontArray;
      break;
    case 1:
      srcRect = rightArray+seq;
      break;
    default:
      break;

   }
   SDL_Rect tempPosRect = *posRect;
   int changeY = speedVector.ySpeed() * (timePast/10.0);

   bool colidedY=false;
   int biggestCollisionY = 0;
   SDL_Rect collisionRect;
   for (int i = 0; i < amountColidables; i++) {
     if (colidables[i] == this) {
       goto skip;
     }
     {
       tempPosRect.y -= changeY;
       OverlapType collisionType = colidables[i]->OverlapDetect(&tempPosRect,&collisionRect);
       if(collisionType!=OL_NO_COLLISION){
         if (collisionRect.h > biggestCollisionY) {
           biggestCollisionY = collisionRect.h;
         }
         colidedY = true;
       }
       tempPosRect.y += changeY;
     }
     skip: ;
   }
   posRect->y -= changeY;
   if (colidedY) {
     posRect->y -= biggestCollisionY * speedVector.yDir();
     speedVector.yInvert();
   }

   if (posRect->y >= 512) { //just dont drop trough the floor will maybe deleted in later stage
     speedVector.yInvert();
     posRect->y = 512;
   }
}

 void BounceEnemy::Draw(SDL_Renderer* renderer){
   SDL_RenderCopy(renderer, spriteSheet, srcRect, posRect);
 }


 OverlapType BounceEnemy::OverlapDetect(SDL_Rect* rect,SDL_Rect* resultRect){
   if (rect == posRect) {
     return OL_NO_COLLISION;
   }
   if(SDL_IntersectRect(rect,posRect,resultRect)) {
     return OL_DEADLY;
   } else {
     return OL_NO_COLLISION;
   }
 }
