#include "engine.h"

Event::Event(Pair pair , Player* player): loacation(pair) , player(player){}

Pair Event::getLocation() {
	return loacation;
}

Player* Event::getPlayer() {
	return player;
}

void Event::setLocation(Pair pair) {
	loacation = pair;
}

void Event::setPlayer(Player* player) {
	this->player = player;
}

