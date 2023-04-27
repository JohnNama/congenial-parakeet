#include "ChessPiece.h"

// ChesePiece Implantation
ChessPiece::ChessPiece()
{
	full_name = "";
	short_name = ' ';
	color = false;
	current_location = { -1, -1 };
	previous_location = { -1, -1 };
	isEmpty = true;
	weight = 0;
	initial_move = false;
	index = -1;
}

inline void ChessPiece::setPos(int x, int y) {
	previous_location = current_location;
	current_location = { x, y };
}
vector<pair<int, int>> ChessPiece::checkMovement(ChessBoard& board, ChessPiece& chess_piece) {
	vector<pair<int, int>>all_availiable_moves;
	return all_availiable_moves;
}

ostream& operator<<(ostream& os, ChessPiece& chess_piece) {
	os << "Chess piece name: " << chess_piece.full_name << '\n'
		<< "Position: " << chess_piece.current_location.first << ", " << chess_piece.current_location.second << '\n'
		<< "Previous position: " << chess_piece.previous_location.first << ", " << chess_piece.previous_location.second << '\n'
		<< "Weight: " << chess_piece.weight << "\n";
	return os;
}

King::King(int x, int y, bool color)
{
	full_name = "King";
	short_name = 'K';

	current_location = { x, y };
	previous_location = { -1, -1 };

	this->color = color;

	isEmpty = false;
	initial_move = false;

	index = 0;
	weight = 1000;
}

vector<pair<int, int>> King::checkMovement(ChessBoard& Board, ChessPiece& chess_piece)
{
	vector<pair<int, int>>all_availiable_moves;
	for (int i = chess_piece.current_location.first - 1; i <= chess_piece.current_location.first + 1 && i >= 0 && i < 8; i++)
	{
		for (int j = chess_piece.current_location.second - 1; j <= chess_piece.current_location.second + 1 && j >= 0 && j < 8; j++)
		{
			if (!Board.chess_board[i][j].isEmpty || Board.chess_board[i][j].color != chess_piece.color < 0) {
				all_availiable_moves.push_back({ i, j });
			}
		}
	}
	return all_availiable_moves;
}

