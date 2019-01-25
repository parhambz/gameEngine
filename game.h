//
// Created by Parham Bagherzadeh on 1/23/2019 AD.
//

#ifndef GAMEENGINE_GAME_H
#define GAMEENGINE_GAME_H

#endif //GAMEENGINE_GAME_H

#include "engine.h"

class DoozBoard :public Board{

    virtual void start();
    virtual void createDice();
    virtual void doMove(Event event);

public:
	DoozBoard(Pair size);
};

class DoozRule :public Rule {
	int turn;
	DoozRule();
public:
	bool checkMove(Event move);
	bool checkLefttoRight(Pair location);
	bool checkUptoDown(Pair location);
	bool checkGhotr1(Pair location);
	bool checkGhotr2(Pair location);
	bool checkState(Player* player);
	bool isOver(vector<Player*> players);
	int playerTurn();
	int getPlayerTime();
	bool checkGameStruct(GameStruct g);
	static Rule* getInstance();

};

class RealPlayer : public Player {
private:
	
public:
	RealPlayer(int index, Pair p, string name, int state);
	virtual Event move();

};