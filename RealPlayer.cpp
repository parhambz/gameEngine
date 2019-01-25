#include "game.h"

RealPlayer::RealPlayer (int index, Pair p, string name, int state):
	Player(index, p, name, state){}



Event RealPlayer::move() {

	Pair * p = getEngine()->giveMyMove(getIndex());
	Event move(*p,this); // ?

	return move;
}