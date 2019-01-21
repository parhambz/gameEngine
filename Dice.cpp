//
// Created by Parham Bagherzadeh on 1/21/2019 AD.
//
#include <cstdlib>
#include "engine.h"
Dice::Dice(vector<int> sides):sides(sides){
    value=rand()% sides.size();
}
void Dice::update(){
    value=rand()% sides.size();
}
int Dice::getValue(){
    return sides.at(value);
}
int Dice::getNSide(){
    return sides.size();
}