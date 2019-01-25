
#ifndef GAMEENGINE_ENGINE_H
#define GAMEENGINE_ENGINE_H

#endif //GAMEENGINE_ENGINE_H
#include <vector>
#include <string>
#include<iostream>
using namespace std;

class GameStruct;
class Engine;
class Event;
class Board;
class Pair;
class Player;
class Rule;
class UIConnection;
class Dice;
class Cell;
class Clock;

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
    friend Board;
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
protected:
	static Board* board;
	static Rule* Instance;

public:
	
	virtual bool checkMove(Event move)=0;
	virtual bool checkState(Player* player)=0;
	virtual bool isOver(vector<Player*> players)=0;
	virtual int playerTurn() = 0;
	virtual int getPlayerTime()=0;
	virtual bool checkGameStruct(GameStruct g) = 0;
};

class Pair {
private:
	int x;
	int y;
public:
	Pair(int x , int y );
	virtual int getX();
	virtual int getY();
	virtual void setX(int x);
	virtual void setY(int y);
};


class Event {
	friend Player;
private:
	Player* player;
	Pair loacation;
	
public:
	Event(Pair pair, Player* player);
	virtual Player* getPlayer();
	virtual void    setPlayer(Player* player);
	virtual Pair    getLocation();
	virtual void    setLocation(Pair pair);
};



class Cell {
	friend Board;
	friend class Rule;
private:
	vector<Player *> players;
	Pair location;
	Cell(Pair location,bool availablity);
	bool availablity;

public:
	virtual bool  isAvailable();
	virtual int getNPlayer();
	virtual void setAvailablity(bool state);
	virtual Pair getLocation();
	virtual void setLocation(Pair location);
	virtual void removePlayer(int index);
	virtual void addPlayer(Player * p);
	virtual vector<Player*> getPlayers();
};

class Board{
	friend Engine;
	friend class Rule;
protected:
	virtual void start()=0;
	vector <Dice> dices;
	Pair size;
	Board(Pair size);
	static Board * instance;
	virtual void createDice()=0;
	virtual void doMove(Event event)=0;
	Pair indexToLocation(int index);
	
public:
	vector <Cell *> cells;
	virtual int getSize();
	virtual int locationToIndex(Pair location);
	~Board();
};

class Player {
	friend Engine;
protected:
	string  name;
	static Engine* engine;
	Clock   clk;
	vector<Event>  moves;
	Pair    location;
	int     index;
	int  state;
public:
	Player(int index, Pair p, string name, int state);
	virtual Event move() = 0;
	void setLocation(Event move);
	Pair getLocation();
	void setName(string st);
	string getName();
	Engine* getEngine();
	void setEngine(Engine* eng);
	int getIndex();
	void setIndex(int In);
	void addMove(Event move);
	int getState();
	void setState(int st);



};



class Engine{
protected:
	Rule * rule;
	Board * board;
	vector<Player *> players;
	UIConnection * ui;
    static Engine * instance;
    GameStruct * gs;
    Engine();
public:
  static Engine * getInstance();
	virtual Pair * giveMyMove(int index);
	virtual void start();
	virtual int end();
	virtual void addPlayer(Player * p);
	virtual void setBoard(Board * b);
	virtual void setRule(Rule * r);
    virtual void setUIConnection(UIConnection * u);
    virtual void setGameStruct(GameStruct * gs);
	virtual Event askMove(int index);
    virtual void sendDiceToUI(vector<Dice> dices);
    virtual Board* getBoardInstance();
    virtual Rule * getRuleInstance();
	virtual GameStruct * getGameStruct();
	virtual bool move(int x,int y);
	virtual bool isOver();
	virtual int botMove();
    ~Engine();
};
class GameStruct{
public:
	Pair * BoardSize;
	vector <string>  playersNames;
    vector<bool>isAuto;
	GameStruct();
};
class UIConnection{
	friend Engine;
private:
	static UIConnection * instance;
	static UIConnection * getInstance();
	virtual Pair * giveMove(int index);
	virtual void start();
	virtual void end();
	virtual GameStruct * giveStartData();
	virtual void setClock(int seconds);
	virtual void startClock();
	virtual void endClock();
	virtual void showDice(vector <Dice> dices);
	virtual void movePlayer(Event event);
	virtual void showPlayersStates(vector <Pair> states);
	virtual void wrongMove();
};