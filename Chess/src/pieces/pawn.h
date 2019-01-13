#pragma once
#include "piece.h"
#include "queen.h"

namespace chess {

	class Pawn : public Piece
	{
	private:
		bool getMove(const int& newX, const int& newY, const Vec2<int>& kingPos,
			const std::shared_ptr<Piece> const (&board)[8][8], std::shared_ptr<Piece>(&cachedBoard)[8][8]) const override;
		void getCopy(std::shared_ptr<Piece>& copyTo) const override;
	public:
		bool lastTwoSteps;
	public:
		Pawn(const Vec2<int>& position, const bool& white);
		int getPossibleMoves(const Vec2<int>& kingPos, const std::shared_ptr<Piece> const (&board)[8][8],
			std::shared_ptr<Piece>(&cachedBoards)[27][8][8]) const override;
	};

}