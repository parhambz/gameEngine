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
	GameStruct * gameS = engine->getGameStruct();
	for (int i = 0; i < gameS->playersNames.size(); i++) {
		Pair p(-1,-1);
		Player * playerr=new RealPlayer (i, p, gameS->playersNames[i], 0);
		engine->addPlayer(playerr);
	}
	engine->start();
	int exit;
	cin >> exit;
    return 0;
}