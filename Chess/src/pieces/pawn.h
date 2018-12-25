#pragma once
#include "piece.h"
#include "queen.h"

namespace chess {

	class Pawn : public Piece
	{
	private:
		void init();
	public:
		bool lastTwoSteps;
	public:
		int getPossibleMoves(const Vec2<int>& kingPos, const std::shared_ptr<Piece> const (&board)[8][8],
			std::shared_ptr<Piece>(&cachedBoards)[26][8][8]) override;
	};

}