#include "Board.h"

Board::Board(int size) {
	boardSize = size;

	grid = new char*[boardSize];

	for (int x = 0; x < boardSize; x++) {
		grid[x] = new char[boardSize];
		for (int y = 0; y < boardSize; y++) {
			grid[x][y] = ' ';
		}
	}
}

Board::~Board(){
	for(int i = 0; i < boardSize; i++){
		delete [] grid[i];
	}

	delete [] grid;
}

void Board::addMove(Player *player, int x, int y) {
	// Get current coordinates
	int currentX, currentY;
	player->getCoordinates(currentX, currentY);

	// Check if new coordinates are not out of bound
	if (!inBounds(x, y)) {
		player->crash();
		setAt('*', currentX, currentY);
		return;
	}

	// Check if we crashed into a 0
	if (getAt(x, y) == '0') {
		setAt('*', x, y);
		player->crash();
	} else
		setAt(player->getChar(), x, y);

	setAt('0', currentX, currentY);
	player->setCoordinates(x, y);

}

void Board::setAt(char c, int x, int y) {
	grid[x][y] = c;
}

char Board::getAt(int x, int y) {
	return grid[x][y];
}

int Board::getSize() {
	return boardSize;
}

bool Board::inBounds(int x, int y) {
	if ((x < 0 || x > boardSize - 1) || (y < 0 || y > boardSize - 1))
		return false;
	return true;
}

bool Board::isValidSpace(int x, int y){
	return inBounds(x,y) && getAt(x,y) == ' ';
}

void Board::display() {
	cout << "\n\n\n";

	for (int y = 0; y < boardSize; y++) {

		for (int i = 0; i < boardSize; i++) {
			cout << " ---";
		}

		cout << endl;

		for (int x = 0; x < boardSize; x++) {
			cout << "| " << grid[x][y] << " ";
		}

		cout << "|" << endl;
	}

	for (int i = 0; i < boardSize; i++) {
		cout << " ---";
	}

	cout << "\n" << endl;
}
