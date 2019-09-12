#include "Game.h"
#include "HumanPlayer.h"
#include "SmartPlayer.h"

Game::Game() {
		initBoard();
		initPlayers();
}

Game::~Game() {
	delete players[0];
	delete players[1];
	delete board;
}

// Get the size and initalise the board
void Game::initBoard() {
	int bsize = 0;
	cout << "\nEnter the size of the board [4-20]: ";
	cin >> bsize;

	while (bsize < 4 || bsize > 20) {
		cout << "\nEnter a size between 4 and 20." << endl;
		cin >> bsize;
	}

	board = new Board(bsize);

	cout << endl << endl;
}

// Get the type of each player and initialise
void Game::initPlayers() {
	int type;
	int coord;
	for (int i = 0; i < 2; i++) {
		if (i == 0)
			coord = 1;
		else
			coord = board->getSize() - 2;

		cout << "1: Human Player" << endl << "2: Random Player" << endl
				<< "3: Smart Player" << endl << "Enter your choice for Player "
				<< i + 1 << ": ";

		cin >> type;
		cout << endl;
		switch (type) {
		case 1:
			players[i] = new HumanPlayer(coord, coord, board);
			break;
		case 2:
			players[i] = new RandomPlayer(coord, coord, board);
			break;
		case 3:
			players[i] = new SmartPlayer(coord, coord, board);
			break;
		default:
			break;
		}
		cout << "\n\n";
	}
}

void Game::play() {

	while (!hasEnded()) {
			board->display();
		movePlayers();
		checkCollisions();
	}
		board->display();

	displayEndMessage();
}

void Game::movePlayers() {
	int x1, y1, x2, y2;

	players[0]->getMove(x1, y1);
	players[1]->getMove(x2, y2);

	board->addMove(players[0], x1, y1);
	board->addMove(players[1], x2, y2);
}

// Check if the Players have crashed into each other
void Game::checkCollisions() {
	int x1, y1, x2, y2;
	players[0]->getCoordinates(x1, y1);
	players[1]->getCoordinates(x2, y2);

	if (x1 == x2 && y1 == y2) {
		players[0]->crash();
		players[1]->crash();
		board->setAt('*', x1, y2);
	}
}

bool Game::hasEnded() {
	return (players[0]->hasCrashed() || players[1]->hasCrashed());
}

void Game::displayEndMessage() {
	if (players[0]->hasCrashed() && players[1]->hasCrashed()) {
		cout << "\nThe game has finished in a draw!";
		return;
	}

	if (players[0]->hasCrashed()) {
		cout << "\n" << players[1]->getType() << " Player "
				<< players[1]->getChar() << " has won!" << endl;
		return;
	} else {
		cout << "\n" << players[0]->getType() << " Player "
				<< players[0]->getChar() << " has won!" << endl;
	}
}