Queen::Queen(int x, int y, bool color)
{
	full_name = "Queen";
	short_name = 'Q';

	current_location = { x, y };
	previous_location = { -1, -1 };

	this->color = color;

	isEmpty = false;
	initial_move = false;

	index = 1;
	weight = 9;
}
vector<pair<int, int>> Queen::checkMovement(ChessBoard& Board, ChessPiece& chess_piece)
{
	vector<pair<int, int>>all_availiable_moves;
	for (int i = chess_piece.current_location.first + 1; i < 8; i++) {
		if (Board.chess_board[i][chess_piece.current_location.second].isEmpty) {
			all_availiable_moves.push_back({ i, chess_piece.current_location.second });
		}
		else if (Board.chess_board[i][chess_piece.current_location.second].color != chess_piece.color == 0) {
			all_availiable_moves.push_back({ i, chess_piece.current_location.second });
			break;
		}
		else break;
	}
	for (int i = chess_piece.current_location.first - 1; i >= 0; i--) {
		if (Board.chess_board[i][chess_piece.current_location.second].isEmpty) {
			all_availiable_moves.push_back({ i, chess_piece.current_location.second });
		}
		else if (Board.chess_board[i][chess_piece.current_location.second].color != chess_piece.color == 0) {
			all_availiable_moves.push_back({ i, chess_piece.current_location.second });
			break;
		}
		else break;
	}
	for (int i = chess_piece.current_location.second + 1; i < 8; i++) {
		if (Board.chess_board[chess_piece.current_location.first][i].isEmpty) {
			all_availiable_moves.push_back({ chess_piece.current_location.first, i });
		}
		else if (Board.chess_board[chess_piece.current_location.first][i].color != chess_piece.color == 0) {
			all_availiable_moves.push_back({ chess_piece.current_location.first, i });
			break;
		}
		else break;
	}
	for (int i = chess_piece.current_location.second - 1; i >= 0; i--) {
		if (Board.chess_board[chess_piece.current_location.first][i].isEmpty) {
			all_availiable_moves.push_back({ chess_piece.current_location.first, i });
		}
		else if (Board.chess_board[chess_piece.current_location.first][i].color != chess_piece.color == 0) {
			all_availiable_moves.push_back({ chess_piece.current_location.first, i });
			break;
		}
		else break;
	}
	for (int i = chess_piece.current_location.first + 1, j = chess_piece.current_location.second + 1; i < 8 && j < 8 && i >= 0 && j >= 0; i++, j++) {
		if (Board.chess_board[i][j].isEmpty)
			all_availiable_moves.push_back({ i, j });
		else if (!Board.chess_board[i][j].isEmpty && Board.chess_board[i][j].color != chess_piece.color) {
			all_availiable_moves.push_back({ i, j });
			break;
		}
		else break;
	}
	for (int i = chess_piece.current_location.first + 1, j = chess_piece.current_location.second - 1; i < 8 && j < 8 && i >= 0 && j >= 0; i++, j--) {
		if (Board.chess_board[i][j].isEmpty)
			all_availiable_moves.push_back({ i, j });
		else if (!Board.chess_board[i][j].isEmpty && Board.chess_board[i][j].color != chess_piece.color) {
			all_availiable_moves.push_back({ i, j });
			break;
		}
		else break;
	}
	for (int i = chess_piece.current_location.first - 1, j = chess_piece.current_location.second + 1; i < 8 && j < 8 && i >= 0 && j >= 0; i--, j++) {
		if (Board.chess_board[i][j].isEmpty)
			all_availiable_moves.push_back({ i, j });
		else if (!Board.chess_board[i][j].isEmpty && Board.chess_board[i][j].color != chess_piece.color) {
			all_availiable_moves.push_back({ i, j });
			break;
		}
		else break;
	}
	for (int i = chess_piece.current_location.first - 1, j = chess_piece.current_location.second - 1; i < 8 && j < 8 && i >= 0 && j >= 0; i--, j--) {
		if (Board.chess_board[i][j].isEmpty)
			all_availiable_moves.push_back({ i, j });
		else if (!Board.chess_board[i][j].isEmpty && Board.chess_board[i][j].color != chess_piece.color) {
			all_availiable_moves.push_back({ i, j });
			break;
		}
		else break;
	}

	return all_availiable_moves;
}
Rook::Rook(int x, int y, bool color)
{
	full_name = "Rook";
	short_name = 'R';

	current_location = { x, y };
	previous_location = { -1, -1 };

	this->color = color;

	isEmpty = false;
	initial_move = false;

	index = 2;
	weight = 5;
}
vector<pair<int, int>> Rook::checkMovement(ChessBoard& Board, ChessPiece& chess_piece) {
	vector<pair<int, int>>all_availiable_moves;
	for (int i = chess_piece.current_location.first + 1; i < 8; i++) {
		if (Board.chess_board[i][chess_piece.current_location.second].isEmpty) {
			all_availiable_moves.push_back({ i, chess_piece.current_location.second });
		}
		else if (Board.chess_board[i][chess_piece.current_location.second].color != chess_piece.color == 0) {
			all_availiable_moves.push_back({ i, chess_piece.current_location.second });
			break;
		}
		else break;
	}
	for (int i = chess_piece.current_location.first - 1; i >= 0; i--) {
		if (Board.chess_board[i][chess_piece.current_location.second].isEmpty) {
			all_availiable_moves.push_back({ i, chess_piece.current_location.second });
		}
		else if (Board.chess_board[i][chess_piece.current_location.second].color != chess_piece.color == 0) {
			all_availiable_moves.push_back({ i, chess_piece.current_location.second });
			break;
		}
		else break;
	}
	for (int i = chess_piece.current_location.second + 1; i < 8; i++) {
		if (Board.chess_board[chess_piece.current_location.first][i].isEmpty) {
			all_availiable_moves.push_back({ chess_piece.current_location.first, i });
		}
		else if (Board.chess_board[chess_piece.current_location.first][i].color != chess_piece.color == 0) {
			all_availiable_moves.push_back({ chess_piece.current_location.first, i });
			break;
		}
		else break;
	}
	for (int i = chess_piece.current_location.second - 1; i >= 0; i--) {
		if (Board.chess_board[chess_piece.current_location.first][i].isEmpty) {
			all_availiable_moves.push_back({ chess_piece.current_location.first, i });
		}
		else if (Board.chess_board[chess_piece.current_location.first][i].color != chess_piece.color == 0) {
			all_availiable_moves.push_back({ chess_piece.current_location.first, i });
			break;
		}
		else break;
	}
	return all_availiable_moves;
}
Knight::Knight(int x, int y, bool color)
{
	full_name = "Knight";
	short_name = 'N';

	current_location = { x, y };
	previous_location = { -1, -1 };

	this->color = color;

	isEmpty = false;
	initial_move = false;

	index = 3;
	weight = 3;
}
vector<pair<int, int>> Knight::checkMovement(ChessBoard& Board, ChessPiece& chess_piece) {
	vector<pair<int, int>>all_availiable_moves;

	if (chess_piece.current_location.first - 1 >= 0 && chess_piece.current_location.second - 2 >= 0)
		if (Board.chess_board[chess_piece.current_location.first - 1][chess_piece.current_location.second - 2].isEmpty || Board.chess_board[chess_piece.current_location.first - 1][chess_piece.current_location.second - 2].color != chess_piece.color)
			all_availiable_moves.push_back({ chess_piece.current_location.first - 1, chess_piece.current_location.second - 2 });

	if (chess_piece.current_location.first - 1 >= 0 && chess_piece.current_location.second + 2 < 8)
		if (Board.chess_board[chess_piece.current_location.first - 1][chess_piece.current_location.second + 2].isEmpty || Board.chess_board[chess_piece.current_location.first - 1][chess_piece.current_location.second + 2].color != chess_piece.color)
			all_availiable_moves.push_back({ chess_piece.current_location.first - 1, chess_piece.current_location.second + 2 });

	if (chess_piece.current_location.first + 1 < 8 && chess_piece.current_location.second - 2 >= 0)
		if (Board.chess_board[chess_piece.current_location.first + 1][chess_piece.current_location.second - 2].isEmpty || Board.chess_board[chess_piece.current_location.first + 1][chess_piece.current_location.second - 2].color != chess_piece.color)
			all_availiable_moves.push_back({ chess_piece.current_location.first + 1, chess_piece.current_location.second - 2 });

	if (chess_piece.current_location.first + 1 < 8 && chess_piece.current_location.second + 2 < 8)
		if (Board.chess_board[chess_piece.current_location.first + 1][chess_piece.current_location.second + 2].isEmpty || Board.chess_board[chess_piece.current_location.first + 1][chess_piece.current_location.second + 2].color != chess_piece.color)
			all_availiable_moves.push_back({ chess_piece.current_location.first + 1, chess_piece.current_location.second + 2 });

	if (chess_piece.current_location.first - 2 >= 0 && chess_piece.current_location.second - 1 >= 0)
		if (Board.chess_board[chess_piece.current_location.first - 2][chess_piece.current_location.second - 1].isEmpty || Board.chess_board[chess_piece.current_location.first - 2][chess_piece.current_location.second - 1].color != chess_piece.color)
			all_availiable_moves.push_back({ chess_piece.current_location.first - 2, chess_piece.current_location.second - 1 });

	if (chess_piece.current_location.first - 2 >= 0 && chess_piece.current_location.second + 1 < 8)
		if (Board.chess_board[chess_piece.current_location.first - 2][chess_piece.current_location.second + 1].isEmpty || Board.chess_board[chess_piece.current_location.first - 2][chess_piece.current_location.second + 1].color != chess_piece.color)
			all_availiable_moves.push_back({ chess_piece.current_location.first - 2, chess_piece.current_location.second + 1 });

	if (chess_piece.current_location.first + 2 < 8 && chess_piece.current_location.second - 1 >= 0)
		if (Board.chess_board[chess_piece.current_location.first + 2][chess_piece.current_location.second - 1].isEmpty || Board.chess_board[chess_piece.current_location.first + 2][chess_piece.current_location.second - 1].color != chess_piece.color)
			all_availiable_moves.push_back({ chess_piece.current_location.first + 2, chess_piece.current_location.second - 1 });

	if (chess_piece.current_location.first + 2 < 8 && chess_piece.current_location.second + 1 < 8)
		if (Board.chess_board[chess_piece.current_location.first + 2][chess_piece.current_location.second + 1].isEmpty || Board.chess_board[chess_piece.current_location.first + 2][chess_piece.current_location.second + 1].color != chess_piece.color)
			all_availiable_moves.push_back({ chess_piece.current_location.first + 2, chess_piece.current_location.second + 1 });

	return all_availiable_moves;
}
Bishop::Bishop(int x, int y, bool color)
{
	full_name = "Bishop";
	short_name = 'B';

	current_location = { x, y };
	previous_location = { -1, -1 };

	this->color = color;

	isEmpty = false;
	initial_move = false;

	index = 4;
	weight = 3;
}
vector<pair<int, int>> Bishop::checkMovement(ChessBoard& Board, ChessPiece& chess_piece) {
	vector<pair<int, int>>all_availiable_moves;

	for (int i = chess_piece.current_location.first + 1, j = chess_piece.current_location.second + 1; i < 8 && j < 8 && i >= 0 && j >= 0; i++, j++) {
		if (Board.chess_board[i][j].isEmpty)
			all_availiable_moves.push_back({ i, j });
		else if (!Board.chess_board[i][j].isEmpty && Board.chess_board[i][j].color != chess_piece.color) {
			all_availiable_moves.push_back({ i, j });
			break;
		}
		else break;
	}
	for (int i = chess_piece.current_location.first + 1, j = chess_piece.current_location.second - 1; i < 8 && j < 8 && i >= 0 && j >= 0; i++, j--) {
		if (Board.chess_board[i][j].isEmpty)
			all_availiable_moves.push_back({ i, j });
		else if (!Board.chess_board[i][j].isEmpty && Board.chess_board[i][j].color != chess_piece.color) {
			all_availiable_moves.push_back({ i, j });
			break;
		}
		else break;
	}
	for (int i = chess_piece.current_location.first - 1, j = chess_piece.current_location.second + 1; i < 8 && j < 8 && i >= 0 && j >= 0; i--, j++) {
		if (Board.chess_board[i][j].isEmpty)
			all_availiable_moves.push_back({ i, j });
		else if (!Board.chess_board[i][j].isEmpty && Board.chess_board[i][j].color != chess_piece.color) {
			all_availiable_moves.push_back({ i, j });
			break;
		}
		else break;
	}
	for (int i = chess_piece.current_location.first - 1, j = chess_piece.current_location.second - 1; i < 8 && j < 8 && i >= 0 && j >= 0; i--, j--) {
		if (Board.chess_board[i][j].isEmpty)
			all_availiable_moves.push_back({ i, j });
		else if (!Board.chess_board[i][j].isEmpty && Board.chess_board[i][j].color != chess_piece.color) {
			all_availiable_moves.push_back({ i, j });
			break;
		}
		else break;
	}
	return all_availiable_moves;
}
Pawn::Pawn(int x, int y, bool color)
{
	full_name = "Pawn";
	short_name = 'P';

	current_location = { x, y };
	previous_location = { -1, -1 };

	this->color = color;

	isEmpty = false;
	initial_move = false;

	index = 5;
	weight = 1;
}
vector<pair<int, int>> Pawn::checkMovement(ChessBoard& Board, ChessPiece& chess_piece) {
	vector<pair<int, int>>all_availiable_moves;

	if (!chess_piece.color) {
		if (!chess_piece.initial_move && Board.chess_board[chess_piece.current_location.first + 2][chess_piece.current_location.second].isEmpty)
			if (chess_piece.current_location.first + 2 < 8)
				if (Board.chess_board[chess_piece.current_location.first + 2][chess_piece.current_location.second].isEmpty)
					all_availiable_moves.push_back({ chess_piece.current_location.first + 2, chess_piece.current_location.second });

		if (chess_piece.current_location.first + 1 < 8)
			if (Board.chess_board[chess_piece.current_location.first + 1][chess_piece.current_location.second].isEmpty)
				all_availiable_moves.push_back({ chess_piece.current_location.first + 1, chess_piece.current_location.second });


		if (chess_piece.current_location.first + 1 < 8 && chess_piece.current_location.second + 1 < 8)
			if (chess_piece.color != Board.chess_board[chess_piece.current_location.first + 1][chess_piece.current_location.second + 1].color && !Board.chess_board[chess_piece.current_location.first + 1][chess_piece.current_location.second + 1].isEmpty)
				all_availiable_moves.push_back({ chess_piece.current_location.first + 1, chess_piece.current_location.second + 1 });


		if (chess_piece.current_location.first + 1 < 8 && chess_piece.current_location.second - 1 >= 0)
			if (chess_piece.color != Board.chess_board[chess_piece.current_location.first + 1][chess_piece.current_location.second - 1].color && !Board.chess_board[chess_piece.current_location.first + 1][chess_piece.current_location.second - 1].isEmpty)
				all_availiable_moves.push_back({ chess_piece.current_location.first + 1,chess_piece.current_location.second - 1 });
	}
	else {
		if (!chess_piece.initial_move && Board.chess_board[chess_piece.current_location.first - 1][chess_piece.current_location.second].isEmpty)
			if (chess_piece.current_location.first - 2 >= 0)
				if (Board.chess_board[chess_piece.current_location.first - 2][chess_piece.current_location.second].isEmpty)
					all_availiable_moves.push_back({ chess_piece.current_location.first - 2, chess_piece.current_location.second });

		if (chess_piece.current_location.first - 1 >= 0)
			if (Board.chess_board[chess_piece.current_location.first - 1][chess_piece.current_location.second].isEmpty)
				all_availiable_moves.push_back({ chess_piece.current_location.first - 1, chess_piece.current_location.second });

		if (chess_piece.current_location.first - 1 >= 0 && chess_piece.current_location.second - 1 >= 0)
			if (chess_piece.color != Board.chess_board[chess_piece.current_location.first - 1][chess_piece.current_location.second - 1].color && !Board.chess_board[chess_piece.current_location.first - 1][chess_piece.current_location.second - 1].isEmpty)
				all_availiable_moves.push_back({ chess_piece.current_location.first - 1, chess_piece.current_location.second - 1 });

		if (chess_piece.current_location.first - 1 >= 0 && chess_piece.current_location.second + 1 < 8)
			if (chess_piece.color != Board.chess_board[chess_piece.current_location.first - 1][chess_piece.current_location.second + 1].color && !Board.chess_board[chess_piece.current_location.first - 1][chess_piece.current_location.second + 1].isEmpty)
				all_availiable_moves.push_back({ chess_piece.current_location.first - 1, chess_piece.current_location.second + 1 });

	}

	chess_piece.initial_move = true;

	return all_availiable_moves;
}

