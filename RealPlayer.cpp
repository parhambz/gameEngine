#include "engine.h"

RealPlayer::RealPlayer (int index, Pair p, string name, int state):
	Player(index, p, name, state){}



Event RealPlayer::move() {

	Event move(getEngine()->giveMyMove(getIndex()), this);

	return move;
}