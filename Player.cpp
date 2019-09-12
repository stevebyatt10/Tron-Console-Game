#include "Player.h"

Player::Player(int X, int Y, Board* b, string t) {
	x = X;
	y = Y;
	crashed = false;
	character = '$';
	board = b;
	type = t;
}

void Player::setCoordinates(int newX, int newY) {
	x = newX;
	y = newY;
}

void Player::getCoordinates(int &newX, int &newY) {
	newX = x;
	newY = y;
}

char Player::getChar(){
	return character;
}

bool Player::hasCrashed(){
	return crashed;
}

void Player::crash(){
	crashed = true;
}

void Player::getMove(int &newX, int &newY) {

}
string Player::getType(){
	return type;
}

Player::~Player() {
}

