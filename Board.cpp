//
// Created by Parham Bagherzadeh on 1/21/2019 AD.
//
#include "engine.h"
Board * Board::instance = nullptr;


Pair Board::indexToLocation(int index) {
    Pair location(index/(size.getY()),index%size.getY() );
    return location;
}
int Board::locationToIndex(Pair location) {
    return location.getX()*this->size.getY()+location.getY();
}
Board::Board(Pair size):size(size){
    int vectorSize=size.getY()*size.getY();
    for(int i=0;i<vectorSize;i++){
        cells.push_back(new Cell(Board::indexToLocation(i) , false));
    }
}
int Board::getSize() { return cells.size();}
Board::~Board() {
    for (int i=0 ;i<cells.size();i++){
        delete(cells[i]);
    }
}