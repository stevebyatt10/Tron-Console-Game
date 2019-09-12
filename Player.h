#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include "Board.h"
#include <string>
using namespace std;

class Board;

class Player {
protected:
	int x, y;
	char character;
	bool crashed;
	Board *board;
	string type;

public:
	Player(int X, int Y, Board *b, string t);
	virtual void getMove(int &newX, int &newY);
	virtual ~Player();
	void setCoordinates(int newX, int newY);
	void getCoordinates(int &newX, int &newY);
	char getChar();
	string getType();
	bool hasCrashed();
	void crash();
};
#endif
