#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include "Player.h"

class HumanPlayer: public Player {
private:
	static const char moves[8];
public:
	HumanPlayer(int X, int Y, Board *board);
	void getMove(int &newX, int &newY);
	bool validInput(char input);

};

#endif
