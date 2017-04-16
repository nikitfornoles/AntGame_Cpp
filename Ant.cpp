#include "Ant.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

Ant::Ant () {
	lifeline = 1;
	position = 5;
	direction = 4;
	Board board;
	lock = false;
}
void Ant::setPosition (int p) {
	position = p;
}
int Ant::getPosition () {
	return position;
}
void Ant::setLifeline (int l) {
	lifeline = l;
}
int Ant::getLifeline () {
	return lifeline;
}
void Ant::setDirection (int d) {
	direction = d;
}
int Ant::getDirection () {
	return direction;
}
void Ant::setLock (bool l) {
	lock = l;
}
bool Ant::isLocked () {
	return lock;
}
void Ant::moveUp () {
	if ((position - getBoardLength()) < 1) {
		cout << "That move is not allowed\n";
		setLock (true);
	}
	else {
		position = position - getBoardLength();
		setLock (false);
	}
}
void Ant::moveDown () {
	if ((position + getBoardLength()) > (getBoardLength()*getBoardLength())) {
		cout << "That move is not allowed\n";
		setLock (true);
	}
	else {
		position = position + getBoardLength();
		setLock (false);
	}
}
void Ant::moveLeft () {
	if ((((position - 1) % getBoardLength()) == 0) || (position == 1)) {
		cout << "That move is not allowed\n";
		setLock (true);
	}
	else {
		position = position - 1;
		setLock (false);
	}
}
void Ant::moveRight () {
	if ((position % getBoardLength()) == 0 || position == getBoardLength()*getBoardLength()) {
		cout << "That move is not allowed\n";
		setLock (true);
	}
	else {
		position = position + 1;
		setLock (false);
	}
}
void Ant::surprisesToEncounter () {
	board.generateTileWithReward(getBoardLength ());
	board.generateTileWithTrap(getBoardLength ());
}
void Ant::resetSurprise () {
	board.removeAllRewards ();
	board.removeAllTraps ();
}
void Ant::checkTileRewardOrTrap () {
	if (board.hasReward (getPosition ())) {
		setLifeline (getLifeline () + board.getRewardValue());
		cout << "Tile " << position << " has a hidden coin. Lifeline is now " << getLifeline() << "\n";
	}
	else if (board.hasTrap (getPosition ())) {
		srand(time(0));
		int trapType = rand()%3 + 1;
		checkTrapType (trapType);
	}
	else
		cout << "There is no hidden reward or trap in this tile.\n";
}
void Ant::checkTrapType (int num) {
	if (num == 1) {
		cout << "Tile " << getPosition () << " contains water trap. Ant died immediately.\n";
		setLifeline (0);
	}
	else if (num == 2) {
		cout << "Tile " << getPosition () << " contains mud trap. Ant's lifeline decreases by 3.\n";
		setLifeline (getLifeline() - 3);
		cout << "Lifeline is now " << getLifeline() << "\n";
	}
	else if (num == 3) {
		cout << "Tile " << getPosition () << " contains hill trap. Ant's lifeline decreases by 1.\n";
		setLifeline (getLifeline() - 1);
		cout << "Lifeline is now " << getLifeline() << "\n";
	}
}
void Ant::setBoardToUse (int length) {
	board.setN(length);
}
int Ant::getBoardLength () {
	return board.getN();
}
void Ant::displayPosition () {
	for (int i = 1; i <= getBoardLength ()*getBoardLength (); i++) {
		if (i == position)
			cout << "* ";
		else
			cout << "_ ";
		if (i%getBoardLength () == 0)
			cout << "\n";
	}
}