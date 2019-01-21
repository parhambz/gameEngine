
#ifndef GAMEENGINE_ENGINE_H
#define GAMEENGINE_ENGINE_H

#endif //GAMEENGINE_ENGINE_H
#include <vector>
#include <string>
using namespace std;

class Engine;
class Event;
class Board;
class Pair;
class Player;
class Rule;
class UIConnection;

class Clock {
private:
	int timeLeft;
public:
	virtual void setTime(int time) ;
	virtual void puase() ;
	virtual void start() ;
	virtual int  getTime();
};

class Dice{
    friend Player;
private:
    Dice(vector<int> sides);
    int value;
    vector <int> sides;
public:
    virtual void update();
    virtual int getValue();
    virtual int getNSide();
};


class Rule {
private:
	Board* board;

public:
	
	virtual int checkMove(Event move)=0;
	virtual int checkState(Player player)=0;
	virtual int isOver()=0;
};



class Event {
	friend Player;
private:
	Player* player;
	Pair loacation;
	Event(Pair pair);
public:
	virtual Player* getPlayer();
	virtual void    setPlayer();
	virtual Pair    getLocation();
	virtual void    setLocation();
};

class Pair{
private:
	int x;
	int y;
public:
	Pair(int x=0,int y =0);
	virtual int getX();
	virtual int getY();
	virtual void setX(int x);
	virtual void setY(int y);
};

class Cell {
	friend Board;
	friend Rule;
private:
	vector<Player *> players;
	Pair Location;
	Cell(Pair location);

	virtual bool  isAvailable();
	virtual int getNPlayer();
	virtual void setNPlayer();

	virtual Pair getLocation();
	virtual void setLocation(Pair location);
	virtual void removePlayer(int index);
	virtual void addPlayer(Player * p);
};

class Board{
	friend Engine;
private:
	vector <Cell *> cells;
	Pair size;
	Board(Pair size);
	void doMove(Event event);
public:
	int getSize();
};

class Player {
	friend Engine;
private:
	string  name;
	Engine* engine;
	Clock   clk;
	Event**  moves;
	Dice*   dice;
	Pair    location;
	int     index;
	string  state;
public:
	virtual Event move() = 0;
	void setLocation(Pair pair);
	void setName(string st);
	string getName();


};

class RealPlayer : public Player {
private:
	RealPlayer(int index, Pair p, string name, int state);
public:
	virtual Event move();

};

class Engine{
private:
	Rule * rule;
	Board * board;
	Player ** players;
	int nPlayer;
	UIConnection * ui;
public:
	Event giveMyMove(int index);
	void start();
	void end();
	void addPlayer(string name,bool isAuto);
	void setBoard();
	void setRule();
	Event askMove(int index);

};
class GameStruct{
public:
	Pair BoardSize;
	vector <string>  playersNames;
};
class UIConnection{
	friend Engine;
private:
	virtual Event giveMove(int index);
	virtual void start();
	virtual void end();
	virtual GameStruct giveStartData();
	virtual void setClock(int seconds);
	virtual void startClock();
	virtual void endClock();
	virtual void showDice(vector <Dice> dices);
	virtual void movePlayer(Event event);
	virtual void showPlayersStates(vector <Pair> states);
};