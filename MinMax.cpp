#include "MinMax.h"

int MinMax::evaluate(ChessBoard board) const {
	int white_value = 0;
	int black_value = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (!board.chess_board[i][j].isEmpty) {
				board.chess_board[i][j].color == true ?
					white_value +=
					(board.chess_board[i][j].weight + chess_weight_on_board[1][board.chess_board[i][j].index][i][j])
					:
					black_value +=
					(board.chess_board[i][j].weight + chess_weight_on_board[0][board.chess_board[i][j].index][i][j]);
			}
		}
	}
	return black_value - white_value;
}

int MinMax::minMax(int depth, int alpha, int beta, bool isMax, ChessBoard board) {
	if (depth == 0)
		return evaluate(board);

	if (isMax) {
		int maxEval = INT_MIN;
		vector<Move> moves = generateMoves(board, true);
		for (Move move : moves) {
			ChessBoard newBoard = board.makeMove(board, move);
			int eval = minMax(depth - 1, alpha, beta, true, newBoard);
			maxEval = max(maxEval, eval);
			alpha = max(alpha, eval);
			if (beta <= alpha)
				break;
		}
		return maxEval;
	}
	else {
		int minEval = INT_MAX;
		vector<Move> moves = generateMoves(board, false);
		for (Move move : moves) {
			ChessBoard newBoard = board.makeMove(board, move);
			int eval = minMax(depth - 1, alpha, beta, true, newBoard);
			minEval = min(beta, eval);
			beta = min(beta, eval);
			if (beta <= alpha)
				break;
		}
		return minEval;
	}
}

Move MinMax::findBestMove(ChessBoard board) {
	vector<Move>moves = generateMoves(board, false);
	int bestEval = INT_MIN;
	Move bestMove;
	for (Move move : moves) {
		ChessBoard newBoard = board.makeMove(board, move);
		int eval = minMax(3, INT_MIN, INT_MAX, true, newBoard);
		if (eval > bestEval) {
			bestEval = eval;
			bestMove = move;
		}
	}
	return bestMove;
}

vector<Move> MinMax::generateMoves(ChessBoard &board, bool isWhite) {
	vector<Move>moves;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (!board.chess_board[i][j].isEmpty && board.chess_board[i][j].color == isWhite)
			{
				vector<pair<int, int>>pieceMoves = board.chess_board[i][j].checkMovement(board, board.chess_board[i][j]);
				for (auto& pieceMove : pieceMoves) {
					Move move = { i, j, pieceMove.first, pieceMove.second };
					moves.push_back(move);
				}
			}
		}
	}
	return moves;
}