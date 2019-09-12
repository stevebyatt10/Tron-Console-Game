#ifndef SMARTPLAYER_H
#define SMARTPLAYER_H

#include "ComputerPlayer.h"

class SmartPlayer: public ComputerPlayer {
public:
	SmartPlayer(int X, int Y, Board *board);
	int decideMove();
	int countSteps(int index);
};

#endif
