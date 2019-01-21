//
// Created by Parham Bagherzadeh on 1/21/2019 AD.
//
#include "engine.h"
Pair Board::indexToLocation(int index) {
    Pair location(i/size.getY(),i%size.getY());
    return location;
}
int Board::locationToIndex(Pair location) {
    return location.getY()*this->size.getY()+location.getX();
}
Board::Board(Pair size):size(size){
    int vectorSize=size.getY()*size.getY();
    for(int i=0;i<vectorSize;i++){
        cells.push_back(new Cell(Board::indexToLocation(i)));
    }
}
int Board::getSize() { return cells.size();}