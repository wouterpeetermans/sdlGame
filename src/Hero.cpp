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

 #include "Hero.h"

 Hero::Hero(Scene* context,int x, int y):Sprite("game/hero.png", context){
   int lenght = 6;
   leftArray = new SDL_Rect[lenght];
   rightArray = new SDL_Rect[lenght];
   backArray = new SDL_Rect[lenght];
   frontArray = new SDL_Rect[lenght];
   for (int i = 0; i < lenght; i++) {
     SDL_Rect rect;
     rect.h = 64;
     rect.w = 32;
     rect.x = i*32;
     rect.y = 0;
     frontArray[i] = rect;
     rect.y = 64;
     backArray[i] = rect;
     rect.y = 128;
     rightArray[i] = rect;
     rect.y = 192;
     leftArray[i] = rect;
   }
   posRect = new SDL_Rect;
   posRect->h = 64;
   posRect->w = 32;
   posRect->x = x*32;
   posRect->y = y*32;
   srcRect = frontArray;
   speedVector.xZero();
   speedVector.yZero();
 }

 Hero::~Hero(){

 }

 void Hero::GetKeys(SDL_Event* e){
   Gvector leftVector(-3,0);
   Gvector rightVector(3,0);
   Gvector jumpVector(0,12);
   if(e->type == SDL_KEYDOWN) {//keys pressed
     switch (e->key.keysym.sym) {
       case SDLK_RIGHT:
       //pos++;
       speedVector.xZero();
       speedVector += rightVector;
       break;
       case SDLK_LEFT:
       //pos--;
       speedVector.xZero();
       speedVector += leftVector;
       break;
       case SDLK_UP:
       if (jumpKeyPressed) {
         break;
       }
       if (hasJumped<2) {
         jumpKeyPressed = true;
         hasJumped ++;
         speedVector += jumpVector;
       }
       break;
       default:
       //speedVector.xZero();
       break;
     }
   } else if(e->type == SDL_KEYUP) {//keys pressed
       switch (e->key.keysym.sym) {
         case SDLK_RIGHT:
         //pos++;
         speedVector.xZero();
         break;
         case SDLK_LEFT:
         //pos--;
         speedVector.xZero();
         break;
         case SDLK_UP:
         jumpKeyPressed = false;
         default:
         //speedVector.xZero();
         break;
     }
   }
 }

 void Hero::Update(unsigned int timePast,Colidable** colideArray,int amountColidables){
   Gvector gravityVector(0,-1);
   if(seqb<36){
     seqb++;
   }
   else{
     seqb = 0;
   }
   int seq = seqb/6;
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

   }
   SDL_Rect tempPosRect = *posRect;
   int changeX = speedVector.xSpeed() * (timePast/10.0);
   int changeY = speedVector.ySpeed() * (timePast/10.0);

   bool colidedX=false , colidedY=false;
   int biggestCollisionX = 0 , biggestCollisionY = 0;
   SDL_Rect collisionRect;
   for (int i = 0; i < amountColidables; i++) {
     tempPosRect.x += changeX;
     OverlapType collisionType = colideArray[i]->OverlapDetect(&tempPosRect,&collisionRect);
     if(collisionType!=OL_NO_COLLISION){
       if (collisionRect.w > biggestCollisionX) {
         biggestCollisionX = collisionRect.w;
       }
       colidedX = true;
     }
     //if (collisionType == OL_ENEMY) {
    //   isAlive = false;
     //}
     tempPosRect.x -= changeX;
     tempPosRect.y -= changeY;
     collisionType = colideArray[i]->OverlapDetect(&tempPosRect,&collisionRect);
     if(collisionType!=OL_NO_COLLISION){
       if (collisionRect.h > biggestCollisionY) {
         biggestCollisionY = collisionRect.h;
       }
       colidedY = true;
     }
     tempPosRect.y += changeY;
   }
   posRect->x += changeX;
   posRect->y -= changeY;
   if (colidedX) {
     posRect->x += biggestCollisionX * speedVector.xDir();
   }
   if (colidedY) {
     posRect->y -= biggestCollisionY * speedVector.yDir();
     speedVector.yZero();
     hasJumped = 0;
   }
   if(speedVector.ySpeed()>(-7)){
     speedVector += (gravityVector * (timePast/10.0));
   }
   if (posRect->y >= 512) { //just dont drop trough the floor will maybe deleted in later stage
     speedVector.yZero();
     posRect->y = 512;
     hasJumped = 0;
   }
   //speedVector.xZero();
 }


 void Hero::Draw(SDL_Renderer * renderer){
   SDL_RenderCopy(renderer, spriteSheet, srcRect, posRect);
 }

 int Hero::GetPos(){
   return posRect->x;
 }
