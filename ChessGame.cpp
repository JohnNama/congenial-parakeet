#include "ChessPiece.h"
#include "MinMax.h"

int main() {
	ChessBoard Board;
	Board.InitBoard();
	cout << Board;

	MinMax minMax;
	cout<<minMax.findBestMove(Board);
	return 0;
}