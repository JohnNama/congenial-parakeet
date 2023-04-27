#pragma once
#include "dependencies.h"

class ChessPiece;
class ChessBoard;
class Move;

class ChessPiece {
public:
	string full_name;
	char short_name;
	bool color;
	pair<int, int> current_location;
	pair<int, int> previous_location;
	bool isEmpty;
	bool initial_move;
	int index;
	float weight;

	vector<pair<int, int>> checkMovement(ChessBoard &board, ChessPiece& chess_piece);
	
public:
	ChessPiece();
	ChessPiece(const ChessPiece& chess_piece) : full_name(chess_piece.full_name), short_name(chess_piece.short_name), color(chess_piece.color), current_location(chess_piece.current_location), previous_location(chess_piece.previous_location), isEmpty(chess_piece.isEmpty), weight(chess_piece.weight), initial_move(chess_piece.initial_move), index(chess_piece.index) {}

	inline void setPos(int x, int y);

	friend ostream& operator<<(ostream& os, const ChessPiece& chess_piece);
};

class King : public ChessPiece
{
public:
	King(int x, int y, bool color);
	vector<pair<int, int>> checkMovement(ChessBoard& Board, ChessPiece& chess_piece);
	friend ostream& operator<<(ostream& os, const  ChessPiece& chess_piece);
};

class Queen : public ChessPiece
{
public:
	Queen(int x, int y, bool color);
	vector<pair<int, int>> checkMovement(ChessBoard& Board, ChessPiece& chess_piece);
	friend ostream& operator<<(ostream& os, const  ChessPiece& chess_piece);
};

class Rook : public ChessPiece
{
public:
	Rook(int x, int y, bool color);
	vector<pair<int, int>> checkMovement(ChessBoard& Board, ChessPiece& chess_piece);
	friend ostream& operator<<(ostream& os, const ChessPiece& chess_piece);
};

class Knight : public ChessPiece
{
public:
	Knight(int x, int y, bool color);
	vector<pair<int, int>> checkMovement(ChessBoard& Board, ChessPiece& chess_piece);
	friend ostream& operator<<(ostream& os, const ChessPiece& chess_piece);
};

class Bishop : public ChessPiece
{
public:
	Bishop(int x, int y, bool color);
	vector<pair<int, int>> checkMovement(ChessBoard& Board, ChessPiece& chess_piece);
	friend ostream& operator<<(ostream& os, const ChessPiece& chess_piece);
};

class Pawn : public ChessPiece {
public:
	Pawn(int x, int y, bool color);
	vector<pair<int, int>> checkMovement(ChessBoard& Board, ChessPiece& chess_piece);
	friend ostream& operator<<(ostream& os, const ChessPiece& chess_piece);
};



class Move
{
public:
	int start_X, start_Y;
	int end_X, end_Y;
	Move() :start_X(-1), start_Y(-1), end_X(-1), end_Y(-1) {}
	Move(int S_X, int S_Y, int E_X, int E_Y) :start_X(S_X), start_Y(S_Y), end_X(E_X), end_Y(E_Y) {}
	Move(const Move& move) : start_X(move.start_X), start_Y(move.start_Y), end_X(move.end_X), end_Y(move.end_Y) {}
	friend ostream& operator<<(ostream& os, const Move& move);
};




class ChessBoard
{
public:
	ChessPiece **chess_board;
	ChessBoard();
	void InitBoard();
	ChessBoard makeMove(ChessBoard& chess_board, Move& move);
	friend ostream& operator<<(ostream& os, const ChessBoard& board);
};



