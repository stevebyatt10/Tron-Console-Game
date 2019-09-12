#ifndef COMPUTERPLAYER_H
#define COMPUTERPLAYER_H

#include "Player.h"

class ComputerPlayer: public Player {
protected:
	bool avalDirections[4];

public:
	ComputerPlayer(int X, int Y, Board *board, string t);
	void getMove(int &newX, int &newY);
	virtual int decideMove();

	bool canMoveUp();
	bool canMoveDown();
	bool canMoveLeft();
	bool canMoveRight();
};

#endif
