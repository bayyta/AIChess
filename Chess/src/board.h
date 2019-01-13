#pragma once
#include "pieces/piece.h"
#include "pieces/pawn.h"
#include "pieces/rook.h"
#include "pieces/knight.h"
#include "pieces/bishop.h"
#include "pieces/queen.h"
#include "pieces/king.h"
#include <iostream>
#include <memory>
#include <vector>
#include <sstream>

namespace chess {

	class Board
	{
	private:
		bool _whitesTurn;
		bool _moveCount;
		std::shared_ptr<Piece> _board[8][8];
		std::shared_ptr<Piece> _cachedBoards[27][8][8];
		std::shared_ptr<Piece> _whiteKing;
		std::shared_ptr<Piece> _blackKing;
	private:
		void resetBoard();
		void updateKings();
	public:
		Board();
		~Board();
		void makeMove();
		void printBoard();
	};


}