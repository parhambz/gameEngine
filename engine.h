
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
    Dice(vector<int> sides);
    int value;
    vector <int> sides;
public:
    virtual void update();
    virtual int getValue();
    virtual int getNSide();
};

