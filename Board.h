#ifndef BOARD_H
#define BOARD_H

#include "Player.h"
class Player;

class Board {
private:
	int boardSize;
	char **grid;

public:
	Board(int size);
	~Board();

	void setAt(char c, int x, int y);
	char getAt(int x, int y);
	int getSize();
	bool inBounds(int x, int y);
	bool isValidSpace(int x, int y);

	void display();
	void addMove(Player *player, int x, int y);


};
#endif
