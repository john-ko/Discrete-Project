#include "AIShell.h"
#include <iostream>
#include <tuple>

AIShell::AIShell(int numCols, int numRows, bool gravityOn, int** gameState, Move lastMove)
{
	this->deadline=0;
	this->numRows=numRows;
	this->numCols=numCols;
	this->gravityOn=gravityOn;
	this->gameState=gameState;
	this->lastMove=lastMove;
}


AIShell::~AIShell()
{
	
	//delete the gameState variable.
	for (int i =0; i<numCols; i++){
		delete [] gameState[i];
	}
	delete [] gameState;

}

Move AIShell::makeMove(){
	std::vector<Move> moves = getAllAvailableMoves(gameState);

	
	Move m(0, 0);
	return m;
}

std::vector<Move> AIShell::getAllAvailableMoves(int** board) {
	std::vector<Move> moves;
	for(int i=0; i<numCols; i++) {
		for(int j=0; j<numRows; j++) {
			if (board[i][j] == NO_PIECE) {
				Move m(i, j);
				moves.push_back(m);
			}
		}
	}
	return moves;
}


void AIShell::getBestMove(int** gameState, std::vector<Move> moves) {
	for(Move m: moves) {
		// place move swap turn and recurse in
		
		// getBestMove(gameState, )
	}

}

bool AIShell::checkDiagnals(int** gameState, Move move) {
	bool isFork = false;
	int n = k;
	int col = 0;
	int row = 0;

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


	for (std::pair<int, int> pair: directions) {
		col = pair.first;
		row = pair.second;
	}

	// given Move move;

	
	// find each diagnal withing k distance/ or out of bounds

	return isFork;
}

std::vector<std::pair<int,int>> AIShell::getDirections() {
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
	return directions;
}

void AIShell::checkDirections() {
	bool isFork = false;
	int forks = 0;
	int n;
	int col;
	int row;
	int player;
	int count;
	Move move(2,2);

	for(std::pair<int,int> pair: getDirections()) {
		n = k;
		col = pair.first + move.col;
		row = pair.second + move.row;
		count = 1;

		while(inBounds(col, row) && n >= 0) {

			// check
			player = getGameState()[col][row];

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
}

// void AIShell::isPointlessMove(Move move, char turn) {
// 	// move.col;
// 	// move.row;

// 	int n;

// 	std::vector<std::pair<int, int>> directions = {
// 		// north south east west
// 		std::make_pair(1, 0),
// 		std::make_pair(-1, 0),
// 		std::make_pair(0, 1),
// 		std::make_pair(0, -1),

// 		// NE NW SE SW
// 		std::make_pair(1, 1),
// 		std::make_pair(1, -1),
// 		std::make_pair(-1, 1),
// 		std::make_pair(-1, -1)
// 	};

// 	for(std::pair<int, int> p: directions) {
// 		n = k;

// 	}
// }

	bool AIShell::inBounds(int col, int row) {
		return col >=0 && row >= 0 && col < numCols && row < numRows;
	}

	int AIShell::getCols() {
		return numCols;
	}

	int AIShell::getRows() {
		return numRows;
	}

	int** AIShell::getGameState() const {
		return gameState;
	}




