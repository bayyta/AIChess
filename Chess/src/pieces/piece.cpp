#include "piece.h"

namespace chess {


	Piece::Piece(const Vec2<int>& position, const bool& white)
		: pos(position), isWhite(white)
	{
		_moveCount = 0;
	}

	Piece::~Piece()
	{ }

	bool Piece::isChecked(const Vec2<int>& kingPos, const std::shared_ptr<Piece> const (&board)[8][8]) const
	{
		std::vector<Vec2<int>> positions;
		positions.reserve(26);

		for (int y = 0; y < 8; y++)
		{
			for (int x = 0; x < 8; x++)
			{
				auto& piece = board[y][x];
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
		std::shared_ptr<Piece>(&copyTo)[8][8]) const
	{
		for (int y = 0; y < 8; y++)
		{
			for (int x = 0; x < 8; x++)
			{
				copyTo[y][x] = copyFrom[y][x];
			}
		}
	}

	void Piece::movePiece(const int& newX, const int& newY, std::shared_ptr<Piece>(&cachedBoard)[8][8]) const
	{
		//cachedBoard[newY][newX] = std::make_shared<Piece>(*(cachedBoard[pos.y][pos.x]));
		cachedBoard[pos.y][pos.x]->getCopy(cachedBoard[newY][newX]);
		cachedBoard[newY][newX]->pos.x = newX;
		cachedBoard[newY][newX]->pos.y = newY;
		cachedBoard[newY][newX]->_moveCount++;
		cachedBoard[pos.y][pos.x] = nullptr;
	}

	bool Piece::getMove(const int& newX, const int& newY, const Vec2<int>& kingPos,
		const std::shared_ptr<Piece> const (&board)[8][8], std::shared_ptr<Piece>(&cachedBoard)[8][8]) const
	{
		duplicateBoard(board, cachedBoard);
		movePiece(newX, newY, cachedBoard);
		if (!isChecked(kingPos, cachedBoard))
			return true;
		return false;
	}

	void Piece::getPositions(std::vector<Vec2<int>>& outPositions, const std::shared_ptr<Piece> const (&board)[8][8]) const
	{
		return;
	}

	const int& Piece::getMoveCount() const
	{
		return _moveCount;
	}

	const char& Piece::getType() const
	{
		return _type;
	}

}