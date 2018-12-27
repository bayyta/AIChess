#pragma once
#include "piece.h"
#include <vector>

namespace chess {

	class Runner : public Piece
	{
	protected:
		std::vector<Vec2<int>> directions;
	protected:
		virtual void init() override = 0;
		void getPositions(std::vector<Vec2<int>>& outPositions,
			const std::shared_ptr<Piece> const (&board)[8][8]) override;
	public:
		int getPossibleMoves(const Vec2<int>& kingPos, const std::shared_ptr<Piece> const (&board)[8][8],
			std::shared_ptr<Piece>(&cachedBoards)[27][8][8]) override;
	};

}