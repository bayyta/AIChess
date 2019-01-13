#include "runner.h"

namespace chess {

	Runner::Runner(const Vec2<int>& position, const bool& white)
		: Piece(position, white)
	{ }

	int Runner::getPossibleMoves(const Vec2<int>& kingPos, const std::shared_ptr<Piece> const (&board)[8][8],
		std::shared_ptr<Piece>(&cachedBoards)[27][8][8]) const
	{
		int count = 0;

		std::vector<Vec2<int>> positions;
		positions.reserve(27);
		getPositions(positions, board);

		for (auto& p : positions)
		{
			if (getMove(p.x, p.y, kingPos, board, cachedBoards[count]))
				count++;
		}

		return count;
	}

	void Runner::getPositions(std::vector<Vec2<int>>& outPositions, const std::shared_ptr<Piece> const (&board)[8][8])
		const
	{
		Vec2<int> newPos;
		for (auto& dir : _offsets)
		{
			int i = 1;
			newPos.x = pos.x + dir.x * i;
			newPos.y = pos.y + dir.y * i;
			if (newPos.x < 0 || newPos.x >= 8 || newPos.y < 0 || newPos.y >= 8)
			{
				continue;
			}
			while (board[newPos.y][newPos.x] == nullptr)
			{
				// can move to
				outPositions.push_back(newPos);
				i++;
				newPos.x = pos.x + dir.x * i;
				newPos.y = pos.y + dir.y * i;
				if (newPos.x < 0 || newPos.x >= 8 || newPos.y < 0 || newPos.y >= 8)
				{
					i = -1;
					break;
				}
			}
			if (i >= 0)
			{
				if (board[newPos.y][newPos.x]->isWhite != isWhite)
				{
					// can capture piece
					outPositions.push_back(newPos);
				}
			}
		}
	}

}