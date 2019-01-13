#include "king.h"

namespace chess {

	King::King(const Vec2<int>& position, const bool& white)
		: Piece(position, white)
	{
		_type = 'K';
		_offsets = { {0, -1}, {1, 0}, {0, 1}, {-1, 0} };
	}

	int King::getPossibleMoves(const Vec2<int>& kingPos, const std::shared_ptr<Piece> const (&board)[8][8],
		std::shared_ptr<Piece>(&cachedBoards)[27][8][8]) const
	{
		int count = 0;

		Vec2<int> newPos;
		// normal moves
		for (auto& o : _offsets)
		{
			newPos.x = pos.x + o.x;
			newPos.y = pos.y + o.y;
			if (newPos.x < 0 || newPos.x >= 8 || newPos.y < 0 || newPos.y >= 8)
				continue;
			if (board[newPos.y][newPos.x] != nullptr)
			{
				if (board[newPos.y][newPos.x]->isWhite == isWhite)
					continue;
			}
			if (getMove(newPos.x, newPos.y, newPos, board, cachedBoards[count]))
				count++;
		}

		// castle
		if (_moveCount == 0)
		{
			if (!isChecked(pos, board))
			{
				int xOffset = 0;
				for (int dir = -1; dir < 2; dir += 2)
				{
					// queen side castle
					if (board[pos.y][xOffset] != nullptr)
					{
						if (board[pos.y][xOffset]->getType() == 'R' && board[pos.y][xOffset]->getMoveCount() == 0)
						{
							int i = 1;
							while (board[pos.y][pos.x + i * dir] != nullptr)
							{
								i++;
							}
							if ((pos.x + i * dir) % 7 == 0)
							{
								// king moves through attacked square?
								if (getMove(pos.x + dir, pos.y, Vec2<int>(pos.x + dir, pos.y), board,
									cachedBoards[count]))
								{
									if (getMove(pos.x + dir * 2, pos.y, Vec2<int>(pos.x + dir * 2, pos.y), board,
										cachedBoards[count]))
									{
										// can castle, move rook as well
										board[pos.y][xOffset]->movePiece(pos.x + dir, pos.y, cachedBoards[count]);
										count++;
									}
								}
							}
						}
					}

					xOffset += 7;
				}
			}

		}

		return count;
	}

	void King::getCopy(std::shared_ptr<Piece>& copyTo) const
	{
		copyTo = std::make_shared<King>(*this);
	}

}