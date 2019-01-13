#pragma once
#include "piece.h"
#include <vector>

namespace chess {

	class Runner : public Piece
	{
	protected:
		void getPositions(std::vector<Vec2<int>>& outPositions,
			const std::shared_ptr<Piece> const (&board)[8][8]) const override;
		void getCopy(std::shared_ptr<Piece>& copyTo) const override = 0;
	public:
		Runner(const Vec2<int>& position, const bool& white);
		int getPossibleMoves(const Vec2<int>& kingPos, const std::shared_ptr<Piece> const (&board)[8][8],
			std::shared_ptr<Piece>(&cachedBoards)[27][8][8]) const override;
	};

}