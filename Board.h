class Board {
	private:
		int N;
		int rewardValue;
		int trapType;
		int *tilesWithReward;
		int *twrcopy;
		int rewardSize;
		int *tilesWithTrap;
		int *twtcopy;
		int trapSize;

	public:
		Board ();
		void setN (int side);
		int getN ();
		int getRewardValue ();
		void setTileWithReward (int i);
		void generateTileWithReward (int z);
		void getTileWithReward ();
		bool hasReward (int i);
		void removeAllRewards ();
		void setTileWithTrap (int j);
		void generateTileWithTrap (int z);
		void getTileWithTrap ();
		bool hasTrap (int i);
		void removeAllTraps ();
};