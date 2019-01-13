#include "board.h"

// reset pawns lastTwoSteps before making a move

namespace chess {

	Board::Board()
	{
		_whitesTurn = true;
		_moveCount = 0;
		resetBoard();
	}

	Board::~Board()
	{ }

	void Board::resetBoard()
	{
		for (int y = 0; y < 8; y++)
		{
			for (int x = 0; x < 8; x++)
			{
				_board[y][x] = nullptr;
			}
		}

		// black - always at y-index 0
		_board[0][0] = std::make_shared<Rook>(Vec2<int>(0, 0), false);
		_board[0][7] = std::make_shared<Rook>(Vec2<int>(7, 0), false);

		_board[0][1] = std::make_shared<Knight>(Vec2<int>(1, 0), false);
		_board[0][6] = std::make_shared<Knight>(Vec2<int>(6, 0), false);

		_board[0][2] = std::make_shared<Bishop>(Vec2<int>(2, 0), false);
		_board[0][5] = std::make_shared<Bishop>(Vec2<int>(5, 0), false);

		_board[0][3] = std::make_shared<Queen>(Vec2<int>(3, 0), false);
		_board[0][4] = _blackKing = std::make_shared<King>(Vec2<int>(4, 0), false);

		for (int i = 0; i < 8; i++)
		{
			_board[1][i] = std::make_shared<Pawn>(Vec2<int>(i, 1), false);
		}

		// white
		_board[7][0] = std::make_shared<Rook>(Vec2<int>(0, 7), true);
		_board[7][7] = std::make_shared<Rook>(Vec2<int>(7, 7), true);

		_board[7][1] = std::make_shared<Knight>(Vec2<int>(1, 7), true);
		_board[7][6] = std::make_shared<Knight>(Vec2<int>(6, 7), true);

		_board[7][2] = std::make_shared<Bishop>(Vec2<int>(2, 7), true);
		_board[7][5] = std::make_shared<Bishop>(Vec2<int>(5, 7), true);

		_board[7][3] = std::make_shared<Queen>(Vec2<int>(3, 7), true);
		_board[7][4] = _whiteKing = std::make_shared<King>(Vec2<int>(4, 7), true);

		for (int i = 0; i < 8; i++)
		{
			_board[6][i] = std::make_shared<Pawn>(Vec2<int>(i, 6), true);
		}
	}

	void Board::makeMove()
	{
		for (int y = 0; y < 8; y++)
		{
			for (int x = 0; x < 8; x++)
			{
				if (_board[y][x] != nullptr)
				{
					if (_board[y][x]->isWhite == _whitesTurn)
					{
						int count;
						if (_whitesTurn)
						{
							count = _board[y][x]->getPossibleMoves(_whiteKing->pos, _board, _cachedBoards);
						}
						else
						{
							count = _board[y][x]->getPossibleMoves(_blackKing->pos, _board, _cachedBoards);
						}
						if (count > 0)
						{
							std::cout << count << ", " << _board[y][x]->getType() << std::endl;
							// get first possible move (preliminary)
							_board[y][x]->duplicateBoard(_cachedBoards[0], _board);
							if (!_whitesTurn)
								updateKings();
							_whitesTurn = !_whitesTurn;
							_moveCount++;
							return;
						}
					}
				}
			}
		}

		std::cout << "No possible moves" << std::endl;
	}

	void Board::updateKings()
	{
		for (int y = 0; y < 8; y++)
		{
			for (int x = 0; x < 8; x++)
			{
				if (_board[y][x] != nullptr)
				{
					if (_board[y][x]->getType() == 'K')
					{
						if (_board[y][x]->isWhite)
							_whiteKing = _board[y][x];
						else
							_blackKing = _board[y][x];
					}
				}
			}
		}
	}

	void Board::printBoard()
	{
		std::stringstream ss;

		ss << "  ";
		for (int i = 0; i < 8; i++)
		{
			ss << (char) ('a' + i) << "  ";
		}
		ss << '\n';

		for (int y = 0; y < 8; y++)
		{
			ss << 8 - y << " ";
			for (int x = 0; x < 8; x++)
			{
				if (_board[y][x] != nullptr)
				{
					if (_board[y][x]->isWhite)
						ss << 'w';
					else
						ss << 'b';

					ss << _board[y][x]->getType() << " ";
				}
				else
				{
					ss << " - ";
				}
			}
			ss << '\n';
		}

		std::cout << ss.str();
	}

}