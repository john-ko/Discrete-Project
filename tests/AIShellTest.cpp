#include "gtest/gtest.h"
#include "../AIShell.h"
#include <vector>
#include "../Move.h"
#include <list>
#include <utility>

class AIShellTest: public ::testing::Test {
public:

	AIShell* shell;
	int** gameState;
	int rows;
	int cols;
	AIShellTest() {
		rows = 10;
		cols = 10;
		gameState = this->createBoard(cols, rows);
		shell = new AIShell(cols, rows, false, gameState, NULL);
		shell->k = 5;
	}
	 void SetUp( ) { 
       // code here will execute just before the test ensues 
   }
 
   void TearDown( ) { 
       // code here will be called just after the test completes
       // ok to through exceptions from here if need be
   }

	int** createBoard(int rows, int cols) {
		int** gameState = new int*[cols];

		for(int i=0; i<cols; i++) {
			gameState[i] = new int[rows];

			for(int j = 0; j < rows; j++) {
				gameState[i][j] = 0;
			}
		}

		return gameState;
	}

	~AIShellTest() {
		// delete shell;
	}
};

TEST_F(AIShellTest, CreateAIShell) {
	EXPECT_EQ(rows, cols);
	int** clone = createBoard(rows, cols);

	int** checker = shell->getGameState();

	for(int col = 0; col < cols; col++) {
		for (int row = 0; row < rows; row++) {
			EXPECT_EQ(clone[col][row], checker[col][row]);
		}
	}
	
}

TEST_F(AIShellTest, BoundsTest) {
	EXPECT_EQ(shell->inBounds(0,0), true);
	EXPECT_EQ(shell->inBounds(cols-1, rows-1), true);
	EXPECT_EQ(shell->inBounds(cols,rows), false);
	EXPECT_EQ(shell->inBounds(0,rows), false);
	EXPECT_EQ(shell->inBounds(cols,0), false);
	EXPECT_EQ(shell->inBounds(-1,0), false);
}

TEST_F(AIShellTest, AvailableMoves) {
	std::vector<Move> moves = shell->getAllAvailableMoves(gameState);
	EXPECT_EQ(moves.size(), rows*cols);
}

TEST_F(AIShellTest, GettersTest) {
	EXPECT_EQ(shell->getCols(), cols);
	EXPECT_EQ(shell->getRows(), rows);
	int** board = shell->getGameState();

	for(int i=0; i<cols; i++) {
		for(int j=0; j<rows; j++) {
			EXPECT_EQ(board[i][j], 0);
		}
	}
}

TEST_F(AIShellTest, DirectionsTest) {

	// pretty much copy and pasted :p
	std::vector<std::pair<int, int>> checker = {
		// north south east west
		std::make_pair(1, 0),
		std::make_pair(-1, 0),
		std::make_pair(0, 1),
		std::make_pair(0, -1),

		// NE NW SE SW
		std::make_pair(1, 1),
		std::make_pair(1, -1),
		std::make_pair(-1, 1),
		std::make_pair(-1, -1)
	};

	std::vector<std::pair<int, int>> directions = shell->getDirections();

	// make sure they are same size
	EXPECT_EQ(checker.size(), directions.size());

	for(int i=0; i<checker.size(); ++i) {
		EXPECT_EQ(directions[i].first, checker[i].first);
		EXPECT_EQ(directions[i].second, checker[i].second);
	}

}



TEST_F(AIShellTest, checkMove) {
	bool isFork = false;
	int forks = 0;
	int n;
	int col;
	int row;
	int player;
	int count;
	Move move(2,2);

	std::vector<std::pair<int, int>> directions = shell->getDirections();

	for (std::pair<int, int> pair: directions) {
		n = shell->k;
		col = pair.first + move.col;
		row = pair.second + move.row;
		count = 1;

		while(shell->inBounds(col, row) && n >= 0) {

			// check
			player = shell->getGameState()[col][row];

			switch(player) {
				case AIShell::NO_PIECE:
					break;
				case AIShell::AI_PIECE:
					count++;
					break;
				case AIShell::HUMAN_PIECE:
					break;
				default:
					break;
			}



			// increment
			col += pair.first;
			row += pair.second;
			n--;
		}

	}

	// return isFork;
}
 
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



