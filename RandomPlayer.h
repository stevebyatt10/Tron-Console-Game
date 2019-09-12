#ifndef RANDOMPLAYER_H
#define RANDOMPLAYER_H

#include "ComputerPlayer.h"

class RandomPlayer: public ComputerPlayer {

public:
	RandomPlayer(int X, int Y, Board *board);
	int decideMove();

};
#endif
