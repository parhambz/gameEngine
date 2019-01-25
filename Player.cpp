#include "engine.h"

Engine* Player::engine = NULL;

Player::Player(int index, Pair p, string name, int state):
	index(index), location(p) , name(name) , state(state) {
	engine = Engine::getInstance();
}

void Player::setLocation(Event move) {
	location = move.getLocation();
	addMove(move);
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

void Player::setEngine(Engine* eng) {
	engine = eng;
}



int Player::getIndex() {
	return index;
}

void Player::setIndex(int In) {
	index = In;
}

void Player::addMove(Event move) {

	moves.push_back(move);
}

int Player::getState() {
	return state;
}

void Player::setState(int st) {
	state = st;
}