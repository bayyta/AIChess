#include "knight.h"

namespace chess {

	void Knight::init()
	{
		_type = 'N';
		_offsets = { {1, -2},{2, -1},{2, 1},{1, 2},{-1, 2},{-2, 1},{-2, -1},{-1, -2} };
	}

	int Knight::getPossibleMoves(const Vec2<int>& kingPos, const std::shared_ptr<Piece> const (&board)[8][8],
		std::shared_ptr<Piece>(&cachedBoards)[27][8][8])
	{
		int count = 0;

		Vec2<int> newPos;
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
			if (getMove(newPos.x, newPos.y, kingPos, board, cachedBoards[count]))
				count++;
		}

		return count;
	}

}