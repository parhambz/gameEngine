//
// Created by Parham Bagherzadeh on 1/22/2019 AD.
//

#include "engine.h"

Engine * Engine::instance= nullptr;
Pair * Engine::giveMyMove(int index) {
    return ui->giveMove(index);
}
Engine::Engine(){
    
}
void Engine::setGameStruct(GameStruct * gs) {
    this->gs=gs;
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
        return instance;
    }else{
        instance=new Engine();
    }
}
void Engine::addPlayer(Player * p) {
	players.push_back(p);
}
Event Engine::askMove(int index) {
    return players[index]->move();
}
void Engine::sendDiceToUI(vector<Dice> dices) {}
/*void Engine::starts() {
    ui->start();
    board->start();
    int turn=0;

    while(!rule->isOver(players)){
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
			if (players[i]->getLocation().getX()!=-1) {
				if (rule->checkState(players[i])) {
					players[i]->state = 2;
				}
			}
        }
    }
    end();
}*/
/*void Engine::ends() {
    ui->end();
    vector<Pair> states;
    for (int i=0;i<players.size();i++){
        Pair state (players[i]->index,players[i]->state);
        states.push_back(state);
    }
    ui->showPlayersStates(states);
}*/
Engine::~Engine() {
    delete(board);
    delete(rule);
    delete(ui);
}

Board* Engine::getBoardInstance() {return board;}
Rule* Engine::getRuleInstance() {return rule;}
GameStruct * Engine::getGameStruct() {
	return gs;
}


void Engine::start() {
    board->start();
}
bool Engine::isOver(){
    return rule->isOver(this->players);
}

int Engine::end() {
    for (int i = 0; i < players.size(); i++) {
        if (players[i]->state == 2) {
            return i + 1;
        }
    }
}

bool Engine::move(int x, int y) {
    int turn = rule->playerTurn();
    Event* mv = new Event(Pair(x, y), players[turn]);
    if (rule->checkMove(*mv)) {
        board->doMove(*mv);
        players[turn]->setLocation(*mv);

        for (int i=0;i<players.size();i++){
            if (players[i]->getLocation().getX()!=-1) {
                if (rule->checkState(players[i])) {
                    players[i]->state = 2;
                }
            }
        }
        return true;
    } else {
        rule->playerTurn(); //choon har bar ke in tabe seda zade mishe mire vase nobate badi
        return false;
    }
}

int Engine::botMove() {
    int turn = rule->playerTurn();
    Pair location= players[turn]->move().getLocation();
    move(location.getX(),location.getY());

	return location.getX() * 10 + location.getY();

}