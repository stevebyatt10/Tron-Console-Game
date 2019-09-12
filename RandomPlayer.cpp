#include "RandomPlayer.h"
#include <stdio.h>
#include <stdlib.h>

RandomPlayer::RandomPlayer(int X, int Y, Board *board) :
		ComputerPlayer(X, Y, board, "Random") {
}

int RandomPlayer::decideMove() {

	int direction = rand() % 4;
	while (!avalDirections[direction]) {
		direction = rand() % 4;
	}

	return direction;
}

