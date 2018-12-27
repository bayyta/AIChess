#include "piece.h"

namespace chess {


	Piece::Piece(const Vec2<int>& position, const bool& white)
		: pos(position), isWhite(white)
	{
		_moveCount = 0;
		init();
	}

	Piece::~Piece()
	{ }

	bool Piece::isChecked(const Vec2<int>& kingPos, const std::shared_ptr<Piece> const (&board)[8][8])
	{
		std::vector<Vec2<int>> positions;
		positions.reserve(26);

		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				auto& piece = board[i][j];
				if (piece != nullptr)
				{
					// if piece is opposing rook, bishop or queen
					if (piece->isWhite != isWhite && (piece->_type == 'R' || piece->_type == 'B' || piece->_type == 'Q'))
					{
						positions.clear();
						// get possible new positions
						piece->getPositions(positions, board);
						// check if 'positions' contains king's position
						for (int k = 0; k < positions.size(); k++)
						{
							if (positions[k] == kingPos)
							{
								// opposing team can check, therefore return true
								return true;
							}
						}
					}
				}
			}
		}

		return false;
	}

	void Piece::duplicateBoard(const std::shared_ptr<Piece> const (&copyFrom)[8][8],
		std::shared_ptr<Piece>(&copyTo)[8][8])
	{
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				copyTo[i][j] = copyFrom[i][j];
			}
		}
	}

	void Piece::movePiece(const int& newX, const int& newY, std::shared_ptr<Piece>(&cachedBoard)[8][8])
	{
		cachedBoard[newX][newY] = std::make_shared<Piece>(*(cachedBoard[pos.x][pos.y]));
		cachedBoard[newX][newY]->pos.x = newX;
		cachedBoard[newX][newY]->pos.y = newY;
		cachedBoard[newX][newY]->_moveCount++;
		cachedBoard[pos.x][pos.y] = nullptr;
	}

	bool Piece::getMove(const int& newX, const int& newY, const Vec2<int>& kingPos,
		const std::shared_ptr<Piece> const (&board)[8][8], std::shared_ptr<Piece>(&cachedBoard)[8][8])
	{
		duplicateBoard(board, cachedBoard);
		movePiece(newX, newY, cachedBoard);
		if (!isChecked(kingPos, cachedBoard))
			return true;
		return false;
	}

	void Piece::getPositions(std::vector<Vec2<int>>& outPositions, const std::shared_ptr<Piece> const (&board)[8][8])
	{
		return;
	}

	const int& Piece::getMoveCount()
	{
		return _moveCount;
	}

	const char& Piece::getType()
	{
		return _type;
	}

}