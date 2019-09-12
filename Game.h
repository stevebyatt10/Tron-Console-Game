#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include "Player.h"
#include "RandomPlayer.h"
#include "HumanPlayer.h"

class Game {
private:
	Board *board;
	Player *players[2];

public:
	Game();
	~Game();
	void initBoard();
	void initPlayers();

	void play();
	void checkCollisions();
	bool hasEnded();
	void displayEndMessage();
	void movePlayers();
};
#endif
