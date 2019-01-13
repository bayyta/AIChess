#include "knight.h"

namespace chess {

	Knight::Knight(const Vec2<int>& position, const bool& white)
		: Piece(position, white)
	{
		_type = 'N';
		_offsets = { {1, -2},{2, -1},{2, 1},{1, 2},{-1, 2},{-2, 1},{-2, -1},{-1, -2} };
	}

	int Knight::getPossibleMoves(const Vec2<int>& kingPos, const std::shared_ptr<Piece> const (&board)[8][8],
		std::shared_ptr<Piece>(&cachedBoards)[27][8][8]) const
	{
		int count = 0;

		Vec2<int> newPos;
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
			if (getMove(newPos.x, newPos.y, kingPos, board, cachedBoards[count]))
				count++;
		}

		return count;
	}

	void Knight::getCopy(std::shared_ptr<Piece>& copyTo) const
	{
		copyTo = std::make_shared<Knight>(*this);
	}

}