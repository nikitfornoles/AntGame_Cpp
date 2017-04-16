#include "Board.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

Board::Board () {
	rewardValue = 1;
	trapType = 1;
	twrcopy = new int [20];
	twtcopy = new int [20];
	rewardSize = 0;
	trapSize = 0;
	srand(time(0));
}
void Board::setN (int side) {
	N = side;
}
int Board::getN () {
	return N;
}
int Board::getRewardValue () {
	return rewardValue;
}
void Board::setTileWithReward (int i) {
	rewardSize = rewardSize + 1;
	tilesWithReward = new int [rewardSize];
	twrcopy [rewardSize-1] = i;
	for (int j = 0; j < rewardSize; j++) {
		tilesWithReward [j] = twrcopy [j];
	}
}
void Board::generateTileWithReward (int z) {
	for (int i = 0; i < ((z*z)/4); i++) {
		int answer = (rand () % (z*z)) + 1;
		if (hasReward (answer))
			i = i-1;
		else
			setTileWithReward (answer);
	}
}
void Board::getTileWithReward () {
	for (int i = 0; i < rewardSize; i++) {
		cout << tilesWithReward [i] << ", ";
	}
}
bool Board::hasReward (int i) {
	bool z = false;
	for (int j = 0; j < rewardSize; j++) {
		if (i == tilesWithReward [j])
			z = true;
	}
	return z;
}
void Board::removeAllRewards () {
	rewardSize = 0;
	tilesWithReward = new int [0];
	twrcopy = new int [20];
}
void Board::setTileWithTrap (int i) {
	trapSize = trapSize + 1;
	tilesWithTrap = new int [trapSize];
	twtcopy [trapSize-1] = i;
	for (int j = 0; j < trapSize; j++) {
		tilesWithTrap [j] = twtcopy [j];
	}
}
void Board::generateTileWithTrap (int z) {
	for (int i = 0; i < ((z*z)/4); i++) {
		int answer = (rand()%(z*z)) + 1;
		if (hasReward (answer))
			i = i-1;
		else if (hasTrap (answer))
			i = i-1;
		else
			setTileWithTrap (answer);
	}
}
void Board::getTileWithTrap () {
	for (int i = 0; i < trapSize; i++) {
		cout << tilesWithTrap [i] << ", ";
	}
}
bool Board::hasTrap (int i) {
	bool z = false;
	for (int j = 0; j < trapSize; j++) {
		if (i == tilesWithTrap [j])
			z = true;
	}
	return z;
}
void Board::removeAllTraps () {
	trapSize = 0;
	tilesWithTrap = new int [0];
	twtcopy = new int [20];
}