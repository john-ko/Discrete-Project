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
		rows = 5;
		cols = 5;
		gameState = this->createBoard(cols, rows);
		shell = new AIShell(cols, rows, false, gameState, NULL);
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

	// int** gameState = createBoard(cols,rows);
	
}

TEST_F(AIShellTest, TestingListObjects) {
	std::list<int> numbers;

	for(int i=0; i<10; i++) {
		numbers.push_back(i);
	}

	EXPECT_EQ(numbers.size(), 10);

	int i = 0;
	for(int n: numbers) {
		EXPECT_EQ(numbers.front(), i);
		i++;
		numbers.pop_front();
	}

	EXPECT_EQ(numbers.size(), 0);

	std::vector<std::pair<int, int>> directions = {
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

	for(std::pair<int, int> p: directions) {
		EXPECT_EQ(p.first, 0);
	}
}

TEST_F(AIShellTest, AvailableMoves) {
	std::vector<Move> moves = shell->getAllAvailableMoves(gameState);
	EXPECT_EQ(moves.size(), rows*cols);
}

TEST_F(AIShellTest, TestGetters) {
	EXPECT_EQ(shell->getCols(), cols);
	EXPECT_EQ(shell->getRows(), rows);
	int** board = shell->getGameState();

	for(int i=0; i<cols; i++) {
		for(int j=0; j<rows; j++) {
			EXPECT_EQ(board[i][j], 0);
		}
	}
}

 
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