ChessBoard::ChessBoard()
{
	chess_board = new ChessPiece*[8];
	for (int i = 0; i < 8; i++) {
		chess_board[i] = new ChessPiece[8];
	}
}

void ChessBoard::InitBoard()
{
	string chess_place_order = "3452154366666666000000000000000000000000000000006666666634521543";
	bool color = false;
	char pos_board;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			pos_board = chess_place_order[i * 8 + j];
			if (i * 8 + j > 32)
				color = true;
			else
				color = false;

			switch (pos_board)
			{
			case '1':
				chess_board[i][j] = King(i, j, color);
				continue;
			case '2':
				chess_board[i][j] = Queen(i, j, color);
				continue;
			case '3':
				chess_board[i][j] = Rook(i, j, color);
				continue;
			case '4':
				chess_board[i][j] = Knight(i, j, color);
				continue;
			case '5':
				chess_board[i][j] = Bishop(i, j, color);
				continue;
			case '6':
				chess_board[i][j] = Pawn(i, j, color);
				continue;
			}
		}
	}
}

ChessBoard ChessBoard::makeMove(ChessBoard& chess_board, Move& move)
{
	chess_board.chess_board[move.end_X][move.end_Y] = chess_board.chess_board[move.start_X][move.start_Y];
	chess_board.chess_board[move.start_X][move.start_Y] = ChessPiece();
	return chess_board;
}

ostream& operator<<(ostream& os, const Move& move) {
	os << move.start_X << ", " << move.start_Y << endl;
	os << move.end_X << ", " << move.end_Y << endl;
	return os;
}

ostream& operator<<(ostream& os, const ChessBoard& board) {
	os << "Board Condition: " << endl;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (!board.chess_board[i][j].isEmpty)
			{
				board.chess_board[i][j].color == true ? os << 'w' : os << 'b';
				os << board.chess_board[i][j].short_name << "  ";
			}
			else
				os << "  ";
		}
		os << "\n\n";
	}
	return os;
}