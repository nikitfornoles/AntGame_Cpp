#include "Ant.h"
#include <iostream>
using namespace std;


int main () {
	int N = 0;
	int pos = 0;
	int direction = 0;
	Ant a;

	cout << "Enter the value of N (the length of the side of the square Board): ";
	cin >> N;
	a.setBoardToUse (N);

	if (a.getBoardLength () > 7)
		a.setLifeline ((a.getBoardLength ()*a.getBoardLength ())/8);

	cout << "Enter the starting position of the Ant (1 - " << N*N << "): ";
	cin >> pos;
	
	while ((pos < 1) || (pos > N*N)) {
		cout << "Enter the starting position of the Ant (1 - " <<  N*N << "): ";
		cin >> pos;
	}

	a.surprisesToEncounter ();
	a.setPosition (pos);
	a.displayPosition ();
	a.checkTileRewardOrTrap ();

	while (a.getLifeline() > 0 && a.getLifeline() < (N*N)/4) {
		a.resetSurprise();
		a.surprisesToEncounter ();
		cout << "\nEnter 8 (up), 2, (down), 4 (left) or 6 (right): ";
		cin >> direction;
		
		if (direction == 8)
			a.moveUp();
		else if (direction == 2)
			a.moveDown();
		else if (direction == 4)
			a.moveLeft();
		else if (direction == 6)
			a.moveRight();
		
		if (!a.isLocked()) {
			cout << "Ant is now at Tile " << a.getPosition() << "\n";
			a.displayPosition ();
			a.checkTileRewardOrTrap ();
		}
	}
	if (a.getLifeline() >= ((N*N)/4)) {
		cout << "\nYou win\n";
		return 0;
	}
	else if (a.getLifeline() < 1) {
		cout << "\nYou lose\n";
		return 0;
	}
}