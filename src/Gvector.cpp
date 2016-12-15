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

#include "Gvector.h"

int Gvector::xDir(){
  if (x < 0) {
    return 1;
  }
  else if(x > 0){
    return -1;
  }
  else {
    return 0;
  }
}


int Gvector::yDir(){
  if (y < 0) {
    return 1;
  }
  else if(y > 0){
    return -1;
  }
  else {
    return 0;
  }
}

void Gvector::operator+=(const Gvector& other){
  x += other.x;
  y += other.y;
}
