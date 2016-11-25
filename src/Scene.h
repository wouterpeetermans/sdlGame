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


#include <SDL2/SDL.h>
#include <iostream>
#define window_Height 480
#define window_Width 640
#define fps 60

class Scene {
	private:
		SDL_Window* window;
		SDL_Surface* screen;

	public:
	Scene();
	void Run();
	~Scene();


};


#endif
