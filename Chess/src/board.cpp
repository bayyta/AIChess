#include "board.h"

// reset pawns lastTwoSteps before making a move

namespace chess {

	Board::Board()
	{
		_whitesTurn = true;
		_moveCount = 0;
	}

	Board::~Board()
	{ }

	void Board::resetBoard()
	{
		// black - always at y-index 0
		_board[0][0] = std::make_shared<Rook>(Vec2<int>(0, 0), false);
		_board[7][0] = std::make_shared<Rook>(Vec2<int>(7, 0), false);

		_board[1][0] = std::make_shared<Knight>(Vec2<int>(1, 0), false);
		_board[6][0] = std::make_shared<Knight>(Vec2<int>(6, 0), false);

		_board[2][0] = std::make_shared<Bishop>(Vec2<int>(2, 0), false);
		_board[5][0] = std::make_shared<Bishop>(Vec2<int>(5, 0), false);

		_board[3][0] = std::make_shared<Queen>(Vec2<int>(3, 0), false);
		_board[4][0] = std::make_shared<King>(Vec2<int>(4, 0), false);

		for (int i = 0; i < 8; i++)
		{
			_board[i][1] = std::make_shared<Pawn>(Vec2<int>(i, 1), false);
		}

		// white
		_board[0][0] = std::make_shared<Rook>(Vec2<int>(0, 7), true);
		_board[7][0] = std::make_shared<Rook>(Vec2<int>(7, 7), true);

		_board[1][0] = std::make_shared<Knight>(Vec2<int>(1, 7), true);
		_board[6][0] = std::make_shared<Knight>(Vec2<int>(6, 7), true);

		_board[2][0] = std::make_shared<Bishop>(Vec2<int>(2, 7), true);
		_board[5][0] = std::make_shared<Bishop>(Vec2<int>(5, 7), true);

		_board[3][0] = std::make_shared<Queen>(Vec2<int>(3, 7), true);
		_board[4][0] = std::make_shared<King>(Vec2<int>(4, 7), true);

		for (int i = 0; i < 8; i++)
		{
			_board[i][7] = std::make_shared<Pawn>(Vec2<int>(i, 7), true);
		}
	}

	void Board::makeMove()
	{

	}

}