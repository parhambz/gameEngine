
#ifndef GAMEENGINE_ENGINE_H
#define GAMEENGINE_ENGINE_H

#endif //GAMEENGINE_ENGINE_H


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
    friend class Player;
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