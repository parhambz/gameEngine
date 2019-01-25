#include "game.h"



 DoozRule::DoozRule():turn(1) {
	 board = Engine::getInstance()->getBoardInstance();
 }

 bool DoozRule::checkMove(Event move) {
		int index = board->locationToIndex(move.getLocation());
		if (board->cells[index]->isAvailable()) {
			return true;
		}
		return false;

	}

 bool DoozRule::checkLefttoRight(Pair location) {
		int Count = 0;
		for (int i = 1; i < 4; i++) {
			if (location.getX() + i <= 5)
			{
				Pair p(location.getX() + i, location.getY());
				int currentCellindex = board->locationToIndex(p);
				int playerIndex = board->locationToIndex(location);
				if (board->cells[currentCellindex]->getPlayers().size() != 0) {
					if ((board->cells[currentCellindex]->getPlayers())[0] == (board->cells[playerIndex]->getPlayers())[0]) {
						Count++;
						continue;
					}
					else {
						break;

					}
				}
				else { break; }
			}
			else {
				break;
			}

		}

		for (int i = 1; i < 4; i++)
		{
			if (location.getX() - i >= 0) {
				Pair p(location.getX() - i, location.getY());
				int currentCellindex = board->locationToIndex(p);
				int playerIndex = board->locationToIndex(location);
				if (board->cells[currentCellindex]->getPlayers().size() != 0) {
					if ((board->cells[currentCellindex]->getPlayers())[0] == (board->cells[playerIndex]->getPlayers())[0]) {
						Count++;
						continue;
					}
					else {
						break;

					}
				}
				else { break; }

			}
			else {
				break;
			}

		}

		if (Count >= 3) {
			return true;
		}
		else {
			return false;
		}

	}

 bool DoozRule::checkUptoDown(Pair location) {
		int Count = 0;
		for (int i = 1; i < 4; i++) {
			if (location.getY() + i <= 5)
			{
				Pair p(location.getX(), location.getY() + i);
				int currentCellindex = board->locationToIndex(p);
				int playerIndex = board->locationToIndex(location);
				if (board->cells[currentCellindex]->getPlayers().size() != 0) {
					if ((board->cells[currentCellindex]->getPlayers())[0] == (board->cells[playerIndex]->getPlayers())[0]) {
						Count++;
						continue;
					}
					else {
						break;

					}
				}
				else { break; }
			}
			else {
				break;
			}

		}

		for (int i = 1; i < 4; i++)
		{
			if (location.getY() - i >= 0) {
				Pair p(location.getX(), location.getY() - i);
				int currentCellindex = board->locationToIndex(p);
				int playerIndex = board->locationToIndex(location);
				if (board->cells[currentCellindex]->getPlayers().size() != 0) {
					if ((board->cells[currentCellindex]->getPlayers())[0] == (board->cells[playerIndex]->getPlayers())[0]) {
						Count++;
						continue;
					}
					else {
						break;

					}
				}
				else { break; }

			}
			else {
				break;
			}

		}

		if (Count >= 3) {
			return true;
		}
		else {
			return false;
		}
	}

 bool DoozRule::checkGhotr1(Pair location) {
		int Count = 0;
		for (int i = 1; i < 4; i++) {
			if (location.getY() + i <= 5 && location.getX() + i <= 5)
			{
				Pair p(location.getX() + i, location.getY() + i);
				int currentCellindex = board->locationToIndex(p);
				int playerIndex = board->locationToIndex(location);
				if (board->cells[currentCellindex]->getPlayers().size() != 0) {
					if ((board->cells[currentCellindex]->getPlayers())[0] == (board->cells[playerIndex]->getPlayers())[0]) {
						Count++;
						continue;
					}
					else {
						break;

					}
				}
				else { break; }
			}
			else {
				break;
			}

		}

		for (int i = 1; i < 4; i++)
		{
			if (location.getY() - i >= 0 && location.getX() - i >= 0) {
				Pair p(location.getX() - i, location.getY() - i);
				int currentCellindex = board->locationToIndex(p);
				int playerIndex = board->locationToIndex(location);
				if (board->cells[currentCellindex]->getPlayers().size() != 0) {
					if ((board->cells[currentCellindex]->getPlayers())[0] == (board->cells[playerIndex]->getPlayers())[0]) {
						Count++;
						continue;
					}
					else {
						break;

					}
				}
				else { break; }
			}
			else {
				break;
			}
		}
		if (Count >= 3) {
			return true;
		}
		else {
			return false;
		}
	}

 bool DoozRule::checkGhotr2(Pair location) {
		int Count = 0;
		for (int i = 1; i < 4; i++) {
			if (location.getY() + i <= 5 && location.getX() - i >= 0)
			{
				Pair p(location.getX() - i, location.getY() + i);
				int currentCellindex = board->locationToIndex(p);
				int playerIndex = board->locationToIndex(location);
				if (board->cells[currentCellindex]->getPlayers().size() != 0) {
					if ((board->cells[currentCellindex]->getPlayers())[0] == (board->cells[playerIndex]->getPlayers())[0]) {
						Count++;
						continue;
					}
					else {
						break;

					}
				}
				else { break; }
			}
			else {
				break;
			}

		}

		for (int i = 1; i < 4; i++)
		{
			if (location.getY() - i >= 0 && location.getX() + i <= 5) {
				Pair p(location.getX() + i, location.getY() - i);
				int currentCellindex = board->locationToIndex(p);
				int playerIndex = board->locationToIndex(location);
				if (board->cells[currentCellindex]->getPlayers().size() != 0) {
					if ((board->cells[currentCellindex]->getPlayers())[0] == (board->cells[playerIndex]->getPlayers())[0]) {
						Count++;
						continue;
					}
					else {
						break;

					}
				}
				else { break; }

			}
			else {
				break;
			}
		}
		if (Count >= 3) {
			return true;
		}
		else {
			return false;
		}
	}

	 bool DoozRule::checkState(Player* player) {

		if (checkLefttoRight(player->getLocation())) {
			return true;
		}
		else if (checkUptoDown(player->getLocation())) {
			return true;
		}

		else if (checkGhotr1(player->getLocation())) {
			return true;
		}

		else if (checkGhotr2(player->getLocation())) {
			return true;
		}
		else {
			return false;
		}
	}

 bool DoozRule::isOver(vector<Player*> players) {
		for (auto iter = players.begin(); iter != players.end(); iter++) {
			if ((*iter)->getState() == 2) {
				for (auto iter2 = players.begin(); iter2 != players.end(); iter2++) {
					if ((*iter) != (*iter2)) {
						(*iter2)->setState(1);
					}
					else {
						continue;
					}
				}
				return true;
			}
			else {
				continue;
			}
		}
		return false;
	}

 int DoozRule::playerTurn() {
		if (turn == 0) {
			turn = 1;
			return turn;
		}
		if (turn == 1) {
			turn = 0;
			return turn;
		}
	}


 int DoozRule::getPlayerTime() {
		return 10;
	}

 bool DoozRule::checkGameStruct(GameStruct g) {

		int NumberOfPlayers = 0;
		for (auto iter = g.playersNames.begin(); iter != g.playersNames.end(); iter++) {
			NumberOfPlayers++;
		}

		if (g.BoardSize->getX() == 6 && g.BoardSize->getY() == 6 && NumberOfPlayers == 2) {

			return true;
		}

		else {
			return false;
		}
	}

 Rule* DoozRule::getInstance() {
		if (Instance != NULL) {
			return Instance;
		}
		else {
			Instance = new DoozRule();
		}
	}


