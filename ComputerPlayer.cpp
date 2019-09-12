#include "ComputerPlayer.h"

ComputerPlayer::ComputerPlayer(int X, int Y, Board *board, string t) :
		Player(X, Y, board, t) {

	for (int i = 0; i < 4; i++) {
		avalDirections[i] = true;
	}

	// Assign a random character
	int atoz = rand() % 26 + 65;
	character = atoz;

	board->setAt(character, x, y);
}

void ComputerPlayer::getMove(int &newX, int &newY) {
	avalDirections[0] = canMoveUp();
	avalDirections[1] = canMoveDown();
	avalDirections[2] = canMoveLeft();
	avalDirections[3] = canMoveRight();

	getCoordinates(newX, newY);

	// Check if at least one direction is available
	for (int i = 0; i < 4; i++) {
		if (avalDirections[i])
			break;

		if (i == 3) {
			newX++;
			return;
		}
	}

	int direction = decideMove();

	switch (direction) {
	case 0:
		newY--;
		break;
	case 1:
		newY++;
		break;
	case 2:
		newX--;
		break;
	case 3:
		newX++;
		break;
	default:
		cout << "\nComputer Player made an invalid move " << endl;
	}
}

int ComputerPlayer::decideMove() {
	return 0;
}

bool ComputerPlayer::canMoveUp() {
	return board->isValidSpace(x, y - 1);
}

bool ComputerPlayer::canMoveDown() {
	return board->isValidSpace(x, y + 1);
}

bool ComputerPlayer::canMoveLeft() {
	return board->isValidSpace(x - 1, y);
}

bool ComputerPlayer::canMoveRight() {
	return board->isValidSpace(x + 1, y);
}
