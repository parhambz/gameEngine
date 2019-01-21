
#ifndef GAMEENGINE_ENGINE_H
#define GAMEENGINE_ENGINE_H

#endif //GAMEENGINE_ENGINE_H


class Event;
class Board;
class Player;
class Rule;

class Clock {
private:
	int timeLeft;
public:
	virtual void setTime(int time) ;
	virtual void puase() = 0;
	virtual void start() = 0;
	virtual int  getTime();
};

class Dice{
    friend Player;
private:
    Dice(int nsSde ,int sides[] );
    int value;
    int nSide;
    int sides[];
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
	Player players[];
	int nPlayer;
	Pair Location;
	Cell(Pair location);

	virtual bool  isAvailable();
	virtual int getNPlayer();
	virtual void setNPlayer();

	virtual Pair getLocation();
	virtual void setLocation(Pair location);
};

