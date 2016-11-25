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



void AIShell::isPointlessMove(Move move, char turn) {
	// move.col;
	// move.row;

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

	}
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




