#pragma once
#include "piece.h"

namespace chess {

	class Knight : public Piece
	{
	private:
		void getCopy(std::shared_ptr<Piece>& copyTo) const override;
	public:
		Knight(const Vec2<int>& position, const bool& white);
		int getPossibleMoves(const Vec2<int>& kingPos, const std::shared_ptr<Piece> const (&board)[8][8],
			std::shared_ptr<Piece>(&cachedBoards)[27][8][8]) const override;
	};

}