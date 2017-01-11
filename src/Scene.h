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
#ifndef Scene_Included //include guard this makes shure the file is not included more then once
#define Scene_Included


#include <SDL2/SDL.h>  //import the main SDL library
#include <SDL2/SDL_image.h>  // import the image convorting part of SDL
#include <iostream> //give me some c++ powers like string support and cout
#include "Drawable.h"
#define window_Height 480 //set the height of the window (this wil go out in a later stage)
#define window_Width 640 // set the width
#define fps 60 // set the disired frames per second (not implemented yet)

class Scene {  //all screen related activitys go in here
	private:
		//variables
		SDL_Window* window; // this wil be the pointer to the SDL window we are using
		SDL_Renderer* screenRenderer; // pointer to the renderer of the window above
		//functions



	public:
		//constructor and deconstructor
		Scene();
	  ~Scene();
		//functions
		void Run();// this is the main function of Scene and it wil go on till the program ends
		SDL_Texture* loadTexture(std::string);

};

#endif // end of includeGuard
