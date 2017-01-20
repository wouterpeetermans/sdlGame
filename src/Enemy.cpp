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

 #include "Enemy.h"

 Enemy::Enemy(Scene* context,int xPos ,int yPos):Sprite("game/enemy.png", context){
   int lenght = 3;
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
   int sizeCor = 25;
   for (int i = 0; i < lenght; i++) {
     SDL_Rect rect;
     rect.h = 64 - sizeCor;
     rect.w = 32;
     rect.x = i*32;
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
   Gvector initVector(-1,0);
   speedVector = initVector;
 }


 void Enemy::Update(unsigned int timePast, Colidable** colidables, int amountColidables){
   Gvector gravityVector(0,-1);
   if(seqb<2){
     seqb++;
   }
   else{
     seqb = 0;
   }
   int seq = seqb;
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
   int changeX = speedVector.xSpeed() * (timePast/10.0);
   int changeY = speedVector.ySpeed() * (timePast/10.0);

   bool colidedX=false , colidedY=false;
   int biggestCollisionX = 0 , biggestCollisionY = 0;
   SDL_Rect collisionRect;
   for (int i = 0; i < amountColidables; i++) {
     if (colidables[i] == this) {
       goto skip;
     }
     {
       tempPosRect.x += changeX;
       OverlapType collisionType = colidables[i]->OverlapDetect(&tempPosRect,&collisionRect);
       if(collisionType!=OL_NO_COLLISION){
         if (collisionRect.w > biggestCollisionX) {
           biggestCollisionX = collisionRect.w;
         }
         colidedX = true;
       }
       tempPosRect.x -= changeX;
       tempPosRect.y -= changeY;
       collisionType = colidables[i]->OverlapDetect(&tempPosRect,&collisionRect);
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
   posRect->x += changeX;
   posRect->y -= changeY;
   if (colidedX) {
     posRect->x += biggestCollisionX * speedVector.xDir();
     speedVector.xInvert();
   }
   if (colidedY) {
     posRect->y -= biggestCollisionY * speedVector.yDir();
     speedVector.yZero();
   }
   if(speedVector.ySpeed()>(-7)){
     speedVector += (gravityVector * (timePast/10.0));
   }
   if (posRect->y >= 512) { //just dont drop trough the floor will maybe deleted in later stage
     speedVector.yZero();
     posRect->y = 512;
   }
}

 void Enemy::Draw(SDL_Renderer* renderer){
   SDL_RenderCopy(renderer, spriteSheet, srcRect, posRect);
 }


 OverlapType Enemy::OverlapDetect(SDL_Rect* rect,SDL_Rect* resultRect){
   if (rect == posRect) {
     return OL_NO_COLLISION;
   }
   if(SDL_IntersectRect(rect,posRect,resultRect)) {
     return OL_ENEMY;
   } else {
     return OL_NO_COLLISION;
   }
 }
