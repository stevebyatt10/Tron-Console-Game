#include "HumanPlayer.h"

HumanPlayer::HumanPlayer(int X, int Y, Board *board) :
		Player(X, Y, board, "Human") {

	cout << "Enter the symbol for this Player: ";
	cin >> character;
	board->setAt(character, x, y);
}

// Define all valid user inputs
const char HumanPlayer::moves[8] = { 'U', 'u', 'D', 'd', 'L', 'l', 'R', 'r' };

// Check if user input is valid
bool HumanPlayer::validInput(char input) {

	for (int i = 0; i < 8; i++) {
		if (moves[i] == input)
			return true;
	}

	return false;
}

void HumanPlayer::getMove(int &newX, int &newY) {
	char move;
	newX = x;
	newY = y;

	cout << "\n\nEnter the move for Player " << character << ": ";
	cin >> move;

	while (!validInput(move)) {
		cout << "\nInvalid move!" << endl;
		cout << "Please enter a valid move (U, D, L, R): ";
		cin >> move;
	}

	switch (move) {
	case 'U':
	case 'u':
		newY--;
		break;
	case 'D':
	case 'd':
		newY++;
		break;
	case 'L':
	case 'l':
		newX--;
		break;
	case 'R':
	case 'r':
		newX++;
		break;
	}

}
