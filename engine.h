
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
private:
	static Board* board;
	static Rule* Inctance;

public:
	
	virtual bool checkMove(Event move)=0;
	virtual bool checkState(Player& player)=0;
	virtual bool isOver()=0;
	virtual bool playerTurn() = 0;
	virtual bool getPlayerTime()=0;
	virtual bool checkGameStruct(GameStruct g) = 0;
};



class Event {
	friend Player;
private:
	Player& player;
	Pair loacation;
	Event(Pair pair , Player& player);
public:
	virtual Player& getPlayer();
	virtual void    setPlayer(Player& player);
	virtual Pair    getLocation();
	virtual void    setLocation(Pair pair);
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
	friend Rule;
protected:
	vector <Cell *> cells;
	vector <Dice> dices;
	Pair size;
	Board(Pair size);
	static Board * instance;
	virtual void createDice()=0;
	virtual void doMove(Event event)=0;
	static Pair indexToLocation(int index);
	virtual int locationToIndex(Pair location);
public:
	virtual int getSize();
	~Board();
};

class Player {
	friend Engine;
private:
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
	int getIndex();
	void addMove(Event move);


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
  static Engine * getInstance();
	virtual Pair giveMyMove(int index);
	virtual void start();
	virtual void end();
	virtual void addPlayer(string name,bool isAuto);
	virtual void setBoard(Board * b);
	virtual void setRule(Rule * r);
    virtual void setUIConnection(UIConnection * u);
    virtual void setGameStruct();
	virtual Event askMove(int index);
    virtual void sendDiceToUI(vector<Dice> dices);
	virtual void setPlayers();
    virtual Board* getBoardInstance();
    virtual Rule * getRuleInstance();
    ~Engine();
};
class GameStruct{
public:
	Pair BoardSize;
	vector <string>  playersNames;
    vector<bool>isAuto;
};
class UIConnection{
	friend Engine;
private:
	static UIConnection * instance;
	//Todo: initialize the instance;
	static UIConnection * getInstance();
	virtual Pair & giveMove(int index);
	virtual void start();
	virtual void end();
	virtual GameStruct & giveStartData();
	virtual void setClock(int seconds);
	virtual void startClock();
	virtual void endClock();
	virtual void showDice(vector <Dice> dices);
	virtual void movePlayer(Event event);
	virtual void showPlayersStates(vector <Pair> states);
	virtual void wrongMove();
};