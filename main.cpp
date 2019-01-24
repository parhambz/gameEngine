#include "game.h"

int main() {
	Engine* engine = Engine::getInstance();
	Pair size(6, 6);
	DoozBoard board(size);
	engine->setBoard(&board);
	Rule* rule = DoozRule::getInstance();
	engine->setRule(rule);
	UIConnection* conection = new UIConnection() ;
	engine->setUIConnection(conection);
	engine->setGameStruct();
	engine->start();
	
    return 0;
}