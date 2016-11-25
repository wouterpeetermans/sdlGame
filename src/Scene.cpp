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

Scene::Scene(){
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("sdlGame",
					SDL_WINDOWPOS_UNDEFINED,
					SDL_WINDOWPOS_UNDEFINED,
					window_Width,
					window_Height,
					SDL_WINDOW_RESIZABLE);
	screen = SDL_GetWindowSurface(window);
	}

	Scene::~Scene(){
		SDL_DestroyWindow(window);
		SDL_Quit();
	}

	void Scene::Run(){
		SDL_Rect img_rect,scrn_rect;
		img_rect.x = 0;
		img_rect.y = 0;
		img_rect.w = 320;
		img_rect.h = 240;
		scrn_rect.x = 0;
		scrn_rect.y = 0;
		scrn_rect.w = 320;
		scrn_rect.h = 240;
		SDL_Surface* image = SDL_LoadBMP("game/hello.bmp");
		if (image == NULL) {
			std::cout << "de afbeelding is niet geladen" << std::endl;
		}
		SDL_BlitSurface(image,NULL,screen,NULL);
		SDL_UpdateWindowSurface(window);
		SDL_FreeSurface(image);
		SDL_Delay(5000);
	}
