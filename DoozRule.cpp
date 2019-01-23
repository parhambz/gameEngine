#include "Rule.cpp"

class DoozRule : public Rule {
	int turn;

	DoozRule() :turn(1) {}
public:

	virtual bool checkMove(Event move) {
		int index = board->locationToIndex(move.getLocation());
		if (board->cells[index]->isAvailable()) {
			return true;
		}
		return false;

	}

	bool checkLefttoRight(Pair location) {
		int Count = 0;
		for (int i = 1; i < 4; i++) {
			if (location.getX() + i <= 6)
			{
				Pair p(location.getX() + i, location.getY());
				int currentCellindex = board->locationToIndex(p);
				int playerIndex = board->locationToIndex(location);
				if (board->cells[currentCellindex]->getPlayers[0] == board->cells[playerIndex]->getPlayers[0]) {
					Count++;
					continue;
				}
				else {
					break;

				}
			}
			else {
				break;
			}

		}

		for (int i = 0; i < 4; i++)
		{
			if (location.getX() - i >= 0) {
				Pair p(location.getX() - i, location.getY());
				int currentCellindex = board->locationToIndex(p);
				int playerIndex = board->locationToIndex(location);
				if (board->cells[currentCellindex]->getPlayers[0] == board->cells[playerIndex]->getPlayers[0]) {
					Count++;
					continue;
				}
				else {
					break;

				}

			}
			else {
				break;
			}

			if (Count >= 3) {
				return true;
			}
			else {
				return false;
			}
		}

	}
	bool checkUptoDown(Pair location) {
		int Count = 0;
		for (int i = 1; i < 4; i++) {
			if (location.getY() + i <= 6)
			{
				Pair p(location.getX(), location.getY() + i);
				int currentCellindex = board->locationToIndex(p);
				int playerIndex = board->locationToIndex(location);
				if (board->cells[currentCellindex]->getPlayers[0] == board->cells[playerIndex]->getPlayers[0]) {
					Count++;
					continue;
				}
				else {
					break;

				}
			}
			else {
				break;
			}

		}

		for (int i = 0; i < 4; i++)
		{
			if (location.getY() - i >= 0) {
				Pair p(location.getX(), location.getY() - i);
				int currentCellindex = board->locationToIndex(p);
				int playerIndex = board->locationToIndex(location);
				if (board->cells[currentCellindex]->getPlayers[0] == board->cells[playerIndex]->getPlayers[0]) {
					Count++;
					continue;
				}
				else {
					break;

				}

			}
			else {
				break;
			}

			if (Count >= 3) {
				return true;
			}
			else {
				return false;
			}
		}
	}
	bool checkGhotr1(Pair location) {
		int Count = 0;
		for (int i = 1; i < 4; i++) {
			if (location.getY() + i <= 6 && location.getX() + i <= 6)
			{
				Pair p(location.getX() + i, location.getY() + i);
				int currentCellindex = board->locationToIndex(p);
				int playerIndex = board->locationToIndex(location);
				if (board->cells[currentCellindex]->getPlayers[0] == board->cells[playerIndex]->getPlayers[0]) {
					Count++;
					continue;
				}
				else {
					break;

				}
			}
			else {
				break;
			}

		}

		for (int i = 0; i < 4; i++)
		{
			if (location.getY() - i >= 0 && location.getX() - i >= 0) {
				Pair p(location.getX() - i, location.getY() - i);
				int currentCellindex = board->locationToIndex(p);
				int playerIndex = board->locationToIndex(location);
				if (board->cells[currentCellindex]->getPlayers[0] == board->cells[playerIndex]->getPlayers[0]) {
					Count++;
					continue;
				}
				else {
					break;

				}

			}
			else {
				break;
			}

			if (Count >= 3) {
				return true;
			}
			else {
				return false;
			}
		}
	}
	bool checkGhotr2(Pair location) {
		int Count = 0;
		for (int i = 1; i < 4; i++) {
			if (location.getY() + i <= 6 && location.getX() - i >= 0)
			{
				Pair p(location.getX() - i, location.getY() + i);
				int currentCellindex = board->locationToIndex(p);
				int playerIndex = board->locationToIndex(location);
				if (board->cells[currentCellindex]->getPlayers[0] == board->cells[playerIndex]->getPlayers[0]) {
					Count++;
					continue;
				}
				else {
					break;

				}
			}
			else {
				break;
			}

		}

		for (int i = 0; i < 4; i++)
		{
			if (location.getY() - i >= 0 && location.getX() + i <= 6) {
				Pair p(location.getX() + i, location.getY() - i);
				int currentCellindex = board->locationToIndex(p);
				int playerIndex = board->locationToIndex(location);
				if (board->cells[currentCellindex]->getPlayers[0] == board->cells[playerIndex]->getPlayers[0]) {
					Count++;
					continue;
				}
				else {
					break;

				}

			}
			else {
				break;
			}

			if (Count >= 3) {
				return true;
			}
			else {
				return false;
			}
		}
	}

	virtual bool checkState(Player& player) {

		if (checkLefttoRight(player.getLocation())) {
			return true;
		}
		else if (checkUptoDown(player.getLocation())) {
			return true;
		}

		else if (checkGhotr1(player.getLocation())) {
			return true;
		}

		else if (checkGhotr2(player.getLocation())) {
			return true;
		}
		else {
			return false;
		}
	}

	bool isOver(vector<Player&> players) {
		for (auto iter = players.begin(); iter != players.end(); iter++) {
			if ((*iter).getState() == 2) {
				return true;
			}
			else {
				continue;
			}
		}
		return false;
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
