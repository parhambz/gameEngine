#include "engine.h"

Engine* Player::engine = NULL;

Player::Player(int index, Pair p, string name, int state):
	index(index), location(p) , name(name) , state(state) {}

void Player::setLocation(Pair p) {
	location = p;
}

Pair Player::getLocation() {
	return location; 
}

void Player::setName(string st) {
	name = st;
}

string Player::getName() {
	return name;
}

Engine* Player::getEngine() {
	return engine;
}

int Player::getIndex() {
	return index;
}