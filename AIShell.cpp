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



void AIShell::checkDirections(int** state) {
	bool isFork = false;
	int forks = 0;
	int n;
	int col;
	int row;
	int player;
	int reverseDirection;
	int count;
	int current;
	bool blocked;
	bool gap;
	Move move(2,2);

	current = state[move.col][move.row];

	for(std::pair<int,int> pair: getDirections()) {
		n = k;
		col = pair.first + move.col;
		row = pair.second + move.row;
		count = 1;
		blocked = false;
		gap = false;
		reverseDirection = getPlayer(state, getOpposite(pair));
		while(inBounds(col, row) && n >= 0) {

			// check
			player = state[col][row];

			if (current == player) {
				count++;
			} else if (player == AIShell::NO_PIECE) {
				gap = true;
				// skip
			} else {
				blocked = true;
				// blocked?
				break;
			}

			// increment
			col += pair.first;
			row += pair.second;
			n--;
		}

		if ((k-2) == count && !blocked && !gap) {
			// must be blocked!
		} else if ((k-1) == count && !blocked && gap) {

		}
	}
}

std::pair<int, int> AIShell::getOpposite(std::pair<int, int> pair) {
	return getOpposite(pair.first, pair.second);
}

std::pair<int,int> AIShell::getOpposite(int col, int row) {
	col = col * -1;
	row = row * -1;
	return std::make_pair(col,row);
}


int AIShell::getPlayer(int** state, int col, int row) {
	if (inBounds(col, row)) {
		return state[col][row];
	}

	// raise exception?
	return OUT_OF_BOUNDS;
}

int AIShell::getPlayer(int** state, std::pair<int,int> pair) {
	if(inBounds(pair.first, pair.second)) {
		return state[pair.first][pair.second];
	}

	return OUT_OF_BOUNDS;
}
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




