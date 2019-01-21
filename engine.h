//
// Created by Parham Bagherzadeh on 1/21/2019 AD.
//

#ifndef GAMEENGINE_ENGINE_H
#define GAMEENGINE_ENGINE_H

#endif //GAMEENGINE_ENGINE_H
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

