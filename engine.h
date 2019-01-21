
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
    friend Player;
private:
    Dice(int nsSde=6,int sides={1,2,3,4,5,6});
    int value;
    int nSide;
    int sides[];
public:
    virtual void update();
    virtual int getValue();
    virtual int getNSide();
};

