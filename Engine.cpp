//
// Created by Parham Bagherzadeh on 1/22/2019 AD.
//

#include "engine.h"
Engine * Engine::instance= nullptr;
Pair Engine::giveMyMove(int index) {
    return ui->giveMove(index);
}
Engine::Engine(){
    setRule();
    setUIConnection();
    setGameStruct();
    setBoard();
    setPlayers();
}
void Engine::setGameStruct() {
    *gs=ui->giveStartData();
    if(rule->checkGameStruct(*gs)){}else{setGameStruct();}
}
void Engine::setBoard(Board * b) {
    board=b;
}
void Engine::setUIConnection(UIConnection * u) {
    ui=u;
}
void Engine::setRule(Rule * r) {
    rule=r;
}
Engine* Engine::getInstance() {
    if (instance!= nullptr){
        return this->instance;
    }else{
        instance=new Engine();
    }
}
void Engine::addPlayer(string name, bool isAuto,int index) {
    if (!isAuto) {
        this->players.push_back(new RealPlayer(index,Pair (-1,-1),name,0));
    }else{
        this->players.push_back(new AutoPlayer(index,Pair (-1,-1),name,0));
    }
    }
Event Engine::askMove(int index) {
    return players[index]->move();
}
void Engine::sendDiceToUI(vector<Dice> dices) {}
void Engine::start() {
    ui->start();
    int turn=0;

    while(!rule->isOver()){
        turn =rule->playerTurn();
        sendDiceToUI(board->dices);
        int seconds=rule->getPlayerTime();
        players[turn]->clk.setTime(seconds);
        players[turn]->clk.start();
        ui->setClock(seconds);
        ui->startClock();
        Event mv=players[turn]->move();
        while(!rule->checkMove(mv)){
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
        todo:Pair state (players[i]->index,players[i]->state);
        states.push_back(state);
    }
    ui->showPlayersStates(states);
}
Engine::~Engine() {
    delete(board);
    delete(rule);
    delete(ui);
}
void Engine::setPlayers() {
    for(int i=0;i<gs->playersNames.size();i++){
        addPlayer(gs->playersNames[i],gs->autoStates[i],i);
    }
}
Board* Engine::getBoardInstance() {return board;}
Rule* Engine::getRuleInstance() {return rule;}