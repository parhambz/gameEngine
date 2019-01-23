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
};

class DoozRule :public Rule {

};