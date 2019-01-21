//
// Created by Parham Bagherzadeh on 1/21/2019 AD.
//
#include "engine.h"
Pair::Pair(int x=0, int y=0):x(x),y(y) {}
int Pair::getX() {return this->x;}
int Pair::getY() {return this->y;}
void Pair::setX(int x) {this->x=x;}
void Pair::setY(int y) {this->y=y;}
