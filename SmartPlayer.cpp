#include "SmartPlayer.h"

SmartPlayer::SmartPlayer(int X, int Y, Board *board) :
		ComputerPlayer(X, Y, board, "Smart") {
}

int SmartPlayer::decideMove() {
	// Check how many open moves a direction has and score them
	// OR:: and further evaluate other directions, further simulate

	int bestDirectionIndex = -1;
	int bestSteps = 0;
	int currentSteps;
	for (int i = 0; i < 4; i++) {
		if (avalDirections[i]) {
			currentSteps = countSteps(i);
			if (currentSteps >= bestSteps) {
				bestSteps = currentSteps;
				bestDirectionIndex = i;
			}
		}
	}
	return bestDirectionIndex;
}

int SmartPlayer::countSteps(int index) {
	int steps = 0;
	int x, y;
	getCoordinates(x, y);

	do{
		switch (index) {
		case 0:
			y--;
			break;
		case 1:
			y++;
			break;
		case 2:
			x--;
			break;
		case 3:
			x++;
			break;
		}
		steps++;
	}	while (board->inBounds(x,y) && board->getAt(x, y) == ' ') ;

	return steps;
}
