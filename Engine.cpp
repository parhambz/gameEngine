//
// Created by Parham Bagherzadeh on 1/22/2019 AD.
//

#include "engine.h"
Engine * Engine::instance= nullptr;
Event Engine::giveMyMove(int index) {
    return ui->giveMove(index);
}
Engine::Engine(){
    setRule();
    setUIConnection();
    setGameStruct();
    setBoard();
}
void Engine::setGameStruct() {
    *gs=ui->giveStartData();
}
void Engine::setBoard() {
    board=new Board(gs->BoardSize);
}
void Engine::setUIConnection() {
    ui=new UIConnection();
}
void Engine::setRule() {
    rule=new Rule();
}
Engine* Engine::getInstance() {
    if (instance!= nullptr){
        return this->instance;
    }else{
        instance=new Engine();
    }
}
void Engine::addPlayer(string name, bool isAuto) {
    if (isAuto== false) {
        this->players.push_back(new RealPlayer(name));
    }else{
        this->players.push_back(new AutoPlayer(name));
    }
    }
Event Engine::askMove(int index) {
    return players[index]->move();
}
void Engine::sendDiceToUI(vector<Dice> dices) {}
void Engine::start() {
    ui->start();
    int turn=0;

    while(rule->isOver()==false){
        //TODO: ask turn from Rule
        //todo:sendDiceToUI(players[turn].dices);
        //todo :int seconds=rule.getPlayerTime(turn);
        players[turn]->clk.setTime(seconds);
        players[turn]->clk.start();
        ui->setClock(seconds);
        ui->startClock();
        Event mv=players[turn]->move();
        while(rule->checkMove(mv)==false){
            if(players[turn]->clk.getTime()<0){
                players[turn]->clk.puase();
                ui->endClock();
                break;
            }
            ui->wrongMove();
            mv=players[turn]->move();
        }
        players[turn]->clk.puase();
        ui->endClock();
        if(players[turn]->clk.getTime()>0){
            board->doMove(mv);
            ui->movePlayer(mv);
            players[turn]->setLocation(mv);
        }
        for (int i=0;i<players.size();i++){
            if(players[i]->state!=rule->checkState(players[i])){
                players[i]->state=rule->checkState(players[i]);
                ui->showPlayerState(players[i]);
            }
        }
    }
    end();
}
void Engine::end() {
    ui->end();
    vector<Pair> states;
    for (int i=0;i<players.size();i++){
        //todo:Pair state (players[i]->index,players[i].getState());
        states.push_back(state);
    }
    ui->showPlayersStates(states);
}
Engine::~Engine() {
    delete(board);
    delete(rule);
    delete(ui);
}