#include "gtest/gtest.h"
#include "../AIShell.h"
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

TEST(SquareRootTest, PositiveNos) { 
    EXPECT_EQ (18.0, 18.0);
    EXPECT_EQ (25.4, 25.4);
    EXPECT_EQ (50, 50);
}

TEST (SquareRootTest, ZeroAndNegativeNos) { 
    ASSERT_EQ (0.0, 0.0);
    ASSERT_EQ (-1, -1);
}

TEST(AIShellCreation, CreateAIShell) {
	int rows = 5;
	int cols = 5;
	int** gameState = createBoard(cols,rows);
	AIShell shell(cols,rows, false, gameState, NULL);
}
 
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}