#include "king.h"

namespace chess {

	void King::init()
	{
		_type = 'K';
		_offsets = { {0, -1}, {1, 0}, {0, 1}, {-1, 0} };
	}

	int King::getPossibleMoves(const Vec2<int>& kingPos, const std::shared_ptr<Piece> const (&board)[8][8],
		std::shared_ptr<Piece>(&cachedBoards)[27][8][8])
	{
		int count = 0;

		Vec2<int> newPos;
		// normal moves
		for (auto& o : _offsets)
		{
			newPos = pos + o;
			if (newPos.x < 0 || newPos.x >= 8 || newPos.y < 0 || newPos.y >= 8)
				continue;
			if (board[newPos.x][newPos.y] != nullptr)
			{
				if (board[newPos.x][newPos.y]->isWhite == isWhite)
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
					if (board[xOffset][pos.y] != nullptr)
					{
						if (board[xOffset][pos.y]->getType() == 'R' && board[xOffset][pos.y]->getMoveCount() == 0)
						{
							int i = 1;
							while (board[pos.x + i * dir][pos.y] != nullptr)
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
										board[xOffset][pos.y]->movePiece(pos.x + dir, pos.y, cachedBoards[count]);
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

}