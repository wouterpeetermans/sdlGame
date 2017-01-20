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

#ifndef _Gvector
#define _Gvector 1


class Gvector {
private:
  int x , y;
public:
  Gvector() : x(0) , y(0) {};
  Gvector(int a,int b) : x(a) , y(b) {};
  int xDir();
  int yDir();
  int xSpeed(){return x;};
  int ySpeed(){return y;};
  void xZero() {x = 0;};
  void yZero() {y = 0;};
  void xInvert();
  void yInvert();
  void operator+= (const Gvector&);
  Gvector operator* (const double);
};

#endif
