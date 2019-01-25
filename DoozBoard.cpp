//
// Created by Parham Bagherzadeh on 1/23/2019 AD.
//

#include "game.h"

DoozBoard::DoozBoard(Pair size):Board(size){}

void DoozBoard::start() {
    for (int i=0;i<cells.size();i++){
        cells[i]->setAvailablity(false);
    }
    for (int i=0 ;i<size.getX();i++){
        int index=locationToIndex(Pair (i,0));
        cells[index]->setAvailablity(true);
    }
}
void DoozBoard::createDice() {}
void DoozBoard::doMove(Event event) {
    int index=locationToIndex(event.getLocation());
    cells[index]->addPlayer(event.getPlayer());
    cells[index]->setAvailablity(false);
    if (event.getLocation().getY()!=size.getY()-1){
		cout << "asdasdas" << endl;
        Pair temp(event.getLocation().getX(),event.getLocation().getY()+1);
    int indexn=locationToIndex(temp);
        cells[indexn]->setAvailablity(true);
    }
}