#include "Rule.cpp"

class DoozRule: public Rule {
	DoozRule() {}
public:

	virtual bool checkMove(Event move) {

	}
	virtual bool checkState(Player& player) {

	}
	virtual bool isOver() {

	}
	virtual bool playerTurn() {

	}
	virtual bool getPlayerTime() {

	}

	virtual bool checkGameStruct(GameStruct g) {

	}
	
	static Rule* getInstance() {
		if (Instance != NULL) {
			return Instance;
		}
		else {
			Instance = new DoozRule();
		}
	}

};