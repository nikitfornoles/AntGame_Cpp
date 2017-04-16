#include "Board.h"

class Ant {
	private:
		int position;
		int lifeline;
		int direction;
		bool lock;
		Board board;

	public:
		Ant ();
		void setPosition (int p);
		int getPosition ();
		void setLifeline (int l);
		int getLifeline ();
		void setDirection (int d);
		int getDirection ();
		void setLock (bool l);
		bool isLocked ();
		void moveUp ();
		void moveDown ();
		void moveLeft ();
		void moveRight ();
		void surprisesToEncounter ();
		void resetSurprise ();
		void checkTileRewardOrTrap ();
		void checkTrapType (int num);
		void setBoardToUse (int length);	
		int getBoardLength ();
		void displayPosition ();
};