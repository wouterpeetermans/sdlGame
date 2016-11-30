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
//constructor
Scene::Scene(){
	SDL_Init(SDL_INIT_EVERYTHING); // everything because why not
	window = SDL_CreateWindow("sdlGame", // give the window a name
					SDL_WINDOWPOS_UNDEFINED, // put it where you want
					SDL_WINDOWPOS_UNDEFINED,
					window_Width, //window width defined in the header file
					window_Height, //same here
					SDL_WINDOW_RESIZABLE);// I like resizable windows so for the heck of it
	screen = SDL_GetWindowSurface(window); // make screen point to the surface of the window
}
	//destructor because I dont like memory leaks
Scene::~Scene(){
		SDL_DestroyWindow(window); // blow up the window with electronic magic
		SDL_Quit(); // quit SDL
}
// fuction does what it tells you it does
SDL_Surface* Scene::loadSurface(std::string path){
		SDL_Surface* optimizedSurface = NULL; //here I store the newly generated surface
		SDL_Surface* loadedSurface = SDL_LoadBMP(path.c_str());//load a surface from a file
		if (loadedSurface == NULL) {//detect if there is something in is and if not give some error
			std::cout << "image could not be loaded" << std::endl;
		}
		else {//optimize the surface for the screen we are using
			optimizedSurface = SDL_ConvertSurface(loadedSurface, screen->format, NULL); //see SDL docs for wath it does
			if(optimizedSurface == NULL){//same as above
				std::cout << "image not optimized" << std::endl;
			}
			SDL_FreeSurface(loadedSurface);//prevent memory leaks because they are anoying
		}
		return optimizedSurface; //return something
}

void Scene::Run(){ // the place where all the magic happens
		SDL_Rect scrn_rect; //this will go in to some class later on
		scrn_rect.x = 576;
		scrn_rect.y = 432;
		scrn_rect.w = 64;
		scrn_rect.h = 48;
		bool quit = false; //this bool tels if the user has quited the hard game already
		SDL_Event e;// a place to store an event of some type
		SDL_Surface* image = loadSurface("game/hello.bmp"); // use the above created surface
		if (image == NULL) { // errors ...
			std::cout << "de afbeelding is niet geladen" << std::endl;
		}
		while ( !quit ) { // the main loop that goes on until the user is done with it
			while ( SDL_PollEvent( &e ) !=0 ) {//a loop to go over all the events the user managed to create in a fraction of a second
				if (e.type == SDL_QUIT) { //now I am able to use the litle cross on top of the window
					quit = true;
				}
				else if(e.type = SDL_KEYDOWN) {
					switch (e.key.keysym.sym) {
						case SDLK_ESCAPE: //escape makes the program quit for now
						quit = true;
						break;
						default:
						break;
					}
				}
			}
			SDL_BlitSurface(image,NULL,screen,NULL);// put the optimized surface on the screen surface
			SDL_BlitScaled(image,NULL,screen,&scrn_rect);//put a smaller version of the image on the screen in the bottom right corner (minimap)
			SDL_UpdateWindowSurface(window);//push this all to the real screen

		}
		SDL_FreeSurface(image);//clean up
}
