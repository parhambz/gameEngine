
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
	Pair location;
	Cell(Pair location,bool availablity= true);
	bool availablity;

	virtual bool  isAvailable();
	virtual int getNPlayer();
	virtual void setAvailablity(bool state);
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
	virtual void doMove(Event event)=0;
	static Pair indexToLocation(int index);
	virtual int locationToIndex(Pair location);
public:
	virtual int getSize();
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
protected:
	Rule * rule;
	Board * board;
	vector<Player *> players;
	UIConnection * ui;
    static Engine * instance;
    GameStruct * gs;
    Engine(Pair size);
public:
    virtual static Engine * getInstance();
	virtual Event giveMyMove(int index);
	virtual void start();
	virtual void end();
	virtual void addPlayer(string name,bool isAuto);
	virtual void setBoard();
	virtual void setRule();
    virtual void setUIConnection();
    virtual void setGameStruct();
	virtual Event askMove(int index);
    virtual void sendDiceToUI(vector<Dice> dices);
    ~Engine();
};
class GameStruct{
public:
	Pair BoardSize;
	vector <string>  playersNames;
};
class UIConnection{
	friend Engine;
private:
	static UIConnection * instance;
	//Todo: initialize the instance;
	static UIConnection * getInstance();
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
	virtual void wrongMove();
	virtual void shoPlayerState(Player p);
};