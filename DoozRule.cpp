#include "Rule.cpp"

class DoozRule: public Rule {
	int turn ;
	
	DoozRule():turn(1) {}
public:

	virtual bool checkMove(Event move) {
		int index = board->locationToIndex(move.getLocation());
		if (board->cells[index]->isAvailable()) {
			if (move.getLocation().getY - 1 < 0) {
				return true;
			}
			else {
				Pair p(move.getLocation().getX, move.getLocation().getY - 1);
				int LowerCellindex = board->locationToIndex(p);
				if (!board->cells[LowerCellindex]->isAvailable) {
					return true;
					}
			}
		}
		return false;
		
	}


	virtual bool checkState(Player& player) {

	}

	virtual bool isOver(vector<Player&> players) {

		for (auto iter = players.begin(); iter != players.end(); iter++) {
			if ((*iter).getState == 1) {
				return true;
			}

			return false;
		}

	}
	virtual int playerTurn() {
		if (turn == 0) {
			turn = 1;
			return turn;
		}
		if (turn == 1) {
			turn = 0;
			return turn;
		}
	}
	virtual int getPlayerTime() {
		return 10;
	}

	virtual bool checkGameStruct(GameStruct g) {

		int NumberOfPlayers = 0;
		for (auto iter = g.playersNames.begin(); iter != g.playersNames.end(); iter++) {
			NumberOfPlayers++;
		}
		for (auto iter = g.isAuto.begin(); iter != g.isAuto.end(); iter++) {
			NumberOfPlayers++;
		}

		if (g.BoardSize.getX() == 6 && g.BoardSize.getY() == 6 && NumberOfPlayers == 2) {
			
				return true;	
		}

		else {
			return false;
		}
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