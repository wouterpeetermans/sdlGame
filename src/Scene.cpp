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

#include "Scene.h"
#include "Hero.h"
#include "Brick.h"
//#include "Colidable.h"
//constructor
Scene::Scene(){
	SDL_Init(SDL_INIT_EVERYTHING); // everything because why not
	window = SDL_CreateWindow("sdlGame", // give the window a name
					SDL_WINDOWPOS_UNDEFINED, // put it where you want
					SDL_WINDOWPOS_UNDEFINED,
					window_Width, //window width defined in the header file
					window_Height, //same here
					SDL_WINDOW_RESIZABLE);// I like resizable windows so why not
	if (window == NULL) {
		std::cout<< "window could not be created" << SDL_GetError() << std::endl;
	}
	else {
		screenRenderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		if (screenRenderer == NULL) {
			std::cout << "screen render could not be created" << SDL_GetError() << std::endl;
		}
		else {
			if(0!=SDL_SetRenderDrawColor(screenRenderer, 0x12, 0xFF, 0xFF, 0xFF)){
				std::cout << "something wrong with renerDrawCollor" << SDL_GetError() << std::endl;
			}
			if(!IMG_Init(IMG_INIT_PNG)){
				std::cout<<"image library could not be loaded" << IMG_GetError() <<std::endl;
			}
		}
	}
}
	//destructor because I dont like memory leaks
Scene::~Scene(){
		SDL_DestroyRenderer(screenRenderer);
		SDL_DestroyWindow(window);
		screenRenderer = NULL; // destroy the pointers to
		window = NULL;
		IMG_Quit();
		SDL_Quit(); // quit SDL
		std::cout << "quited properly" << std::endl;
		std::cout << '\a';
}
// fuction does what it tells you it does
SDL_Texture* Scene::loadTexture(std::string path){
		SDL_Texture* newTexture = NULL; //here I store the newly generated surface
		SDL_Surface* loadedSurface = IMG_Load(path.c_str());//load a surface from a file
		if (loadedSurface == NULL) {//detect if there is something in is and if not give some error
			std::cout << "image could not be loaded" << SDL_GetError() << std::endl;
			}
		else {//optimize the surface for the screen we are using
			newTexture = SDL_CreateTextureFromSurface(screenRenderer, loadedSurface);
			if(newTexture == NULL){//same as above
				std::cout << "texture not created" << SDL_GetError() << std::endl;
			}
			SDL_FreeSurface(loadedSurface);//prevent memory leaks because they are anoying
		}
		return newTexture; //return something
}

void Scene::Run(){ // the place where all the magic happens
		//SDL_Rect scrn_rect; //this will go in to some class later on
		//scrn_rect.x = 576;
		//scrn_rect.y = 432;
		//scrn_rect.w = 64;
		//scrn_rect.h = 48;
		bool quit = false; //this bool tels if the user has quited the hard game already
		SDL_Event e;// a place to store an event of some type

		Hero held(this);
		Brick* blokjes[10];
		Colidable* colidables[10];
		for (size_t i = 0; i < 10; i++) {
			colidables[i]= blokjes[i] = new Brick(this,4+i,12);
		}

		unsigned int startTime=0 , currentTime , timeTook=0;
		while ( !quit ) { // the main loop that goes on until the user is done with it
			startTime = SDL_GetTicks();//get wath time we started to cap the framerate
			while ( SDL_PollEvent( &e ) !=0 ) {//a loop to go over all the events the user managed to create in a fraction of a second
				if (e.type == SDL_QUIT) { //now I am able to use the litle cross on top of the window
					quit = true;
				}
				held.GetKeys(&e);
			}
			held.Update(timeTook,colidables,10);
			SDL_RenderClear(screenRenderer);
			held.Draw(screenRenderer);
			for (size_t i = 0; i < 10; i++) {
				blokjes[i]->Draw(screenRenderer);
			}
			//blok.Draw(screenRenderer);
			SDL_RenderPresent(screenRenderer);
			currentTime = SDL_GetTicks();
			if (currentTime<(startTime+16)) {//cap the framerate at about 100 fps not used when vsync is working
				SDL_Delay((startTime+16)-currentTime);
			}
			timeTook = SDL_GetTicks() - startTime;
		}
}
