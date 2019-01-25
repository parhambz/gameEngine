//
// Created by Parham Bagherzadeh on 1/21/2019 AD.
//
#include "engine.h"

Cell::Cell(Pair location,bool availablity= true):location(location),availablity(availablity) {
}

void Cell::addPlayer(Player *p)
{
    players.push_back(p);
}
Pair Cell::getLocation() {
    return this->location;
}
int Cell::getNPlayer() {
    return this->players.size();
}
bool Cell::isAvailable() {
    return this->availablity;
}
void Cell::removePlayer(int index) {

    for (int i=0 ;i<players.size();i++){
        if(players[i]->getIndex()==index){
            players.erase(players.begin()+i);
        }
    }
}
void Cell::setLocation(Pair location) {
    this->location=location;
}
void Cell::setAvailablity(bool state) {
    this->availablity=state;
}

vector<Player*> Cell::getPlayers() {
	return players;
}